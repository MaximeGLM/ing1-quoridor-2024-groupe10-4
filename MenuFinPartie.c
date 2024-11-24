#include <stdio.h>

#include "sousprogramme.h"

//fonction qui affiche une fin de partie sans gagnant avant de revenir au menu pricipale
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

//Fonction qui affiche la victoire du joueur et actualise le score
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
    score(gagnant);
}