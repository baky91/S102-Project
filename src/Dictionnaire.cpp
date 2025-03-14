#include <vector>
#include <fstream>
#include <iostream>
#include "Tuile.h"
#include "Dictionnaire.h"

using namespace std;

Dictionnaire::Dictionnaire(const string& nomDuFichier){
    //infos du fichier
    string nom;
    int x;
    int y;
    string propriete;

    int nbLignes;

    //parcours du fichier
    ifstream ific(nomDuFichier.c_str(), ios::in); // ouverture du fichier en lecture
    if(!ific.is_open())
        throw string("l'ouverture du fichier a echoue : " + nomDuFichier);
    ific >> nbLignes;
//    while(!ific.eof()){ //tant qu'on a pas atteint la fin du fichier
    for(int i=1;i<=nbLignes;i++){
        //lecture des infos pour chaque objet
        ific >> nom >> x >> y >> propriete;

        _lesTuiles.push_back(Tuile(nom,x,y,propriete));
    }
    ific.close();
}

void Dictionnaire::afficher(){
    cout<<"Liste des tuiles: "<< endl;
    for(int i=0;i<_lesTuiles.size();i++)
        _lesTuiles[i].afficher();
}

// RECHERCHE DICHOTOMIQUE
bool Dictionnaire::recherche(string nom, Tuile & tuile){
    bool trouve = false;
    int debut=0, milieu, fin=_lesTuiles.size()-1;
    while(!trouve && debut <= fin){
        milieu = (debut+fin)/2;
        trouve = (_lesTuiles[milieu].getNom() == nom);
        if(trouve)
            tuile = _lesTuiles[milieu];
        else{
            if(_lesTuiles[milieu].getNom() > nom)
                fin = milieu-0;
            else
                debut = milieu+1;
        }
    }
    return trouve;
}
