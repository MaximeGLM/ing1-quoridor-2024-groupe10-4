//
// Created by maxgo on 16/11/2024.
//
#include <conio.h>
#include <stdio.h>

#include "sousprogramme.h"
// On définit le caractère des jetons
#define jeton1 190
#define jeton2 208
#define jeton3 207
#define jeton4 209
//Fonction qui vérifie la position des joueurs pour confirmer la victoire d'un joueur
int conditionvictoire(int PosXj1,int PosXj2, int PosYj3, int PosYj4) {
    if (PosXj1 == 1) {
        return 1;
    }
    if (PosXj2 == 17) {
        return 2;
    }
    if (PosYj3 == 2) {
        return 3;
    }
    if (PosYj4 == 34) {
        return 4;
    }
    return 0;
}
int DeroulementPartie2j(char * Joueur1,char * Joueur2, char nombrejoueur) {
    //On initialise les variables
    int choix = 0;
    int coordonnéesbarrières[3][20];
    int nombrebarrières=0;
    int barrièreJ1 = 10;
    int barrièreJ2 = 10;
    int DerniereAction[10] = {0};


    //On place les pions à leurs origines
    int PosXj1 = 17, PosYj1 = 18;
    int PosXj2 = 1, PosYj2 = 18;

// Boucle pour l'instant infinie pour le déroulement de la partie
    while (1) {
        //---------------------Premier joueur------------------------
        do {
            //Actualise la console
            clearConsole();
            plateau(Joueur1, nombrejoueur, jeton1, coordonnéesbarrières,nombrebarrières ,barrièreJ1);
            //Place les pions
            gotoligcol(PosXj2, PosYj2);
            printf("%c", jeton2);
            Color(10, 0);
            gotoligcol(PosXj1, PosYj1);
            printf("%c", jeton1);
            Color(15, 0);
            //Choix de l'action du joueur (blindé)
            choix = getch();
            switch (choix) {
                case '1':
                    DerniereAction[0] = 1;//On enregistre le déplacement
                    DerniereAction[1] = 1;//On enregistre le joueur
                    DerniereAction[2] = PosXj1;//On enregistre la coordonnée X
                    DerniereAction[3] = PosYj1;//On enregistre la coordonnée Y
                    Deplacement(&PosXj1, &PosYj1); break;
                case '2':
                    if (barrièreJ1 > 0 ) {
                        DerniereAction[0] = 2;//On enregistre la pause d'une barrière
                        DerniereAction[1] = 2;//On enregistre le joueur
                        barrieres(coordonnéesbarrières, &nombrebarrières);
                        barrièreJ1--;
                    } else {
                        choix = 0 ;
                    }
                break;
                case '3': break; // passe son tour
                case '4':
                    AnnulerLaDerniereAction(DerniereAction, &PosXj1, &PosYj1, &PosXj2, &PosYj2,0,0,0,0, coordonnéesbarrières, &nombrebarrières, &barrièreJ1, &barrièreJ2, 0,0);
                    break;// annuler la dernière action
                case '5': if (MenuPause() == 1) {return 0;} break;
            }
        } while (choix != '1' && choix != '2' && choix != '3' && choix != '4');

        // verification de victoire du joueur 1
        if (conditionvictoire(PosXj1, PosYj2,0,0)==1) {
            return 1;
        }
        // ------------------------------Deuxième joueur-------------------------------------
        do {
            clearConsole();
            plateau(Joueur2, nombrejoueur, jeton2, coordonnéesbarrières, nombrebarrières, barrièreJ2);
            Color(10, 0);
            gotoligcol(PosXj2, PosYj2);
            printf("%c", jeton2);
            Color(15, 0);
            gotoligcol(PosXj1, PosYj1);
            printf("%c", jeton1);
            choix = getch();
            switch (choix) {
                case '1':
                    DerniereAction[0] = 1;//On enregistre le déplacement
                    DerniereAction[1] = 2;//On enregistre le joueur
                    DerniereAction[2] = PosXj2;//On enregistre la coordonnée X
                    DerniereAction[3] = PosYj2;//On enregistre la coordonnée Y
                    Deplacement(&PosXj2, &PosYj2);
                break;
                case '2':
                    if (barrièreJ2 > 0 ) {
                        DerniereAction[0] = 2;//On enregistre la pause d'une barrière
                        DerniereAction[1] = 2;//On enregistre le joueur
                        barrieres(coordonnéesbarrières, &nombrebarrières);
                        barrièreJ2--;
                    } else {
                        choix = 0 ;
                    }
                break;
                case '3':break; // passe son tour
                case '4':
                    AnnulerLaDerniereAction(DerniereAction, &PosXj1, &PosYj1, &PosXj2, &PosYj2,0,0,0,0, coordonnéesbarrières, &nombrebarrières, &barrièreJ1, &barrièreJ2, 0,0);
                break;// annuler la dernière action
                case '5': if (MenuPause()==1) {return 0;} break;
            }
        } while (choix != '1' && choix != '2' && choix != '3' && choix != '4');

        if (conditionvictoire(PosXj1, PosXj2,0,0)==2) {
            return 2;
        }
    }
}

