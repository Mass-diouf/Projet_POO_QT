#include "maisonlisteviewer.h"
#include "ui_maisonlisteviewer.h"
#include <QListWidgetItem>
#include "MaisonDAO.h"
#include "maisonviewer.h"

extern QSqlDatabase globalDb;

MaisonListeViewer::MaisonListeViewer(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::MaisonListeViewer)
{
    ui->setupUi(this);
    loadMaisons();

    // Connecte le clic sur une maison à l'ouverture du détail
    connect(ui->listWidgetMaisons, &QListWidget::itemClicked,
            this, &MaisonListeViewer::ouvrirMaisonViewer);
}

MaisonListeViewer::MaisonListeViewer(const QVector<Maison> &maisons, QWidget *parent)
    : QDialog(parent), ui(new Ui::MaisonListeViewer), maisons(maisons)
{
    ui->setupUi(this);
    loadMaisons(); // ou une méthode adaptée pour afficher le contenu du QVector maisons

    // Connexion signal si nécessaire
    connect(ui->listWidgetMaisons, &QListWidget::itemClicked,
            this, &MaisonListeViewer::ouvrirMaisonViewer);
}


MaisonListeViewer::~MaisonListeViewer()
{
    delete ui;
}

void MaisonListeViewer::loadMaisons()
{
    ui->listWidgetMaisons->clear();

    QSqlQuery query(globalDb);
    if (!query.exec("SELECT cle, type, nbChambres, nbToilettes FROM maisons")) {
        QMessageBox::warning(this, "Erreur DB", "Impossible de charger la liste : " + query.lastError().text());
        return;
    }

    while (query.next()) {
        QString cle = query.value(0).toString();
        QString type = query.value(1).toString();
        int nbChambres = query.value(2).toInt();
        int nbToilettes = query.value(3).toInt();

        // Affichage : clé - type - nb chambres - nb toilettes
        QString texte = QString("%1 - %2 - %3 chambres - %4 toilettes")
                            .arg(cle, type)
                            .arg(nbChambres)
                            .arg(nbToilettes);

        QListWidgetItem* item = new QListWidgetItem(texte);
        item->setData(Qt::UserRole, cle);  // stocker la clé pour l'identification
        ui->listWidgetMaisons->addItem(item);
    }
}

void MaisonListeViewer::ouvrirMaisonViewer(QListWidgetItem *item)
{
    if (!item)
        return;

    QString cle = item->data(Qt::UserRole).toString();
    Maison maison = MaisonDAO::chercherParCle(cle);

    MaisonViewer *viewer = new MaisonViewer(this);
    viewer->afficherMaison(maison);
    viewer->exec();
}
