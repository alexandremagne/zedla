#include "map.h"


Map::Map()
{
    this->mapScene = new QGraphicsScene(); // fixe
    //this->controller->zelda = new Zelda;
    this->cameraView = new Scene(); // "la camera mobile"
   this->setFixedSize(500, 500);//la vue aura une taille fixe non modifiable
    this->setRenderHint(QPainter::Antialiasing, true);//sert a rien je crois

    this->numberFlamme=1;

}

void Map::resetView(){
    delete this->mapScene;
    delete this->cameraView;
    this->mapScene = new QGraphicsScene(); // fixe
    this->cameraView = new Scene(); // "la camera mobile"
    this->setFixedSize(500, 500);//la vue aura une taille fixe non modifiable
    this->setRenderHint(QPainter::Antialiasing, true);//sert a rien je crois
}

void Map::initialiserScene()
{ 
    if(this->numberFlamme==1){
           this->numberFlamme=2;
       } else this->numberFlamme=1;

    std::vector<std::vector<int> > tab = this->controller->getModel()->getNiveau()->getCarteMatrice();
    delete this->mapScene;
    this->mapScene = new QGraphicsScene();

    int i = 0, j = 0, z, sizeOfTabY=tab.size(), sizeOfTabX=tab[0].size();
    mapScene->setSceneRect(this->cameraView->getPosX(),this->cameraView->getPosY(),500,500); // on définie la camera

    if (this->controller->getModel()->getNiveau()->getNiveauActuel() > 0){
        //ce premier "for" met le fond d'écran partout pareil
        for (i = 0 ; i < sizeOfTabY ; i++)
        {
            for (j = 0 ; j < sizeOfTabX ; j++)
            {
                QPixmap oneTile;
                oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/fond_beige.png").scaled(50,50);
                z=0;
                QGraphicsPixmapItem *pGraphicsPixmapItem = new QGraphicsPixmapItem(oneTile);
                pGraphicsPixmapItem->setPixmap(oneTile);
                pGraphicsPixmapItem->setPos(j*50,i*50);
                pGraphicsPixmapItem->setZValue(z); // on affecte au fond baige la valeur z=0
                this->mapScene->addItem(pGraphicsPixmapItem);
            }
        }
        //ce deuxieme for permet de rajouter les element par dessus
        for (i = 0 ; i < sizeOfTabY ; i++)
        {
            for (j = 0 ; j < sizeOfTabX ; j++)
            {
                QPixmap oneTile;

                if(tab[i][j]==1){
                    if (this->controller->getModel()->getNiveau()->getNiveauActuel()==3){
                        oneTile = QPixmap("/Users//Desktop/Zelda2/Tiles/Object/falaises.png").scaled(50,50, Qt::IgnoreAspectRatio);
                        z=5;
                    } else {
                        oneTile = QPixmap("/Users//Desktop/Zelda2/Tiles/Object/rocher_marron.png").scaled(50,50, Qt::IgnoreAspectRatio);
                        z=5;
                    }
                }else if(tab[i][j]==10){
                    if (this->controller->getModel()->getNiveau()->getNiveauActuel()==3){
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau_enfer/1.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    } else {
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau/1.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    }
                }else if(tab[i][j]==11){
                    if (this->controller->getModel()->getNiveau()->getNiveauActuel()==3){
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau_enfer/2.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    } else {
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau/2.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    }
                }else if(tab[i][j]==12){
                    if (this->controller->getModel()->getNiveau()->getNiveauActuel()==3){
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau_enfer/3.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    } else {
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau/3.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    }
                }else if(tab[i][j]==13){
                    if (this->controller->getModel()->getNiveau()->getNiveauActuel()==3){
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau_enfer/4.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    } else {
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau/4.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    }
                }else if(tab[i][j]==14){
                    if (this->controller->getModel()->getNiveau()->getNiveauActuel()==3){
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau_enfer/5.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    } else {
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau/5.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    }
                }else if(tab[i][j]==15){
                    if (this->controller->getModel()->getNiveau()->getNiveauActuel()==3){
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau_enfer/6.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    } else {
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau/6.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    }
                }else if(tab[i][j]==16){
                    if (this->controller->getModel()->getNiveau()->getNiveauActuel()==3){
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau_enfer/7.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    } else {
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau/7.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    }
                }else if(tab[i][j]==17){
                    if (this->controller->getModel()->getNiveau()->getNiveauActuel()==3){
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau_enfer/8.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    } else {
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau/8.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    }
                }else if(tab[i][j]==18){
                    if (this->controller->getModel()->getNiveau()->getNiveauActuel()==3){
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau_enfer/9.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    } else {
                        oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/eau/9.png").scaled(50,50,Qt::IgnoreAspectRatio);
                        z=1;
                    }
                }else if(tab[i][j]==20){
                    oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/arbre/ase1.png").scaled(50,50,Qt::IgnoreAspectRatio);
                    z=5;
                }else if(tab[i][j]==22){
                    oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/arbre/ase2.png").scaled(50,50,Qt::IgnoreAspectRatio);
                    z=5;
                }else if(tab[i][j]==23){
                    oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/arbre/ase3.png").scaled(50,50,Qt::IgnoreAspectRatio);
                    z=5;
                }else if(tab[i][j]==21){
                    oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/arbre/arbre12.png").scaled(50,50,Qt::IgnoreAspectRatio);
                    z=5;
                }else if(tab[i][j]==24){
                    oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/arbre/arbre22.png").scaled(50,50,Qt::IgnoreAspectRatio);
                    z=5;
                }else if(tab[i][j]==25){
                    oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/arbre/ase4.png").scaled(50,50,Qt::IgnoreAspectRatio);
                    z=5;
                }else if(tab[i][j]==26){
                    oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/arbre/aseb.png").scaled(50,50,Qt::IgnoreAspectRatio);
                    z=5;//element passablea
                }else if(tab[i][j]==111){
                    oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/cheminbois/pathsureau.png").scaled(50,50,Qt::IgnoreAspectRatio);
                    z=0;//element passable
                }else if(tab[i][j]==112){
                    oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/cheminbois/chemin_up.png").scaled(50,50,Qt::IgnoreAspectRatio);
                    z=0;//element passable
                }else if(tab[i][j]==29){
                    oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/arbre/arbuste_vert.png").scaled(30,30,Qt::IgnoreAspectRatio);
                    z=5;//element passablea
                }else if(tab[i][j]==30){
                oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/final_level/sol_enfer.png").scaled(50,50,Qt::IgnoreAspectRatio);
                z=0;
            }else if(tab[i][j]==31){
                QString s = QString::number(this->numberFlamme);
                oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/final_level/flamme_" + s + ".png").scaled(50,50,Qt::IgnoreAspectRatio);
                z=3; // flammes
            }else if(tab[i][j]==113
                     ){
                    QString s = QString::number(this->numberFlamme);
                    oneTile = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/cheminbois/chemin_bois_feu_" + s + ".png").scaled(50,50,Qt::IgnoreAspectRatio);
                    z=3; // flammes
                }

                QGraphicsPixmapItem *pGraphicsPixmapItem = new QGraphicsPixmapItem(oneTile);
                //pGraphicsPixmapItem->setPixmap(oneTile);
                pGraphicsPixmapItem->setPos(j*50,i*50);
                pGraphicsPixmapItem->setZValue(z);//veleur retourner pour conntaitre itemAT
                this->mapScene->addItem(pGraphicsPixmapItem);
            }
        }
        affichageMenuEnHaut();
    }
    //principal menu
    if (this->controller->getModel()->getNiveau()->getNiveauActuel() == 0){
        QPixmap pix = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/menu_principal.jpg").scaled(500,500);
        QGraphicsPixmapItem *pGraphicsPixmapItem = new QGraphicsPixmapItem(pix);
        pGraphicsPixmapItem->setPixmap(pix);
        pGraphicsPixmapItem->setPos(0,0);
        pGraphicsPixmapItem->setZValue(1000);
        this->mapScene->addItem(pGraphicsPixmapItem);
        mapScene->setSceneRect(0,0,500,500); // on définie la camera
    }
    //game over menu
    if (this->controller->getModel()->getNiveau()->getNiveauActuel() == -1){

        QPixmap pix = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/game_over.png").scaled(500,500);
        QGraphicsPixmapItem *pGraphicsPixmapItem = new QGraphicsPixmapItem(pix);
        pGraphicsPixmapItem->setPixmap(pix);
        pGraphicsPixmapItem->setPos(0,0);
        pGraphicsPixmapItem->setZValue(1000);
        this->mapScene->addItem(pGraphicsPixmapItem);
        mapScene->setSceneRect(0,0,500,500); // on définie la camera
    } if (this->controller->getModel()->getNiveau()->getNiveauActuel() == -2){
        QPixmap pix = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/game_finished.png").scaled(500,500);
        QGraphicsPixmapItem *pGraphicsPixmapItem = new QGraphicsPixmapItem(pix);
        pGraphicsPixmapItem->setPixmap(pix);
        pGraphicsPixmapItem->setPos(0,0);
        pGraphicsPixmapItem->setZValue(1000);
        this->mapScene->addItem(pGraphicsPixmapItem);
        mapScene->setSceneRect(0,0,500,500); // on définie la camera
    }


    this->setScene(this->mapScene);
}


