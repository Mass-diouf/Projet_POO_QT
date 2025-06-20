#include "tablehachage.h"

TableHachage::TableHachage(int cap, unsigned int (*fctHachage)(const QString&))
    : capacite(cap), taille(0), fonctionHachage(fctHachage)
{
    table.resize(capacite);  // redimensionne le tableau

}

void TableHachage::clear() {
    for (int i = 0; i < table.size(); ++i) {
        table[i].clear();
    }
    taille=0;
}

int TableHachage:: col() const
{
    return collison;
}

void TableHachage::insertion(const Maison& maison)
{
    int index = fonctionHachage(maison.getCle()) % capacite;
    if (index < 0) index += capacite;

    liste& listeCellule = table[index];

    //Rechercher si la maison est déjà présente
    for (Maison& m : listeCellule) {
        if (m.getCle() == maison.getCle()) {
            m = maison;  // Remplacer
            return;      // Pas de collision ici
        }
    }

    //  Si on arrive ici, la clé n'existe pas encore
    //  On regarde s'il y avait déjà des maisons : donc collision
    if (!listeCellule.isEmpty()) {
        ++collison;  //  Collision détectée
    }

    listeCellule.append(maison);
    ++taille;
}



bool TableHachage::contient(const QString& cle) const
{
    int index = fonctionHachage(cle) % capacite;
    const liste& l = table[index];

    for (const Maison& m : l) {
        if (m.getCle() == cle)
            return true;
    }

    return false;
}


Maison* TableHachage::get(const QString& cle)
{
    int index = fonctionHachage(cle) % capacite;
    liste& l = table[index];

    for (Maison& m : l) {
        if (m.getCle() == cle)
            return &m;
    }

    return nullptr;
}


bool TableHachage::suppression(const QString& cle)
{
    int index = fonctionHachage(cle);
    index %= capacite;
    if (index < 0) index += capacite;

    liste& listeCellule = table[index];

    for (int i = 0; i < listeCellule.size(); ++i) {
        if (listeCellule[i].getCle() == cle) {
            listeCellule.removeAt(i);
            --taille;
            return true;
        }
    }
    return false;
}

int TableHachage::size() const
{
    return taille;
}

bool TableHachage::estVide() const
{
    return taille == 0;
}

void TableHachage::changerFonctionHachage(unsigned int (*nouvelleFct)(const QString&))

{
    fonctionHachage = nouvelleFct;

    QVector<liste> nouvelleTable(capacite);

    for (const liste& listeCellule : table) {
        for (const Maison& m : listeCellule) {
            int index = fonctionHachage(m.getCle());
            index %= capacite;
            if (index < 0) index += capacite;

            nouvelleTable[index].append(m);
        }
    }

    table = nouvelleTable;
}
QList<Maison> TableHachage::getListe(int index) const {
    if (index >= 0 && index < capacite)
        return table[index];
    return QList<Maison>();
}

int TableHachage::getCapacite() const
{
    return capacite;
}



