/********************************************************************************
** Form generated from reading UI file 'maisonlisteviewer.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAISONLISTEVIEWER_H
#define UI_MAISONLISTEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_MaisonListeViewer
{
public:
    QListWidget *listWidgetMaisons;

    void setupUi(QDialog *MaisonListeViewer)
    {
        if (MaisonListeViewer->objectName().isEmpty())
            MaisonListeViewer->setObjectName("MaisonListeViewer");
        MaisonListeViewer->resize(1302, 670);
        listWidgetMaisons = new QListWidget(MaisonListeViewer);
        listWidgetMaisons->setObjectName("listWidgetMaisons");
        listWidgetMaisons->setGeometry(QRect(40, 30, 1231, 611));

        retranslateUi(MaisonListeViewer);

        QMetaObject::connectSlotsByName(MaisonListeViewer);
    } // setupUi

    void retranslateUi(QDialog *MaisonListeViewer)
    {
        MaisonListeViewer->setWindowTitle(QCoreApplication::translate("MaisonListeViewer", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MaisonListeViewer: public Ui_MaisonListeViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAISONLISTEVIEWER_H
