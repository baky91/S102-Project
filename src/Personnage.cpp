#include "Personnage.h"
#include "Niveau.h"


Personnage::Personnage(Image image, int skin_x, int skin_y, int x, int y){
    _image = image;
    _x = x * TAILLE_CASE;
    _y = y * TAILLE_CASE;


    _skin_x = skin_x;
    _skin_y = skin_y;
    //DIRECTIONS :  0 = Bas ; 1 = Gauche ; 2 = Droite ; 3 = Haut;
    _currentDir = 0;
    _currentAni = 1;
}

int Personnage::getDir(){
    return _currentDir;
}

int Personnage::getX(){
    return _x;
}

int Personnage::getY(){
    return _y;
}

void Personnage::dessiner(){
    _image.selectionnerRectangle((_skin_x + (_currentAni%3)-1)*TAILLE_CASE,(_skin_y + _currentDir)*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE);
    _image.dessiner(_x,_y);
}

void Personnage::allerDroite(){
    _currentDir = 2;
    if(!bordAtteint(_currentDir))
        _x += TAILLE_CASE;
}

void Personnage::allerGauche(){
    _currentDir = 1;
    if(!bordAtteint(_currentDir))
        _x -= TAILLE_CASE;
}

void Personnage::allerHaut(){
    _currentDir=3;
    if(!bordAtteint(_currentDir))
        _y -= TAILLE_CASE;
}

void Personnage::allerBas(){
    _currentDir = 0;
    if(!bordAtteint(_currentDir))
        _y += TAILLE_CASE;
}

bool Personnage::bordAtteint(int dir){
    bool estAtteint = false;
    switch (dir){
        case 0:
            return estAtteint = _y>=7*TAILLE_CASE;
            break;
        case 1:
            return estAtteint = _x<=0;
            break;
        case 2:
            return estAtteint = _x>=9*TAILLE_CASE;
            break;
        case 3:
            return estAtteint = _y<=0;
        default:
            break;
    }
}

bool Personnage::caseLibre(int dir, Niveau & niv){
    bool estLibre = true;
    switch (dir){
        case 0:
            return estLibre = niv.caseEstLibre(_x, _y+TAILLE_CASE);
            break;
        case 1:
            return estLibre = niv.caseEstLibre(_x-TAILLE_CASE, _y);
            break;
        case 2:
            return estLibre = niv.caseEstLibre(_x+TAILLE_CASE, _y);
            break;
        case 3:
            return estLibre = niv.caseEstLibre(_x, _y-TAILLE_CASE);
        default:
            break;
    }
}

void Personnage::majDirection(int dir){
    if(bordAtteint(dir)){
        switch(dir){
        case 0:
            _currentDir = 3;
            break;
        case 1:
            _currentDir = 2;
            break;
        case 2:
            _currentDir = 1;
            break;
        case 3:
            _currentDir = 0;
            break;
        default:
            break;
        }
    }
}

void Personnage::avancer(int dir){
    switch(dir){
    case 0:
        majAnimation();
        allerBas();
        break;
    case 1:
        majAnimation();
        allerGauche();
        break;
    case 2:
        majAnimation();
        allerDroite();
        break;
    case 3:
        majAnimation();
        allerHaut();
        break;
    default:
        break;
    }
}

bool Personnage::touche(Personnage ennemi){
    bool aTouche = false;
    return aTouche = _x == ennemi.getX() && _y == ennemi.getY();
}

void Personnage::setDir(int dir){
    _currentDir = dir;
}

void Personnage::setAni(int ani){
    _currentAni = ani;
}

void Personnage::majAnimation(){
    _currentAni++;
}

