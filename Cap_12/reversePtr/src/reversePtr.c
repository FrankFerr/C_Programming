#include <stdio.h>

#define LEN 10

int main(void){

    printf("*** Stampa una serie di numeri inseriti dall'utente al contrario usando l'aritmetica dei puntatori ***\n\n");

    int* arr = (int[LEN]) {0};

    printf("Inserisci %d numeri: ", LEN);
    for(int* p = arr; p < arr + LEN; p++){
        scanf("%d", p);
    }

    printf("Al contrario: ");
    for(int* p = (arr + LEN) - 1; p >= arr; p--){
        printf("%d ", *p);
    }

    printf("\n");
    return 0;
}