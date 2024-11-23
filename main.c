//
// Created by maxgo on 30/10/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include "sousprogramme.h"
#include <conio.h>

int main() {
    int sortie = 0;
    //Boucle qui arrête le progamme seulement si le joueur choisit l'option de quitter le jeu dans le menu principal
    do {
        //initialisation des variables pour la partie
        char nombrejoueur;
        char nom1[15];
        char nom2[15];
        char nom3[15];
        char nom4[15];
        menu(nom1, nom2, &nombrejoueur, nom3, nom4, &sortie);
        //Si l'utilisateur n'a pas choisit de quitter la partie alors...
        if (sortie == 0) {
            clearConsole();
            //Démarre une partie en fonction du nombre de joueur
            switch (nombrejoueur) {
                case '2': DeroulementPartie2j(nom1, nom2, nombrejoueur); break;
                case '4': DeroulementPartie4j(nom1, nom2, nom3, nom4, nombrejoueur); break;
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