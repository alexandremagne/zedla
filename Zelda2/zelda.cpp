#include "zelda.h"

Zelda::Zelda()
{
    this->setPosX(0);
    this->setPosY(0);
    this->setLifeStatue(8);//on met une vie de 5 coeurs
    this->number = 1;//pour les tiles et l'animastion
    this->invincibilité = 0;//0 et 1 pour savoir si il est invincible
    this->direction = "down";//pour connaitre si il regarde a gauche ou a droite
    this->tile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/link_down/10.png").scaled(30,30);//image par défaut
    this->myMonture=new monture("horse");//pour savoir si il a une monture
    this->isSwimmingOrNot =0;//zelda ne nage pas au début
    this->isBurningOrNot = 0;//zelda ne brule pas par defaut
    this->isEmprisonneParLambeau = 0;//pareil
    this->isAmoradoOrNot = 0;
    this->zeldaRechargeAttaqueHammerOuPas = 250;//pour avoir les 10 sec
    this->sword=new Sword;//pour savoir si il a l'épée
    for(int i =0;i<5;i++) this->ajouterItem("arrow_item");
}


QPixmap Zelda::getTile()
{
    return this->tile;
}

void Zelda::ajouterItem(QString s)
{
    this->mesItems.push_back(new item(s));
}

void Zelda::deleteItem(int i)
{
    if(this->mesItems.size()!=0){
    delete this->mesItems[i];
    this->mesItems.erase(this->mesItems.begin()+i);
    }
}

void Zelda::deleteItem(QString nomItem)
{
    if (this->mesItems.size()!=0){
        for (unsigned long i=0;i < this->mesItems.size();i++){
            if (this->mesItems[i]->getType_of_item() == nomItem){
                deleteItem(i);
                return;
            }
        }
    }
}

int Zelda::zeldaPossedeKeyOuPas()
{
    if (this->mesItems.size()!=0){
        for (unsigned long i = 0;i<this->mesItems.size();i++){
            if (this->mesItems[i]->getType_of_item() == "keyaccesslevelup"){
                return 1;
            }
        }return 0;
    }else return 0;
}

int Zelda::compteurDeFleche()
{
    int compteurFleche=0;
    for (unsigned long i =0 ;i<this->mesItems.size();i++){

        if (this->mesItems[i]->getType_of_item() == "arrow_item")
        {
            compteurFleche+=1;//si fleche alors compteur + 1
        }

    }return compteurFleche;
}

void Zelda::zeldaSupprimerKey()
{
    if (this->mesItems.size()!=0){
        for (unsigned long i = 0;i<this->mesItems.size();i++){
            if (this->mesItems[i]->getType_of_item() == "keyaccesslevelup"){
                deleteItem(i);
                return;
            }
        }
    }
}


