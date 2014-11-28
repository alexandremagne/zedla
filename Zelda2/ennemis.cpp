#include "ennemis.h"

Ennemis::Ennemis(int posXinit, int posYinit, QString direction, QString type_of_monstre) // constructeur
{
    this->setPosX(posXinit);
    this->setPosY(posYinit);

    this->posXinitiale = posXinit;
    this->posYinitiale = posYinit;

    this->deplacementMax=0;
    this->directionAleatoire=1; // on initialise la direction aléatoire de l'ennemis à 1

    this->speed=2;


    this->direction = direction;
    this->type_of_monstre = type_of_monstre;
    this->i = 1;//pour les tiles di monstres
    setTilePosition();
    setInit(type_of_monstre);

    //setLifeStatue(2);//on met une vie de 4

   // this->tile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/ennemis/crabe_orange_1.png").scaled(30,30);//image par défaut
}



// non utilisé pour le moment
void Ennemis::setTilePosition()
{
    if(this->type_of_monstre == "boss_niveau_2_"){
         (this->i>=7)?this->i=1:this->i+=1;
        QString s = QString::number(this->i);
        //this->direction="left";
        this->tile=QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/ennemis/"+this->type_of_monstre+"/"+this->type_of_monstre+"left_"+s+".png").scaled(30,30);
    }else if(this->type_of_monstre == "final_boss_"){
        QString s = QString::number(this->i);
        this->tile=QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/ennemis/"+this->type_of_monstre+"/"+this->type_of_monstre+this->direction+"_"+s+".png").scaled(30,30);
        (this->i>=10)?this->i=1:this->i+=1;
    } else if (this->type_of_monstre=="zelda"){
        QString s = QString::number(this->i);
        this->tile=QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/"+this->type_of_monstre+"/"+this->type_of_monstre+"_"+this->direction+"_"+s+".png").scaled(30,30);
        (this->i>=6)?this->i=1:this->i+=1;
    }
    else{
        (this->i==1)?this->i=2:this->i=1;
        QString s = QString::number(this->i);
        this->tile=QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/ennemis/"+this->type_of_monstre+"/"+this->type_of_monstre+this->direction+"_"+s+".png").scaled(30,30);
        }
    }

void Ennemis::setInit(QString type)
{
    if(type == "crabe_orange_"){
        this->setSpeed(1);
        this->setLifeStatue(1);
    }
    else if(type == "crabe_bleu_"){
        this->setSpeed(3);
        this->setLifeStatue(2);
    }else if(type == "bouche_bizarre_"){
        this->setSpeed(1);
        this->setLifeStatue(1);
    }else if(type == "boule_de_feu_"){
        this->setSpeed(6);
        this->setLifeStatue(100);
    }else if(type == "gardien_clef_orange_"){
        this->setSpeed(1);
        this->setLifeStatue(3);
    }else if(type == "chauve_souris_bleu_"){
        this->setSpeed(5);
        this->setLifeStatue(1);
    }else if(type == "boss_niveau_2_"){
        this->setSpeed(10);
        this->setLifeStatue(5);
    }else if(type == "lambeau_boss_niveau_2_"){
        this->setSpeed(10);
        this->setLifeStatue(1); // zelda peut détruire le lambeau
    }else if(type == "final_boss_"){
        this->setSpeed(5);
        this->setLifeStatue(8);
    }else if(type == "zelda"){
        this->setSpeed(5);
        this->setLifeStatue(1);
    }
}

