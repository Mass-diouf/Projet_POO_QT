#include "MaisonForm.h"
#include "ui_MaisonForm.h"
#include "MaisonDAO.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

extern QSqlDatabase globalDb; // déclaré dans mainwindow.cpp (à définir globalement ou passer en paramètre)

MaisonForm::MaisonForm(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::MaisonForm)
{
    ui->setupUi(this);
    ui->labelinfoAjouterPhoto->setText(tr("Aucune photo sélectionnée"));
}

MaisonForm::~MaisonForm()
{
    delete ui;
}

void MaisonForm::on_pushButtonAjouterPhoto_clicked()
{
    QStringList fichiers = QFileDialog::getOpenFileNames(
        this,
        tr("Ajouter des photos"),
        QDir::homePath(),
        tr("Images (*.png *.jpg *.jpeg *.bmp)")
    );

    if (fichiers.size() < 3) {
        QMessageBox::warning(this, tr("Nombre insuffisant"),
                             tr("Veuillez sélectionner au moins 3 photos."));
        return;
    }

    if (fichiers.size() > 5) {
        QMessageBox::warning(this, tr("Trop de fichiers"),
                             tr("Vous pouvez ajouter au maximum 5 photos."));
        return;
    }

    photos.clear();
    for (const QString& fichier : fichiers) {
        photos.push_back(fichier);
    }

    ui->labelinfoAjouterPhoto->setText(
        tr("%1 photo(s) sélectionnée(s) ✅ (min. 3)").arg(fichiers.size())
    );

    QMessageBox::information(this, tr("Photos ajoutées"),
                             QString::number(fichiers.size()) + " photo(s) ajoutée(s).");
}

void MaisonForm::on_pushButtonValider_clicked()
{
    if (ui->lineEditCle->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, tr("Champ manquant"),
                             tr("La clé de la maison est obligatoire."));
        return;
    }

    Maison maison = getMaison();

    MaisonDAO dao(globalDb);
    if (dao.insererMaison(maison)) {
        QMessageBox::information(this, tr("Succès"), tr("Maison ajoutée avec succès en base de données."));
        accept();
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Erreur lors de l'insertion en base."));
    }
}

Maison MaisonForm::getMaison() const
{
    return Maison(
        ui->lineEditCle->text(),
        ui->comboBoxType->currentText(),
        ui->comboBoxStanding->currentText(),
        ui->spinBoxChambres->value(),
        ui->spinBoxToilettes->value(),
        photos,
        ui->textEditDescription->toPlainText()
    );
}
