#ifndef MAISONSELISTEVIEWER_H
#define MAISONSELISTEVIEWER_H
#include <QDialog>
#include <QVBoxLayout>
#include "maison.h"
#include "maisonviewer.h"

namespace Ui {
class MaisonListeViewer;
}

class MaisonListeViewer : public QDialog
{
    Q_OBJECT

public:
    explicit MaisonListeViewer(const QVector<Maison>& maisons, QWidget *parent = nullptr);
    ~MaisonListeViewer();

private:
    Ui::MaisonListeViewer *ui;
};

#endif // MAISONSESLISTVIEWER_H
