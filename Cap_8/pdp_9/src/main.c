#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define LEN_ROW 10
#define LEN_COL 10
#define LEN_LETTERE 26
#define LIMITE_SU -1
#define LIMITE_DESTRA 10
#define LIMITE_GIU 10
#define LIMITE_SINISTRA -1

int main(void){

    printf("*** Crea un percorso casuale di lettere A-Z in una matrice 10x10 ***\n\n");

    char matrice[LEN_ROW][LEN_COL];
    char lettere[LEN_LETTERE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                                  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    int dir = 0, rowTmp = 0, colTmp = 0, idxLettere = 0, tentativi = 4;

    for(int row = 0; row < LEN_ROW; row++){
        for(int col = 0; col < LEN_COL; col++){
            matrice[row][col] = '.';
        }
    }

    srand((unsigned) time(NULL));

    while(true){
        if(tentativi == 4){
            matrice[rowTmp][colTmp] = lettere[idxLettere];
            idxLettere++;

            dir = rand() % 4;
        }

        if(tentativi == 0 || idxLettere == LEN_LETTERE)
            break;

        switch(dir){
            case 0: {
                if(rowTmp - 1 > LIMITE_SU && matrice[rowTmp - 1][colTmp] == '.'){
                    rowTmp--;
                    tentativi = 4;
                } else {
                    dir = 1;
                    tentativi--;
                }
                break;
            }
            case 1: {
                if(colTmp + 1 < LIMITE_DESTRA && matrice[rowTmp][colTmp + 1] == '.'){
                    colTmp++;
                    tentativi = 4;
                } else {
                    dir = 2;
                    tentativi--;
                }
                break;
            }
            case 2: {
                if(rowTmp + 1 < LIMITE_GIU && matrice[rowTmp + 1][colTmp] == '.'){
                    rowTmp++;
                    tentativi = 4;
                } else {
                    dir = 3;
                    tentativi--;
                }
                break;
            }
            case 3: {
                if(colTmp - 1 > LIMITE_SINISTRA && matrice[rowTmp][colTmp - 1] == '.'){
                    colTmp--;
                    tentativi = 4;
                } else {
                    dir = 0;
                    tentativi--;
                }
                break;
            }
        }
    }

    for(int row = 0; row < LEN_ROW; row++){
        for(int col = 0; col < LEN_COL; col++){
            printf("%5c", matrice[row][col]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}