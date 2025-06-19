#include "fonctionhachage.h"

unsigned int FonctionsHachage::hachage1(const QString& cle) {
    unsigned int a = 1, b = 0;
    const int MOD_ADLER = 65521;

    for (int i = 0; i < cle.size(); ++i) {
        a = (a + static_cast<unsigned char>(cle[i].toLatin1())) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }

    return (b << 16) | a;
}


unsigned int FonctionsHachage::hachage2(const QString& cle) {
    unsigned int hash = 0;
    const unsigned int prime = 2654435761; // Knuth

    for (int i = 0; i < cle.size(); ++i) {
        hash ^= static_cast<unsigned char>(cle[i].toLatin1());
        hash *= prime;
    }

    return hash;
}



unsigned int FonctionsHachage::hachage3(const QString& cle) {
    unsigned int somme = 0;
    for (int i = 0; i < cle.size(); ++i) {
        somme += static_cast<unsigned char>(cle.at(i).toLatin1());
    }
    return somme;
}

// 4. Indexation directe (clé entière)
unsigned int FonctionsHachage::hachageSans(const QString &cle) {
    return 0;
}

