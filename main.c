//
// Created by maxgo on 30/10/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include "sousprogramme.h"
#include <conio.h>
#include <time.h>

int main() {
    int sortie = 0;
    //Couleur initiale
    Color(15,0);
    //Boucle qui arrête le progamme seulement si le joueur choisit l'option de quitter le jeu dans le menu principal
    do {
        //initialisation des variables pour la partie
        char nombrejoueur;
        char nom1[15]={0};
        char nom2[15]={0};
        char nom3[15]={0};
        char nom4[15]={0};
        char Joueur1[15]={0};
        char Joueur2[15]={0};
        char Joueur3[15]={0};
        char Joueur4[15]={0};
        //Affichage du menu principal
        menu(nom1, nom2, &nombrejoueur, nom3, nom4, &sortie);
        //1er joueur tiré au hasard, les autres gardent leur ordre de passage
        srand(time(NULL));
        switch (nombrejoueur) {
            case '4':
                switch (rand() % 4) {
                    case 0: strcpy(Joueur1, nom1); strcpy(Joueur2, nom2); strcpy(Joueur3, nom3); strcpy(Joueur4, nom4); break;
                    case 1: strcpy(Joueur1, nom2); strcpy(Joueur2, nom3); strcpy(Joueur3, nom4); strcpy(Joueur4, nom1); break;
                    case 2: strcpy(Joueur1, nom3); strcpy(Joueur2, nom4); strcpy(Joueur3, nom1); strcpy(Joueur4, nom2); break;
                    case 3: strcpy(Joueur1, nom4); strcpy(Joueur2, nom1); strcpy(Joueur3, nom2); strcpy(Joueur4, nom3); break;
                }break;
            case '2':
                switch (rand() % 2) {
                    case 0: strcpy(Joueur1, nom1); strcpy(Joueur2, nom2); break;
                    case 1: strcpy(Joueur1, nom2); strcpy(Joueur2, nom1); break;
                }break;
        }
        //Si l'utilisateur n'a pas choisi de quitter la partie alors...
        if (sortie == 0) {
            clearConsole();
            //Démarre une partie en fonction du nombre de joueurs
            switch (nombrejoueur) {
                case '2':
                    switch(DeroulementPartie2j(Joueur1, Joueur2, nombrejoueur)) {
                        //affiche les écrans de victoire
                        case 0: pas_de_victoire(); getch(); break;
                        case 1: break;//Victoire du joueur 1
                        case 2: break;// Victoire du joueur 2
                    }break;
                case '4':
                    switch(DeroulementPartie4j(Joueur1, Joueur2, Joueur3, Joueur4, nombrejoueur)) {
                        //affiche les écrans de victoire
                        case 0: pas_de_victoire(); getch(); break;
                        case 1: break;//Victoire du joueur 1
                        case 2: break;//Victoire du joueur 2
                        case 3: break;//Victoire du joueur 3
                        case 4: break;//Victoire du joueur 4
                    } break;
            }
        }
    } while (sortie != 1);
    return 0;
#ifdef _WIN32
        Sleep(5);
#else
        usleep(100000);
#endif

}
