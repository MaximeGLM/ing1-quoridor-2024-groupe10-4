//
// Created by maxgo on 31/10/2024.
//
#include <stdio.h>
#include "sousprogramme.h"
#include <conio.h>



// Cette fonction efface la barrière en remplaçant les caractères
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

//Cette fonction affiche une barrière verticale en fonction de ses coordonnées
void AfficherLaBarrièreVerticale(int y,int x) {
    gotoligcol(y - 1, x);
    printf("%c", 186);
    gotoligcol(y, x);
    printf("%c", 186);
    gotoligcol(y + 1, x);
    printf("%c", 186);
}

//Cette fonction affiche une barrière verticale en fonction de ses coordonnées
void AfficherLaBarrièreHorizontale(int y,int x) {
    gotoligcol(y, x - 2);
    printf("%c", 205);
    gotoligcol(y, x);
    printf("%c", 205);
    gotoligcol(y, x + 2);
    printf("%c", 205);
}

//Cette fonction permet de placer temporairement une barrière jusqu'à validation du joueur
int barrieres(int coordonnéesbarrières[3][20], int* nombrebarrière){
    //On pose une barrière en x=16 et en y = 2
    int positionx = 16;
    int positiony = 2;
    char detection;
    int sens =0;


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
                sens = 0;
            }
        }

        if(detection == '8'){

            if(positiony > 3) {
                EffacerLaBarrière(positiony, positionx);
                positiony = positiony - 2;
                AfficherLaBarrièreVerticale(positiony, positionx);
                sens = 0;
            }

        }

        if (detection == '4') {
            if(positionx > 4) {
                EffacerLaBarrière(positiony, positionx);
                positionx = positionx - 4;
                AfficherLaBarrièreHorizontale(positiony, positionx);
                sens = 1;
            }
        }
        if (detection == '6') {
            if(positionx < 32) {
                EffacerLaBarrière(positiony, positionx);
                positionx = positionx + 4;
                AfficherLaBarrièreHorizontale(positiony, positionx);
                sens = 1;
            }
        }
        afficherBarrières(coordonnéesbarrières, *nombrebarrière);
    }while(detection != '\r');//L'utilisateur valide la position de la barrière
    //La position est enregistrée dans un tableau
    coordonnéesbarrières[0][*nombrebarrière] = positionx;
    coordonnéesbarrières[1][*nombrebarrière] = positiony;
    coordonnéesbarrières[2][*nombrebarrière] = sens;
    *nombrebarrière=*nombrebarrière+1;// Ce compteur permet de lire facilement le tableau
    return 0;
}
