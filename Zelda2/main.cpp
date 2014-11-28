#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMovie>
#include <QEvent>
#include <iostream>
#include <vector>
#include <QDebug>
#include <QSound>
#include <QTimer>


#include "map.h"
#include "controller.h"
#include "model.h"


using namespace std;


int main(int argc, char *argv[])
{
     QApplication app(argc, argv);

   // QSound son("/Users/alexandremagne/Music/1.wav");
   // son.play();






     Model m;
     Map v;
     Controller controller(&v,&m);
     //controller.setCarteMatrice(x);//on créer le vecteur de matrice dans le controlleur

     controller.startGame();

    //Map carte;//on instancie un objet de type vue

   // carte.monTableauDeCarte = tab;
   // carte.initialiserScene(carte.monTableauDeCarte);//on initialise la scene
   // carte.show();

    return app.exec();

}



//QGraphicsView view(&scene);

//view.setBackgroundBrush(QPixmap("/Developer/QtProjects/Zelda/images/Background_2.png"));
// view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
// view.ensureVisible();
// QGraphicsPixmapItem item(QPixmap("/Developer/QtProjects/Zelda/desert.png").scaled(50,50));
// scene.addItem(&item);
//int tab[10][10] = {{0}};

