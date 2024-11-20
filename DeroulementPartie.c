//
// Created by maxgo on 16/11/2024.
//
#include <conio.h>
#include <stdio.h>

#include "sousprogramme.h"
#define jeton1 190
#define jeton2 208
#define jeton3 207
#define jeton4 209
//Fonction qui vérifie la position des joueurs pour confirmer la victoire d'un joueur
//On peut ajouter un écran de fin
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
void DeroulementPartie2j(char * nom1,char * nom2, char nombrejoueur) {
    //On initialise les variables
    int victoire = 0;
    int choix = 0;
    int coordonnéesbarrières[3][20];
    int nombrebarrières=0;


    //On place les pions à leurs origines
    int PosXj1 = 17, PosYj1 = 18;
    int PosXj2 = 1, PosYj2 = 18;

// Boucle pour l'instant infinie pour le déroulement de la partie
    while (victoire == 0) {
        //Actualise la console
        clearConsole();
        plateau(nom1, nombrejoueur, jeton1, coordonnéesbarrières, nombrebarrières);
        //Place les pions
        gotoligcol(PosXj2, PosYj2);
        printf("%c", jeton2);
        gotoligcol(PosXj1, PosYj1);
        printf("%c", jeton1);

        do {
            choix = getch();
            switch (choix) {
                case '1': Deplacement(&PosXj1, &PosYj1); break;
                case '2': barrieres(coordonnéesbarrières, &nombrebarrières); break;
                case '4': ; break;// annuler la dernière action
                case '5': Menupause(); break;//lenu pause
            }
            if (choix == '3') break;// passer son tour
        } while (choix != '1' && choix != '2' && choix != '3' && choix != '4'&& choix != '5');// annuler la dernière action

        if (conditionvictoire(PosXj1, PosYj2,0,0)==1) {
            return;
        }
        clearConsole();
        plateau(nom2, nombrejoueur, jeton2, coordonnéesbarrières, nombrebarrières);
        gotoligcol(PosXj2, PosYj2);
        printf("%c", jeton2);
        gotoligcol(PosXj1, PosYj1);
        printf("%c", jeton1);
        do {
            choix = getch();
            switch (choix) {
                case '1': Deplacement(&PosXj2, &PosYj2); break;
                case '2': barrieres(coordonnéesbarrières, &nombrebarrières); break;
                case '4': ; break;// annuler la dernière action
            }
            if (choix == '3') break;// passer son tour
        } while (choix != '1' && choix != '2' && choix != '3' && choix != '4');
        if (conditionvictoire(PosXj1, PosXj2,0,0)==2) {
            return;
        }
    }
}

void DeroulementPartie4j(char * nom1,char * nom2,char * nom3, char * nom4, char NombreJoueur) {
    int victoire = 0;
    int choix = 0;
    //Initialise les positions des joueurs (les positions des joueurs 3 et 4 sont à revérifier
    int PosXj1 = 17, PosYj1 = 18;
    int PosXj2 = 1, PosYj2 = 18;
    int PosXj3 = 9, PosYj3 = 34;
    int PosXj4 = 9, PosYj4 = 2;
    //Initialise un tableau pour enregistrer les coordonnées des barrières
    int coordonnéesbarrières[3][20];
    int nombrebarrières=0;
    //Initialise un compteur de barrière pour chaque joueur
    int barrièreJ1 = 0;
    int barrièreJ2 = 0;
    int barrièreJ3 = 0;
    int barrièreJ4 = 0;


    while (victoire == 0) {
        // On nettoie la console et on affiche le plateau, les pions, les barrières
        clearConsole();
        plateau(nom1, NombreJoueur, jeton1,coordonnéesbarrières, nombrebarrières);
        ActualiserPositionPions(PosXj1,PosYj1,PosXj2,PosYj2,PosXj3,PosYj3,PosXj4,PosYj4,jeton1,jeton2,jeton3,jeton4);
        gotoligcol(26, 0);


        //Saisit du choix du joueur
        do {
            choix = getch();
            switch (choix) {
                case '1': Deplacement(&PosXj1, &PosYj1); break;
                case '2': barrieres(coordonnéesbarrières, &nombrebarrières); break;
                case '4': ; break;// annuler la dernière action
            }
            if (choix == '3') break;// passer son tour
        } while (choix != '1' && choix != '2' && choix != '3' && choix != '4');
        // verification de victoire
        if (conditionvictoire(PosXj1, PosXj2,PosYj3,PosYj4)==1) {
            return;
        }

        //---------------------------Deuxième tour------------------------------
        clearConsole();
        plateau(nom2, NombreJoueur, jeton2,coordonnéesbarrières, nombrebarrières);        ActualiserPositionPions(PosXj1,PosYj1,PosXj2,PosYj2,PosXj3,PosYj3,PosXj4,PosYj4,jeton1,jeton2,jeton3,jeton4);
        ActualiserPositionPions(PosXj1,PosYj1,PosXj2,PosYj2,PosXj3,PosYj3,PosXj4,PosYj4,jeton1,jeton2,jeton3,jeton4);

        do {
            choix = getch();
            switch (choix) {
                case '1': Deplacement(&PosXj1, &PosYj1); break;
                case '2': barrieres(coordonnéesbarrières, &nombrebarrières); break;
                case '4': ; break;// annuler la dernière action
            }
            if (choix == '3') break;// passer son tour
        } while (choix != '1' && choix != '2' && choix != '3' && choix != '4');
        if (conditionvictoire(PosXj1, PosXj2,0,0)==2) {
            return;
        }

        //---------------------------Troisième tour------------------------------
        clearConsole();
        plateau(nom3, NombreJoueur, jeton3, coordonnéesbarrières, nombrebarrières);
        ActualiserPositionPions(PosXj1,PosYj1,PosXj2,PosYj2,PosXj3,PosYj3,PosXj4,PosYj4,jeton1,jeton2,jeton3,jeton4);

        do {
            choix = getch();
            switch (choix) {
                case '1': Deplacement(&PosXj1, &PosYj1); break;
                case '2': barrieres(coordonnéesbarrières, &nombrebarrières); break;
                case '4': ; break;// annuler la dernière action
            }
            if (choix == '3') break;// passer son tour
        } while (choix != '1' && choix != '2' && choix != '3' && choix != '4');
        if (conditionvictoire(PosXj1, PosXj2, PosYj3, PosYj4)==3) {
            return;
        }

        //---------------------------Quatrième tour------------------------------

        clearConsole();
        plateau(nom4, NombreJoueur, jeton4, coordonnéesbarrières, nombrebarrières);
        ActualiserPositionPions(PosXj1,PosYj1,PosXj2,PosYj2,PosXj3,PosYj3,PosXj4,PosYj4,jeton1,jeton2,jeton3,jeton4);

        do {
            choix = getch();
            switch (choix) {
                case '1': Deplacement(&PosXj1, &PosYj1); break;
                case '2': barrieres(coordonnéesbarrières, &nombrebarrières); break;
                case '4': ; break;// annuler la dernière action
            }
            if (choix == '3') break;// passer son tour
        } while (choix != '1' && choix != '2' && choix != '3' && choix != '4');
        if (conditionvictoire(PosXj1, PosXj2, PosYj3, PosYj4)==4) {
            return;
        }
    }
}