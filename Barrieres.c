//
// Created by maxgo on 31/10/2024.
//
#include <stdio.h>
#include "sousprogramme.h"
#include <conio.h>

void EffacerLaBarrière(int y,int x) {
    gotoligcol(y, x + 2);
    printf("%c", 32);
    gotoligcol(y, x - 2);
    printf("%c", 32);
    gotoligcol(y - 1, x);
    printf("%c", 32);
    gotoligcol(y, x);
    printf("%c", 32);
    gotoligcol(y + 1, x);
    printf("%c", 32);
}

void AfficherLaBarrièreVerticale(int y,int x) {
    gotoligcol(y - 1, x);
    printf("%c", 186);
    gotoligcol(y, x);
    printf("%c", 186);
    gotoligcol(y + 1, x);
    printf("%c", 186);
}

void AfficherLaBarrièreHorizontale(int y,int x) {
    gotoligcol(y, x - 2);
    printf("%c", 205);
    gotoligcol(y, x);
    printf("%c", 205);
    gotoligcol(y, x + 2);
    printf("%c", 205);
}

int barrieres(){

    int positionx = 16;
    int positiony = 2;
    int detection;

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
                EffacerLaBarrière(positiony, positionx);
                positiony = positiony + 2;
                AfficherLaBarrièreVerticale(positiony, positionx);
            }
        }

        if(detection == '8'){

            if(positiony > 3) {
                EffacerLaBarrière(positiony, positionx);
                positiony = positiony - 2;
                AfficherLaBarrièreVerticale(positiony, positionx);
            }

        }

        if (detection == '4') {
            if(positionx > 4) {
                EffacerLaBarrière(positiony, positionx);
                positionx = positionx - 4;
                AfficherLaBarrièreHorizontale(positiony, positionx);
            }
        }
        if (detection == '6') {
            if(positionx < 32) {
                EffacerLaBarrière(positiony, positionx);
                positionx = positionx + 4;
                AfficherLaBarrièreHorizontale(positiony, positionx);
            }
        }
    }while(detection != '\r');
}
