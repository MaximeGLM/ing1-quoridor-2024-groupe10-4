#include <stdio.h>

#include "sousprogramme.h"
//
// Created by maxgo on 23/11/2024.
//
void pas_de_victoire() {
    clearConsole();
    FILE *fichierFinSansVictoire = fopen("../menus/FinPartieSansVictoire.txt", "r");
    char c;

    // Vérifier si le fichier a été ouvert avec succès
    if (fichierFinSansVictoire == NULL) {
        perror("Erreur à l'ouverture du fichier FinPartieSansVictoire.txt");
        return;  // Retourner une erreur
    }

    // Lire et afficher le contenu du fichier caractère par caractère
    while ((c = fgetc(fichierFinSansVictoire)) != EOF) {
        putchar(c);  // Afficher le caractère dans la console
    }

    // Fermer le fichier
    fclose(fichierFinSansVictoire);
}

void Victoire(char gagnant[]) {
    clearConsole();
    FILE *fichierFinVictoire = fopen("../menus/FinPartieVictoire.txt", "r");
    char c;

    // Vérifier si le fichier a été ouvert avec succès
    if (fichierFinVictoire == NULL) {
        perror("Erreur à l'ouverture du fichier FinPartieVictoire.txt");
        return;  // Retourner une erreur
    }

    // Lire et afficher le contenu du fichier caractère par caractère
    while ((c = fgetc(fichierFinVictoire)) != EOF) {
        putchar(c);  // Afficher le caractère dans la console
    }

    printf(" %s",gagnant);

    // Fermer le fichier
    fclose(fichierFinVictoire);
}