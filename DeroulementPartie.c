//
// Created by maxgo on 16/11/2024.
//
#include <conio.h>
#include <stdio.h>

#include "sousprogramme.h"

void DeroulementPartie2j(char * nom1,char * nom2, int nombrejoueur) {
    char jeton1 = 190, jeton2 = 208;
    int victoire = 0;

    int choix = 0;

    int PosXj1 = 17, PosXj2 = 1 , PosYj1 = 18, PosYj2 = 18;


    while (victoire!= 1) {
        clearConsole();
        plateau(nom1, nombrejoueur, jeton1);
        gotoligcol(PosXj2, PosYj2);
        printf("%c", jeton2);
        gotoligcol(PosXj1, PosYj1);
        printf("%c", jeton1);
        choix = getch();
        switch (choix) {
            case '1': Deplacement(&PosXj1, &PosYj1); break;
            case '2': barrieres(); break;
            case '3': ; break;// sauter son tour
            case '4': ; break;// annuler la dernière action
        }
        clearConsole();
        plateau(nom1, nombrejoueur, jeton2);
        gotoligcol(PosXj2, PosYj2);
        printf("%c", jeton2);
        gotoligcol(PosXj1, PosYj1);
        printf("%c", jeton1);
        switch (choix) {
            case '1': Deplacement(&PosXj2, &PosYj2); break;
            case '2': barrieres(); break;
            case '3': ; break;// sauter son tour
            case '4': ; break;// annuler la dernière action
        }

    }
}