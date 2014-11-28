#ifndef FINAL_BOSS__H
#define FINAL_BOSS__H

#include "ennemis.h"
#include <QDebug>
#include <QString>
class final_boss_: public Ennemis
{
public:
    final_boss_(int posXinit, int posYinit, QString direction, QString type_of_monstre);
    void setTilePosition() ;
    int getIsFlyingOrNot() const;
    void setIsFlyingOrNot(int value);

private:
    int isFlyingOrNot;
};

#endif // FINAL_BOSS__H
