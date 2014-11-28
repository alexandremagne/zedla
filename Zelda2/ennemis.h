#ifndef ENNEMIS_H
#define ENNEMIS_H

#include "personnage.h"
#include <QPixmap>
#include <QDebug>

class Ennemis : public Personnage
{

public:
    Ennemis(int posXinit, int posYinit, QString direction, QString type_of_monstre); // constructeur
    ~Ennemis(){//
    };
    QPixmap getTile(); // renvoie un QPixmap
    void setTilePosition(); // Donne la position de la tile
    void setInit(QString type);

    void deplacementEnnemis(Ennemis *ennemis);
    int deplacementProjectile(Ennemis *ennemis);

    int getPosXinitiale() const;
    void setPosXinitiale(int value);

    int getPosYinitiale() const;
    void setPosYinitiale(int value);


    QString getDirection() const;
    void setDirection(const QString &value);

    QString getType_of_monstre() const;
    void setType_of_monstre(const QString &value);

    int getSpeed() const;
    void setSpeed(int value);


    int getDeplacementMax() const;
    void setDeplacementMax(int value);

    int getDirectionAleatoire() const;
    void setDirectionAleatoire(int value);

    int getI() const;
    void setI(int value);

protected:
    int i;//pour savoir quel image afficher (une sur 2 en gros)
    QPixmap tile; // attribut "tile" de type pixmax
    QString type_of_monstre;
    QString direction;

private:

    int posXinitiale;
    int posYinitiale;
    int id_monstre;//pour mettre le z value et reconnaitre le monstre


    int speed;
    int deplacementMax;
    int directionAleatoire;

};

#endif // ENNEMIS_H
