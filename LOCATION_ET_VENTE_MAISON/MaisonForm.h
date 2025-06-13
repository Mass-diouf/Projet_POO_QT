#ifndef MAISONFORM_H
#define MAISONFORM_H
#include "ui_MaisonForm.h"
#include <QDialog>
#include <QVector>
#include "maison.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MaisonForm; }
QT_END_NAMESPACE

class MaisonForm : public QDialog
{
    Q_OBJECT

public:
    explicit MaisonForm(QWidget *parent = nullptr);
    ~MaisonForm();

    Maison getMaison() const;  // méthode pour récupérer la maison saisie

private slots:
    void on_pushButtonAjouterPhoto_clicked();
    void on_pushButtonValider_clicked();
    void on_pushButtonPhotos_clicked();


private:
    Ui::MaisonForm *ui;
    QVector<QString> photos;  // chemins des photos

    void enregistrerMaisonDansCSV(const Maison& maison);
};

#endif // MAISONFORM_H
