//
// Created by maxgo on 08/11/2024.
//
#include "sousprogramme.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep() on Unix-based systems
#include <windows.h>
#include <conio.h>

void gotoligcol( int lig, int col )
{
    // ressources
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
int Deplacement(int* PosX, int* PosY) {
    char choix;

    do {
        choix = _getch();
        switch (choix) {
            case '8':
                if ( *PosX > 1 ) {
                    *PosX = *PosX - 2; return choix;
                } break;
            case '2':
                if ( *PosX < 17 ) {
                    *PosX = *PosX + 2; return choix;
                } break;

            case '4':
                if (  *PosY > 2) {
                    *PosY = *PosY - 4; return choix;
                } break;
            case '6':
                if ( *PosY < 32) {
                    *PosY = *PosY + 4; return choix;
                } break;
        }
    }while (1);
}

int deplacement(int* lig, int* col) {
    char haut;

    do {
        haut = _getch();
        if (haut == '8' && *lig > 1) {
            *lig = *lig - 2;
            return haut; // Indicate a movement action
        } else if (haut == '2' && *lig < 17) {
            *lig = *lig + 2;
            return haut; // Indicate a movement action
        } else if (haut == '6' && *col < 34){
            *col = *col + 4;
            return haut;
        } else if(haut == '4' && *col > 2){
            *col = *col - 4;
            return haut;
        }
    }while (haut != '8' && haut != '2' && haut != '6' && haut != '4');
    return 0; // No movement detected
}

int deplacement2(int* lig2, int* col2) {
    if (_kbhit()) {
        char bas = _getch();

        if (bas == 'w' && *lig2 > 1 ) {
            *lig2 = *lig2 - 2;  // Move up
            return bas; // Retorne a tecla pressionada
        } else if (bas == 's' && *lig2 < 17) {
            *lig2 = *lig2 + 2;  // Move down
            return bas;
        } else if (bas == 'd' && *col2 < 34) {
            *col2 = *col2 + 4;  // Move right
            return bas;
        } else if (bas == 'a' && *col2 > 2) {
            *col2 = *col2 - 4;
            return bas;
        }
    }
    return 0;
}