#include "maisonlisteviewer.h"
#include "ui_maisonlisteviewer.h"

MaisonListeViewer::MaisonListeViewer(const QVector<Maison>& maisons, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MaisonListeViewer)
{
    ui->setupUi(this);

    QWidget *container = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(container);

    for (const Maison &m : maisons) {
        MaisonViewer *widgetMaison = new MaisonViewer(m, this);
        layout->addWidget(widgetMaison);
    }
    layout->addStretch();

    // Affecter ce container à la zone de scroll

}


MaisonListeViewer::~MaisonListeViewer()
{
    delete ui;
}
