//
// Created by maxgo on 31/10/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "sousprogramme.h"


void bordures(char plateaudejeu[19][19]) {
    // On place le contour du plateau
    for (int i=1; i<=18;i++) {
        plateaudejeu[0][i] = 196;
    }
    for (int i=1; i<=18;i++) {
        plateaudejeu[18][i] = 196;
    }
    for (int i=1; i<=18;i++) {
        plateaudejeu[i][0] = 179;
    }
    for (int i=1; i<=18;i++) {
        plateaudejeu[i][18] = 179;
    }

    // mise en place des coins sur le plateau de jeu
    plateaudejeu[0][0] = 218;
    plateaudejeu[0][18] = 191;
    plateaudejeu[18][0] = 192;
    plateaudejeu[18][18] = 217;
}

void afficherBarrières(int coordonnéesbarrières[3][20], int nombrebarriere) {
    for (int i=0; i<nombrebarriere;i++) {
        if (coordonnéesbarrières[2][i]==1) {
            AfficherLaBarrièreHorizontale(coordonnéesbarrières[1][i],coordonnéesbarrières[0][i] );
        }
        if (coordonnéesbarrières[2][i]==0) {
            AfficherLaBarrièreVerticale(coordonnéesbarrières[1][i],coordonnéesbarrières[0][i] );
        }
    }
}


void plateau(char nom1[], char nj, char jeton,int coordonnéesbarrières[3][20],int nombrebarrières, int murs) {

    int score = 10;

    char plateaudejeu[19][19] = {
            {254, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32},
            {254, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32},
            {254, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32},
            {254, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32},
            {254, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32},
            {254, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32},
            {254, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32},
            {254, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32},
            {254, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32},
            {254, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32},
            {254, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32},
            {254, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32},
            {254, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32},
            {254, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32},
            {254, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32},
            {254, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32},
            {254, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32},
            {254, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32, 254, 32},
            {254, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32}
    };

    char *messages[] = {
            "Nombre de joueurs:", "Joueur:", "Score partie:", "Jeton:",
            "Murs restants:"
    };

    bordures(plateaudejeu);
    Color(8,0);
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            printf("%c ", plateaudejeu[i][j]);
        }
        if( i == 0) {
            Color(15,0);
            printf(" %s %c\n", messages[i], nj );
            Color(8,0);

        }else if( i == 1){
            Color(15,0);
            printf(" %s %s\n", messages[i], nom1 );
            Color(8,0);
        }else if( i == 2){
            Color(15,0);
            printf(" %s %d\n", messages[i], score );
            Color(8,0);
        }else if( i == 3){
            Color(15,0);
            printf(" %s %c\n", messages[i], jeton );
            Color(8,0);
        }else if( i == 4){
            Color(15,0);
            printf(" %s %d\n", messages[i], murs );
            Color(8,0);
        } else{
            printf("\n");
        }
    }
    Color(15,0);
    afficherBarrières(coordonnéesbarrières, nombrebarrières);
    gotoligcol(20,20);
    printf("\n");
    printf("Actions possibles:\n");
    printf("1) Deplacer son pion\n");
    printf("2) Poser une barriere\n");
    printf("3) Passer son tour\n");
    printf("4) Annuler la derniere action\n");
    printf("5) Pause\n");
}

///////////////////////////////////////
// Nom du sous-programme : COLOR
// Rôle : change la couleur du texte dans la console, ainsi que la couleur du fond pour la ligne
// Compatibilité : Xindows
///////////////////////////////////////
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}