#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep() on Unix-based systems
#include <windows.h>
#include <conio.h>
#include "sousprogramme.h"

void Menupause() {
    int stoop;

    clearConsole();
    FILE *fichier4 = fopen("../menus/Menupause.txt", "r");
    char c;

    // Vérifier si le fichier a été ouvert avec succès
    if (fichier4 == NULL) {
        perror("Erreur à l'ouverture du fichier Menupause.txt");
        return;  // Retourner une erreur
    }

    // Lire et afficher le contenu du fichier caractère par caractère
    while ((c = fgetc(fichier4)) != EOF) {
        putchar(c);  // Afficher le caractère dans la console
    }

    // Fermer le fichier
    fclose(fichier4);
}

int MenuPause() {
    int stoop;
    clearConsole();
    char option = _getch();
    if (option == '1') {

    } else if (option == '2') {

    } else if (option == '3') {
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
        if(sortir == 27){
        }
    }else if (option == '4') {

    }
}