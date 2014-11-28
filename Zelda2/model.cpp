#include "model.h"

Model::Model()
{
    this->zelda = new Zelda();
    this->niveau = new Niveaux();


}

void Model::resetModel(){
    this->zelda = new Zelda();
    this->niveau = new Niveaux();
}

Zelda *Model::getZelda() const
{
    return zelda;
}

void Model::setZelda(Zelda *value)
{
    zelda = value;
}
Niveaux *Model::getNiveau() const
{
    return niveau;
}

void Model::setNiveau(Niveaux *value)
{
    niveau = value;
}



