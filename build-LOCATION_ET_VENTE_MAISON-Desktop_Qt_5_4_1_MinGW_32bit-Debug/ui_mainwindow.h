/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCHARGER;
    QAction *actionAFFICHER;
    QAction *actionTAILLE;
    QAction *actionSAUVEGARDER;
    QAction *actionRECHERCHER;
    QAction *actionSUPPRIMER;
    QAction *actionINSERER;
    QAction *actionF1;
    QAction *actionF2;
    QAction *actionF3;
    QAction *actionSANS_HACHAGE;
    QAction *actionCOURBE_HVS;
    QAction *actionCOURBE_f1_VS_f2;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuBASE;
    QMenu *menuMAISON;
    QMenu *menuFONCTION_HACHAGE;
    QMenu *menuCOMPARAISON;
    QMenu *menuQUITTER;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1032, 526);
        actionCHARGER = new QAction(MainWindow);
        actionCHARGER->setObjectName(QStringLiteral("actionCHARGER"));
        actionAFFICHER = new QAction(MainWindow);
        actionAFFICHER->setObjectName(QStringLiteral("actionAFFICHER"));
        actionTAILLE = new QAction(MainWindow);
        actionTAILLE->setObjectName(QStringLiteral("actionTAILLE"));
        actionSAUVEGARDER = new QAction(MainWindow);
        actionSAUVEGARDER->setObjectName(QStringLiteral("actionSAUVEGARDER"));
        actionRECHERCHER = new QAction(MainWindow);
        actionRECHERCHER->setObjectName(QStringLiteral("actionRECHERCHER"));
        actionSUPPRIMER = new QAction(MainWindow);
        actionSUPPRIMER->setObjectName(QStringLiteral("actionSUPPRIMER"));
        actionINSERER = new QAction(MainWindow);
        actionINSERER->setObjectName(QStringLiteral("actionINSERER"));
        actionF1 = new QAction(MainWindow);
        actionF1->setObjectName(QStringLiteral("actionF1"));
        actionF2 = new QAction(MainWindow);
        actionF2->setObjectName(QStringLiteral("actionF2"));
        actionF3 = new QAction(MainWindow);
        actionF3->setObjectName(QStringLiteral("actionF3"));
        actionSANS_HACHAGE = new QAction(MainWindow);
        actionSANS_HACHAGE->setObjectName(QStringLiteral("actionSANS_HACHAGE"));
        actionCOURBE_HVS = new QAction(MainWindow);
        actionCOURBE_HVS->setObjectName(QStringLiteral("actionCOURBE_HVS"));
        actionCOURBE_f1_VS_f2 = new QAction(MainWindow);
        actionCOURBE_f1_VS_f2->setObjectName(QStringLiteral("actionCOURBE_f1_VS_f2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1032, 31));
        menuBASE = new QMenu(menubar);
        menuBASE->setObjectName(QStringLiteral("menuBASE"));
        menuMAISON = new QMenu(menubar);
        menuMAISON->setObjectName(QStringLiteral("menuMAISON"));
        menuFONCTION_HACHAGE = new QMenu(menubar);
        menuFONCTION_HACHAGE->setObjectName(QStringLiteral("menuFONCTION_HACHAGE"));
        menuCOMPARAISON = new QMenu(menubar);
        menuCOMPARAISON->setObjectName(QStringLiteral("menuCOMPARAISON"));
        menuQUITTER = new QMenu(menubar);
        menuQUITTER->setObjectName(QStringLiteral("menuQUITTER"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuBASE->menuAction());
        menubar->addAction(menuMAISON->menuAction());
        menubar->addAction(menuFONCTION_HACHAGE->menuAction());
        menubar->addAction(menuCOMPARAISON->menuAction());
        menubar->addAction(menuQUITTER->menuAction());
        menuBASE->addAction(actionCHARGER);
        menuBASE->addAction(actionAFFICHER);
        menuBASE->addAction(actionTAILLE);
        menuBASE->addAction(actionSAUVEGARDER);
        menuMAISON->addAction(actionRECHERCHER);
        menuMAISON->addAction(actionSUPPRIMER);
        menuMAISON->addAction(actionINSERER);
        menuFONCTION_HACHAGE->addAction(actionF1);
        menuFONCTION_HACHAGE->addAction(actionF2);
        menuFONCTION_HACHAGE->addAction(actionF3);
        menuFONCTION_HACHAGE->addAction(actionSANS_HACHAGE);
        menuCOMPARAISON->addAction(actionCOURBE_HVS);
        menuCOMPARAISON->addAction(actionCOURBE_f1_VS_f2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionCHARGER->setText(QApplication::translate("MainWindow", "CHARGER", 0));
        actionAFFICHER->setText(QApplication::translate("MainWindow", "AFFICHER", 0));
        actionTAILLE->setText(QApplication::translate("MainWindow", "TAILLE", 0));
        actionSAUVEGARDER->setText(QApplication::translate("MainWindow", "SAUVEGARDER", 0));
        actionRECHERCHER->setText(QApplication::translate("MainWindow", "RECHERCHER", 0));
        actionSUPPRIMER->setText(QApplication::translate("MainWindow", "SUPPRIMER", 0));
        actionINSERER->setText(QApplication::translate("MainWindow", "INSERER", 0));
        actionF1->setText(QApplication::translate("MainWindow", "f1", 0));
        actionF2->setText(QApplication::translate("MainWindow", "f2", 0));
        actionF3->setText(QApplication::translate("MainWindow", "f3", 0));
        actionSANS_HACHAGE->setText(QApplication::translate("MainWindow", "SANS HACHAGE", 0));
        actionCOURBE_HVS->setText(QApplication::translate("MainWindow", "COURBE HVS", 0));
        actionCOURBE_f1_VS_f2->setText(QApplication::translate("MainWindow", "COURBE f1 VS f2", 0));
        menuBASE->setTitle(QApplication::translate("MainWindow", "BASE", 0));
        menuMAISON->setTitle(QApplication::translate("MainWindow", "MAISON", 0));
        menuFONCTION_HACHAGE->setTitle(QApplication::translate("MainWindow", "FONCTION HACHAGE", 0));
        menuCOMPARAISON->setTitle(QApplication::translate("MainWindow", "COMPARAISON ", 0));
        menuQUITTER->setTitle(QApplication::translate("MainWindow", "QUITTER", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
