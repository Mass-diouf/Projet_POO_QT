#include "Maison.h"

// Constructeur par défaut
Maison::Maison()
    : cle(""), type(""), standing(""), description(""),
      nbChambres(0), nbToilettes(0), cheminsPhotos() {}

// Constructeur avec paramètres
Maison::Maison(const QString& cle,
               const QString& type,
               const QString& standing,
               int nbChambres,
               int nbToilettes,
               const QVector<QString>& cheminsPhotos,
               const QString& description)
    : cle(cle), type(type), standing(standing), nbChambres(nbChambres),
      nbToilettes(nbToilettes), cheminsPhotos(cheminsPhotos), description(description) {}

// Destructeur
Maison::~Maison() {}

// GETTERS
QString Maison::getCle() const {
    return cle;
}

QString Maison::getType() const {
    return type;
}

QString Maison::getStanding() const {
    return standing;
}

int Maison::getNbChambres() const {
    return nbChambres;
}

int Maison::getNbToilettes() const {
    return nbToilettes;
}

QString Maison::getDescription() const {
    return description;
}

QVector<QString> Maison::getCheminsPhotos() const {
    return cheminsPhotos;
}

// SETTERS
void Maison::setCle(const QString& c) {
    cle = c;
}

void Maison::setType(const QString& t) {
    type = t;
}

void Maison::setStanding(const QString& s) {
    standing = s;
}

void Maison::setNbChambres(int n) {
    nbChambres = n;
}

 void Maison::setNbToilettes(int n) {     nbToilettes = n;
 }

 void Maison::setDescription(const QString& d) {
     description = d;
 }

 void Maison::setCheminsPhotos(const QVector<QString>& photos) {
     cheminsPhotos = photos;
}
