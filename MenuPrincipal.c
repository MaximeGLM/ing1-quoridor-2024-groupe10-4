//
// Created by maxgo on 31/10/2024.
//
//Liste des librairies utilisés
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//Header auquel il est relié
#include "sousprogramme.h"

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}



int menu(char *nom1, char *nom2, char *nj) {
    int stoop;
    do {
        clearConsole();

        FILE *fichier;
        char c;

        // Ouvrir le fichier en mode lecture
        fichier = fopen("menu.txt", "r");

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

            FILE *fichier2;
            char c2;        // Variable pour stocker chaque caractère lu

            // Ouvrir le fichier en mode lecture
            fichier2 = fopen("menu1.txt", "r");

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
            }
        } else if (option == '2') {
            // Adicione seu código para a opção 2 aqui
        } else if (option == '3') {
            clearConsole();
            FILE *fichier3;
            char c3;

            // Ouvrir le fichier en mode lecture
            fichier3 = fopen("menuAide.txt", "r");

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
        }
    } while (stoop != 10);
}