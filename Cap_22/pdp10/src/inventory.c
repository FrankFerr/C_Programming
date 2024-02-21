#include <stdio.h>
#include <stdbool.h>
#include "..\include\prod_list.h"

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
            case 'r': dump(inventory);
                break;
            case 'l': load(&inventory);
                break;
            case 'q': clearList(inventory);
                      continuare = false;
                break;
            default: printf("Operazione inesistente!\n");
        }

        printf("\n");
    }

    return 0;
}

void printMenu(void){
    printf("Scegli un opzione\n");
    printf("i) Inserisci\ns) Cerca\nu) Aggiorna\np) Stampa inventario\nd) Elimina\nr) Salva\nl) Carica\nq) Esci\n>");
}
