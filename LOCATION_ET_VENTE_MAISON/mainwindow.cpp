#include "mainwindow.h"
#include "ui_mainwindow.h"

// 🔹 Formulaires et fenêtres annexes
#include "maisonform.h"
#include "maisonlisteviewer.h"


// QTcharts
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>



// 🔹 Qt

#include <QtGlobal>
#include <QTime>

#include <QElapsedTimer>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

//  Table de hachage
#include "tablehachage.h"
#include "fonctionhachage.h"

QT_CHARTS_USE_NAMESPACE


//  Base de données globale
QSqlDatabase globalDb;

//  Constructeur et destructeur
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      table(1000, FonctionsHachage::hachage1)  // Initialisation avec F1 par défaut
{
    ui->setupUi(this);

    globalDb = QSqlDatabase::addDatabase("QSQLITE");
    globalDb.setDatabaseName("maisons.db");

    if (!globalDb.open()) {
        QMessageBox::critical(this, "Erreur base données",
                              "Impossible d'ouvrir la base de données : " + globalDb.lastError().text());
        qApp->quit();
    } else {
        QSqlQuery query(globalDb);
        query.exec("CREATE TABLE IF NOT EXISTS maisons ("
                   "cle TEXT PRIMARY KEY,"
                   "type TEXT,"
                   "standing TEXT,"
                   "nbChambres INTEGER,"
                   "nbToilettes INTEGER,"
                   "photos TEXT,"
                   "description TEXT)");
    }
}

MainWindow::~MainWindow()
{
    if (globalDb.isOpen())
        globalDb.close();
    delete ui;
}




//  MENU : BASE DE DONNÉES

void MainWindow::on_pushButtonInsererMaison_clicked()
{
    MaisonForm dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        Maison maison = dlg.getMaison();

        // Conversion QVector<QString> en QStringList puis en chaîne
        QVector<QString> vectPhotos = maison.getCheminsPhotos();
        QStringList listPhotos;
        for (const QString &s : vectPhotos) {
            listPhotos << s;
        }
        QString photosConcat = listPhotos.join(";");

        // Préparation de la requête
        QSqlQuery query;
        query.prepare("INSERT OR REPLACE INTO maisons "
                      "(cle, type, standing, nbChambres, nbToilettes, photos, description) "
                      "VALUES (:cle, :type, :standing, :nbChambres, :nbToilettes, :photos, :description)");

        query.bindValue(":cle", maison.getCle());
        query.bindValue(":type", maison.getType());
        query.bindValue(":standing", maison.getStanding());
        query.bindValue(":nbChambres", maison.getNbChambres());
        query.bindValue(":nbToilettes", maison.getNbToilettes());
        query.bindValue(":photos", photosConcat);
        query.bindValue(":description", maison.getDescription());

        if (!query.exec()) {
            QMessageBox::warning(this, "Erreur insertion DB",
                                 "Erreur SQL : " + query.lastError().text());
        } else {
            QMessageBox::information(this, "Succès", "Maison ajoutée !");
        }
    }
}

void MainWindow::on_actionCHARGER_triggered()
{
    QSqlQuery query(globalDb);
    if (!query.exec("SELECT * FROM maisons")) {
        QMessageBox::warning(this, "Erreur DB", "Impossible de charger les données : " + query.lastError().text());
        return;
    }

    table.clear();  // Vide la table avant de recharger

    while (query.next()) {
        QString cle = query.value("cle").toString();
        QString type = query.value("type").toString();
        QString standing = query.value("standing").toString();
        int nbChambres = query.value("nbChambres").toInt();
        int nbToilettes = query.value("nbToilettes").toInt();
        QString photosStr = query.value("photos").toString();
        QString description = query.value("description").toString();

        // Sépare les photos en QVector<QString>
        QStringList photosList = photosStr.split(";", QString::SplitBehavior::SkipEmptyParts);

        // Crée un objet Maison avec les données
        QVector<QString> photosVector = photosList.toVector();
        Maison maison(cle, type, standing, nbChambres, nbToilettes, photosVector, description);


        // Ajoute la maison dans la table de hachage
        table.insertion(maison);

    }

    QMessageBox::information(this, "Chargement", "Données chargées depuis la base SQLite !");
}




