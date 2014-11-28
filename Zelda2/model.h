#ifndef MODEL_H
#define MODEL_H

#include "zelda.h"
#include "niveaux.h"



class Model
{
public:
    Model();

    Zelda *getZelda() const;
    void setZelda(Zelda *value);

    void resetModel();

    Niveaux *getNiveau() const;
    void setNiveau(Niveaux *value);


private:
    Zelda *zelda;
    Niveaux *niveau;



};

#endif // MODEL_H
