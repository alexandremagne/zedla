#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QMovie>
#include <QDebug>
#include <QKeyEvent>

class Scene:QGraphicsScene
{
public:
    Scene();
    void setPosX(int i);
    void setPosY(int j);
    int getPosX();
    int getPosY();

private:
    int posX;
    int posY;
};

#endif // SCENE_H
