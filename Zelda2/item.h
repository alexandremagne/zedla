#ifndef ITEM_H
#define ITEM_H

#include <QPixmap>
#include <QString>
#include <QDebug>

class item
{
public:
    item(int posXinitiale, int posYinitiale, QString type_of_item);
    item(QString s);
    void setTilefaismain(); // définie l'image à charger
    int faireAvancerFleche();


    //SETTEURS AUTOMATIQUE

    QString getType_of_item() const;
    void setType_of_item(const QString &value);

    int getPosXinitiale() const;
    void setPosXinitiale(int value);

    int getPosYinitiale() const;
    void setPosYinitiale(int value);

    QPixmap getTile() const;
    void setTile(const QPixmap &value);

    int getPosXactuel() const;
    void setPosXactuel(int value);

    int getPosYactuel() const;
    void setPosYactuel(int value);



private:
    QPixmap tile; // attribut "tile" de type pixmax
    int posXinitiale;
    int posYinitiale;
    int posXactuel;
    int posYactuel;

    QString type_of_item;
};

#endif // ITEM_H
