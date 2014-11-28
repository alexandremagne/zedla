#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <vector>
#include <QGraphicsPixmapItem>
#include <QPixmap>

using namespace std;

class Personnage
{
public:
    Personnage();
    void setPosX(int i);
    void setPosY(int j);
    int getPosX();
    int getPosY();
    float getLifeStatue();
    void setLifeStatue(int life);

private:
    int posX;//position sur la carte
    int posY;//

    float life;//vie du personnage qui doit etre > ou = à 0



};

#endif // PERSONNAGE_H
