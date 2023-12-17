#include <stdio.h>
#include <stdbool.h>

#define LEN_CIFRE 10

int main(void){

    printf("*** Per ogni numero inserito dall'utente tiene traccia delle cifre ripetute ***\n\n");

    int cifre[LEN_CIFRE] = {0};
    int num = -1;
    bool uscire = false;

    printf("Inserisci i numeri\n");

    while(!uscire){
        printf("> ");
        scanf("%d", &num);

        uscire = true;

        if(num != 0){
            uscire = false;

            while(num > 0){
                cifre[num % 10]++;
                num /= 10;
            }
        }
    }

    printf("\nCifre   ");
    for(int i = 0; i < LEN_CIFRE; i++){
        printf("%6d", i);
    }

    printf("\nInserita");
    for(int i = 0; i < LEN_CIFRE; i++){
        printf("%6d", cifre[i]);
    }

    printf("\n");
    return 0;
}