// fonction appelée toute les 20 ms
void Ennemis::deplacementEnnemis(Ennemis *ennemis){
    if (ennemis->getType_of_monstre()=="boss_niveau_2_"){
        int diffY = (ennemis->getPosY() - ennemis->getPosYinitiale());
                    if ((ennemis->getDirection() == "down") && diffY<100){ // déplacement max de 100 px
                        ennemis->setPosY(ennemis->getSpeed());
                    } else if ((ennemis->getDirection() == "up") && diffY<111 && diffY >0){
                        ennemis->setPosY(-ennemis->getSpeed());
                    } else{
                            if (ennemis->getDirection() == "up"){
                                    ennemis->setDirection("down");
                            }  else ennemis->setDirection("up");
                    }
                    ennemis->setTilePosition(); // déplacement (2 images)

    }else if(ennemis->getType_of_monstre()=="final_boss_"){
                    //int diffX = (ennemis->getPosX() - ennemis->getPosXinitiale());
                    //int diffY = (ennemis->getPosY() - ennemis->getPosYinitiale());
                    int diffMax = ennemis->getDeplacementMax();

                    if ((ennemis->getDirection() == "right") && (diffMax<20)){ // déplacement max de 100 px
                        ennemis->setPosX(ennemis->getSpeed());
                        ennemis->deplacementMax=ennemis->deplacementMax+1;
                    } else if ((ennemis->getDirection() == "left") && (diffMax<20)){
                        ennemis->setPosX(-ennemis->getSpeed());
                        ennemis->deplacementMax=ennemis->deplacementMax+1;
                    } else if ((ennemis->getDirection() == "down") && (diffMax<20)){ // déplacement max de 100 px
                        ennemis->setPosY(ennemis->getSpeed());
                        ennemis->deplacementMax=ennemis->deplacementMax+1;
                    } else if ((ennemis->getDirection() == "up") && (diffMax<20)){
                        ennemis->setPosY(-ennemis->getSpeed());
                        ennemis->deplacementMax=ennemis->deplacementMax+1;
                    } else{
                        ennemis->deplacementMax=0;
                                    if(ennemis->direction=="right"){
                                        ennemis->setDirection("down");
                                    }else if(ennemis->direction=="down"){
                                        ennemis->setDirection("left");
                                    }else if(ennemis->direction=="left"){
                                        ennemis->setDirection("up");
                                    }else if(ennemis->direction=="up"){
                                        ennemis->setDirection("right");
                                    }
            ennemis->setTilePosition(); // déplacement (2 images)
            }

    }else if(ennemis->getType_of_monstre() =="zelda"){
        ennemis->setTilePosition();
    }
    else if (ennemis->getType_of_monstre() != "boule_de_feu_" && ennemis->getType_of_monstre() != "lambeau_boss_niveau_2_"){
        int diffMax = ennemis->getDeplacementMax();

                           if ((ennemis->getDirection() == "right") && (diffMax<40)){ // déplacement max de 100 px
                               ennemis->setPosX(ennemis->getSpeed());
                               ennemis->deplacementMax=ennemis->deplacementMax+1;
                           } else if ((ennemis->getDirection() == "left") && (diffMax<40)){
                               ennemis->setPosX(-ennemis->getSpeed());
                               ennemis->deplacementMax=ennemis->deplacementMax+1;
                           } else if ((ennemis->getDirection() == "down") && (diffMax<40)){ // déplacement max de 100 px
                               ennemis->setPosY(ennemis->getSpeed());
                               ennemis->deplacementMax=ennemis->deplacementMax+1;
                           } else if ((ennemis->getDirection() == "up") && (diffMax<40)){
                               ennemis->setPosY(-ennemis->getSpeed());
                               ennemis->deplacementMax=ennemis->deplacementMax+1;
                           } else{
                                           //attribut une nouvelle direction aléatoirement
                                           ennemis->setDirectionAleatoire(rand() % 4); // 0, 1, 2, ou 3
                                           ennemis->deplacementMax=0;
                                           if(ennemis->getDirectionAleatoire()==0){
                                               ennemis->setDirection("right");
                                           } else if (ennemis->getDirectionAleatoire()==1){
                                               ennemis->setDirection("left");
                                           } else if (ennemis->getDirectionAleatoire()==2){
                                               ennemis->setDirection("up");
                                           } else if (ennemis->getDirectionAleatoire()==3){
                                               ennemis->setDirection("down");
                                           }
                           }
                   ennemis->setTilePosition(); // déplacement (2 images)
               }
}

int Ennemis::deplacementProjectile(Ennemis *ennemis)
{
    if (ennemis->getType_of_monstre() == "boule_de_feu_"){
        if(ennemis->getPosX()<40 || ennemis->getPosX()>1450 || ennemis->getPosY()<40 || ennemis->getPosY()>700)
        {
            //pour les bordure
            return 1;
        }
    if(ennemis->getDirection()=="right" || ennemis->getDirection()=="left"){
            int diffX = (ennemis->getPosX() - ennemis->getPosXinitiale());
            if ((ennemis->getDirection() == "right") && diffX<500){ // déplacement max de 100 px
                ennemis->setPosX(ennemis->getSpeed());
                return 0;
            } else if ((ennemis->getDirection() == "left") && diffX>-500){
                ennemis->setPosX(-ennemis->getSpeed());
                return 0;
            } else{
                    return 1;
            }
    } else if (ennemis->getDirection()=="up" || ennemis->getDirection()=="down"){
            int diffY = (ennemis->getPosY() - ennemis->getPosYinitiale());
            if ((ennemis->getDirection() == "down") && diffY<500){ // déplacement max de 100 px
                ennemis->setPosY(ennemis->getSpeed());
                return 0;
            } else if ((ennemis->getDirection() == "up") && diffY>-500){
                ennemis->setPosY(-ennemis->getSpeed());
                return 0;
            } else{
                   return 1;
            }
    }
    }
    else if(ennemis->getType_of_monstre() == "lambeau_boss_niveau_2_"){
        if(ennemis->getDirection()=="right" || ennemis->getDirection()=="left"){
                int diffX = (ennemis->getPosX() - ennemis->getPosXinitiale());
                if ((ennemis->getDirection() == "right") && diffX<500){ // déplacement max de 100 px
                    ennemis->setPosX(ennemis->getSpeed());
                    ennemis->setTilePosition();
                    return 0;
                } else if ((ennemis->getDirection() == "left") && diffX>-500){
                    ennemis->setPosX(-ennemis->getSpeed());
                    ennemis->setTilePosition();
                    return 0;
                } else{
                        return 1;
                }
    }}
    else return 0;
}


QPixmap Ennemis::getTile()
{
    return this->tile;
}

int Ennemis::getPosXinitiale() const
{
    return posXinitiale;
}

void Ennemis::setPosXinitiale(int value)
{
    posXinitiale = value;
    setPosX(value);
}
int Ennemis::getPosYinitiale() const
{
    return posYinitiale;
}

void Ennemis::setPosYinitiale(int value)
{
    posYinitiale = value;
    setPosY(value);
}






QString Ennemis::getDirection() const
{
    return direction;
}

void Ennemis::setDirection(const QString &value)
{
    direction = value;
}
QString Ennemis::getType_of_monstre() const
{
    return type_of_monstre;
}

void Ennemis::setType_of_monstre(const QString &value)
{
    type_of_monstre = value;
}
int Ennemis::getSpeed() const
{
    return speed;
}

void Ennemis::setSpeed(int value)
{
    speed = value;
}
int Ennemis::getDeplacementMax() const
{
    return deplacementMax;
}

void Ennemis::setDeplacementMax(int value)
{
    deplacementMax = value;
}
int Ennemis::getDirectionAleatoire() const
{
    return directionAleatoire;
}

void Ennemis::setDirectionAleatoire(int value)
{
    directionAleatoire = value;
}














