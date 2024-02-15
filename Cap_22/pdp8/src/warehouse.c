#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "..\include\inventory.h"

void printMenu(void);

int main(void){

    bool continuare = true;
    char op;

    printf("*** Gestione inventario ***\n");
    while(continuare){
        printMenu();
        scanf(" %c", &op);

        while(getchar() != '\n')
            ;
        printf("\n");

        switch(op){
            case 'i': insert();
                break;
            case 's': search();
                break;
            case 'u': update();
                break;
            case 'p': print();
                break;
            case 'd': save();
                break;
            case 'r': load();
                break;
            case 'q': continuare = false;
                break;
            default: printf("Operazione inesistente!\n");
        }
    }

    printf("\n");
    return 0;
}

void printMenu(void){
    printf("\n");
    printf("Scegli un opzione\n");
    printf("i) Inserisci\ns) Cerca\nu) Aggiorna\np) Stampa inventario\nd) Salva\nr) Carica\nq) Esci\n>");
}
