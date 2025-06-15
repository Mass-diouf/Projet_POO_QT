/********************************************************************************
** Form generated from reading UI file 'maisonlisteviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAISONLISTEVIEWER_H
#define UI_MAISONLISTEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_MaisonListeViewer
{
public:
    QListWidget *listWidgetMaisons;

    void setupUi(QDialog *MaisonListeViewer)
    {
        if (MaisonListeViewer->objectName().isEmpty())
            MaisonListeViewer->setObjectName(QStringLiteral("MaisonListeViewer"));
        MaisonListeViewer->resize(1302, 670);
        listWidgetMaisons = new QListWidget(MaisonListeViewer);
        listWidgetMaisons->setObjectName(QStringLiteral("listWidgetMaisons"));
        listWidgetMaisons->setGeometry(QRect(40, 30, 1231, 611));

        retranslateUi(MaisonListeViewer);

        QMetaObject::connectSlotsByName(MaisonListeViewer);
    } // setupUi

    void retranslateUi(QDialog *MaisonListeViewer)
    {
        MaisonListeViewer->setWindowTitle(QApplication::translate("MaisonListeViewer", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class MaisonListeViewer: public Ui_MaisonListeViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAISONLISTEVIEWER_H
