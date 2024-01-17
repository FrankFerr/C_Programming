#include <stdio.h>
#include <stdbool.h>
#include "..\include\inventory.h"

void printMenu(void);

int main(void){
    
    Prod inventory[MAX_PROD];
    int cnProd = 0;
    bool continuare = true;
    char op;

    printf("*** Gestione inventario ***\n\n");
    while(continuare){
        printMenu();
        scanf(" %c", &op);

        while(getchar() != '\n')
            ;
        printf("\n");

        switch(op){
            case 'i': insert(inventory, &cnProd);
                break;
            case 's': search(inventory, &cnProd);
                break;
            case 'u': update(inventory, &cnProd);
                break;
            case 'p': print(inventory, &cnProd);
                break;
            case 'q': continuare = false;
                break;
            default: printf("Operazione inesistente!\n");
        }

        printf("\n");
    }

    printf("\n");
    return 0;
}

void printMenu(void){
    printf("Scegli un opzione\n");
    printf("i) Inserisci\ns) Cerca\nu) Aggiorna\np) Stampa inventario\nq) Esci\n>");
}
