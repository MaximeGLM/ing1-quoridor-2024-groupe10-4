//
// Created by maxgo on 31/10/2024.
//
#include <stdio.h>
#include "sousprogramme.h"
#include <conio.h>

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
