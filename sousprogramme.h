//
// Created by pedro on 18/10/2024.
//
#define QuatitédeBarrières 20

#ifndef PROJETINFO1_0_SOUSPROGRAMME_H
#define PROJETINFO1_0_SOUSPROGRAMME_H
void plateau(char nom1[], char nj, char jeton);
void clearConsole();
void afficherBarrières();
int menu();
void gotoligcol();
int deplacement();
int deplacement2();
int barrieres();
void AfficherLaBarrièreHorizontale();
void AfficherLaBarrièreVerticale();
void DeroulementPartie2j(char * nom1,char * nom2, char nombrejoueur);
void DeroulementPartie4j(char * nom1,char * nom2,char * nom3, char * nom4, char NombreJoueur);
int Deplacement();

#endif //PROJETINFO1_0_SOUSPROGRAMME_H