void Map::afficherPersonnage(Zelda *zelda)
{
    QGraphicsPixmapItem *apparencePersonnage =  new QGraphicsPixmapItem(zelda->getTile());
    apparencePersonnage->setPos(zelda->getPosX(),zelda->getPosY());

    apparencePersonnage->setZValue(100);//pour etre sur
    this->mapScene->addItem(apparencePersonnage);

    // on affiche les items de zelda
        if(this->controller->getModel()->getZelda()->getMesItems().size()!=0){//si le vecteur existe
            int j=0;//pour afficher les arrow
            int k=0;//pour afficher les clef
            for(unsigned long i =0; i<this->controller->getModel()->getZelda()->getMesItems().size(); i++){
                if(this->controller->getModel()->getZelda()->getMesItems()[i]->getType_of_item()=="keyaccesslevelup"){
                    k++;
                    QPixmap pix = this->controller->getModel()->getZelda()->getMesItems()[i]->getTile();
                     QGraphicsPixmapItem *clef = new QGraphicsPixmapItem(pix);
                     clef->setPos((this->cameraView->getPosX()+125+10*k), this->cameraView->getPosY()+8);
                     clef->setZValue((10)); // pour que l'image se place au dessus des autres
                     this->mapScene->addItem(clef);

                }else if(this->controller->getModel()->getZelda()->getMesItems()[i]->getType_of_item()=="arrow_item" && j<=6){                   
                    QPixmap pix = this->controller->getModel()->getZelda()->getMesItems()[i]->getTile();
                    QGraphicsPixmapItem *clef = new QGraphicsPixmapItem(pix);
                    clef->setPos((this->cameraView->getPosX()+300+10*i), this->cameraView->getPosY()+8);
                    clef->setZValue((10)); // pour que l'image se place au dessus des autres
                    this->mapScene->addItem(clef);
                    j++;

               }
            }
        }

}

