#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NM_MAX 100

void initializeNumberGenerator(void);
int newSecretNumber(void);
void readGuess(int secretNumber);

int main(void){

    printf("*** Indovina il numero compreso tra 1 e %d ***\n\n", NM_MAX);

    char command;
    int secretNumber = 0;

    initializeNumberGenerator();

    do{
        secretNumber = newSecretNumber();
        printf("Numero estratto!\n");

        readGuess(secretNumber);

        printf("Vuoi giocare ancora? (y/n): ");
        scanf(" %c", &command);
    }while(command == 'y' || command == 'Y');


    printf("\n");
    return 0;
}

void initializeNumberGenerator(void){
    srand((unsigned) time(NULL));
}

int newSecretNumber(void){
    return rand() % NM_MAX + 1;
}

void readGuess(int secretNumber){
    int num = 0, tentativi = 0;

    while(1){
        tentativi++;
        printf("tentativo: ");
        scanf("%d", &num);

        if(num == secretNumber){
            printf("Hai vinto in %d tentativi!\n\n", tentativi);
            break;
        } else if(num > secretNumber){
            printf("Troppo alto, riprova!\n\n");
        } else if(num < secretNumber){
            printf("Troppo basso, riprova!\n\n");
        }
    }
}