int DeroulementPartie4j(char *Joueur1, char *Joueur2,char* nom3, char* nom4, char nombrejoueur) {
    int victoire = 0;
    int choix = 0;
    //Initialise les positions des joueurs (les positions des joueurs 3 et 4 sont à revérifier
    int PosXj1 = 17, PosYj1 = 18;
    int PosXj2 = 1, PosYj2 = 18;
    int PosXj3 = 9, PosYj3 = 34;
    int PosXj4 = 9, PosYj4 = 2;
    //Initialise un tableau pour enregistrer les coordonnées des barrières
    int coordonnéesbarrières[3][20]={0};
    int nombrebarrières=0;
    int DerniereAction[10] = {0};
    //Initialise un compteur de barrière pour chaque joueur
    int barrièreJ1 = 5;
    int barrièreJ2 = 5;
    int barrièreJ3 = 5;
    int barrièreJ4 = 5;


    while (victoire == 0) {
        //---------------------Premier joueur------------------------
        do {
            //Actualise la console
            clearConsole();
            plateau(Joueur1, nombrejoueur, jeton1, coordonnéesbarrières, nombrebarrières, barrièreJ1);
            //Place les pions
            gotoligcol(PosXj2, PosYj2);
            printf("%c", jeton2);
            gotoligcol(PosXj3, PosYj3);
            printf("%c", jeton3);
            gotoligcol(PosXj4, PosYj4);
            printf("%c", jeton4);
            Color(10, 0);
            gotoligcol(PosXj1, PosYj1);
            printf("%c", jeton1);
            Color(15, 0);
            //Choix de l'action du joueur (blindé)

            choix = getch();
            switch (choix) {
                case '1'://Déplace le pion
                    DerniereAction[0] = 1;//On enregistre le déplacement
                    DerniereAction[1] = 1;//On enregistre le joueur
                    DerniereAction[2] = PosXj1;//On enregistre la coordonnée X
                    DerniereAction[3] = PosYj1;//On enregistre la coordonnée Y
                Deplacement(&PosXj1, &PosYj1); break;
                case '2':// Pose une barrière
                    if (barrièreJ1 > 0 ) {
                        DerniereAction[0] = 2;//On enregistre la pause d'une barrière
                        DerniereAction[1] = 1;//On enregistre le joueur
                        barrieres(coordonnéesbarrières, &nombrebarrières);
                        barrièreJ1--;
                    } else {
                        choix = 0 ;//Annuler l'action et éviter de passer le tour
                    }
                break;
                case '3': break; // passe son tour
                case '4':// Annule la dernière action
                    AnnulerLaDerniereAction(DerniereAction, &PosXj1, &PosYj1, &PosXj2, &PosYj2,&PosXj3,&PosYj3,&PosXj4,&PosYj4, coordonnéesbarrières, &nombrebarrières, &barrièreJ1, &barrièreJ2, &barrièreJ3,&barrièreJ4);
                break;// annuler la dernière action
                case '5': if (MenuPause() == 1) {return 0;} break; // Menu pause
            }
        } while (choix != '1' && choix != '2' && choix != '3' && choix != '4');

        // verification de victoire du joueur 1
        if (conditionvictoire(PosXj1, PosXj2, PosYj3, PosYj4)==1) { return 1; }
        // ------------------------------Deuxième joueur-------------------------------------
        do {
            clearConsole();
            plateau(Joueur2, nombrejoueur, jeton2, coordonnéesbarrières, nombrebarrières, barrièreJ2);
            Color(10, 0);
            gotoligcol(PosXj2, PosYj2);
            printf("%c", jeton2);
            Color(15, 0);
            gotoligcol(PosXj1, PosYj1);
            printf("%c", jeton1);
            gotoligcol(PosXj3, PosYj3);
            printf("%c", jeton3);
            gotoligcol(PosXj4, PosYj4);
            printf("%c", jeton4);
            choix = getch();
            switch (choix) {
                case '1'://Déplace le pion
                    DerniereAction[0] = 1;//On enregistre le déplacement
                DerniereAction[1] = 2;//On enregistre le joueur
                DerniereAction[2] = PosXj2;//On enregistre la coordonnée X
                DerniereAction[3] = PosYj2;//On enregistre la coordonnée Y
                Deplacement(&PosXj2, &PosYj2); break;
                case '2':// Pose une barrière
                    if (barrièreJ2 > 0 ) {
                        DerniereAction[0] = 2;//On enregistre la pause d'une barrière
                        DerniereAction[1] = 2;//On enregistre le joueur
                        barrieres(coordonnéesbarrières, &nombrebarrières);
                        barrièreJ2--;
                    } else {
                        choix = 0 ;//Annuler l'action et éviter de passer le tour
                    }
                break;
                case '3': break; // passe son tour
                case '4':// Annule la dernière action
                    AnnulerLaDerniereAction(DerniereAction, &PosXj1, &PosYj1, &PosXj2, &PosYj2,&PosXj3,&PosYj3,&PosXj4,&PosYj4, coordonnéesbarrières, &nombrebarrières, &barrièreJ1, &barrièreJ2, &barrièreJ3,&barrièreJ4);
                break;// annuler la dernière action
                case '5': if (MenuPause() == 1) {return 0;} break; // Menu pause
            }
        } while (choix != '1' && choix != '2' && choix != '3' && choix != '4');

        if (conditionvictoire(PosXj1, PosXj2, PosYj3, PosYj4)==2) { return 2; }
        //---------------------------Troisième Joueur------------------------------
        do{
            //Actualisation du plateau
            clearConsole();
            plateau(nom3, nombrejoueur, jeton3, coordonnéesbarrières,nombrebarrières, barrièreJ3);
            Color(10, 0);// on affiche le jeton du joueur 3 en couleur
            gotoligcol(PosXj3, PosYj3);
            printf("%c", jeton3);
            Color(15, 0);
            gotoligcol(PosXj1, PosYj1);
            printf("%c", jeton1);
            gotoligcol(PosXj2, PosYj2);
            printf("%c", jeton2);
            gotoligcol(PosXj4, PosYj4);
            printf("%c", jeton4);

            //Menu de choix
            choix = getch();
            switch (choix) {
                case '1'://Déplace le pion
                    DerniereAction[0] = 1;//On enregistre le déplacement
                DerniereAction[1] = 3;//On enregistre le joueur
                DerniereAction[2] = PosXj3;//On enregistre la coordonnée X
                DerniereAction[3] = PosYj3;//On enregistre la coordonnée Y
                Deplacement(&PosXj3, &PosYj3); break;
                case '2':// Pose une barrière
                    if (barrièreJ3 > 0 ) {
                        DerniereAction[0] = 2;//On enregistre la pause d'une barrière
                        DerniereAction[1] = 3;//On enregistre le joueur
                        barrieres(coordonnéesbarrières, &nombrebarrières);
                        barrièreJ3--;
                    } else {
                        choix = 0 ;//Annuler l'action et éviter de passer le tour
                    }
                break;
                case '3': break; // passe son tour
                case '4':// Annule la dernière action
                    AnnulerLaDerniereAction(DerniereAction, &PosXj1, &PosYj1, &PosXj2, &PosYj2,&PosXj3,&PosYj3,&PosXj4,&PosYj4, coordonnéesbarrières, &nombrebarrières, &barrièreJ1, &barrièreJ2, &barrièreJ3,&barrièreJ4);
                break;// annuler la dernière action
                case '5': if (MenuPause() == 1) {return 0;} break; // Menu pause
            }
        } while (choix != '1' && choix != '2' && choix != '3' && choix != '4');
        if (conditionvictoire(PosXj1, PosXj2, PosYj3, PosYj4)==3) { return 3; }

        //---------------------------Quatrième Joueur------------------------------
        do {
            //Actualisation du plateau
            clearConsole();
            plateau(nom4, nombrejoueur, jeton4, coordonnéesbarrières,nombrebarrières, barrièreJ4);
            Color(10, 0);// on affiche le jeton du joueur 4 en couleur
            gotoligcol(PosXj4, PosYj4);
            printf("%c", jeton4);
            Color(15, 0);
            gotoligcol(PosXj1, PosYj1);
            printf("%c", jeton1);
            gotoligcol(PosXj2, PosYj2);
            printf("%c", jeton2);
            gotoligcol(PosXj3, PosYj3);
            printf("%c", jeton3);

            choix = getch();
            switch (choix) {
                case '1'://Déplace le pion
                    DerniereAction[0] = 1;//On enregistre le déplacement
                DerniereAction[1] = 4;//On enregistre le joueur
                DerniereAction[2] = PosXj4;//On enregistre la coordonnée X
                DerniereAction[3] = PosYj4;//On enregistre la coordonnée Y
                Deplacement(&PosXj4, &PosYj4); break;
                case '2':// Pose une barrière
                    if (barrièreJ4 > 0 ) {
                        DerniereAction[0] = 2;//On enregistre la pause d'une barrière
                        DerniereAction[1] = 4;//On enregistre le joueur
                        barrieres(coordonnéesbarrières, &nombrebarrières);
                        barrièreJ4--;
                    } else {
                        choix = 0 ;//Annuler l'action et éviter de passer le tour
                    }
                break;
                case '3': break; // passe son tour
                case '4':// Annule la dernière action
                    AnnulerLaDerniereAction(DerniereAction, &PosXj1, &PosYj1, &PosXj2, &PosYj2,&PosXj3,&PosYj3,&PosXj4,&PosYj4, coordonnéesbarrières, &nombrebarrières, &barrièreJ1, &barrièreJ2, &barrièreJ3,&barrièreJ4);
                break;// annuler la dernière action
                case '5': if (MenuPause() == 1) {return 0;} break; // Menu pause
            }
        } while (choix != '1' && choix != '2' && choix != '3' && choix != '4');
        if (conditionvictoire(PosXj1, PosXj2, PosYj3, PosYj4) == 4) { return 4; }
    }
}