void Map::afficherEnnemis(Ennemis *ennemi)
{
    QGraphicsPixmapItem *apparenceMechant =  new QGraphicsPixmapItem(ennemi->getTile());
    apparenceMechant->setPos(ennemi->getPosX(),ennemi->getPosY());

    apparenceMechant->setZValue(10);//pour etre sur
    this->mapScene->addItem(apparenceMechant);
}

void Map::afficherItemsMap( vector<item*> vec){
    if(vec.size()!=0){
        for (unsigned long i = 0; i<vec.size(); i++){
            QPixmap pix = vec[i]->getTile();
            QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pix);
            item->setPos(vec[i]->getPosXactuel(),vec[i]->getPosYactuel());
            if(vec[i]->getType_of_item()=="explosion"||vec[i]->getType_of_item()=="explosion1")
                item->setZValue(11);
            else item->setZValue(10);
            this->mapScene->addItem(item);
        }
    }
}



void Map::affichageMenuEnHaut()
{
    QGraphicsRectItem *rectangleDuHaut= new QGraphicsRectItem(this->cameraView->getPosX(),this->cameraView->getPosY(),500,40);
    rectangleDuHaut->setBrush(QBrush(Qt::white));
    rectangleDuHaut->setZValue(5);
    this->mapScene->addItem(rectangleDuHaut);

    int l=0;
    int c=0;//pour afficher les coeurs sur 2 rangees au lieu de une seule
   //pour afficher les coeur en haut
    for (int i=0;i<this->controller->getModel()->getZelda()->getLifeStatue();i++){

        if(this->controller->getModel()->getZelda()->getLifeStatue()<11){
            QPixmap pix = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/menu/heart.png").scaled(15,15);
            QGraphicsPixmapItem * io = new QGraphicsPixmapItem(pix);
            io->setPos((this->cameraView->getPosX()+15*l),this->cameraView->getPosY()+1+15*c);
            io->setZValue(10); // on affecte au fond baige la valeur z=0
            this->mapScene->addItem(io);
        }
        l++;
        if(l==5){
            c=1;
            l=0;
        }
    }
    //pour l'epee
    if (this->controller->getModel()->getZelda()->getSword()!=NULL){
        QPixmap pix = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/menu/sword.png").scaled(80,30);
        QGraphicsPixmapItem * io = new QGraphicsPixmapItem(pix);
        io->setPos((this->cameraView->getPosX()+200),this->cameraView->getPosY()+4);
        io->setZValue(10); // on affecte au fond baige la valeur z=0
        this->mapScene->addItem(io);
     }
    //pour le bow
    QPixmap bow = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/menu/bow.png").scaled(80,30);
    QGraphicsPixmapItem * bowGraph = new QGraphicsPixmapItem(bow);
    bowGraph->setPos((this->cameraView->getPosX()+270),this->cameraView->getPosY()+4);
    bowGraph->setZValue(10); // on affecte au fond baige la valeur z=0
    this->mapScene->addItem(bowGraph);
    //pour le hammer
    QPixmap hammer = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/menu/hammer.png").scaled(80,30);
    QGraphicsPixmapItem * hammerGraph = new QGraphicsPixmapItem(hammer);
    hammerGraph->setPos((this->cameraView->getPosX()+400),this->cameraView->getPosY()+4);
    hammerGraph->setZValue(10); // on affecte au fond baige la valeur z=0
    this->mapScene->addItem(hammerGraph);
    //pour le rechargement du hammer
    int statut_chargement=0;
    if(this->controller->getModel()->getZelda()->getZeldaRechargeAttaqueHammerOuPas()==250) statut_chargement=10;
    if(this->controller->getModel()->getZelda()->getZeldaRechargeAttaqueHammerOuPas()<250) statut_chargement=8;
    if(this->controller->getModel()->getZelda()->getZeldaRechargeAttaqueHammerOuPas()<200) statut_chargement=6;
    if(this->controller->getModel()->getZelda()->getZeldaRechargeAttaqueHammerOuPas()<150) statut_chargement=4;
    if(this->controller->getModel()->getZelda()->getZeldaRechargeAttaqueHammerOuPas()<100) statut_chargement=2;
    if(this->controller->getModel()->getZelda()->getZeldaRechargeAttaqueHammerOuPas()<50) statut_chargement=0;

    QString s = QString::number(statut_chargement);
    QPixmap loading_hammer = QPixmap("/Users/alexandremagne/Desktop/Zelda2/Tiles/Object/menu/loading_hammer/loading_hammer_"+s+".png").scaled(10,30);
    QGraphicsPixmapItem * loading_hammer_graph = new QGraphicsPixmapItem(loading_hammer);
    loading_hammer_graph->setPos((this->cameraView->getPosX()+445),this->cameraView->getPosY()+4);
    loading_hammer_graph->setZValue(10); // on affecte au fond baige la valeur z=0
    this->mapScene->addItem(loading_hammer_graph);

}

