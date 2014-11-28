#include "monture.h"

monture::monture(QString nom)
{
    this->name=nom;
    this->initMonture(nom);
    this->isRidingOrNot=0;
}

void monture::initMonture(QString nom)
{
    if (nom == "horse") this->speed=20;
}
int monture::getIsRidingOrNot() const
{
    return isRidingOrNot;
}

void monture::setIsRidingOrNot(int value)
{
    isRidingOrNot = value;
}



QString monture::getName() const
{
    return name;
}

void monture::setName(const QString &value)
{
    name = value;
}
int monture::getSpeed() const
{
    return speed;
}

void monture::setSpeed(int value)
{
    speed = value;
}




