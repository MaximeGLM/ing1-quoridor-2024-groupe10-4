#include "sousprogramme.h"

void AnnulerLaDerniereAction(int DerniereAction[], int *PosXj1, int *PosYj1, int *PosXj2, int *PosYj2, int *PosXj3, int *PosYj3, int *PosXj4, int *PosYj4, int CoordonneesBarrieres[3][20], int *nombreBarrieres, int *BarriresJ1, int *BarriresJ2, int *BarriresJ3, int *BarriresJ4) {
    switch (DerniereAction[0]) {
        case 1:// il s'agit d'un déplacement
            switch (DerniereAction[1]) {
                case 1:// On change les coordonnées du joueur 1
                    *PosXj1 = DerniereAction[2];
                    *PosYj1 = DerniereAction[3];
                return;
                case 2:// On change les coordonnées du joueur 2
                    *PosXj2 = DerniereAction[2];
                    *PosYj2 = DerniereAction[3];
                return;
                case 3:// On change les coordonnées du joueur 3
                    *PosXj3 = DerniereAction[2];
                    *PosYj3 = DerniereAction[3];
                return;
                case 4:// On change les coordonnées du joueur 4
                    *PosXj4 = DerniereAction[2];
                    *PosYj4 = DerniereAction[3];
                return;
            }
        case 2:// il s'agit d'une barrière
            // On supprime la dernière barrière ajoutée du tableau
            CoordonneesBarrieres[0][*nombreBarrieres] = -1;
            CoordonneesBarrieres[1][*nombreBarrieres] = -1;
            CoordonneesBarrieres[2][*nombreBarrieres] = -1;
            (*nombreBarrieres)--;
            //En fonction de qui à posé la barrière on actualise les compteurs des joueurs
            switch (DerniereAction[1]) {
                case 1:
                    (*BarriresJ1)++;
                return;
                case 2:
                    (*BarriresJ2)++;
                return;
                case 3:
                    (*BarriresJ3)++;
                return;
                case 4:
                    (*BarriresJ4)++;
                return;
            }
    }
}