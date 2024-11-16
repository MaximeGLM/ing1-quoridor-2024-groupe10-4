//
// Created by maxgo on 16/11/2024.
//
#include <conio.h>
#include <stdio.h>

#include "sousprogramme.h"
#define jeton1 190
#define jeton2 208
int conditionvictoire(int PosXj1,int PosXj2) {
    if (PosXj1 == 1) {
        return 1;
    }

    if (PosXj2 == 1) {
        return 2;
    }

    return 0;
}
void DeroulementPartie2j(char * nom1,char * nom2, int nombrejoueur) {
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
            return 1;
        }
        clearConsole();
        plateau(nom1, nombrejoueur, jeton2);
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
        if (conditionvictoire(PosXj1, PosYj2)==2) {
            return 2;
        }
    }
}