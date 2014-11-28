#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "map.h"
#include "model.h"



#include <QWidget>
#include <QObject>
#include <QTimer>
#include <QVBoxLayout>
#include <QTime>
#include <QEventLoop>
#include <QCoreApplication>
#include <QSound>


/*Mon controleur doit savoir
 * - avoir un statut : par exemple 1 = au menu principale
 *      2= en jeu ======> on peut dire la correspondance des touche en fonction de ca
 *
 * - afficher la map
 * - à quel niveau on veut aller et donc envoyer dans "map" ma matrice de la carte
 * - mon personnage qui va se balader dans les niveaux
 * -
 *
 */
class Map;
class Controller : public QWidget
{
    Q_OBJECT

public:
    Controller(Map *view, Model *model);//constructeur
    // void setView();
    void startGame();
    void pressKey(std::string key);

    Model *getModel() const;
    void setModel(Model *value);

protected:
    void delay(int i);
/*              zelda et element naturel                        */
    void zelda_va_dans_leau(QString direction);

/*          attaques et Zelda        */
    void attack_function(QString direction);//attaque de l'epee
    void attaque_hammer_function();//attaque du marteau
    void checkCollisionArrowsWithEnnemis();//pour checker la collision flech ennemie
    void faireAvancerArrow();//pour que les flechent se deplacent
/*          Jeu et Zelda        */
    void next_level_procedure();
    void game_over_procedure();//en cas de game over
    void game_finished_procedure();
    void checkObjectifNiveau();//pour voir l'objectif du niveau
    int check_quete();//pour voir si il y a des quete ou non
    void mettreInvincibilitZelda();//au bout de 2 sec zelda nest plus invincible
    void zeldaPeutFaireCoupHammer();//toutes les 2 seconde le coup du hammer
/*          Ennemis et Zelda        */
    void toucheEnnemisQuandZeldaAttaque(Ennemis *ennemi);
    void gestionApparitionExplosionToucheEnnemi();//si ya une explosion ca gere l'animation de l'explosion
    void checkCollisionEnnemis(Ennemis *ennemis);//collision zelda ennemi
    void checkCollisionDecortWithEnnemi(Ennemis *ennemis);
    void lootAleatoireDesEnnemis(Ennemis *ennemis);
    void collisionZeldaBouleDeFeu();//action quand zelda se pred une boule de feu
    void collisionZeldaLambeau();//pareil avec lambeau
/*          Item et Zelda        */
    void checkCollisionItemsWithZelda();//collision item zelda
    void zeldaRammasseUnCoeur(int i);//si zelda ramasse un coeur
    void zeldaRammasseUneFleche(int i);//si zelda ramasse une fleche
    void zeldaRammasseLaSword(int i);
    void zeldaRammasseLaKey(int i);





private:
    Map *view;//represente la vue, ce que voit l'utilisateur
    Model *model;
    QTimer *timer;//raffraichissmeent de la scene
    QSound *son;
    int statueSon;//pour le son, pour le changer au niveau 2
    int zeldaAttaqueOuPas;//si zelda a l'animation sword ou epee , on va gerer les probleme de qpixmap null
    int niveauActuel;


public slots:
    void mooveEnnemis();
    void afficherScene();

};

#endif // CONTROLLER_H
