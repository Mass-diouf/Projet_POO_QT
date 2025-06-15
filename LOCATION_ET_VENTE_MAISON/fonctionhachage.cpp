#include "fonctionhachage.h"

// 1. Somme ASCII (hachage brut)
unsigned int FonctionsHachage::hachage1(const QString& cle) {
    unsigned int somme = 0;
    for (int i = 0; i < cle.size(); ++i) {
        somme += static_cast<unsigned char>(cle.at(i).toLatin1());
    }
    return somme;
}

// 2. Hachage polynomial (base 31) - hachage brut
unsigned int FonctionsHachage::hachage2(const QString& cle) {
    unsigned int hash = 0;
    int base = 31;
    for (int i = 0; i < cle.size(); ++i) {
        hash = hash * base + static_cast<unsigned char>(cle.at(i).toLatin1());
    }
    return hash;
}

// 3. Hachage DJB2 - hachage brut
unsigned int FonctionsHachage::hachage3(const QString& cle) {
    unsigned int hash = 5381;
    for (int i = 0; i < cle.size(); ++i) {
        hash = ((hash << 5) + hash) + static_cast<unsigned char>(cle.at(i).toLatin1()); // hash * 33 + c
    }
    return hash;
}

// 4. Indexation directe (clé entière)
unsigned int FonctionsHachage::hachageSans(const QString &cle) {
    return 0;
}

