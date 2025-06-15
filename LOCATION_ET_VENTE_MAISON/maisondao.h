#ifndef MAISONDDAO_H
#define MAISONDDAO_H

#include <QString>
#include <QVector>
#include <QSqlDatabase>
#include "Maison.h"

class MaisonDAO {
public:
    explicit MaisonDAO(QSqlDatabase& db);

    bool insererMaison(const Maison& maison);
    bool supprimerMaison(const QString& cle);
    QVector<Maison> chargerMaisons();
    static QVector<Maison> chargerToutes();

    static Maison chercherParCle(const QString& cle);



private:
    QSqlDatabase& m_db;
};

#endif // MAISONDDAO_H
