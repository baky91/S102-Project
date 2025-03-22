#include <vector>

#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Dictionnaire.h"
#include "Niveau.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
    // Initialisation du jeu
    Moteur moteur("Mon super jeu vidéo");

    // TODO: charger images, creer personnages, etc.

    //chargement des images, niveau et dictionnaire
    Image objets(moteur, "assets/objets.png");
    Dictionnaire dictionnaire("assets/dictionnaire.txt");
    Niveau niveau1(objets, "assets/niveau1.txt", dictionnaire);
    Image chiffres(moteur, "assets/caracteres.png");
    Image personnages(moteur, "assets/personnages.png");
    Image gameover(moteur, "assets/gameover.png");
    Image bravo(moteur, "assets/bravo.png");

    // Directions
    // 0 = Bas ; 1 = Gauche ; 2 = Droite ; 3 = Haut;

    //personnages-----------
    Personnage perso1(personnages,7,0,1,1);
    Personnage ennemi1(personnages,10,0,5,1);
    Personnage ennemi2(personnages,1,4,1,5);
    int dir1, dir2;         //  directions des deux ennemis qui seront actualisées dans chaque boucles du jeu

    bool quitter = false;
    //  bool coffreouvert = false;

    // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
    // (en general, 60 fois par seconde)
    while (!quitter)
    {

    // I. Gestion des evenements
    Evenement evenement = moteur.evenementRecu();
    while (evenement != AUCUN)
    {
        switch (evenement)
        {
//         QUITTER = croix de la fenetre ou Echap
        case QUITTER_APPUYE:
            quitter = true;
            break;
//  DEPLACEMENT DU PERSONNAGE
        case GAUCHE_APPUYE:
            perso1.setDir(1);
            if(perso1.caseLibre(1, niveau1))
                perso1.avancer(1);
            break;
        case DROITE_APPUYE:
            perso1.setDir(2);
            if(perso1.caseLibre(2, niveau1))
                perso1.avancer(2);
            break;
        case HAUT_APPUYE:
            perso1.setDir(3);
            if(perso1.caseLibre(3, niveau1))
                perso1.avancer(3);
            break;
        case BAS_APPUYE:
            perso1.setDir(0);
            if(perso1.caseLibre(0, niveau1))
                perso1.avancer(0);
            break;
//  REINITIALISATION DES ANIMATIONS LORSQUE QUE LE JOUEUR RELACHE LA TOUCHE
        case GAUCHE_RELACHE:
            perso1.setAni(1);
            break;
        case DROITE_RELACHE:
            perso1.setAni(1);
            break;
        case HAUT_RELACHE:
            perso1.setAni(1);
            break;
        case BAS_RELACHE:
            perso1.setAni(1);
            break;

        default:
            break;
        }

        evenement = moteur.evenementRecu();
    }


    // II. Mise à jour de l'état du jeu


    // TODO: faire bouger vos personnages, etc.



    if(moteur.animationsAmettreAjour()){

        dir1 = rand() % 4;
        ennemi1.majDirection(dir1);
        if(ennemi1.caseLibre(dir1, niveau1))
            ennemi1.avancer(dir1);

        dir2 = rand() % 4;
        ennemi2.majDirection(dir2);
        if(ennemi2.caseLibre(dir2, niveau1))
            ennemi2.avancer(dir2);
    }


    // III. Generation de l'image à afficher


//    moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

    // TODO: afficher vos personnages, objets, etc.
    niveau1.dessiner();
    perso1.dessiner();
    ennemi1.dessiner();
    ennemi2.dessiner();


    niveau1.testerBonusEtPrendre(perso1.getX(), perso1.getY());


// AFFICHAGE DE L'IMAGE INDIQUANT LE NOMBRE DE BONUS RAMASSE PAR LE JOUEUR
    switch(niveau1.getBonus()){
    case 0:
        chiffres.selectionnerRectangle(3*TAILLE_CASE,0,TAILLE_CASE,TAILLE_CASE);
        chiffres.dessiner(9*TAILLE_CASE,0);
        break;
    case 1:
        chiffres.selectionnerRectangle(2*TAILLE_CASE,0,TAILLE_CASE,TAILLE_CASE);
        chiffres.dessiner(9*TAILLE_CASE,0);
        break;
    case 2:
        chiffres.selectionnerRectangle(1*TAILLE_CASE,0,TAILLE_CASE,TAILLE_CASE);
        chiffres.dessiner(9*TAILLE_CASE,0);
        break;
    case 3:
        chiffres.selectionnerRectangle(0,0,TAILLE_CASE,TAILLE_CASE);
        chiffres.dessiner(9*TAILLE_CASE,0);
        break;
    case 4:
        chiffres.selectionnerRectangle(4*TAILLE_CASE,1*TAILLE_CASE,TAILLE_CASE,TAILLE_CASE);
        chiffres.dessiner(9*TAILLE_CASE,0);
        break;
    default:
        break;
    }

    /*
      Affiche l'image en se cadencant sur la frequence de
      rafraichissement de l'ecran (donc va en general mettre le
      programme en pause jusqu'a ce que l'ecran soit rafraichi). En
      general, 60 images fois par seconde, mais ca peut dependre du
      materiel
    */

//--- CONDITIONS DE SORTIE DE LA BOUCLE DU JEU

    if(perso1.touche(ennemi1) || perso1.touche(ennemi2) || niveau1.gagne()){
        quitter = true;
    }

    moteur.finaliserRendu();

    }
    // SORTIE DE LA BOUCLE

// SI ON GAGNE OU ON PERD ON ATTEND UN PEU POUR NE PAS AFFICHER L'IMAGE DE FIN DIRECTEMENT
    if(perso1.touche(ennemi1) || perso1.touche(ennemi2) || niveau1.gagne())
        moteur.attendre(0.5);

    moteur.initialiserRendu();
    moteur.finaliserRendu();

// DANS LE CAS OU LE JOUEUR A PERDU
    if(perso1.touche(ennemi1) || perso1.touche(ennemi2)){
        gameover.dessiner(2*TAILLE_CASE,3*TAILLE_CASE);
        moteur.finaliserRendu();
    }

// DANS LE CAS OU LE JOUEUR A GAGNE
    if(niveau1.gagne()){
        bravo.dessiner(2*TAILLE_CASE,3*TAILLE_CASE);
        moteur.finaliserRendu();
    }


    if(perso1.touche(ennemi1) || perso1.touche(ennemi2) || niveau1.gagne())
        moteur.attendre(3);

    return 0;
}
