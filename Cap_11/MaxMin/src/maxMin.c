#include <stdio.h>

#define N 10

void findMinMax(int arr[], int *min, int *max);

int main(void){

    printf("*** Stampa il numero minore e maggiore in una serie di numeri in input ***\n\n");

    int arr[N] = {0};
    int min = 0, max = 0;

    printf("Inserisci 10 numeri: ");
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }

    findMinMax(arr, &min, &max);

    printf("Max: %d\nMin: %d\n", max, min);

    printf("\n");
    return 0;
}

void findMinMax(int arr[], int *min, int *max){
    *min = *max = arr[0];

    for(int i = 1; i < N; i++){
        if(*min > arr[i]){
            *min = arr[i];
        }

        if(*max < arr[i]){
            *max = arr[i];
        }
    }
}