void Map::afficherQuete(Quete *quete)
{

    QGraphicsPixmapItem *apparenceQuete =  new QGraphicsPixmapItem(quete->getQuete());
    apparenceQuete->setPos(this->cameraView->getPosX()+50,this->cameraView->getPosY()+300);

    apparenceQuete->setZValue(10);//pour etre sur
    this->mapScene->addItem(apparenceQuete);

}

QGraphicsScene *Map::getMapScene() const
{
    return mapScene;
}

void Map::setMapScene(QGraphicsScene *value)
{
    mapScene = value;
}
Scene *Map::getCameraView() const
{
    return cameraView;
}

void Map::setCameraView(Scene *value)
{
    cameraView = value;
}






void Map::keyPressEvent(QKeyEvent *event)// je gére quand j'appuie sur une touche
{

     switch ( event->key())
      {
     case Qt::Key_Return:
     {
           this->controller->pressKey("enter");
           break;
    }
      case Qt::Key_Right:
      {
            this->controller->pressKey("right");
            break;
     }
      case Qt::Key_Left:
     {
         this->controller->pressKey("left");
            break;
     }
      case Qt::Key_Down:
           {
         this->controller->pressKey("down");
        break;
     }
      case Qt::Key_Up:
           {this->controller->pressKey("up");
     break;
     }
     case Qt::Key_A:
     {
         {
             this->controller->pressKey("a");
             break;
         }
     } case Qt::Key_B:
     {
         if(event->isAutoRepeat())
            break;
         else {
             this->controller->pressKey("b");
             break;
         }
     }case Qt::Key_Z:
     {
         if(event->isAutoRepeat())
            break;
         else {
             this->controller->pressKey("z");
             break;
         }
     }case Qt::Key_E:
     {
         if(event->isAutoRepeat())
            break;
         else {
             this->controller->pressKey("e");
             break;
         }
     }
        }
}

/*void Map::keyReleaseEvent(QKeyEvent * event)
{
    switch ( event->key())
     {
     case Qt::Key_Right:
     {
           this->controller->releaseKey("right");
           break;
    }
     case Qt::Key_Left:
    {
        this->controller->releaseKey("left");
           break;
    }
     case Qt::Key_Down:
          {
        this->controller->releaseKey("down");
       break;
    }
     case Qt::Key_Up:
          {this->controller->releaseKey("up");
    break;
    }
       }
}
*/

