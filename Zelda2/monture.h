#ifndef MONTURE_H
#define MONTURE_H
#include <QString>
class monture
{
public:
    monture(QString nom);//cheval ou monstre ou autre

    QString getName() const;
    void setName(const QString &value);

    int getSpeed() const;
    void setSpeed(int value);

    void initMonture(QString nom);

    int getIsRidingOrNot() const;
    void setIsRidingOrNot(int value);

private:
    int speed;//vitesse de la monture
    int isRidingOrNot;//pour savoir si la monture est montee
    QString name;//pour savoir quel type de monture

};

#endif // MONTURE_H
