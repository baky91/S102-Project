#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED

#include <vector>
#include <iostream>
#include "Tuile.h"

using namespace std;

class Dictionnaire{
private:
    vector<Tuile> _lesTuiles;

public:
//constructeur
    Dictionnaire(const string& nomDuFichier);

//méthodes
    void afficher();
    bool recherche(string, Tuile &);        // RECHERCHE DICHOTOMIQUE
};


#endif // DICTIONNAIRE_H_INCLUDED
