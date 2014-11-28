#include "sword.h"

Sword::Sword()
{
}
QPixmap Sword::getTile() const
{
    return tile;
}

void Sword::setTile(const QPixmap &value)
{
    tile = value;
}


