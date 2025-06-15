#include "MaisonDAO.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QStringList>
#include <QDebug>
#include <QString>


MaisonDAO::MaisonDAO(QSqlDatabase& db) : m_db(db) {}

bool MaisonDAO::insererMaison(const Maison& maison)
{
    if (!m_db.isOpen()) return false;

    QVector<QString> vectPhotos = maison.getCheminsPhotos();
    QStringList listPhotos;
    for (const QString &s : vectPhotos) {
        listPhotos << s;
    }
    QString photosConcat = listPhotos.join(";");

    QSqlQuery query(m_db);
    query.prepare("INSERT OR REPLACE INTO maisons "
                  "(cle, type, standing, nbChambres, nbToilettes, photos, description) "
                  "VALUES (:cle, :type, :standing, :nbChambres, :nbToilettes, :photos, :description)");

    query.bindValue(":cle", maison.getCle());
    query.bindValue(":type", maison.getType());
    query.bindValue(":standing", maison.getStanding());
    query.bindValue(":nbChambres", maison.getNbChambres());
    query.bindValue(":nbToilettes", maison.getNbToilettes());
    query.bindValue(":photos", photosConcat);
    query.bindValue(":description", maison.getDescription());

    if (!query.exec()) {
        qDebug() << "Erreur insertion maison:" << query.lastError().text();
        return false;
    }
    return true;
}

bool MaisonDAO::supprimerMaison(const QString& cle)
{
    if (!m_db.isOpen()) return false;

    QSqlQuery query(m_db);
    query.prepare("DELETE FROM maisons WHERE cle = :cle");
    query.bindValue(":cle", cle);
    if (!query.exec()) {
        qDebug() << "Erreur suppression maison:" << query.lastError().text();
        return false;
    }
    return true;
}

QVector<Maison> MaisonDAO::chargerMaisons()
{
    QVector<Maison> listeMaisons;

    if (!m_db.isOpen()) return listeMaisons;

    QSqlQuery query("SELECT * FROM maisons", m_db);
    if (!query.isActive()) {
        qDebug() << "Erreur chargement maisons:" << query.lastError().text();
        return listeMaisons;
    }

    while (query.next()) {
        QString cle = query.value("cle").toString();
        QString type = query.value("type").toString();
        QString standing = query.value("standing").toString();
        int nbChambres = query.value("nbChambres").toInt();
        int nbToilettes = query.value("nbToilettes").toInt();
        QString photosStr = query.value("photos").toString();
        QString description = query.value("description").toString();

        QVector<QString> photos = photosStr.split(";", QString::SkipEmptyParts).toVector();



        Maison maison(cle, type, standing, nbChambres, nbToilettes, photos, description);
        listeMaisons.append(maison);
    }

    return listeMaisons;
}

QVector<Maison> MaisonDAO::chargerToutes() {
    QVector<Maison> liste;

    QSqlQuery query;
    if (!query.exec("SELECT cle, type, standing, nbChambres, nbToilettes, photos, description FROM maison")) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        return liste;
    }

    while (query.next()) {
        QString cle = query.value(0).toString();
        QString type = query.value(1).toString();
        QString standing = query.value(2).toString();
        int nbChambres = query.value(3).toInt();
        int nbToilettes = query.value(4).toInt();
        QString photosStr = query.value(5).toString();
        QStringList photos =photosStr.split(";", QString::SkipEmptyParts);

        QString description = query.value(6).toString();

        QVector<QString> vectPhotos = photos.toVector();
        Maison maison(cle, type, standing, nbChambres, nbToilettes, vectPhotos, description);


    }

    return liste;
}


#include "maisondao.h"
#include "maison.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QStringList>

Maison MaisonDAO::chercherParCle(const QString& cle) {
    QSqlQuery query;
    query.prepare("SELECT * FROM maisons WHERE cle = :cle");
    query.bindValue(":cle", cle);

    if (query.exec() && query.next()) {
        QString type = query.value("type").toString();
        QString standing = query.value("standing").toString();
        int nbChambres = query.value("nbChambres").toInt();
        int nbToilettes = query.value("nbToilettes").toInt();
        QString photosStr = query.value("photos").toString();
        QString description = query.value("description").toString();

        QVector<QString> photos = photosStr.split(";", QString::SkipEmptyParts).toVector();

        return Maison(cle, type, standing, nbChambres, nbToilettes, photos, description);
    }

    return Maison();  // ou throw une erreur, selon ton design
}
