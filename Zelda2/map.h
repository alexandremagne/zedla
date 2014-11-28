#ifndef MAP_H
#define MAP_H

#include<vector>
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QMovie>
#include <QDebug>
#include <QKeyEvent>
#include <QLineEdit>

#include "scene.h"
#include "quete.h"
#include "zelda.h"
#include "controller.h"
#include "ennemis.h"

class Controller;

class Map:public QGraphicsView//ma classe hérite afin d'avoir la possibilité d'utiliser les touche
{
public:
    Map();
    void setControl(Controller *controller) {
            this->controller = controller;
    }//ici on associe le controller à la vue
    void resetView();
    void initialiserScene();//on passe en paramètre le vecteur qui sera la carte

    void afficherPersonnage(Zelda *zelda);//methode pour mettre le personnage (pas top ici peut etre je sais pas
    void afficherEnnemis(Ennemis *ennemi);
    void afficherQuete(Quete *quete);
    void afficherItemsMap(vector<item*> vec);
    QGraphicsScene *getMapScene() const;
    Scene *getCameraView() const;

  protected:
    void keyPressEvent(QKeyEvent *event);//pour gérer les touches appuyer
    //void keyReleaseEvent(QKeyEvent * event);//relaché
    void setMapScene(QGraphicsScene *value);
    void setCameraView(Scene *value);

    void affichageMenuEnHaut();

private:
    Controller *controller;//pour relier le controleur à la view
    QGraphicsScene *mapScene;//la map contient une scene:la carte
    Scene *cameraView;
    int numberFlamme;


};

#endif // MAP_H
