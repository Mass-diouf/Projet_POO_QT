#ifndef TABLEHACHAGE_H
#define TABLEHACHAGE_H
#include "fonctionhachage.h"
#include <QString>
#include <QVector>
#include <QList>
#include "Maison.h"

typedef QList<Maison> liste;

class TableHachage {
private:
    QVector<liste> table;
    int capacite;
    int taille;
    unsigned int (*fonctionHachage)(const QString&);
    int collison=0;


public:
    TableHachage(int capacite, unsigned int (*f)(const QString&));
    void insertion(const Maison& maison);
    bool contient(const QString& cle) const;
    Maison* get(const QString& cle);
    bool suppression(const QString& cle);
   int col() const;
    int size() const;
    bool estVide() const;
    int getCapacite() const;
    QList<Maison> getListe(int index) const;
    void clear();

    void changerFonctionHachage(unsigned int (*nouvelleFct)(const QString&));

};

#endif // TABLEHACHAGE_H
