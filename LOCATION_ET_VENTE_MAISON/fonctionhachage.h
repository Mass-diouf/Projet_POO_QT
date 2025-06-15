#ifndef FONCTIONHACHAGE_H
#define FONCTIONHACHAGE_H



#include <QString>

class FonctionsHachage {
public:
    static unsigned int hachage1(const QString& cle);
    static unsigned int hachage2(const QString& cle);
    static unsigned int hachage3(const QString& cle);
    static unsigned int hachageSans(const QString &cle); // ✅ Ajout de la fonction sans hachage

};

#endif // FONCTIONHACHAGE_H
