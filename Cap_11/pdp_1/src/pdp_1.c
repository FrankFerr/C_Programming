#include <stdio.h>

void payAmount(int totale, int* venti, int* dieci, int* cinque, int* uno);

int main(void){

    printf("*** Calcola quante banconote da 20, 10, 5 e moneta da 1 ***\n\n");

    int totale = 0, venti = 0, dieci = 0, cinque = 0, uno = 0;

    printf("Inserisci un totale da calcolare: ");
    scanf("%d", &totale);
    getchar();

    while(totale > 0){
        payAmount(totale, &venti, &dieci, &cinque, &uno);

        printf("\nPer pagare %d hai bisogno di:\n", totale);
        printf("20 (Venti):  %d\n", venti);
        printf("10 (Dieci):  %d\n", dieci);
        printf(" 5 (Cinque): %d\n", cinque);
        printf(" 1 (Uno):    %d\n\n", uno);

        printf("Inserisci un totale da calcolare: ");
        scanf("%d", &totale);
        getchar();
    }

    printf("\n");
    return 0;
}

void payAmount(int totale, int* venti, int* dieci, int* cinque, int* uno){

    while(totale > 0){
        if(totale >= 20){
            *venti = totale / 20;
            totale -= (*venti * 20);
        } else if(totale >= 10){
            *dieci = totale / 10;
            totale -= (*dieci * 10);
        }else if(totale >= 5){
            *cinque = totale / 5;
            totale -= (*cinque * 5);
        }else{
            *uno = totale;
            totale -= *uno;
        }
    }
}