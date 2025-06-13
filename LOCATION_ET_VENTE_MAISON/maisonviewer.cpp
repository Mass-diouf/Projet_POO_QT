#include "maisonviewer.h"
#include "ui_maisonviewer.h"
#include <QPixmap>
#include <QFileInfo>

MaisonViewer::MaisonViewer(const Maison& m, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MaisonViewer),
    maisonRef(m),
    indexImg(0)
{
    ui->setupUi(this);

    // Remplir les informations
    ui->labelCle->setText(maisonRef.getCle());
    ui->labelType->setText(maisonRef.getType());
    ui->labelStanding->setText(maisonRef.getStanding());
    ui->labelChambres->setText(QString::number(maisonRef.getNbChambres()));
    ui->labelToillettes->setText(QString::number(maisonRef.getNbToilettes()));
    ui->textEditDescription->setPlainText(maisonRef.getDescription());

    // Connexions des boutons
    connect(ui->btnPrev, &QPushButton::clicked, this, &MaisonViewer::afficherPrec);
    connect(ui->btnNext, &QPushButton::clicked, this, &MaisonViewer::afficherSuiv);

    afficherImage();
}

MaisonViewer::~MaisonViewer()
{
    delete ui;
}

void MaisonViewer::afficherImage()
{
    const auto& photos = maisonRef.getCheminsPhotos();

    if (photos.isEmpty()) {
        ui->labelPhoto->setText("Aucune image");
        return;
    }

    if (indexImg < 0) indexImg = photos.size() - 1;
    if (indexImg >= photos.size()) indexImg = 0;

    QString chemin = photos[indexImg];
    QPixmap pix(chemin);

    if (pix.isNull()) {
        ui->labelPhoto->setText("Image introuvable");
    } else {
        ui->labelPhoto->setPixmap(pix.scaled(
            ui->labelPhoto->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation));
    }
}

void MaisonViewer::afficherPrec()
{
    indexImg--;
    afficherImage();
}

void MaisonViewer::afficherSuiv()
{
    indexImg++;
    afficherImage();
}
