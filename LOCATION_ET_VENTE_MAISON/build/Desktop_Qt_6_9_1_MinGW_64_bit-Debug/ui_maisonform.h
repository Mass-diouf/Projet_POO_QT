/********************************************************************************
** Form generated from reading UI file 'maisonform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAISONFORM_H
#define UI_MAISONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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
            MaisonForm->setObjectName("MaisonForm");
        MaisonForm->setWindowModality(Qt::NonModal);
        MaisonForm->resize(1239, 600);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        MaisonForm->setFont(font);
        labelCle = new QLabel(MaisonForm);
        labelCle->setObjectName("labelCle");
        labelCle->setGeometry(QRect(20, 120, 120, 40));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        labelCle->setFont(font1);
        lineEditCle = new QLineEdit(MaisonForm);
        lineEditCle->setObjectName("lineEditCle");
        lineEditCle->setGeometry(QRect(180, 120, 300, 40));
        labelType = new QLabel(MaisonForm);
        labelType->setObjectName("labelType");
        labelType->setGeometry(QRect(20, 190, 120, 40));
        labelType->setFont(font1);
        comboBoxType = new QComboBox(MaisonForm);
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->setObjectName("comboBoxType");
        comboBoxType->setGeometry(QRect(180, 190, 300, 40));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(false);
        comboBoxType->setFont(font2);
        labelStanding = new QLabel(MaisonForm);
        labelStanding->setObjectName("labelStanding");
        labelStanding->setGeometry(QRect(20, 260, 151, 40));
        labelStanding->setFont(font1);
        comboBoxStanding = new QComboBox(MaisonForm);
        comboBoxStanding->addItem(QString());
        comboBoxStanding->addItem(QString());
        comboBoxStanding->addItem(QString());
        comboBoxStanding->setObjectName("comboBoxStanding");
        comboBoxStanding->setGeometry(QRect(200, 260, 300, 40));
        comboBoxStanding->setFont(font2);
        labelToilettes = new QLabel(MaisonForm);
        labelToilettes->setObjectName("labelToilettes");
        labelToilettes->setGeometry(QRect(20, 330, 151, 40));
        labelToilettes->setFont(font1);
        spinBoxToilettes = new QSpinBox(MaisonForm);
        spinBoxToilettes->setObjectName("spinBoxToilettes");
        spinBoxToilettes->setGeometry(QRect(200, 330, 300, 40));
        labelChambres = new QLabel(MaisonForm);
        labelChambres->setObjectName("labelChambres");
        labelChambres->setGeometry(QRect(20, 400, 151, 40));
        labelChambres->setFont(font1);
        spinBoxChambres = new QSpinBox(MaisonForm);
        spinBoxChambres->setObjectName("spinBoxChambres");
        spinBoxChambres->setGeometry(QRect(200, 400, 300, 40));
        labelDescription = new QLabel(MaisonForm);
        labelDescription->setObjectName("labelDescription");
        labelDescription->setGeometry(QRect(690, 100, 200, 40));
        labelDescription->setFont(font1);
        textEditDescription = new QTextEdit(MaisonForm);
        textEditDescription->setObjectName("textEditDescription");
        textEditDescription->setGeometry(QRect(690, 150, 300, 160));
        pushButtonAjouterPhoto = new QPushButton(MaisonForm);
        pushButtonAjouterPhoto->setObjectName("pushButtonAjouterPhoto");
        pushButtonAjouterPhoto->setGeometry(QRect(690, 330, 300, 45));
        pushButtonAjouterPhoto->setFont(font2);
        labelinfoAjouterPhoto = new QLabel(MaisonForm);
        labelinfoAjouterPhoto->setObjectName("labelinfoAjouterPhoto");
        labelinfoAjouterPhoto->setGeometry(QRect(690, 385, 301, 51));
        QFont font3;
        font3.setPointSize(6);
        font3.setBold(false);
        labelinfoAjouterPhoto->setFont(font3);
        labelinfoAjouterPhoto->setAlignment(Qt::AlignCenter);
        pushButtonValider = new QPushButton(MaisonForm);
        pushButtonValider->setObjectName("pushButtonValider");
        pushButtonValider->setGeometry(QRect(510, 500, 180, 50));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        pushButtonValider->setFont(font4);
        labelTitre = new QLabel(MaisonForm);
        labelTitre->setObjectName("labelTitre");
        labelTitre->setGeometry(QRect(320, 20, 560, 50));
        QFont font5;
        font5.setPointSize(22);
        font5.setBold(true);
        labelTitre->setFont(font5);
        labelTitre->setAlignment(Qt::AlignCenter);

        retranslateUi(MaisonForm);

        QMetaObject::connectSlotsByName(MaisonForm);
    } // setupUi

    void retranslateUi(QWidget *MaisonForm)
    {
        MaisonForm->setWindowTitle(QCoreApplication::translate("MaisonForm", "Ajouter une Maison", nullptr));
        MaisonForm->setStyleSheet(QCoreApplication::translate("MaisonForm", "background-color: white; color: black;", nullptr));
        labelCle->setText(QCoreApplication::translate("MaisonForm", "Cl\303\251 :", nullptr));
        labelType->setText(QCoreApplication::translate("MaisonForm", "Type :", nullptr));
        comboBoxType->setItemText(0, QCoreApplication::translate("MaisonForm", "LOCATION", nullptr));
        comboBoxType->setItemText(1, QCoreApplication::translate("MaisonForm", "VENTE", nullptr));

        labelStanding->setText(QCoreApplication::translate("MaisonForm", "Standing :", nullptr));
        comboBoxStanding->setItemText(0, QCoreApplication::translate("MaisonForm", "Haut", nullptr));
        comboBoxStanding->setItemText(1, QCoreApplication::translate("MaisonForm", "Moyen", nullptr));
        comboBoxStanding->setItemText(2, QCoreApplication::translate("MaisonForm", "Bas", nullptr));

        labelToilettes->setText(QCoreApplication::translate("MaisonForm", "Toilettes :", nullptr));
        labelChambres->setText(QCoreApplication::translate("MaisonForm", "Chambres :", nullptr));
        labelDescription->setText(QCoreApplication::translate("MaisonForm", "Description :", nullptr));
        pushButtonAjouterPhoto->setText(QCoreApplication::translate("MaisonForm", "Ajouter photos", nullptr));
        labelinfoAjouterPhoto->setText(QCoreApplication::translate("MaisonForm", "Aucune photo ajout\303\251e", nullptr));
        pushButtonValider->setText(QCoreApplication::translate("MaisonForm", "Valider", nullptr));
        labelTitre->setText(QCoreApplication::translate("MaisonForm", "Ajouter une Maison", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MaisonForm: public Ui_MaisonForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAISONFORM_H
