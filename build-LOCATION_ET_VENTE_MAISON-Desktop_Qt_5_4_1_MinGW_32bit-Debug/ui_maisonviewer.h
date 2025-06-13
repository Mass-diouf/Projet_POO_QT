/********************************************************************************
** Form generated from reading UI file 'maisonviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAISONVIEWER_H
#define UI_MAISONVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
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
            MaisonViewer->setObjectName(QStringLiteral("MaisonViewer"));
        MaisonViewer->resize(1310, 574);
        labelPhoto = new QLabel(MaisonViewer);
        labelPhoto->setObjectName(QStringLiteral("labelPhoto"));
        labelPhoto->setGeometry(QRect(640, 100, 451, 321));
        labelPhoto->setMinimumSize(QSize(300, 200));
        labelPhoto->setScaledContents(true);
        btnPrev = new QPushButton(MaisonViewer);
        btnPrev->setObjectName(QStringLiteral("btnPrev"));
        btnPrev->setGeometry(QRect(760, 450, 112, 34));
        btnNext = new QPushButton(MaisonViewer);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setGeometry(QRect(890, 450, 112, 34));
        formLayoutWidget = new QWidget(MaisonViewer);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 110, 571, 201));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelCle = new QLabel(formLayoutWidget);
        labelCle->setObjectName(QStringLiteral("labelCle"));
        labelCle->setMinimumSize(QSize(10, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        labelCle->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelCle);

        labelType = new QLabel(formLayoutWidget);
        labelType->setObjectName(QStringLiteral("labelType"));
        QFont font1;
        font1.setPointSize(12);
        labelType->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelType);

        labelChambres = new QLabel(formLayoutWidget);
        labelChambres->setObjectName(QStringLiteral("labelChambres"));
        labelChambres->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, labelChambres);

        labelStanding = new QLabel(formLayoutWidget);
        labelStanding->setObjectName(QStringLiteral("labelStanding"));
        labelStanding->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelStanding);

        labelToillettes = new QLabel(formLayoutWidget);
        labelToillettes->setObjectName(QStringLiteral("labelToillettes"));
        labelToillettes->setFont(font1);

        formLayout->setWidget(4, QFormLayout::LabelRole, labelToillettes);

        labelTitre = new QLabel(MaisonViewer);
        labelTitre->setObjectName(QStringLiteral("labelTitre"));
        labelTitre->setGeometry(QRect(420, 20, 291, 41));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        labelTitre->setFont(font2);
        labelDescription = new QLabel(MaisonViewer);
        labelDescription->setObjectName(QStringLiteral("labelDescription"));
        labelDescription->setGeometry(QRect(240, 330, 121, 19));
        labelDescription->setFont(font1);
        textEditDescription = new QTextEdit(MaisonViewer);
        textEditDescription->setObjectName(QStringLiteral("textEditDescription"));
        textEditDescription->setGeometry(QRect(30, 376, 581, 121));

        retranslateUi(MaisonViewer);

        QMetaObject::connectSlotsByName(MaisonViewer);
    } // setupUi

    void retranslateUi(QDialog *MaisonViewer)
    {
        MaisonViewer->setWindowTitle(QApplication::translate("MaisonViewer", "Dialog", 0));
        labelPhoto->setText(QString());
        btnPrev->setText(QApplication::translate("MaisonViewer", " < Pr\303\251c\303\251dent ", 0));
        btnNext->setText(QApplication::translate("MaisonViewer", "Suivant >", 0));
        labelCle->setText(QApplication::translate("MaisonViewer", "Cle :", 0));
        labelType->setText(QApplication::translate("MaisonViewer", "Type :", 0));
        labelChambres->setText(QApplication::translate("MaisonViewer", "Chambres :", 0));
        labelStanding->setText(QApplication::translate("MaisonViewer", "Standing :", 0));
        labelToillettes->setText(QApplication::translate("MaisonViewer", "Toillettes :", 0));
        labelTitre->setText(QApplication::translate("MaisonViewer", "INFORMATION MAISON", 0));
        labelDescription->setText(QApplication::translate("MaisonViewer", "Descrption", 0));
    } // retranslateUi

};

namespace Ui {
    class MaisonViewer: public Ui_MaisonViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAISONVIEWER_H
