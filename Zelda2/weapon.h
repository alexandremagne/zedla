#ifndef WEAPON_H
#define WEAPON_H

#include <QPixmap>
#include <QString>

class Weapon
{
public:
    Weapon();

    QPixmap getTile(QString);

    QString getNom() const;
    void setNom(const QString &value);

    int getDega() const;
    void setDega(int value);

private:
    QString nom;
    int dega;
};

#endif // WEAPON_H
