#ifndef SWORD_H
#define SWORD_H

#include <QPixmap>
class Sword
{
public:
    Sword();



    QPixmap getTile() const;
    void setTile(const QPixmap &value);

private:
    QPixmap tile;
};

#endif // SWORD_H
