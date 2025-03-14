#include "Niveau.h"
#include <iostream>

// CONSTRUCTEUR
Niveau::Niveau(Image image, string nomFichier, Dictionnaire dico){
    //infos du fichier
    string nomObj;
    int x;
    int y;

    int nbLignes;
    _nbBonus = 0;

    //parcours du fichier
    ifstream ific(nomFichier.c_str(), ios::in); // ouverture du fichier en lecture
    if(!ific.is_open())
        throw string("l'ouverture du fichier a echoue : " + nomFichier);
    ific >> nbLignes;
    for(int i=1;i<=nbLignes;i++){
        //lecture des infos pour chaque objet
        ific >> nomObj >> x >> y;

        _lesObjets.push_back(Objet(image, nomObj, dico,x,y));
        if(_lesObjets.back().getProp() == "bonus")
            _nbBonus++;
    }
    ific.close();
}

void Niveau::afficher(){
    for(int i=0;i<_lesObjets.size();i++)
        _lesObjets[i].afficher();
    cout<<_nbBonus<< endl;
}

void Niveau::dessiner(){
    for(int i=0;i<_lesObjets.size();i++){
        if(_lesObjets[i].getProp() != "cache")
            _lesObjets[i].dessiner();
    }

}

int Niveau::indiceObjet(int x, int y, string propriete){
    int indice = -1;
    for(int i=0;i<_lesObjets.size();i++){
        if((_lesObjets[i].getProp() == propriete) && (_lesObjets[i].getX() == (x/TAILLE_CASE)) && (_lesObjets[i].getY() == (y/TAILLE_CASE))){
            indice = i;
        }
    }
    return indice;
}

bool Niveau::caseEstLibre(int x,int y){
    bool estLibre = true;
//    for(int i=0;i<_lesObjets.size();i++){
//        if((_lesObjets[i].getProp() == "solide") && (_lesObjets[i].getX() == (x/TAILLE_CASE)) && (_lesObjets[i].getY() == (y/TAILLE_CASE))){
//            estLibre = false;
//        }
//    }
    int indice = indiceObjet(x,y,"solide");
    if(indice != -1)
        estLibre = false;

    return estLibre;
}

void Niveau::testerBonusEtPrendre(int x, int y){
//    for(int i=0;i<_lesObjets.size();i++){
//        if((_lesObjets[i].getProp() == "bonus") && (_lesObjets[i].getX() == (x/TAILLE_CASE)) && (_lesObjets[i].getY() == (y/TAILLE_CASE))){
//            if(_nbBonus>0)
//                _nbBonus--;
//            _lesObjets[i].cacher();
//        }
//    }
    int indice = indiceObjet(x,y,"bonus");
    if(indice != -1){
        _nbBonus--;
        _lesObjets[indice].cacher();
    }
}

bool Niveau::gagne(){
    bool aGagne = false;
    return aGagne = _nbBonus == 0;
}

int Niveau::getBonus(){
    return _nbBonus;
}
