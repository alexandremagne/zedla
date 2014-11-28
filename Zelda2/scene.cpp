#include "scene.h"

Scene::Scene()
{
    this->posX = 0;
    this->posY = 0;
}

void Scene::setPosX(int i)
{
    if ((i+this->posX)<0)
        return;
    else if ((i+this->posX)>1000)
        return;
    else
        this->posX = i+this->posX;
}
void Scene::setPosY(int j)
{
    if ((j+this->posY)<0)
        return;
    else if ((j+this->posY)>250)
        return;
    else
        this->posY = j+this->posY;

}
int Scene::getPosX()
{
    return this->posX;
}

int Scene::getPosY()
{
    return this->posY;
}
