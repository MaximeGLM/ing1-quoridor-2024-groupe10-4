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
int conditionvictoire(int PosXj1,int PosXj2) {
    if (PosXj1 == 1) {
        return 1;
    }

    if (PosXj2 == 17) {
        return 2;
    }

    return 0;
}
void DeroulementPartie2j(char * nom1,char * nom2, char nombrejoueur) {
    int victoire = 0;
    int choix = 0;
    int PosXj1 = 17, PosXj2 = 1 , PosYj1 = 18, PosYj2 = 18;
    int coordonnéesbarrières[3][20];
    int nombrebarrières=0;


    while (victoire == 0) {
        clearConsole();
        plateau(nom1, nombrejoueur, jeton1);
        gotoligcol(PosXj2, PosYj2);
        printf("%c", jeton2);
        gotoligcol(PosXj1, PosYj1);
        printf("%c", jeton1);
        afficherBarrières(coordonnéesbarrières, nombrebarrières);
        choix = getch();
        switch (choix) {
            case '1': Deplacement(&PosXj1, &PosYj1); break;
            case '2': barrieres(coordonnéesbarrières, &nombrebarrières); break;
            case '3': ; break;// sauter son tour
            case '4': ; break;// annuler la dernière action
        }
        if (conditionvictoire(PosXj1, PosYj2)==1) {
            return;
        }
        clearConsole();
        plateau(nom2, nombrejoueur, jeton2);
        gotoligcol(PosXj2, PosYj2);
        printf("%c", jeton2);
        gotoligcol(PosXj1, PosYj1);
        printf("%c", jeton1);
        afficherBarrières(coordonnéesbarrières, nombrebarrières);
        choix = getch();
        switch (choix) {
            case '1': Deplacement(&PosXj2, &PosYj2); break;
            case '2': barrieres(coordonnéesbarrières, &nombrebarrières); break;
            case '3': ; break;// sauter son tour
            case '4': ; break;// annuler la dernière action
        }
        if (conditionvictoire(PosXj1, PosXj2)==2) {
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
        clearConsole();
        plateau(nom1, NombreJoueur, jeton1);
        afficherBarrières(coordonnéesbarrières, nombrebarrières);
        gotoligcol(PosXj1, PosYj1);
        printf("%c", jeton1);
        gotoligcol(PosXj2, PosYj2);
        printf("%c", jeton2);
        gotoligcol(PosXj3, PosYj3);
        printf("%c", jeton3);
        gotoligcol(PosXj4, PosYj4);
        printf("%c", jeton4);

        choix = getch();
        switch (choix) {
            case '1': Deplacement(&PosXj1, &PosYj1); break;
            case '2': barrieres(coordonnéesbarrières, &nombrebarrières); break;
            case '3': ; break;// sauter son tour
            case '4': ; break;// annuler la dernière action
        }
        if (conditionvictoire(PosXj1, PosYj2)==1) {
            return;
        }
        clearConsole();
        plateau(nom2, NombreJoueur, jeton2);
        afficherBarrières(coordonnéesbarrières, nombrebarrières);
        gotoligcol(PosXj1, PosYj1);
        printf("%c", jeton1);
        gotoligcol(PosXj2, PosYj2);
        printf("%c", jeton2);
        gotoligcol(PosXj3, PosYj3);
        printf("%c", jeton3);
        gotoligcol(PosXj4, PosYj4);
        printf("%c", jeton4);

        choix = getch();
        switch (choix) {
            case '1': Deplacement(&PosXj2, &PosYj2); break;
            case '2': barrieres(coordonnéesbarrières, &nombrebarrières); break;
            case '3': ; break;// sauter son tour
            case '4': ; break;// annuler la dernière action
        }
        if (conditionvictoire(PosXj1, PosXj2)==2) {
            return;
        }
        clearConsole();
        plateau(nom3, NombreJoueur, jeton3);
        afficherBarrières(coordonnéesbarrières, nombrebarrières);
        gotoligcol(PosXj1, PosYj1);
        printf("%c", jeton1);
        gotoligcol(PosXj2, PosYj2);
        printf("%c", jeton2);
        gotoligcol(PosXj3, PosYj3);
        printf("%c", jeton3);
        gotoligcol(PosXj4, PosYj4);
        printf("%c", jeton4);

        choix = getch();
        switch (choix) {
            case '1': Deplacement(&PosXj3, &PosYj3); break;
            case '2': barrieres(coordonnéesbarrières, &nombrebarrières); break;
            case '3': ; break;// sauter son tour
            case '4': ; break;// annuler la dernière action
        }
        if (conditionvictoire(PosXj1, PosXj2)==2) {
            return;
        }
        clearConsole();
        plateau(nom4, NombreJoueur, jeton4);
        afficherBarrières(coordonnéesbarrières, nombrebarrières);
        gotoligcol(PosXj1, PosYj1);
        printf("%c", jeton1);
        gotoligcol(PosXj2, PosYj2);
        printf("%c", jeton2);
        gotoligcol(PosXj3, PosYj3);
        printf("%c", jeton3);
        gotoligcol(PosXj4, PosYj4);
        printf("%c", jeton4);

        choix = getch();
        switch (choix) {
            case '1': Deplacement(&PosXj4, &PosYj4); break;
            case '2': barrieres(coordonnéesbarrières, &nombrebarrières); break;
            case '3': ; break;// sauter son tour
            case '4': ; break;// annuler la dernière action
        }
        if (conditionvictoire(PosXj1, PosXj2)==2) {
            return;
        }
    }
}