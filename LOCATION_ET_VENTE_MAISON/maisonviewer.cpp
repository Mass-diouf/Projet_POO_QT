#include "maisonviewer.h"
#include "ui_maisonviewer.h"
#include <QPixmap>
#include <QDebug>

MaisonViewer::MaisonViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MaisonViewer),
    photoIndex(0)
{
    ui->setupUi(this);

    connect(ui->btnPrev, &QPushButton::clicked, this, &MaisonViewer::on_btnPrev_clicked);
    connect(ui->btnNext, &QPushButton::clicked, this, &MaisonViewer::on_btnNext_clicked);
}

MaisonViewer::~MaisonViewer()
{
    delete ui;
}

void MaisonViewer::afficherMaison(const Maison &maison)
{
    ui->labelCle->setText("Clé : " + maison.getCle());
    ui->labelType->setText("Type : " + maison.getType());
    ui->labelStanding->setText("Standing : " + maison.getStanding());
    ui->labelChambres->setText("Chambres : " + QString::number(maison.getNbChambres()));
    ui->labelToillettes->setText("Toilettes : " + QString::number(maison.getNbToilettes()));
    ui->textEditDescription->setPlainText(maison.getDescription());

    photos = maison.getCheminsPhotos().toList();  // QStringList ou QVector<QString>
    photoIndex = 0;
    updatePhotoDisplay();
}

void MaisonViewer::updatePhotoDisplay()
{
    if (photos.isEmpty()) {
        ui->labelPhoto->clear();
        ui->labelPhoto->setText("Pas de photo disponible");
        return;
    }

    QPixmap pix(photos[photoIndex]);
    if (!pix.isNull()) {
        ui->labelPhoto->setPixmap(pix.scaled(ui->labelPhoto->size(), Qt::KeepAspectRatio));
    } else {
        ui->labelPhoto->setText("Image introuvable");
    }
}

void MaisonViewer::on_btnNext_clicked()
{
    if (photos.isEmpty()) return;

    photoIndex = (photoIndex + 1) % photos.size();
    updatePhotoDisplay();
}

void MaisonViewer::on_btnPrev_clicked()
{
    if (photos.isEmpty()) return;

    photoIndex = (photoIndex - 1 + photos.size()) % photos.size();
    updatePhotoDisplay();
}
