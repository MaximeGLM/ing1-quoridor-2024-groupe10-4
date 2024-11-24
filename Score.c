#include <stdio.h>
#include <string.h>
//Calcule le nombre de joueurs sauvegardé
int NombreDeGagnant() {
    FILE *fichierScore = fopen("../Score/Score.txt", "r");

    int score;
    int compteur;
    char nom[15];
    while (fscanf(fichierScore, "%s %d", nom, &score) == 2) {
        compteur++;
    }

    fclose(fichierScore);
    return compteur;
}

int JoueurInscrit(int NombreJoueur, char * gagnant) {
    FILE *fichierScore = fopen("../Score/Score.txt", "r");
    char nom[15];
    int score;
    for (int i = 0; i < NombreJoueur; i++) {
        if (fscanf(fichierScore, "%s %d", nom, &score) == 2) {
            if (strcmp(nom, gagnant) == 0) {
                fclose(fichierScore);
                return i;
            }
        }
    }
    return -1;
}

void inscription(char * gagnant) {
    // On ouvre le fichier qui sauvegarde les scores
    FILE *fichierScore = fopen("../Score/Score.txt", "a");
    char c;

    // Vérifier si le fichier a été ouvert avec succès
    if (fichierScore == NULL) {
        perror("Erreur à l'ouverture du fichier Score.txt");
        return;  // Retourner une erreur
    }

    //écrire le score du gagnant
    fprintf(fichierScore, "%s %d\n", gagnant, 5);

    // Fermer le fichier
    fclose(fichierScore);
}

void ModifierScore(char * gagnant) {
    char nom[50];
    int score;

    FILE *fichierScore = fopen("../Score/Score.txt", "r");
    FILE *fichiertemporaire = fopen("../Score/temporaire.txt", "w");

    if (!fichiertemporaire) {
        perror("Erreur à l'ouverture du fichier temporaire");
        if (fichierScore) fclose(fichierScore);
        return;
    }

    // Lire chaque ligne du fichier original
    if (fichierScore) {
        while (fscanf(fichierScore, "%s %d", nom, &score) == 2) {
            if (strcmp(nom, gagnant) == 0) {
                // Si le joueur est trouvé, remplacer son score
                fprintf(fichiertemporaire, "%s %d\n", nom, score+5);
            } else {
                // Copier les autres joueurs sans modification
                fprintf(fichiertemporaire, "%s %d\n", nom, score);
            }
        }
        fclose(fichierScore);
    }

    fclose(fichiertemporaire);

    // Remplacer le fichier original par le fichier temporaire
    remove("../Score/Score.txt");
    rename("../Score/temporaire.txt", "../Score/Score.txt");
}

void score(char gagnant[]) {
    int score;
    int NombreJoueurs=0;

    //On compte le nombre de joueurs inscrit
    NombreJoueurs = NombreDeGagnant();

    // On vérifie que le joueur n'est pas déjà inscrit et on écrit sur une nouvelle ligne le nouveau score
    if (JoueurInscrit(NombreJoueurs, gagnant)==-1) {
        inscription(gagnant);
        return;
    }

    //Sinon on modifie le score du joueur déjà inscrit
    ModifierScore(gagnant);

}
