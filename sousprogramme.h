//
// Created by pedro on 18/10/2024.
//

#ifndef PROJETINFO1_0_SOUSPROGRAMME_H
#define PROJETINFO1_0_SOUSPROGRAMME_H
void plateau(char nom1[], char nj, char jeton);
void clearConsole();
int menu(char *nom1, char *nom2, char *nj);
void gotoligcol( int lig, int col );
int deplacement(int* lig, int* col);
int deplacement2(int* lig2, int* col2);
int barrieres();

#endif //PROJETINFO1_0_SOUSPROGRAMME_H
