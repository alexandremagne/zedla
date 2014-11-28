#ifndef NIVEAUX_H
#define NIVEAUX_H

#include <vector>
#include <QDebug>
#include <QSound>
#include "ennemis.h"
#include "quete.h"
#include "item.h"
#include "final_boss_.h"

using namespace std;

class Niveaux
{


public:
    Niveaux();
    void chargerNiveau();
    void setMatrice(int tab[15][30]);
    void deleteMonstre(int i);
    void ajouterItem(int posX,int posY, QString s);
    void deleteItem(int i);
    void ajouterMonstre(int posX, int posY, QString direction, QString nom);
    void ajouterProjectileLancerParUnMonstre(Ennemis *ennemi);
    void changerNiveau3quandLeMonstreEstTuer();



    vector<vector<int> > getCarteMatrice() const;
    void setCarteMatrice(const vector<vector<int> > &value);

    int getNiveauActuel() const;
    void setNiveauActuel(int value);

    Ennemis *getEnnemi() const;
    void setEnnemi(Ennemis *value);


    //QSound *getMusique() const;
    //void setMusique(QSound *value);

    vector<Ennemis*> getMonstres() const;
    void setMonstres(const vector<Ennemis*> &value);

    QSound *getMusique() const;
    void setMusique(QSound *value);

    Quete *getQuete() const;
    void setQuete(Quete *value);

    vector<item *> getMapItems() const;
    void setMapItems(const vector<item *> &value);

    int getStatusPontLevis() const;
    void setStatusPontLevis(int value);

private:
    int niveauActuel;
    int statusPontLevis;
    vector<vector<int> > carteMatrice; // Notre carte
    Ennemis *ennemi;
     Quete *quete;

    vector<Ennemis*> monstres;


    QSound *musique;

     vector<item *> mapItems;

};

#endif // NIVEAUX_H
