/********************************************************************************
** Form generated from reading UI file 'maisonviewer.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAISONVIEWER_H
#define UI_MAISONVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaisonViewer
{
public:
    QLabel *labelPhoto;
    QPushButton *btnPrev;
    QPushButton *btnNext;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelCle;
    QLabel *labelType;
    QLabel *labelChambres;
    QLabel *labelStanding;
    QLabel *labelToillettes;
    QLabel *labelTitre;
    QLabel *labelDescription;
    QTextEdit *textEditDescription;

    void setupUi(QDialog *MaisonViewer)
    {
        if (MaisonViewer->objectName().isEmpty())
            MaisonViewer->setObjectName("MaisonViewer");
        MaisonViewer->resize(1310, 574);
        labelPhoto = new QLabel(MaisonViewer);
        labelPhoto->setObjectName("labelPhoto");
        labelPhoto->setGeometry(QRect(660, 100, 451, 321));
        labelPhoto->setMinimumSize(QSize(300, 200));
        labelPhoto->setScaledContents(true);
        btnPrev = new QPushButton(MaisonViewer);
        btnPrev->setObjectName("btnPrev");
        btnPrev->setGeometry(QRect(760, 450, 112, 34));
        btnNext = new QPushButton(MaisonViewer);
        btnNext->setObjectName("btnNext");
        btnNext->setGeometry(QRect(890, 450, 112, 34));
        formLayoutWidget = new QWidget(MaisonViewer);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 110, 571, 201));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelCle = new QLabel(formLayoutWidget);
        labelCle->setObjectName("labelCle");
        labelCle->setMinimumSize(QSize(10, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        labelCle->setFont(font);

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelCle);

        labelType = new QLabel(formLayoutWidget);
        labelType->setObjectName("labelType");
        QFont font1;
        font1.setPointSize(12);
        labelType->setFont(font1);

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelType);

        labelChambres = new QLabel(formLayoutWidget);
        labelChambres->setObjectName("labelChambres");
        labelChambres->setFont(font1);

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelChambres);

        labelStanding = new QLabel(formLayoutWidget);
        labelStanding->setObjectName("labelStanding");
        labelStanding->setFont(font1);

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelStanding);

        labelToillettes = new QLabel(formLayoutWidget);
        labelToillettes->setObjectName("labelToillettes");
        labelToillettes->setFont(font1);

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, labelToillettes);

        labelTitre = new QLabel(MaisonViewer);
        labelTitre->setObjectName("labelTitre");
        labelTitre->setGeometry(QRect(420, 20, 291, 41));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        labelTitre->setFont(font2);
        labelDescription = new QLabel(MaisonViewer);
        labelDescription->setObjectName("labelDescription");
        labelDescription->setGeometry(QRect(240, 330, 121, 19));
        labelDescription->setFont(font1);
        textEditDescription = new QTextEdit(MaisonViewer);
        textEditDescription->setObjectName("textEditDescription");
        textEditDescription->setGeometry(QRect(30, 376, 581, 121));

        retranslateUi(MaisonViewer);

        QMetaObject::connectSlotsByName(MaisonViewer);
    } // setupUi

    void retranslateUi(QDialog *MaisonViewer)
    {
        MaisonViewer->setWindowTitle(QCoreApplication::translate("MaisonViewer", "Dialog", nullptr));
        labelPhoto->setText(QString());
        btnPrev->setText(QCoreApplication::translate("MaisonViewer", " < Pr\303\251c\303\251dent ", nullptr));
        btnNext->setText(QCoreApplication::translate("MaisonViewer", "Suivant >", nullptr));
        labelCle->setText(QCoreApplication::translate("MaisonViewer", "Cle :", nullptr));
        labelType->setText(QCoreApplication::translate("MaisonViewer", "Type :", nullptr));
        labelChambres->setText(QCoreApplication::translate("MaisonViewer", "Chambres :", nullptr));
        labelStanding->setText(QCoreApplication::translate("MaisonViewer", "Standing :", nullptr));
        labelToillettes->setText(QCoreApplication::translate("MaisonViewer", "Toillettes :", nullptr));
        labelTitre->setText(QCoreApplication::translate("MaisonViewer", "INFORMATION MAISON", nullptr));
        labelDescription->setText(QCoreApplication::translate("MaisonViewer", "Descrption", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MaisonViewer: public Ui_MaisonViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAISONVIEWER_H
