//
// Created by maxgo on 30/10/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include "sousprogramme.h"
#include <conio.h>

int main() {

    char nj;
    char nom1[15];
    char nom2[15];
    char j1 = 190;
    char j2 = 208;
    int lig1 = 17, col1 = 18;
    int lig2 = 1, col2 = 18;
    int coordonnéesbarrières[3][20];
    int nombrebarrière = 0;

    menu(nom1, nom2, &nj);
    clearConsole();
    int tour = 1;
    plateau(nom1, nj, j1);
    gotoligcol(lig2, col2);
    printf("%c", j2);
    gotoligcol(lig1, col1);
    printf("%c", j1);

    barrieres(coordonnéesbarrières, nombrebarrière);
    nombrebarrière = nombrebarrière + 1;

    // Game loop
    while (1) {

        if (tour == 1) {

            char haut = deplacement(&lig1, &col1);
            if (haut) {

                if (lig1 == lig2 && col1 == col2) {

                    if (haut == '8' && ((lig1 - 2) > 1)) {
                        lig1 -= 2;
                    } else if (haut == '4' && ((col1 - 4) > 2)) {
                        col1 -= 4;
                    } else if (haut == '6' && ((col1 + 4) < 34)) {
                        col1 += 4;
                    } else if (haut == '2' && ((lig1 + 2) < 17)) {
                        lig1 += 2;
                    }
                }

                clearConsole();
                plateau(nom2, nj, j2);
                gotoligcol(lig1, col1);
                printf("%c", j1);
                gotoligcol(lig2, col2);
                printf("%c", j2);
                tour = 2;
            }

        } else if (tour == 2) {


            char bas = deplacement2(&lig2, &col2);
            if (bas) {

                if (lig1 == lig2 && col1 == col2) {

                    if (bas == 'w' && ((lig2 - 2) > 1)) {
                        lig2 -= 2;
                    } else if (bas == 'a' && ((col2 - 4) > 2)) {
                        col2 -= 4;
                    } else if (bas == 'd' && ((col2 + 4) < 34)) {
                        col2 += 4;
                    } else if (bas == 's' && ((lig2 + 2) < 17)) {
                        lig2 += 2;
                    }
                }

                clearConsole();
                plateau(nom1, nj, j1);
                gotoligcol(lig2, col2);
                printf("%c", j2);
                gotoligcol(lig1, col1);
                printf("%c", j1);
                tour = 1;
            }
        }


#ifdef _WIN32
        Sleep(5);
#else
        usleep(100000);
#endif
    }
    return 0;
}