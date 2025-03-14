#ifndef TUILE_H_INCLUDED
#define TUILE_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Tuile{
private:
    string _nom;
    int _skin_x;
    int _skin_y;
    string _propriete;
public:
//constructeur
    Tuile(string="aucun", int=0, int=0, string="aucun");

//méthodes
    void afficher();
    string getNom();
    string getProp();
    int getX();
    int getY();
};


#endif // TUILE_H_INCLUDED
