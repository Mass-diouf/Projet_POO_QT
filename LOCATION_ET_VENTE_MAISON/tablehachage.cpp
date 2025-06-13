#include "tablehachage.h"

TableHachage::TableHachage(int cap, int (*fctHachage)(const QString&))
    : capacite(cap), taille(0), fonctionHachage(fctHachage)
{
    table.resize(capacite);  // crée capacite listes vides
}

void TableHachage::insertion(const Maison& maison)
{
    int index = fonctionHachage(maison.getCle());
    index %= capacite;
    if (index < 0) index += capacite;  // sécurité si hash négatif

    liste& listeCellule = table[index];

    // Vérifier si la maison existe déjà (clé identique), si oui remplacer
    for (Maison& m : listeCellule) {
        if (m.getCle() == maison.getCle()) {
            m = maison;
            return;
        }
    }

    // Sinon insérer la maison à la fin de la liste
    listeCellule.append(maison);
    ++taille;
}

bool TableHachage::contient(const QString& cle) const
{
    int index = fonctionHachage(cle);
    index %= capacite;
    if (index < 0) index += capacite;

    const liste& listeCellule = table[index];

    for (const Maison& m : listeCellule) {
        if (m.getCle() == cle)
            return true;
    }
    return false;
}

Maison* TableHachage::get(const QString& cle)
{
    int index = fonctionHachage(cle);
    index %= capacite;
    if (index < 0) index += capacite;

    liste& listeCellule = table[index];

    for (Maison& m : listeCellule) {
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

void TableHachage::changerFonctionHachage(int (*nouvelleFct)(const QString&))
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


int TableHachage:: hachage1(const QString& cle) {
    unsigned int hash = 0;
    unsigned int prime = 31;
    for (int i = 0; i < cle.size(); ++i) {
        QChar ch = cle[i];
        hash = prime * hash + ch.unicode();
        hash ^= (hash >> 16);
    }
    return hash;
}

int TableHachage:: hachage2(const QString& cle) {
    unsigned int hash = 0;
    for (int i = 0; i < cle.size(); ++i) {
        QChar ch = cle[i];
        unsigned int value = ch.unicode();
        hash = hash + value;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

int TableHachage::hachage3 (const QString& cle) {
    int sigma = 0;
    for (int i = 0; i < cle.length(); ++i) {
        sigma += static_cast<int>(cle.at(i).toLatin1());
    }
    return sigma;
}