void MainWindow::on_actionSAUVEGARDER_triggered()
{
    QSqlQuery query(globalDb);
    if (!query.exec("DELETE FROM maisons")) {
        QMessageBox::warning(this, "Erreur DB", "Impossible de vider la table : " + query.lastError().text());
        return;
    }

    bool ok = true;

    for (int i = 0; i < table.getCapacite(); ++i) {
        for (const Maison& m : table.getListe(i)) {
            query.prepare("INSERT INTO maisons "
                          "(cle, type, standing, nbChambres, nbToilettes, photos, description) "
                          "VALUES (:cle, :type, :standing, :nbChambres, :nbToilettes, :photos, :description)");

            query.bindValue(":cle", m.getCle());
            query.bindValue(":type", m.getType());
            query.bindValue(":standing", m.getStanding());
            query.bindValue(":nbChambres", m.getNbChambres());
            query.bindValue(":nbToilettes", m.getNbToilettes());

            // Conversion QVector<QString> vers QStringList, puis join
            QStringList photosList = QStringList::fromVector(m.getCheminsPhotos());
            query.bindValue(":photos", photosList.join(";"));

            query.bindValue(":description", m.getDescription());

            if (!query.exec()) {
                ok = false;
                QMessageBox::warning(this, "Erreur insertion DB", "Erreur SQL : " + query.lastError().text());
                break;
            }
        }
        if (!ok) break;
    }

    if (ok)
        QMessageBox::information(this, "SAUVEGARDE", "Données sauvegardées dans la base SQLite !");
}

void MainWindow::on_actionTAILLE_triggered()
{
    // Par exemple, afficher la taille de la table de hachage
    QMessageBox::information(this, "TAILLE DE LA TABLE", QString::number(table.size()));


}
void MainWindow::on_actionNOMBRE_DE_COLLISION_triggered()
{


    QMessageBox::information(this, "LE NOMBRE DE COLLISON EST ", QString::number(table.col()));

}



// 🔹 MENU : MAISON

void MainWindow::on_actionAFFICHER_triggered()
{
    QVector<Maison> vectMaisons;

    for (int i = 0; i < table.getCapacite(); ++i) {
        const QList<Maison>& liste = table.getListe(i);
        for (const Maison& m : liste)
            vectMaisons.append(m);
    }

    if (vectMaisons.isEmpty()) {
        QMessageBox::information(this, "Aucune maison", "La base ne contient aucune maison.");
        return;
    }

    MaisonListeViewer dlg(vectMaisons, this);

    dlg.exec();
}


void MainWindow::on_actionRECHERCHER_triggered()
{
    QString cle = QInputDialog::getText(this, "Recherche", "Entrez la clé de la maison :");
    if (cle.isEmpty()) return;

    Maison* maison = table.get(cle);

    if (maison) {
        QString info = QString("Clé : %1\nType : %2\nStanding : %3\nChambres : %4\nToilettes : %5\nDescription : %6")
                           .arg(maison->getCle())
                           .arg(maison->getType())
                           .arg(maison->getStanding())
                           .arg(maison->getNbChambres())
                           .arg(maison->getNbToilettes())
                           .arg(maison->getDescription());

        QMessageBox::information(this, "Maison trouvée", info);
    } else {
        QMessageBox::warning(this, "Erreur", "Maison introuvable !");
    }
}


void MainWindow::on_actionINSERER_triggered()
{
    MaisonForm *formulaire = new MaisonForm(this);
    formulaire->exec();
}


void MainWindow::on_actionSUPPRIMER_triggered()
{
    QString cle = QInputDialog::getText(this, "Suppression", "Entrez la clé de la maison à supprimer :");
    if (cle.isEmpty()) return;

    if (table.suppression(cle)) {

            QMessageBox::information(this, "Suppression", "Maison supprimée avec succès !");
        }
     else {
        QMessageBox::warning(this, "Erreur", "Maison non trouvée !");
    }
}


// 🔹 MENU : FONCTIONS DE HACHAGE

void MainWindow::on_actionF1_triggered()
{
    table.changerFonctionHachage(FonctionsHachage::hachage1);
    QMessageBox::information(this, "Hachage F1", "Fonction F1 appliquée !");
}

void MainWindow::on_actionF2_triggered()
{
    table.changerFonctionHachage(FonctionsHachage::hachage2);
    QMessageBox::information(this, "Hachage F2", "Fonction F2 appliquée !");
}

void MainWindow::on_actionF3_triggered()
{
    table.changerFonctionHachage(FonctionsHachage::hachage3);
    QMessageBox::information(this, "Hachage F3", "Fonction F3 appliquée !");
}

void MainWindow::on_actionSANS_HACHAGE_triggered()
{
    table.changerFonctionHachage(FonctionsHachage::hachageSans);
    QMessageBox::information(this, "Sans Hachage", "Indexation directe appliquée !");
}


// 🔹 MENU : COURBES

void MainWindow::on_actionCOURBE_HVS_triggered()
{
    afficherCourbeComparaison();
}




