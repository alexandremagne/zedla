#include "quete.h"

Quete::Quete(QString level)
{
    this->quete = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/quete/quete"+level).scaled(400,200);
}
QPixmap Quete::getQuete() const
{
    return quete;
}

void Quete::setQuete(const QPixmap &value)
{
    quete = value;
}

