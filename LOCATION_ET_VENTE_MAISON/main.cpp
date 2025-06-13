#include <QApplication>
#include <QDebug>
#include "mainwindow.h"
#include "Maison.h"
#include "TableHachage.h"
#include "fonctionhachage.h"

int main(int argc, char *argv[]) {
  qDebug() << "Lancement du programme...";
    QApplication a(argc, argv);
    MainWindow w;
    w.show(); // ✅ ESSENTIEL !
    return a.exec();
}
