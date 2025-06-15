#ifndef MAISONLISTEVIEWER_H
#define MAISONLISTEVIEWER_H
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

#include <QDialog>
#include <QVector>
#include <QListWidgetItem>
#include "maison.h"

namespace Ui {
class MaisonListeViewer;
}

class MaisonListeViewer : public QDialog
{
    Q_OBJECT

public:
    explicit MaisonListeViewer(QWidget *parent = nullptr);
    explicit MaisonListeViewer(const QVector<Maison> &maisons, QWidget *parent = nullptr);
    ~MaisonListeViewer();

private slots:
    void ouvrirMaisonViewer(QListWidgetItem *item);

private:
    Ui::MaisonListeViewer *ui;
    QVector<Maison> maisons;

    void loadMaisons();
};

#endif // MAISONLISTEVIEWER_H