void MainWindow::afficherCourbeComparaison()
{
    QLineSeries *serieHachage = new QLineSeries();
    serieHachage->setName("Hachage");

    QLineSeries *serieSansHachage = new QLineSeries();
    serieSansHachage->setName("Sans hachage");

    // Exemple de données (à remplacer par les vraies données)
    serieHachage->append(0, 5);
    serieHachage->append(1, 8);
    serieHachage->append(2, 10);

    serieSansHachage->append(0, 12);
    serieSansHachage->append(1, 18);
    serieSansHachage->append(2, 25);

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(serieHachage);
    chart->addSeries(serieSansHachage);
    chart->setTitle("Comparaison Hachage vs Sans Hachage");
    chart->createDefaultAxes();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Affichage dans une nouvelle fenêtre
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Courbe de comparaison");
    dialog->resize(1000, 1000);

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);

    dialog->setLayout(layout);
    dialog->exec();
}


qint64 MainWindow::mesurerInsertionHachage1(const QVector<Maison>& liste)
{
    TableHachage table(20,FonctionsHachage:: hachage1);
    QElapsedTimer timer;
    timer.start();
    for (const Maison& m : liste)
        table.insertion(m);
    return timer.elapsed();
}
// f2
qint64 MainWindow::mesurerInsertionHachage2(const QVector<Maison>& liste)
{
    TableHachage table(20,FonctionsHachage:: hachage2);
    QElapsedTimer timer;
    timer.start();
    for (const Maison& m : liste)
        table.insertion(m);
    return timer.elapsed();
}

// f3
qint64 MainWindow::mesurerInsertionHachage3(const QVector<Maison>& liste)
{
    TableHachage table(20,FonctionsHachage:: hachage3);
    QElapsedTimer timer;
    timer.start();
    for (const Maison& m : liste)
        table.insertion(m);
    return timer.elapsed();
}

// sans hachage (QList simple)
qint64 mesurerInsertionSansHachage(const QVector<Maison>& liste)
{
    QElapsedTimer timer;
    timer.start();
    QList<Maison> tempListe;
    for (const Maison& m : liste)
        tempListe.append(m);
    return timer.elapsed();
}

void MainWindow::afficherCourbeF1F2F3()
{
    QLineSeries *f1Series = new QLineSeries();
    QLineSeries *f2Series = new QLineSeries();
    QLineSeries *f3Series = new QLineSeries();
    QLineSeries *sansHachageSeries = new QLineSeries();

    f1Series->setName("Hachage 1");
    f2Series->setName("Hachage 2");
    f3Series->setName("Hachage 3");
    sansHachageSeries->setName("Sans Hachage");

    int capaciteTable = 100;
    QList<int> tailles = {0,1,2,3,4,5,6,7,8,8,10,11,12,13,14,15,16,17,18,19, 20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,38,39,40,41,42,43,44,45,46,47,48,49,50,60,70,80,90,100};

    for (int taille : tailles) {
        QVector<Maison> maisons;
        for (int i = 0; i < taille; ++i) {
            QString cle = QString::number(qrand() % 100000);
            maisons.append(Maison(cle, "Vente", "Haut", 3, 2, {}, "Description"));
        }

        TableHachage tableF1(capaciteTable, FonctionsHachage::hachage1);
        TableHachage tableF2(capaciteTable, FonctionsHachage::hachage2);
        TableHachage tableF3(capaciteTable, FonctionsHachage::hachage3);
        TableHachage tableSans(capaciteTable, FonctionsHachage::hachageSans);

        for (const Maison& m : maisons) {
            tableF1.insertion(m);
            tableF2.insertion(m);
            tableF3.insertion(m);
            tableSans.insertion(m);
        }

        f1Series->append(taille, tableF1.col());
        f2Series->append(taille, tableF2.col());
        f3Series->append(taille, tableF3.col());
        sansHachageSeries->append(taille, tableSans.col());
    }


    QChart *chart = new QChart();
    chart->addSeries(f1Series);
    chart->addSeries(f2Series);
    chart->addSeries(f3Series);
    chart->addSeries(sansHachageSeries);
    chart->setTitle("Courbe de comparaison des collisions (f1, f2, f3, sans)");
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setTitleText("Nombre de clés insérées");
    chart->axes(Qt::Vertical).first()->setTitleText("Nombre de collisions");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Courbe de comparaison des collisions");
    dialog->resize(1000, 1000);

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->exec();
}


void MainWindow::on_actionCOURBE_f1_VS_f2_triggered()
{
    afficherCourbeF1F2F3();
}




// QUITTER

void MainWindow::on_actionQUITTER_triggered()
{
    QApplication::quit();
}
