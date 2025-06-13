 #include "MaisonForm.h"
 #include "ui_MaisonForm.h"
 #include <QFileDialog>
 #include <QMessageBox>
 #include <QDir>
 #include <QFileInfo>
#include <QFile>
#include <QTextStream>

  MaisonForm:: MaisonForm(QWidget *parent )
     : QDialog(parent),
       ui(new Ui::MaisonForm)
 {
     ui->setupUi(this);

     // Texte initial du label
     ui->labelinfoAjouterPhoto->setText("Aucune photo sélectionnée");
 }

 MaisonForm::~MaisonForm()
 {
     delete ui;
 }

/* ---------- Bouton « Ajouter des photos » ---------- */
 void MaisonForm::on_pushButtonPhotos_clicked()
 {
     QStringList fichiers = QFileDialog::getOpenFileNames(
         this,
         tr("Sélectionner entre 3 et 5 photos"),
         QDir::homePath(),
         tr("Images (*.png *.jpg *.jpeg *.bmp)")
     );

     // ⚠️ Vérifie que l'utilisateur sélectionne au moins 3 photos
     if (fichiers.size() < 3) {
         QMessageBox::warning(
             this,
             tr("Nombre insuffisant"),
             tr("Veuillez sélectionner au moins 3 photos.")
         );
         return;
     }

     if (fichiers.size() > 5) {
         QMessageBox::warning(
             this,
             tr("Limite atteinte"),
             tr("Vous ne pouvez sélectionner que jusqu'à 5 photos.")
         );
         return;
     }

     photos.clear(); // vide les anciennes photos si on refait un ajout

     for (const QString &chemin : fichiers) {
        photos.push_back(chemin);
     }

     // Met à jour le label d'information (ex: "4 phtos sélectionnées – OK")
     ui->labelinfoAjouterPhoto->setText(
         QString("%1 photo(s) sélectionnée(s) ✅ (min. 3)").arg(fichiers.size())
     );
 }

 /* ---------- Bouton « Valider » ---------- */


void MaisonForm::on_pushButtonValider_clicked()
{
    // Vérification minimale : la clé ne doit pas être vide
    if (ui->lineEditCle->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, tr("Champ manquant"),
                             tr("La clé de la maison est obligatoire."));
        return;
    }

    // Création de la maison à partir du formulaire
    Maison maison = getMaison();

    // Ouvrir (ou créer) le fichier CSV en mode ajout
    QFile fichier("maisons.csv");
    if (!fichier.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Erreur fichier"),
                              tr("Impossible d'ouvrir ou de créer le fichier maisons.csv"));
        return;
    }

    QTextStream out(&fichier);

    // Préparer la ligne CSV :
    // Pour les photos, on concatène les chemins avec un séparateur, par exemple ;
    QStringList photosList;
    for (const QString &photo : maison.getCheminsPhotos()) {
        photosList.append(photo);
    }
    QString photosConcat = photosList.join(";");



    // Échapper les champs contenant des ; ou des " en entourant par " et en doublant les "
    auto echappeCsv = [](const QString& champ) -> QString {
        QString c = champ;
        if (c.contains('"')) {
            c.replace("\"", "\"\"");
        }
        if (c.contains(';') || c.contains('"') || c.contains('\n')) {
            c = "\"" + c + "\"";
        }
        return c;
    };

    // Construire la ligne CSV
    QString ligne = QString("%1;%2;%3;%4;%5;%6;%7\n")
                    .arg(echappeCsv(maison.getCle()))
                    .arg(echappeCsv(maison.getType()))
                    .arg(echappeCsv(maison.getStanding()))
                    .arg(maison.getNbChambres())
                    .arg(maison.getNbToilettes())
                    .arg(echappeCsv(photosConcat))
                    .arg(echappeCsv(maison.getDescription()));

    out << ligne;

    fichier.close();

    // Indiquer que tout est OK, fermer la fenêtre
    QMessageBox::information(this, tr("Succès"), tr("Maison ajoutée avec succès."));
    accept();
}

 /* ---------- Construction d’une Maison ---------- */
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
 void MaisonForm::on_pushButtonAjouterPhoto_clicked()
 {
     QStringList fichiers = QFileDialog::getOpenFileNames(
         this,
         tr("Ajouter des photos"),
         QDir::homePath(),  // Dossier de départ
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

     // Vider les anciennes photos si l'utilisateur recommence
     photos.clear();

     for (const QString& fichier : fichiers) {
         photos.push_back(fichier);  // std::vector<std::string>
     }

     ui->labelinfoAjouterPhoto->setText(
         QString("%1 photo(s) sélectionnée(s) ✅ (min. 3)").arg(fichiers.size())
     );

     QMessageBox::information(this, "Photos ajoutées",
                              QString::number(fichiers.size()) + " photo(s) ajoutée(s).");
 }


