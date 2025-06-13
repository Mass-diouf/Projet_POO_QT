/********************************************************************************
** Form generated from reading UI file 'maisonform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAISONFORM_H
#define UI_MAISONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaisonForm
{
public:
    QLabel *labelCle;
    QLineEdit *lineEditCle;
    QLabel *labelType;
    QComboBox *comboBoxType;
    QLabel *labelStanding;
    QComboBox *comboBoxStanding;
    QLabel *labelToilettes;
    QSpinBox *spinBoxToilettes;
    QLabel *labelChambres;
    QSpinBox *spinBoxChambres;
    QLabel *labelDescription;
    QTextEdit *textEditDescription;
    QPushButton *pushButtonAjouterPhoto;
    QLabel *labelinfoAjouterPhoto;
    QPushButton *pushButtonValider;
    QLabel *labelTitre;

    void setupUi(QWidget *MaisonForm)
    {
        if (MaisonForm->objectName().isEmpty())
            MaisonForm->setObjectName(QStringLiteral("MaisonForm"));
        MaisonForm->setWindowModality(Qt::NonModal);
        MaisonForm->resize(1239, 600);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        MaisonForm->setFont(font);
        labelCle = new QLabel(MaisonForm);
        labelCle->setObjectName(QStringLiteral("labelCle"));
        labelCle->setGeometry(QRect(20, 120, 120, 40));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        labelCle->setFont(font1);
        lineEditCle = new QLineEdit(MaisonForm);
        lineEditCle->setObjectName(QStringLiteral("lineEditCle"));
        lineEditCle->setGeometry(QRect(180, 120, 300, 40));
        labelType = new QLabel(MaisonForm);
        labelType->setObjectName(QStringLiteral("labelType"));
        labelType->setGeometry(QRect(20, 190, 120, 40));
        labelType->setFont(font1);
        comboBoxType = new QComboBox(MaisonForm);
        comboBoxType->setObjectName(QStringLiteral("comboBoxType"));
        comboBoxType->setGeometry(QRect(180, 190, 300, 40));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setWeight(50);
        comboBoxType->setFont(font2);
        labelStanding = new QLabel(MaisonForm);
        labelStanding->setObjectName(QStringLiteral("labelStanding"));
        labelStanding->setGeometry(QRect(20, 260, 151, 40));
        labelStanding->setFont(font1);
        comboBoxStanding = new QComboBox(MaisonForm);
        comboBoxStanding->setObjectName(QStringLiteral("comboBoxStanding"));
        comboBoxStanding->setGeometry(QRect(200, 260, 300, 40));
        comboBoxStanding->setFont(font2);
        labelToilettes = new QLabel(MaisonForm);
        labelToilettes->setObjectName(QStringLiteral("labelToilettes"));
        labelToilettes->setGeometry(QRect(20, 330, 151, 40));
        labelToilettes->setFont(font1);
        spinBoxToilettes = new QSpinBox(MaisonForm);
        spinBoxToilettes->setObjectName(QStringLiteral("spinBoxToilettes"));
        spinBoxToilettes->setGeometry(QRect(200, 330, 300, 40));
        labelChambres = new QLabel(MaisonForm);
        labelChambres->setObjectName(QStringLiteral("labelChambres"));
        labelChambres->setGeometry(QRect(20, 400, 151, 40));
        labelChambres->setFont(font1);
        spinBoxChambres = new QSpinBox(MaisonForm);
        spinBoxChambres->setObjectName(QStringLiteral("spinBoxChambres"));
        spinBoxChambres->setGeometry(QRect(200, 400, 300, 40));
        labelDescription = new QLabel(MaisonForm);
        labelDescription->setObjectName(QStringLiteral("labelDescription"));
        labelDescription->setGeometry(QRect(690, 100, 200, 40));
        labelDescription->setFont(font1);
        textEditDescription = new QTextEdit(MaisonForm);
        textEditDescription->setObjectName(QStringLiteral("textEditDescription"));
        textEditDescription->setGeometry(QRect(690, 150, 300, 160));
        pushButtonAjouterPhoto = new QPushButton(MaisonForm);
        pushButtonAjouterPhoto->setObjectName(QStringLiteral("pushButtonAjouterPhoto"));
        pushButtonAjouterPhoto->setGeometry(QRect(690, 330, 300, 45));
        pushButtonAjouterPhoto->setFont(font2);
        labelinfoAjouterPhoto = new QLabel(MaisonForm);
        labelinfoAjouterPhoto->setObjectName(QStringLiteral("labelinfoAjouterPhoto"));
        labelinfoAjouterPhoto->setGeometry(QRect(690, 385, 301, 51));
        QFont font3;
        font3.setPointSize(6);
        font3.setBold(false);
        font3.setWeight(50);
        labelinfoAjouterPhoto->setFont(font3);
        labelinfoAjouterPhoto->setAlignment(Qt::AlignCenter);
        pushButtonValider = new QPushButton(MaisonForm);
        pushButtonValider->setObjectName(QStringLiteral("pushButtonValider"));
        pushButtonValider->setGeometry(QRect(510, 500, 180, 50));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        pushButtonValider->setFont(font4);
        labelTitre = new QLabel(MaisonForm);
        labelTitre->setObjectName(QStringLiteral("labelTitre"));
        labelTitre->setGeometry(QRect(320, 20, 560, 50));
        QFont font5;
        font5.setPointSize(22);
        font5.setBold(true);
        font5.setWeight(75);
        labelTitre->setFont(font5);
        labelTitre->setAlignment(Qt::AlignCenter);

        retranslateUi(MaisonForm);

        QMetaObject::connectSlotsByName(MaisonForm);
    } // setupUi

    void retranslateUi(QWidget *MaisonForm)
    {
        MaisonForm->setWindowTitle(QApplication::translate("MaisonForm", "Ajouter une Maison", 0));
        MaisonForm->setStyleSheet(QApplication::translate("MaisonForm", "background-color: white; color: black;", 0));
        labelCle->setText(QApplication::translate("MaisonForm", "Cl\303\251 :", 0));
        labelType->setText(QApplication::translate("MaisonForm", "Type :", 0));
        comboBoxType->clear();
        comboBoxType->insertItems(0, QStringList()
         << QApplication::translate("MaisonForm", "LOCATION", 0)
         << QApplication::translate("MaisonForm", "VENTE", 0)
        );
        labelStanding->setText(QApplication::translate("MaisonForm", "Standing :", 0));
        comboBoxStanding->clear();
        comboBoxStanding->insertItems(0, QStringList()
         << QApplication::translate("MaisonForm", "Haut", 0)
         << QApplication::translate("MaisonForm", "Moyen", 0)
         << QApplication::translate("MaisonForm", "Bas", 0)
        );
        labelToilettes->setText(QApplication::translate("MaisonForm", "Toilettes :", 0));
        labelChambres->setText(QApplication::translate("MaisonForm", "Chambres :", 0));
        labelDescription->setText(QApplication::translate("MaisonForm", "Description :", 0));
        pushButtonAjouterPhoto->setText(QApplication::translate("MaisonForm", "Ajouter photos", 0));
        labelinfoAjouterPhoto->setText(QApplication::translate("MaisonForm", "Aucune photo ajout\303\251e", 0));
        pushButtonValider->setText(QApplication::translate("MaisonForm", "Valider", 0));
        labelTitre->setText(QApplication::translate("MaisonForm", "Ajouter une Maison", 0));
    } // retranslateUi

};

namespace Ui {
    class MaisonForm: public Ui_MaisonForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAISONFORM_H
