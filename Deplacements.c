//
// Created by maxgo on 08/11/2024.
//
#include "sousprogramme.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep() on Unix-based systems
#include <windows.h>
#include <conio.h>

#define jeton1 190
#define jeton2 208
#define jeton3 207
#define jeton4 209

void gotoligcol( int lig, int col )
{
    // ressources
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
char lirecaracconsole(int lignee, int colonnee) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    unsigned char ch;
    COORD coord = {colonnee, lignee};
    DWORD read;

    if (ReadConsoleOutputCharacter(hConsole, &ch, 1, coord, &read)) {
        return ch;
    } else {
        return '\0';
    }
}

int Deplacement(int* PosX, int* PosY) {
    char choix;
    //Variables pour regarder si des barrières entourent le joueur
    int BarriereBas1 = (unsigned char) lirecaracconsole(*PosX + 1,*PosY);
    int BarriereHaut1 = (unsigned char) lirecaracconsole(*PosX - 1,*PosY);
    int BarriereDroite1 = (unsigned char) lirecaracconsole(*PosX,*PosY + 2);
    int BarriereGauche1 = (unsigned char) lirecaracconsole(*PosX,*PosY - 2);
    //Variables pour regarder si un autre pion est à coté du joueur
    int pionBas = (unsigned char) lirecaracconsole(*PosX + 2,*PosY);
    int pionHaut = (unsigned char) lirecaracconsole(*PosX - 2,*PosY);
    int pionDroite = (unsigned char) lirecaracconsole(*PosX,*PosY + 4);
    int pionGauche = (unsigned char) lirecaracconsole(*PosX,*PosY - 4);
    //Variable pour lire les barrière à la case d'après
    int BarriereBas2 = (unsigned char) lirecaracconsole(*PosX + 3,*PosY);
    int BarriereHaut2 = (unsigned char) lirecaracconsole(*PosX - 3,*PosY);
    int BarriereDroite2 = (unsigned char) lirecaracconsole(*PosX,*PosY + 6);
    int BarriereGauche2 = (unsigned char) lirecaracconsole(*PosX,*PosY - 6);
    //Variables pour regarder s'il n'y a pas deux pions à côtés
    int pionBas2 = (unsigned char) lirecaracconsole(*PosX + 4,*PosY);
    int pionHaut2 = (unsigned char) lirecaracconsole(*PosX - 4,*PosY);
    int pionDroite2 = (unsigned char) lirecaracconsole(*PosX,*PosY + 8);
    int pionGauche2 = (unsigned char) lirecaracconsole(*PosX,*PosY - 8);

    do {
        choix = _getch();
        switch (choix) {
            case 'z':
                //Verification si le pion se situe en haut du plateau
                if ( *PosX > 1 ) {
                    //Verification si il n'y a pas de barrière en haut
                    if (BarriereHaut1 != 205 && BarriereHaut1 != 186) {
                        //Verification pour le saut au dessus du pion (avec la vérification de sortie du pion du plateau et des barrières une case plus loin)
                        if ((pionHaut == jeton1 || pionHaut == jeton2 || pionHaut == jeton3 || pionHaut == jeton4) &&  *PosX > 3 && BarriereHaut2 != 205 && BarriereHaut2 != 186) {
                            // verification si il n'y a pas de pion derrière celui qu'on veut sauter
                            if (pionHaut2 != jeton1 && pionHaut2 != jeton2 && pionHaut2 != jeton3 && pionHaut2 != jeton4) {
                                *PosX = *PosX - 4;
                                return choix;
                            }
                            break;
                        }
                        if (pionHaut != jeton1 && pionHaut != jeton2 && pionHaut != jeton3 && pionHaut != jeton4) {
                            *PosX = *PosX - 2;
                            return choix;
                        }
                    }
                    break;
                }
                break;
            case 's':
                //Verification si le pion se situe en bas du plateau
                if ( *PosX < 17 ) {
                        //Verification si il n'y a pas de barrière en bas
                    if (BarriereBas1 != 205 && BarriereBas1 != 186) {
                            //Verification pour le saut au dessus du pion (avec la vérification de sortie du pion du plateau et des barrières une case plus loin)
                        if ((pionBas == jeton1 || pionBas == jeton2 || pionBas == jeton3 || pionBas == jeton4) &&  *PosX < 15 && BarriereBas2 != 205 && BarriereBas2 != 186) {
                            // verification si il n'y a pas de pion derrière celui qu'on veut sauter
                            if (pionBas2 != jeton1 && pionBas2 != jeton2 && pionBas2 != jeton3 && pionBas2 != jeton4) {
                                *PosX = *PosX + 4;
                                return choix;
                            }
                            break;
                        }
                        if (pionBas != jeton1 && pionBas != jeton2 && pionBas != jeton3 && pionBas != jeton4) {
                            *PosX = *PosX + 2;
                            return choix;
                        }
                        break;
                    }
                    break;
                }
                break;
            case 'q':
                //Verification si le pion se situe à gauche du plateau
                if ( *PosY > 2 ) {
                        //Verification si il n'y a pas de barrière à gauche
                    if (BarriereGauche1 != 205 && BarriereGauche1 != 186) {
                            //Verification pour le saut au dessus du pion (avec la vérification de sortie du pion du plateau et des barrières une case plus loin)
                        if ((pionGauche == jeton1 || pionGauche == jeton2 || pionGauche == jeton3 || pionGauche == jeton4) &&  *PosY > 6 && BarriereGauche2 != 205 && BarriereGauche2 != 186) {
                            // verification si il n'y a pas de pion derrière celui qu'on veut sauter
                            if (pionGauche2 != jeton1 && pionGauche2 != jeton2 && pionGauche2 != jeton3 && pionGauche2 != jeton4) {
                                *PosY = *PosY - 8;
                                return choix;
                            }
                            break;
                        }
                        if (pionGauche != jeton1 && pionGauche != jeton2 && pionGauche != jeton3 && pionGauche != jeton4) {
                            *PosY = *PosY - 4;
                            return choix;
                        }
                        break;
                    }
                    break;
                }
                break;
            case 'd':
                //Verification si le pion se situe à droite du plateau
                if ( *PosY < 32 ) {
                    //Verification si il n'y a pas de barrière à droite
                    if (BarriereDroite1 != 205 && BarriereDroite1 != 186) {
                        //Verification pour le saut au dessus du pion (avec la vérification de sortie du pion du plateau et des barrières une case plus loin)
                        if ((pionDroite == jeton1 || pionDroite == jeton2 || pionDroite == jeton3 || pionDroite == jeton4) &&  *PosY < 28 && BarriereDroite2 != 205 && BarriereDroite2 != 186) {
                            // verification si il n'y a pas de pion derrière celui qu'on veut sauter
                            if (pionDroite2 != jeton1 && pionDroite2 != jeton2 && pionDroite2 != jeton3 && pionDroite2 != jeton4) {
                                *PosY = *PosY + 8;
                                return choix;
                            }
                        }
                        if (pionDroite != jeton1 && pionDroite != jeton2 && pionDroite != jeton3 && pionDroite != jeton4) {
                            *PosY = *PosY + 4;
                            return choix;
                        }
                        break;
                    }
                    break;
                }
                break;
        }
    }while (1);
}