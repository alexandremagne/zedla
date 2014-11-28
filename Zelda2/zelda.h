#ifndef ZELDA_H
#define ZELDA_H

#include <QPixmap>
#include <QLabel>
#include <QTimer>
#include <QDebug>
 #include <QString>

#include "monture.h"
#include "personnage.h"
#include "item.h"
#include "sword.h"
class Zelda: public Personnage
{
public:
    Zelda();
    QPixmap getTile();
    void setTilePosition(QString position);//limage
    void ajouterItem(QString s);//ajouter item au vecteur
    void deleteItem(int i);//delete item du vecteur a la position i
    void deleteItem(QString nomItem);//delete item avec le nom
    int zeldaPossedeKeyOuPas();//pour savoir si zelda  une clef ou pas
    int compteurDeFleche();//pour savoir le nombre de fleche de zelda
    void zeldaSupprimerKey();

    int getNumber() const;
    void setNumber(int value);

    vector<item *> getMesItems() const;
    void setMesItems(const vector<item *> &value);

    QString getDirection() const;
    void setDirection(const QString &value);

    int getInvincibilité() const;
    void setInvincibilité(int value);

    monture *getMyMonture() const;
    void setMyMonture(QString nom);
    void deleteMyMonture();

    int getSpeed() const;
    void setSpeed(int value);

    Sword *getSword() const;
    void setSword(Sword *value);

    int getIsSwimmingOrNot() const;
    void setIsSwimmingOrNot(int value);

    int getZeldaRechargeAttaqueHammerOuPas() const;
    void setZeldaRechargeAttaqueHammerOuPas(int value);

    int getIsBurningOrNot() const;
    void setIsBurningOrNot(int value);

    int getIsEmprisonneParLambeau() const;
    void setIsEmprisonneParLambeau(int value);

    int getIsAmoradoOrNot() const;
    void setIsAmoradoOrNot(int value);

private:
    QPixmap tile;
    int number;//pour la position de l'image
    QString direction;
    int speed;
    int invincibilité;//pour check si zelda est invicible
    monture *myMonture;
    Sword *sword;
    int isSwimmingOrNot;//pour savoir si zelda nage 0 non 1 oui
    int isBurningOrNot;//pour savoir si zelda toucher par boule de feu
    int isEmprisonneParLambeau;//pour savoir si zelda est emprisonne par les lambeaux
    int isAmoradoOrNot;//pour quand zelda touche zelda
    int zeldaRechargeAttaqueHammerOuPas;//pour savoir si zelda peut utiliser ou non le marteau (on va dire 10 seconde de recharge)

    vector<item*> mesItems; // vecteur d'items ( le sac a dos de zelda )
};

#endif // ZELDA_H
