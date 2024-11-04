//
// Created by maxgo on 31/10/2024.
//
#include <stdio.h>
#include "sousprogramme.h"
#include <conio.h>

int barrieres(){
    int i;
    int positionx = 16;
    int positiony = 2;
    int detection;
    int changementdaxes = 0;
    gotoligcol(positiony - 1, positionx);
    printf("%c", 186);
    gotoligcol(positiony, positionx);
    printf("%c", 186);
    gotoligcol(positiony + 1, positionx);
    printf("%c", 186);
    do {
        detection = _getch();
        if (detection == '2') {
            if (positiony < 16) {

                gotoligcol(positiony - 1, positionx);
                printf("%c", 32);
                gotoligcol(positiony, positionx);
                printf("%c", 32);
                gotoligcol(positiony + 1, positionx);
                printf("%c", 32);
                positiony = positiony + 2;
                gotoligcol(positiony - 1, positionx);
                printf("%c", 186);
                gotoligcol(positiony, positionx);
                printf("%c", 186);
                gotoligcol(positiony + 1, positionx);
                printf("%c", 186);
            }
        }

        if(detection == '8'){

            if(positiony > 3) {

                gotoligcol(positiony - 1, positionx);
                printf("%c", 32);
                gotoligcol(positiony, positionx);
                printf("%c", 32);
                gotoligcol(positiony + 1, positionx);
                printf("%c", 32);
                positiony = positiony - 2;
                gotoligcol(positiony - 1, positionx);
                printf("%c", 186);
                gotoligcol(positiony, positionx);
                printf("%c", 186);
                gotoligcol(positiony + 1, positionx);
                printf("%c", 186);
            }

        }

        if (detection == '4') {
            if(positionx > 4) {
                gotoligcol(positiony, positionx - 2);
                printf("%c", 32);
                gotoligcol(positiony, positionx);
                printf("%c", 32);
                gotoligcol(positiony, positionx + 2);
                printf("%c", 32);
                positionx = positionx - 4;
                gotoligcol(positiony, positionx - 2);
                printf("%c", 205);
                gotoligcol(positiony, positionx);
                printf("%c", 205);
                gotoligcol(positiony, positionx + 2);
                printf("%c", 205);
            }
        }
        if (detection == '6') {
            if(positionx < 32) {
                gotoligcol(positiony, positionx - 2);
                printf("%c", 32);
                gotoligcol(positiony, positionx);
                printf("%c", 32);
                gotoligcol(positiony, positionx + 2);
                printf("%c", 32);
                positionx = positionx + 4;
                gotoligcol(positiony, positionx - 2);
                printf("%c", 205);
                gotoligcol(positiony, positionx);
                printf("%c", 205);
                gotoligcol(positiony, positionx + 2);
                printf("%c", 205);
            }
        }
    }while(detection != '\r');
}
