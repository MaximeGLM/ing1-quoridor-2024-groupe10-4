//
// Created by pedro on 18/10/2024.
//
#define QuatitédeBarrières 20

#ifndef PROJETINFO1_0_SOUSPROGRAMME_H
#define PROJETINFO1_0_SOUSPROGRAMME_H
void plateau(char nom1[], char nj, char jeton);
void clearConsole();
void afficherBarrières(int coordonnéesbarrières[3][20], int nombrebarriere);
int menu(char *nom1, char *nom2, char *nj);
void gotoligcol( int lig, int col );
int deplacement(int* lig, int* col);
int deplacement2(int* lig2, int* col2);
int barrieres();
void AfficherLaBarrièreHorizontale(int y,int x);
void AfficherLaBarrièreVerticale(int y,int x);
void DeroulementPartie2j();
int Deplacement();

#endif //PROJETINFO1_0_SOUSPROGRAMME_H
