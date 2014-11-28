#include "item.h"

item::item(int posXinit, int posYinit, QString type_of_item)
{
    this->posXinitiale=posXinit;
    this->posYinitiale=posYinit;
    this->posXactuel=posXinit;
    this->posYactuel=posYinit;
    this->type_of_item = type_of_item;
    setTilefaismain(); // on définie l'item à charger lors de sa création
}

item::item(QString s)
{
    this->type_of_item = s;
    setTilefaismain();
}

    void item::setTilefaismain(){
        if (this->getType_of_item()!="hammer_hole")
            this->tile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/items/" + this->getType_of_item() + ".png").scaled(30,30);
        else this->tile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/items/" + this->getType_of_item() + ".png").scaled(60,60);
    }

    int item::faireAvancerFleche()
    {
    if (this->type_of_item == "arrow_right" ||this->type_of_item == "arrow_left" ||this->type_of_item == "arrow_up" ||this->type_of_item == "arrow_down"){
        int diffX = this->posXactuel - this->posXinitiale;
        int diffY = this->posYactuel - this->posYinitiale;
        //pour faire avance la fleche
        if(this->type_of_item == "arrow_right" && diffX<149){
            this->posXactuel+=10;
            return 0;
        }else  if(this->type_of_item == "arrow_left" && diffX>-149){
            this->posXactuel-=10;
            return 0;
        }else  if(this->type_of_item == "arrow_up" && diffY>-149){
            this->posYactuel-=10;
            return 0;
        }else  if(this->type_of_item == "arrow_down" && diffY<149){
            this->posYactuel+=10;
            return 0;
        }else return 1;
    }else return 0;
}



QString item::getType_of_item() const
{
    return type_of_item;
}

void item::setType_of_item(const QString &value)
{
    type_of_item = value;
}
int item::getPosXinitiale() const
{
    return posXinitiale;
}

void item::setPosXinitiale(int value)
{
    posXinitiale = value;
}
int item::getPosYinitiale() const
{
    return posYinitiale;
}

void item::setPosYinitiale(int value)
{
    posYinitiale = value;
}
QPixmap item::getTile() const
{
    return tile;
}

void item::setTile(const QPixmap &value)
{
    tile = value;
}
int item::getPosXactuel() const
{
    return posXactuel;
}

void item::setPosXactuel(int value)
{
    posXactuel = value;
}
int item::getPosYactuel() const
{
    return posYactuel;
}

void item::setPosYactuel(int value)
{
    posYactuel = value;
}









