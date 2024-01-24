#include <stdio.h>
#include <stdbool.h>
#include "..\include\prod_linked_list.h"

void printMenu(void);

int main(void){
    
    struct Prod *inventory = NULL;
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
            case 'i': insert(&inventory);
                break;
            case 's': search(inventory);
                break;
            case 'u': update(inventory);
                break;
            case 'p': print(inventory);
                break;
            case 'd': delete(&inventory);
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
    printf("i) Inserisci\ns) Cerca\nu) Aggiorna\np) Stampa inventario\nd) Elimina\nq) Esci\n>");
}
