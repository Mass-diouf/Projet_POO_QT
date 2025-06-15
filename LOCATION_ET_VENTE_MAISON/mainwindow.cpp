#include "mainwindow.h"
#include "ui_mainwindow.h"

// 🔹 Formulaires et fenêtres annexes
#include "maisonform.h"
#include "maisonlisteviewer.h"





// 🔹 Qt
#include <QMessageBox>
#include <QInputDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

// 🔹 Table de hachage
#include "tablehachage.h"
#include "fonctionhachage.h"




// 🔹 Base de données globale
QSqlDatabase globalDb;

// 🔸 Constructeur et destructeur
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      table(101, FonctionsHachage::hachage1)  // Initialisation avec F1 par défaut
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




// 🔹 MENU : BASE DE DONNÉES

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
        QSqlQuery query(globalDb);
        query.prepare("DELETE FROM maisons WHERE cle = :cle");
        query.bindValue(":cle", cle);
        if (!query.exec()) {
            QMessageBox::warning(this, "Erreur DB", "Erreur suppression base : " + query.lastError().text());
        } else {
            QMessageBox::information(this, "Suppression", "Maison supprimée avec succès !");
        }
    } else {
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


// 🔹 MENU : COURBES ET

void MainWindow::on_actionCOURBE_HVS_triggered()
{
    QMessageBox::information(this, "Courbe HVS", "Affichage de la courbe HVS.");
}

void MainWindow::on_actionCOURBE_f1_VS_f2_triggered()
{
    QMessageBox::information(this, "Courbe f1 vs f2", "Affichage de la courbe f1 VS f2.");
}







// QUITTER

void MainWindow::on_actionQUITTER_triggered()
{
    QApplication::quit();
}
