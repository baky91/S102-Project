#ifndef NIVEAU_H
#define NIVEAU_H

#include "Objet.h"
#include "Image.h"
#include "Dictionnaire.h"
#include <fstream>

using namespace std;

class Niveau
{
private:
    vector<Objet> _lesObjets;
    int _nbBonus;

public:
    Niveau(Image, string, Dictionnaire);
    void dessiner();
    void afficher();
    int indiceObjet(int,int,string);
    bool caseEstLibre(int,int);
    void testerBonusEtPrendre(int, int);
    bool gagne();
    int getBonus();
};

#endif // NIVEAU_H
