#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include "Image.h"
#include "Niveau.h"

class Personnage{
private:
    Image _image;
    int _x;
    int _y;
    int _currentDir;
    int _currentAni;
    int _skin_x;
    int _skin_y;

public:
    //constructeur vide
//    Personnage();

    //constructeur
    Personnage(Image, int, int, int=0, int=0);

    //getters
    int getDir();
    int getX();
    int getY();

    //Méthodes
    void dessiner();
    void allerDroite();
    void allerGauche();
    void allerHaut();
    void allerBas();
    bool bordAtteint(int);
    bool caseLibre(int, Niveau &);
    void setDir(int);
    void setAni(int);

    void majDirection(int);         // utilisé seulement pour les ennemis
    void majAnimation();
    void avancer(int);
    bool touche(Personnage);
};


#endif // PERSONNAGE_H_INCLUDED
