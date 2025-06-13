#ifndef MAISON_H
#define MAISON_H
#include <QString>
#include <QVector>

class Maison {
private:
    QString cle;
    QString type;
    QString standing;
    QString description;
    int nbChambres;
    int nbToilettes;
    QVector<QString> cheminsPhotos;

public:
    Maison();
    Maison(const QString& cle,
           const QString& type,
           const QString& standing,
           int nbChambres,
           int nbToilettes,
           const QVector<QString>& cheminsPhotos,
           const QString& description);

    // getters
    QString getCle() const;
    QString getType() const;
    QString getStanding() const;
    int getNbChambres() const;
    int getNbToilettes() const;
    QString getDescription() const;
    QVector<QString> getCheminsPhotos() const;

    // setters
    void setCle(const QString& c);
    void setType(const QString& t);
    void setStanding(const QString& s);
    void setNbChambres(int n);
    void setNbToilettes(int n);
    void setDescription(const QString& d);
    void setCheminsPhotos(const QVector<QString>& photos);

    ~Maison();
};

#endif // MAISON_H

