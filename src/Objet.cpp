#include "Objet.h"

Objet::Objet(Image image, string nom_obj, Dictionnaire dico, int x, int y){
    Tuile t1;

    dico.recherche(nom_obj, t1);
    _image = image;

    _skin_x = t1.getX();
    _skin_y = t1.getY();

    _x = x;
    _y = y;
    _propriete = t1.getProp();
}

void Objet::dessiner(){
    _image.selectionnerRectangle(_skin_x*TAILLE_CASE, _skin_y*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    _image.dessiner(_x*TAILLE_CASE,_y*TAILLE_CASE);
}

void Objet::afficher(){
    cout<<_skin_x<<" "<<_skin_y<<" "<<_propriete<< endl;
}

string Objet::getProp(){
    return _propriete;
}

int Objet::getX(){
    return _x;
}

int Objet::getY(){
    return _y;
}

void Objet::cacher(){
    _propriete = "cache";
}
