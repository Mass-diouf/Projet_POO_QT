/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
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
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1032, 526);
        actionCHARGER = new QAction(MainWindow);
        actionCHARGER->setObjectName("actionCHARGER");
        actionAFFICHER = new QAction(MainWindow);
        actionAFFICHER->setObjectName("actionAFFICHER");
        actionTAILLE = new QAction(MainWindow);
        actionTAILLE->setObjectName("actionTAILLE");
        actionSAUVEGARDER = new QAction(MainWindow);
        actionSAUVEGARDER->setObjectName("actionSAUVEGARDER");
        actionRECHERCHER = new QAction(MainWindow);
        actionRECHERCHER->setObjectName("actionRECHERCHER");
        actionSUPPRIMER = new QAction(MainWindow);
        actionSUPPRIMER->setObjectName("actionSUPPRIMER");
        actionINSERER = new QAction(MainWindow);
        actionINSERER->setObjectName("actionINSERER");
        actionF1 = new QAction(MainWindow);
        actionF1->setObjectName("actionF1");
        actionF2 = new QAction(MainWindow);
        actionF2->setObjectName("actionF2");
        actionF3 = new QAction(MainWindow);
        actionF3->setObjectName("actionF3");
        actionSANS_HACHAGE = new QAction(MainWindow);
        actionSANS_HACHAGE->setObjectName("actionSANS_HACHAGE");
        actionCOURBE_HVS = new QAction(MainWindow);
        actionCOURBE_HVS->setObjectName("actionCOURBE_HVS");
        actionCOURBE_f1_VS_f2 = new QAction(MainWindow);
        actionCOURBE_f1_VS_f2->setObjectName("actionCOURBE_f1_VS_f2");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1032, 31));
        menuBASE = new QMenu(menubar);
        menuBASE->setObjectName("menuBASE");
        menuMAISON = new QMenu(menubar);
        menuMAISON->setObjectName("menuMAISON");
        menuFONCTION_HACHAGE = new QMenu(menubar);
        menuFONCTION_HACHAGE->setObjectName("menuFONCTION_HACHAGE");
        menuCOMPARAISON = new QMenu(menubar);
        menuCOMPARAISON->setObjectName("menuCOMPARAISON");
        menuQUITTER = new QMenu(menubar);
        menuQUITTER->setObjectName("menuQUITTER");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCHARGER->setText(QCoreApplication::translate("MainWindow", "CHARGER", nullptr));
        actionAFFICHER->setText(QCoreApplication::translate("MainWindow", "AFFICHER", nullptr));
        actionTAILLE->setText(QCoreApplication::translate("MainWindow", "TAILLE", nullptr));
        actionSAUVEGARDER->setText(QCoreApplication::translate("MainWindow", "SAUVEGARDER", nullptr));
        actionRECHERCHER->setText(QCoreApplication::translate("MainWindow", "RECHERCHER", nullptr));
        actionSUPPRIMER->setText(QCoreApplication::translate("MainWindow", "SUPPRIMER", nullptr));
        actionINSERER->setText(QCoreApplication::translate("MainWindow", "INSERER", nullptr));
        actionF1->setText(QCoreApplication::translate("MainWindow", "f1", nullptr));
        actionF2->setText(QCoreApplication::translate("MainWindow", "f2", nullptr));
        actionF3->setText(QCoreApplication::translate("MainWindow", "f3", nullptr));
        actionSANS_HACHAGE->setText(QCoreApplication::translate("MainWindow", "SANS HACHAGE", nullptr));
        actionCOURBE_HVS->setText(QCoreApplication::translate("MainWindow", "COURBE HVS", nullptr));
        actionCOURBE_f1_VS_f2->setText(QCoreApplication::translate("MainWindow", "COURBE f1 VS f2", nullptr));
        menuBASE->setTitle(QCoreApplication::translate("MainWindow", "BASE", nullptr));
        menuMAISON->setTitle(QCoreApplication::translate("MainWindow", "MAISON", nullptr));
        menuFONCTION_HACHAGE->setTitle(QCoreApplication::translate("MainWindow", "FONCTION HACHAGE", nullptr));
        menuCOMPARAISON->setTitle(QCoreApplication::translate("MainWindow", "COMPARAISON ", nullptr));
        menuQUITTER->setTitle(QCoreApplication::translate("MainWindow", "QUITTER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
