#include "Tuile.h"

using namespace std;

Tuile::Tuile(string nom, int x, int y, string propriete){
    _nom = nom;
    _skin_x = x;
    _skin_y = y;
    _propriete = propriete;
}

void Tuile::afficher(){
    cout<<_nom<<": x="<<_skin_x<<", y="<<_skin_y<<", "<<_propriete<< endl;
}

string Tuile::getNom(){
    return _nom;
};

string Tuile::getProp(){
    return _propriete;
}

int Tuile::getX(){
    return _skin_x;
}

int Tuile::getY(){
    return _skin_y;
}
