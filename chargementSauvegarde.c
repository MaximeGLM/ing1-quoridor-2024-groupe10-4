#include <stdio.h>

//Ce fichier s'occupe de la gestion de l'ouverture de la dernière partie sauvegardé
//malheureusement cette fonctionnalité ne fonctionne pas encore, elle sera disponible pour la soutenance

char LectureSauvegardeNombreJoueur() {
    //On ouvre la sauvegarde
    FILE *fichierSauvegarde = fopen("../Sauvegarde/Sauvegarde.txt", "r");

    //Message d'erreur au cas où
    if (!fichierSauvegarde) {
        perror("Erreur à l'ouverture du fichier Sauvegarde");
        return '0';
    }

    char NombreJoueur = fgetc(fichierSauvegarde);
    return NombreJoueur;
}

void LectureSauvegardeNomJoueur(char Joueur1[],char Joueur2[],char Joueur3[],char Joueur4[]) {
    //On ouvre la sauvegarde
    FILE *fichierSauvegarde = fopen("../Sauvegarde/Sauvegarde.txt", "r");

    //Message d'erreur au cas où
    if (!fichierSauvegarde) {
        perror("Erreur à l'ouverture du fichier Sauvegarde");
        return;
    }

    char ligne[256]; // Pour stocker chaque ligne lue
    int compteurLigne = 0;

    // Lire chaque ligne du fichier
    while (fgets(ligne, sizeof(ligne), fichierSauvegarde)) {
        compteurLigne++;

        // Si c'est la deuxième ligne alors il s'agit du nom du joueur 1
        if (compteurLigne == 2) {
            fscanf(fichierSauvegarde, "%s", Joueur1);
        }
        // Si c'est la troisième ligne alors il s'agit du nom du joueur 2
        if (compteurLigne == 3) {
            fscanf(fichierSauvegarde, "%s", Joueur2);
        }
        if (compteurLigne == 4) {
            fscanf(fichierSauvegarde, "%s", Joueur3);
        }
        if (compteurLigne == 5) {
            fscanf(fichierSauvegarde, "%s", Joueur4);
        }
    }

    fclose(fichierSauvegarde);
}
