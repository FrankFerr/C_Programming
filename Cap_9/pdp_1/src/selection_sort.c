#include <stdio.h>

#define LEN 10

void selectionSort(int a[], int n);

int main(void){

    printf("*** Oridna un array di interi con l'algoritmo Selection Sort ***\n\n");

    int num[LEN] = {0};

    printf("Inserisci %d numeri interi: ", LEN);
    for(int i = 0; i < LEN; i++){
        scanf("%d", &num[i]);
    }

    selectionSort(num, LEN);

    printf("\n");
    printf("Ordine crescente: ");
    for(int i = 0; i < LEN; i++){
        printf("%4d", num[i]);
    }


    printf("\n");
    return 0;
}

void selectionSort(int a[], int n){
    if(n == 0)
        return;

    int idxMax = 0, temp = 0;

    for(int i = 0; i < n; i++){
        if(a[idxMax] < a[i]){
            idxMax = i;
        }
    }

    temp = a[n - 1];
    a[n - 1] = a[idxMax];
    a[idxMax] = temp;

    selectionSort(a, n - 1);
}