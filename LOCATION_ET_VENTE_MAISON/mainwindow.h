#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "tablehachage.h"
#include "fonctionhachage.h"
#include <QInputDialog>
#include "maisonlisteviewer.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Méthodes pour la gestion de la base SQLite
    bool ouvrirBase(const QString &dbPath = "maisons_location.sqlite");
    bool insererMaisonDansBase(const Maison &maison);
    QVector<Maison> chargerMaisonsDepuisBase();
    //methode d affichage de la coubre
    void afficherCourbeComparaison();
    void afficherCourbeF1F2F3();
    qint64 mesurerInsertionHachage1(const QVector<Maison>& liste) ;
    qint64 mesurerInsertionHachage2(const QVector<Maison>& liste) ;
    qint64 mesurerInsertionHachage3(const QVector<Maison>& liste) ;

private slots:
    void on_pushButtonInsererMaison_clicked();

    void on_actionCHARGER_triggered();
    void on_actionAFFICHER_triggered();
    void on_actionTAILLE_triggered();
    void on_actionNOMBRE_DE_COLLISION_triggered();
    void on_actionSAUVEGARDER_triggered();

    void on_actionRECHERCHER_triggered();
    void on_actionINSERER_triggered();
    void on_actionSUPPRIMER_triggered();

    void on_actionF1_triggered();
    void on_actionF2_triggered();
    void on_actionF3_triggered();
    void on_actionSANS_HACHAGE_triggered();

    void on_actionCOURBE_HVS_triggered();
    void on_actionCOURBE_f1_VS_f2_triggered();

    void on_actionQUITTER_triggered();

private:
    Ui::MainWindow *ui;
    TableHachage table;

    // Objet base SQLite
    QSqlDatabase database;
};

#endif // MAINWINDOW_H
