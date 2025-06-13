#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "ui_maisonform.h"
#include "maisonform.h"
#include <QFile>
#include "fonctionhachage.h"
#include "maisonform.h"
#include "maisonlisteviewer.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    table(20,hachage1)  // 👈 initialisation correcte
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonInsererMaison_clicked()
{
    MaisonForm dlg(this);   // fenêtre modale
    dlg.exec();             // ouvre la page MaisonForm
}


// MENU BASE

void MainWindow::on_actionCHARGER_triggered()
{
    QString nomFichier = QFileDialog::getOpenFileName(
        this,
        "Charger la base",
        "",
        "Fichiers CSV (*.csv)"
    );

    if (nomFichier.isEmpty())
        return;

    QFile fichier(nomFichier);
    if (!fichier.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier.");
        return;
    }

    QTextStream in(&fichier);
    while (!in.atEnd()) {
        QString ligne = in.readLine();
        QStringList champs = ligne.split(";");  // ou ',' selon ton format

        if (champs.size() >= 6) {
            QString cle = champs[0];
            QString type = champs[1];
            QString standing = champs[2];
            int nbChambres = champs[3].toInt();
            int nbToilettes = champs[4].toInt();
            QString description = champs[5];

            QVector<QString> photos; // à remplir si tu stockes aussi les chemins des photos

            Maison maison(cle, type, standing, nbChambres, nbToilettes, photos, description);
            table.insertion(maison);
        }
    }

    fichier.close();
    QMessageBox::information(this, "CHARGER", "Données chargées !");
}



/*****  MainWindow.cpp  *****/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <QMessageBox>

void MainWindow::on_actionAFFICHER_triggered()
{
    /*------------- 1. Récupérer toutes les maisons depuis la table -------------*/
    QVector<Maison> vectMaisons;

    for (int i = 0; i < table.getCapacite(); ++i)           // parcours chaque « case » de la table
    {
        const QList<Maison>& liste = table.getListe(i);     // getListe(i) → QList<Maison>
        for (const Maison& m : liste)
            vectMaisons.append(m);                          // on copie dans un QVector
    }

    if (vectMaisons.isEmpty())
    {
        QMessageBox::information(this,
                                 tr("Aucune maison"),
                                 tr("La base ne contient aucune maison."));
        return;
    }

    /*------------- 2. Ouvrir la fenêtre qui les affiche -------------*/
    MaisonListeViewer dlg(vectMaisons, this);   // constructeur : (liste, parent)
    dlg.exec();                                 // fenêtre modale
}




void MainWindow::on_actionTAILLE_triggered()
{


    QMessageBox::information(nullptr, "TAILLE de la table EST :", QString::number(table.size()));

}

void MainWindow::on_actionSAUVEGARDER_triggered()
{
    QString nomFichier = QFileDialog::getSaveFileName(this, "Sauvegarder la base", "", "Fichiers CSV (*.csv)");
    if (nomFichier.isEmpty()) return;

    QFile fichier(nomFichier);
    if (!fichier.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier.");
        return;
    }

    QTextStream out(&fichier);

    for (int i = 0; i < table.getCapacite(); ++i) {
        for (const Maison& m : table.getListe(i)) {
            QStringList listePhotos = QStringList::fromVector(m.getCheminsPhotos());
            QString photosConcat = listePhotos.join(";");


            out << m.getCle() << ","
                << m.getType() << ","
                << m.getStanding() << ","
                << m.getNbChambres() << ","
                << m.getNbToilettes() << ","
                << photosConcat << ","
                << m.getDescription() << "\n";
        }
    }

    fichier.close();
    QMessageBox::information(this, "SAUVEGARDE", "Sauvegarde terminée !");
}



// MENU MAISON
void MainWindow::on_actionRECHERCHER_triggered()
{
    QString cle = QInputDialog::getText(this, "Recherche", "Entrez la clé de la maison :");

    if (cle.isEmpty())
        return;

    Maison* maison = table.get(cle);  // méthode de TableHachage

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
    MaisonForm *formulaire = new MaisonForm(this); // le `this` lie la fenêtre principale à la fenêtre secondaire
    formulaire->exec(); // Affichage en modal (bloque jusqu’à fermeture du formulaire)
}




void MainWindow::on_actionSUPPRIMER_triggered()
{
    QString cle = QInputDialog::getText(this, "Suppression", "Entrez la clé de la maison à supprimer :");

    if (cle.isEmpty())
        return;

    if (table.suppression(cle)) {
        QMessageBox::information(this, "Suppression", "Maison supprimée avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "Maison non trouvée !");
    }
}


// MENU FONCTION HACHAGE
void MainWindow::on_actionF1_triggered()
{
    QMessageBox::information(this, "Hachage F1", "Fonction F1 appliquée !");
}

void MainWindow::on_actionF2_triggered()
{
    QMessageBox::information(this, "Hachage F2", "Fonction F2 appliquée !");
}

void MainWindow::on_actionF3_triggered()
{
    QMessageBox::information(this, "Hachage F3", "Fonction F3 appliquée !");
}

void MainWindow::on_actionSANS_HACHAGE_triggered()
{
    QMessageBox::information(this, "Sans Hachage", "Pas de hachage utilisé.");
}

// MENU COMPARAISON
void MainWindow::on_actionCOURBE_HVS_triggered()
{
    QMessageBox::information(this, "Courbe HVS", "Affichage de la courbe HVS.");
}

void MainWindow::on_actionCOURBE_f1_VS_f2_triggered()
{
    QMessageBox::information(this, "Courbe f1 vs f2", "Affichage de la courbe f1 VS f2.");
}

// MENU QUITTER
void MainWindow::on_actionQUITTER_triggered()
{
    QApplication::quit();
}

