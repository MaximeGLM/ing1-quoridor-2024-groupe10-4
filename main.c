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

    char nombrejoueur;
    char nom1[15];
    char nom2[15];

    menu(nom1, nom2, &nombrejoueur);
    clearConsole();
    DeroulementPartie2j(nom1, nom2, &nombrejoueur);

    return 0;

#ifdef _WIN32
        Sleep(5);
#else
        usleep(100000);
#endif

}