#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep() on Unix-based systems
#include <windows.h>
#include <conio.h>
#include "sousprogramme.h"

void Ouvre_le_Menupause() {
    int stoop;

    clearConsole();
    FILE *fichierMenupause = fopen("../menus/Menupause.txt", "r");
    char c;

    // Vérifier si le fichier a été ouvert avec succès
    if (fichierMenupause == NULL) {
        perror("Erreur à l'ouverture du fichier Menupause.txt");
        return;  // Retourner une erreur
    }

    // Lire et afficher le contenu du fichier caractère par caractère
    while ((c = fgetc(fichierMenupause)) != EOF) {
        putchar(c);  // Afficher le caractère dans la console
    }

    // Fermer le fichier
    fclose(fichierMenupause);
}

int MenuPause() {
    do {
        clearConsole();
        Ouvre_le_Menupause();
        char option = _getch();
        switch (option) {
            case '1':
                break;
            case '2':
                return 0;
            case '3':
                clearConsole();
            FILE *fichier3 = fopen("../menus/menuAide.txt", "r");
            char c3;

            // Vérifier si le fichier a été ouvert avec succès
            if (fichier3 == NULL) {
                perror("Erreur à l'ouverture du fichier");
                return 1;  // Retourner une erreur
            }

            // Lire et afficher le contenu du fichier caractère par caractère
            while ((c3 = fgetc(fichier3)) != EOF) {
                putchar(c3);  // Afficher le caractère dans la console
            }

            // Fermer le fichier
            fclose(fichier3);
            char sortir = _getch();
            if(sortir == 27){}
            break;
            case '4':
                return 1;
        }
    } while (1);
}