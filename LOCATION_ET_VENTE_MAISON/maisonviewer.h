#ifndef MAISONVIEWER_H
#define MAISONVIEWER_H

#include <QDialog>
#include "maison.h"
#include "ui_maisonviewer.h"

namespace Ui {
class MaisonViewer;
}

class MaisonViewer : public QDialog
{
    Q_OBJECT

public:
    explicit MaisonViewer(const Maison& m, QWidget *parent = nullptr);
    ~MaisonViewer();

private slots:
    void afficherPrec();
    void afficherSuiv();

private:
    void afficherImage();

    Ui::MaisonViewer *ui;
    const Maison& maisonRef;
    int indexImg;
};

#endif // MAISONVIEWER_H
