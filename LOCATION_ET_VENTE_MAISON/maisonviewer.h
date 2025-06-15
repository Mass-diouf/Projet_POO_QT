#ifndef MAISONVIEWER_H
#define MAISONVIEWER_H
#include"maison.h"
#include <QDialog>
#include <QStringList>

namespace Ui {
class MaisonViewer;
}

class MaisonViewer : public QDialog
{
    Q_OBJECT

public:
    explicit MaisonViewer(QWidget *parent = nullptr);
    ~MaisonViewer();
    void afficherMaison(const Maison& maison);
    void loadMaison(const QString& cle); // Charge la maison par clé

private slots:
    void on_btnPrev_clicked();
    void on_btnNext_clicked();

private:
    Ui::MaisonViewer *ui;

    QStringList photos;  // Liste des chemins des photos
    int photoIndex;      // Index photo affichée actuellement


    void updatePhotoDisplay();
};

#endif // MAISONVIEWER_H
