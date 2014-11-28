#include "weapon.h"

Weapon::Weapon()
{
    this->dega=1; // par default
}
QString Weapon::getNom() const
{
    return nom;
}

void Weapon::setNom(const QString &value)
{
    nom = value;
}
int Weapon::getDega() const
{
    return dega;
}

void Weapon::setDega(int value)
{
    dega = value;
}


