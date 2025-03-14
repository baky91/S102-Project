#ifndef OBJET_H
#define OBJET_H

#include "Image.h"
#include "Dictionnaire.h"

using namespace std;

class Objet
{
private:
    Image _image;
    int _x;
    int _y;
    string _propriete;

    int _skin_x;
    int _skin_y;

public:
    Objet(Image, string, Dictionnaire, int=0, int=0);
    void dessiner();
    void afficher();
    string getProp();
    int getX();
    int getY();
    void cacher();
};

#endif // OBJET_H
