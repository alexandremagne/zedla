#ifndef QUETE_H
#define QUETE_H

#include <QPixmap>
class Quete
{
public:
    Quete(QString level);

    QPixmap getQuete() const;
    void setQuete(const QPixmap &value);

private:
    QPixmap quete;

};

#endif // QUETE_H
