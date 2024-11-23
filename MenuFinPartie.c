#include <stdio.h>

#include "sousprogramme.h"
//
// Created by maxgo on 23/11/2024.
//
void pas_de_victoire() {
    int stoop;

    clearConsole();
    FILE *fichierFinSansVictoire = fopen("../menus/FinPartieSansVictoire.txt", "r");
    char c;

    // Vérifier si le fichier a été ouvert avec succès
    if (fichierFinSansVictoire == NULL) {
        perror("Erreur à l'ouverture du fichier Menupause.txt");
        return;  // Retourner une erreur
    }

    // Lire et afficher le contenu du fichier caractère par caractère
    while ((c = fgetc(fichierFinSansVictoire)) != EOF) {
        putchar(c);  // Afficher le caractère dans la console
    }

    // Fermer le fichier
    fclose(fichierFinSansVictoire);
}