#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define FL_PLAY 'y'
#define NM_TIRI 2

int rollDice(void);
bool playGame(void);

int main(void){

    printf("*** Simula il gioco craps ***\n\n");

    srand((unsigned) time(NULL));

    int vittorie = 0, sconfitte = 0;
    char scelta = 'y';

    while(scelta == FL_PLAY){
        if(playGame()){
            printf("Hai vinto!\n\n");
            vittorie++;
        } else {
            printf("Hai perso!\n\n");
            sconfitte++;
        }

        printf("Vuoi giocare ancora? (y/n): ");
        do{
            scelta = tolower(getchar());
        }while(!isalpha(scelta));

        getchar();
        printf("\n");
    }

    printf("Vittorie: %d, Sconfitte: %d", vittorie, sconfitte);

    printf("\n");
    return 0;
}

int rollDice(void){
    int somma = 0;

    for(int i = 0; i < NM_TIRI; i++){
        somma += (rand() % 6) + 1;
    }

    return somma;
}

bool playGame(void){
    int num = 0, punto = 0;
    bool result = true;

    num = rollDice();
    printf("E' uscito: %d\n", num);
    
    switch(num){
        case 2: case 3: case 12:
            result = false;
            break;
        case 7: case 11:
            break;
        default:
            punto = num;
            printf("Il tuo punto e' %d\n", punto);
    }

    if(punto > 1){
        num = 0;
        while(punto != num && num != 7){
            num = rollDice();
            printf("E' uscito: %d\n", num);
        }

        if(num == 7){
            result = false;
        }
    }

    return result;
}