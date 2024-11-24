//
// Created by maxgo on 31/10/2024.
//
//Liste des librairies utilisés
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//Header auquel il est relié
#include <unistd.h>

#include "sousprogramme.h"
#include <windows.h>

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}



int menu(char *nom1, char *nom2, char *nj, char *nom3, char *nom4, int *sortie) {
    int stoop;
    do {
        clearConsole();

        FILE *fichier = fopen("../menus/menu.txt", "r");
        char c;

        // Vérifier si le fichier a été ouvert avec succès
        if (fichier == NULL) {
            perror("Erreur à l'ouverture du fichier menu");
            return 1;  // Retourner une erreur
        }

        // Lire et afficher le contenu du fichier caractère par caractère
        while ((c = fgetc(fichier)) != EOF) {
            putchar(c);  // Afficher le caractère dans la console
        }

        // Fermer le fichier
        fclose(fichier);

        char option = _getch();
        if (option == '1') {
            clearConsole();

            FILE *fichier2 = fopen("../menus/menuNouvellePartie.txt", "r");
            char c2;

            // Vérifier si le fichier a été ouvert avec succès
            if (fichier2 == NULL) {
                perror("Erreur à l'ouverture du fichier menu1");
                return 1;  // Retourner une erreur
            }

            // Lire et afficher le contenu du fichier caractère par caractère
            while ((c2 = fgetc(fichier2)) != EOF) {
                putchar(c2);  // Afficher le caractère dans la console
            }

            // Fermer le fichier
            fclose(fichier2);
            printf("\n\n                   Nombre de joueurs:\n");

            gotoligcol(26, 38);
            int i;

            *nj = _getch();
            printf("%c\n", *nj);
            if (*nj == '2') {
                printf("                   Joueur 1:\n");
                printf("                   Joueur 2:\n");
                gotoligcol(27, 29);
                for (i = 0; i < 15; i++) {
                    nom1[i] = _getch();
                    printf("%c", nom1[i]);
                    if (nom1[i] == '\r') {
                        nom1[i] = '\0';
                        break;
                    }
                }
                gotoligcol(28, 29);
                for (i = 0; i < 15; i++) {
                    nom2[i] = _getch();
                    printf("%c", nom2[i]);
                    if (nom2[i] == '\r') {
                        nom2[i] = '\0';
                        break;
                    }
                }
                stoop = 10;
            } else if (*nj == '4') {
                printf("                   Joueur 1:\n");
                printf("                   Joueur 2:\n");
                printf("                   Joueur 3:\n");
                printf("                   Joueur 4:\n");
                gotoligcol(25, 29);
                for (i = 0; i < 15; i++) {
                    nom1[i] = _getch();
                    printf("%c", nom1[i]);
                    if (nom1[i] == '\r') {
                        nom1[i] = '\0';
                        break;
                    }
                }
                gotoligcol(26, 29);
                for (i = 0; i < 15; i++) {
                    nom2[i] = _getch();
                    printf("%c", nom2[i]);
                    if (nom2[i] == '\r') {
                        nom2[i] = '\0';
                        break;
                    }
                }
                gotoligcol(27, 29);
                for (i = 0; i < 15; i++) {
                    nom3[i] = _getch();
                    printf("%c", nom3[i]);
                    if (nom3[i] == '\r') {
                        nom3[i] = '\0';
                        break;
                    }
                }
                gotoligcol(28, 29);
                for (i = 0; i < 15; i++) {
                    nom4[i] = _getch();
                    printf("%c", nom4[i]);
                    if (nom4[i] == '\r') {
                        nom4[i] = '\0';
                        break;
                    }
                }
                stoop = 10;
            }
        } else if (option == '2') {
            *nj = '5';
            return 0;

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
                break;
            }
        } else if (option == '4') {
            clearConsole();
            FILE *fichierEsthétiqueScore = fopen("../menus/ScoreDesJoueurs.txt", "r");
            char c4;
            // Lire et afficher le contenu du fichier caractère par caractère
            while ((c4 = fgetc(fichierEsthétiqueScore)) != EOF) {
                putchar(c4);  // Afficher le caractère dans la console
            }
            fclose(fichierEsthétiqueScore);
            printf("\n");
            //On affiche les données de score
            FILE *fichierScore = fopen("../Score/Score.txt", "r");
            char c3;

            // Vérifier si le fichier a été ouvert avec succès
            if (fichierScore == NULL) {
                perror("Erreur à l'ouverture du fichier score.txt");
                return 1;  // Retourner une erreur
            }

            // Lire et afficher le contenu du fichier caractère par caractère
            while ((c3 = fgetc(fichierScore)) != EOF) {
                putchar(c3);  // Afficher le caractère dans la console
            }
            // Fermer le fichier
            fclose(fichierScore);
            getchar();


        } else if (option == '5') {
            *sortie = 1;
            return 0;

        }
    } while (stoop != 10);
}