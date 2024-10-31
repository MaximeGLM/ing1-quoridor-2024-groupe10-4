#include "sousprogramme.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep() on Unix-based systems
#include <windows.h>
#include <conio.h>



// Initialization function - Initialize the game board

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

        char option = _getch(); // Obtenha a entrada do usuário
        if (option == '1') {
            clearConsole(); // Limpa a tela

            FILE *fichier2;  // Déclaration d'un pointeur de fichier
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
            fichier3 = fopen("menu3.txt", "r");

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
            if(sortir == '27'){
                break;
            }
        }
    } while (stoop != 10);
}





void gotoligcol( int lig, int col )
{
    // ressources
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}


int deplacement(int* lig, int* col) {
    if (_kbhit()) {
        char haut = _getch();
        if (haut == '8' && *lig > 1) {
            *lig = *lig - 2;
            return haut; // Indicate a movement action
        } else if (haut == '2' && *lig < 17) {
            *lig = *lig + 2;
            return haut; // Indicate a movement action
        } else if (haut == '6' && *col < 34){
            *col = *col + 4;
            return haut;
        } else if(haut == '4' && *col > 2){
            *col = *col - 4;
            return haut;
        }
    }
    return 0; // No movement detected
}

int deplacement2(int* lig2, int* col2) {
    if (_kbhit()) {
        char bas = _getch();

        if (bas == 'w' && *lig2 > 1 ) {
            *lig2 = *lig2 - 2;  // Move up
            return bas; // Retorne a tecla pressionada
        } else if (bas == 's' && *lig2 < 17) {
            *lig2 = *lig2 + 2;  // Move down
            return bas;
        } else if (bas == 'd' && *col2 < 34) {
            *col2 = *col2 + 4;  // Move right
            return bas;
        } else if (bas == 'a' && *col2 > 2) {
            *col2 = *col2 - 4;
            return bas;
        }
    }
    return 0;
}


int barrieres(){
    int i;
    int positionx = 16;
    int positiony = 1;
    int detection;
    gotoligcol(positiony, positionx);
    printf("%c", 186);
    gotoligcol(positiony + 1, positionx);
    printf("%c", 186);
    gotoligcol(positiony + 2, positionx);
    printf("%c", 186);
    do {
        detection = _getch();
        if (detection == '2') {

            if(positiony < 14) {
                for(i = 1; i< 18; i++){
                    gotoligcol(i, positionx);
                    printf("%c", 32);
                }

                positiony = positiony + 2;
                gotoligcol(positiony, positionx);
                printf("%c", 186);
                gotoligcol(positiony + 1, positionx);
                printf("%c", 186);
                gotoligcol(positiony + 2, positionx);
                printf("%c", 186);

            }else if(positiony == 15){
                for(i = 1; i< 18; i++){
                    gotoligcol(i, positionx);
                    printf("%c", 32);
                }


                positiony = positiony + 2;
                gotoligcol(positiony, positionx);
                printf("%c", 186);
                gotoligcol(positiony - 1, positionx);
                printf("%c", 186);
                gotoligcol(positiony - 2, positionx);
                printf("%c", 186);
            }
        }

        if(detection == '8'){

            if(positiony > 3) {
                for(i = 1; i< 18; i++){
                    gotoligcol(i, positionx);
                    printf("%c", 32);
                }

                positiony = positiony - 2;
                gotoligcol(positiony, positionx);
                printf("%c", 186);
                gotoligcol(positiony - 1, positionx);
                printf("%c", 186);
                gotoligcol(positiony - 2, positionx);
                printf("%c", 186);
            } else if(positiony == 3){
                for(i = 1; i< 18; i++){
                    gotoligcol(i, positionx);
                    printf("%c", 32);
                }

                positiony = positiony - 2;
                gotoligcol(positiony, positionx);
                printf("%c", 186);
                gotoligcol(positiony + 1, positionx);
                printf("%c", 186);
                gotoligcol(positiony + 2, positionx);
                printf("%c", 186);
            }

        }

        if (detection == '4') {

            if(positionx > 4) {
                for(i = 1; i< 36; i++){
                    gotoligcol(positiony, i);
                    printf("%c", 32);
                }

                positiony = positiony + 2;
                gotoligcol(positiony, positionx);
                printf("%c", 186);
                gotoligcol(positiony + 1, positionx);
                printf("%c", 186);
                gotoligcol(positiony + 2, positionx);
                printf("%c", 186);

            }else if(positiony == 15){
                for(i = 1; i< 18; i++){
                    gotoligcol(i, positionx);
                    printf("%c", 32);
                }


                positiony = positiony + 2;
                gotoligcol(positiony, positionx);
                printf("%c", 186);
                gotoligcol(positiony - 1, positionx);
                printf("%c", 186);
                gotoligcol(positiony - 2, positionx);
                printf("%c", 186);
            }
        }
    }while(detection != '\r');
}
