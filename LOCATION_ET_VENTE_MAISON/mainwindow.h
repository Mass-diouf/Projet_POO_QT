#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QMainWindow>
#include "tablehachage.h"
#include "fonctionhachage.h"
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonInsererMaison_clicked();

    void on_actionCHARGER_triggered();
    void on_actionAFFICHER_triggered();
    void on_actionTAILLE_triggered();
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

};

#endif // MAINWINDOW_H