void Zelda::setTilePosition(QString position)
{
    QString s = QString::number(this->number);
       if(position == "a"){//si il y a une attaque epee
               QString path = "/Users/alexandremagne/Desktop/Zelda2/Tiles/link_attack/sword/";
               (this->invincibilité == 0)?path=path + this->direction + s + ".png" : path = path + this->direction + s +"a.png";
               this->tile = QPixmap(path).scaled(30,30);
               (this->number>=6)?this->number=1:this->number+=1; // effet des coup d'épée

    }else if(position == "z"){//si il y a une attaque arc
           QString path = "/Users/alexandremagne/Desktop/Zelda2/Tiles/link_attack/bow/";
           (this->invincibilité == 0)?path=path + this->direction + s + ".png" : path = path + this->direction + s +"a.png";
           this->tile = QPixmap(path).scaled(30,30);
           (this->number>=6)?this->number=1:this->number+=1; // effet des coup d'épée

        }else if(position=="e"){
           QString path = "/Users/alexandremagne/Desktop/Zelda2/Tiles/link_attack/hammer/"+this->direction+"/"+this->direction+s;
           (this->invincibilité == 0)?path=path +".png" : path = path+"a.png";
            if(this->direction=="right" || this->direction=="left")this->tile = QPixmap(path).scaled(40,40);
            else this->tile = QPixmap(path).scaled(30,30);
           (this->number==12)?this->number=1:this->number+=1;
       }else if(position=="right"||position=="left"||position=="up"||position=="down"){//si on bouge
           QString inv;//savoir si zelda est invincible ou non
           (this->invincibilité!=0)?inv="1":inv="0";
                if(this->isAmoradoOrNot==1){
                    // si link a rencontrée zelda
                    if(number>2) {
                        s="1";
                         this->number=1;}
                    this->speed=10;
                    (this->number>=2)?this->number=1:this->number+=1;
                    this->tile=QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/zelda/zeldaetlink/"+position+s+".png").scaled(40,40,Qt::IgnoreAspectRatio);

               }else if(this->myMonture->getIsRidingOrNot()==1 && this->isSwimmingOrNot==0){//si il y a une monture
                   if(number>3) {
                       s="1";
                        this->number=1;}
                   this->speed=this->myMonture->getSpeed();
                    this->tile=QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/link_"+position+"/"+this->myMonture->getName()+s+inv+".png").scaled(50,50,Qt::IgnoreAspectRatio);
                   (this->number>=3)?this->number=1:this->number+=1;
                }else if(this->isSwimmingOrNot==1){//si nage
                   //si zelda swim
                   this->speed=15;
                   (this->number>=7)?this->number=1:this->number+=1;
                   this->tile=QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/link_"+position+"/swim/"+s+".png").scaled(30,30,Qt::IgnoreAspectRatio);
               }else if(this->isBurningOrNot==1){//si zelda brule
                   this->speed=20;
                   (this->number>=7)?this->number=1:this->number+=1;
                   this->tile=QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/link_burn/"+position+s+".png").scaled(30,30,Qt::IgnoreAspectRatio);

               }else if(this->isEmprisonneParLambeau==1){//si zelda est emprisonner par le lambeau
                   if(number>3) {
                       s="1";
                       this->number=1;}
                   this->speed=0;
                   (this->number>=3)?this->number=1:this->number+=1;
                   this->tile=QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/link_emprisonne_lambeau/"+s+".png").scaled(30,30,Qt::IgnoreAspectRatio);

               }else{//si pas nage pas monture
                   if(number>6) {
                       s="1";
                        this->number=1;}
                   this->speed=10;
                   (this->number>=6)?this->number=1:this->number+=1;
                   this->tile=QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/link_"+position+"/"+s+inv+".png").scaled(30,30,Qt::IgnoreAspectRatio);
                }
               this->direction=position;

    }else this->tile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/link_down/10.png").scaled(30,30);

}


int Zelda::getNumber() const
{
    return number;
}

void Zelda::setNumber(int value)
{
    number = value;
}
QString Zelda::getDirection() const
{
    return direction;
}

void Zelda::setDirection(const QString &value)
{
    direction = value;
}
int Zelda::getInvincibilité() const
{
    return invincibilité;
}

void Zelda::setInvincibilité(int value)
{
    invincibilité = value;
}
monture *Zelda::getMyMonture() const
{
    return myMonture;
}

void Zelda::setMyMonture(QString nom)
{

    myMonture = new monture(nom);
}

void Zelda::deleteMyMonture()
{
    delete this->myMonture;
    this->myMonture = NULL;
}
int Zelda::getSpeed() const
{
    return speed;
}

void Zelda::setSpeed(int value)
{
    speed = value;
}
Sword *Zelda::getSword() const
{
    return sword;
}

void Zelda::setSword(Sword *value)
{
    sword = value;
}
int Zelda::getIsSwimmingOrNot() const
{
    return isSwimmingOrNot;
}

void Zelda::setIsSwimmingOrNot(int value)
{
    isSwimmingOrNot = value;
}
int Zelda::getZeldaRechargeAttaqueHammerOuPas() const
{
    return zeldaRechargeAttaqueHammerOuPas;
}

void Zelda::setZeldaRechargeAttaqueHammerOuPas(int value)
{
    zeldaRechargeAttaqueHammerOuPas = value;
}
int Zelda::getIsBurningOrNot() const
{
    return isBurningOrNot;
}

void Zelda::setIsBurningOrNot(int value)
{
    isBurningOrNot = value;
}
int Zelda::getIsEmprisonneParLambeau() const
{
    return isEmprisonneParLambeau;
}

void Zelda::setIsEmprisonneParLambeau(int value)
{
    isEmprisonneParLambeau = value;
}
int Zelda::getIsAmoradoOrNot() const
{
    return isAmoradoOrNot;
}

void Zelda::setIsAmoradoOrNot(int value)
{
    isAmoradoOrNot = value;
}







vector<item *> Zelda::getMesItems() const
{
    return mesItems;
}

void Zelda::setMesItems(const vector<item *> &value)
{
    mesItems = value;
}







