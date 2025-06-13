#ifndef TABLEHACHAGE_H
#define TABLEHACHAGE_H
#include<QString>
#include <QVector>
#include <QList>
#include <QString>
#include "Maison.h"
#include "fonctionhachage.h"


// typedef d'une liste de maisons avec QList (Qt)
typedef QList<Maison> liste;

class TableHachage {
private:
    QVector<liste> table;  // tableau de listes de maisons
    int capacite;          // capacité max (nombre de listes)
    int taille;            // nombre actuel de maisons
    int (*fonctionHachage)(const QString&);    // pointeur vers fonction de hachage

public:
    TableHachage(int capacite, int (*fctHachage)(const QString&));
    void insertion(const Maison& maison);
    bool contient(const QString& cle) const;
    Maison* get(const QString& cle);
    bool suppression(const QString& cle);
    int size() const;
    bool estVide() const;
    int getCapacite() const;
    QList<Maison> getListe(int index) const;
    int hachage1(const QString& cle);
    int hachage2(const QString& cle);
    int hachage3(const QString& cle);
    void changerFonctionHachage(int (*nouvelleFct)(const QString&));
};

#endif // TABLEHACHAGE_H
