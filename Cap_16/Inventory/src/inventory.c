#include <stdio.h>
#include <stdbool.h>
#include "..\include\readline.h"

#define MAX_PROD 100
#define NAME_LEN 20

void insert(void);
void search(void);
int findProd(int id);
void update(void);
void print(void);
void printMenu(void);

struct Prod{
    int id;
    char name[NAME_LEN + 1];
    int qta;
} inventory[MAX_PROD];

int cnProd = 0;

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
            case 'q': continuare = false;
                break;
            default: printf("Operazione inesistente!\n");
        }
    }

    printf("\n");
    return 0;
}

void insert(void){
    int id = 0;

    if(cnProd == MAX_PROD){
        printf("Database pieno!\n");
        return;
    }

    printf("Inserimento nuovo prodotto\n");
    printf("Codice: ");
    scanf("%d", &id);

    if(id < 1)
        id = cnProd + 1;

    if(findProd(id) != -1){
        printf("Prodotto gia' inserito!\n", id);
        return;
    }

    inventory[cnProd].id = id;

    printf("Nome: ");
    readLine(inventory[cnProd].name, NAME_LEN);

    printf("Quantita': ");
    scanf("%d", &inventory[cnProd].qta);

    if(inventory[cnProd].qta < 0)
        inventory[cnProd].qta = 0;

    cnProd++;
}

void search(void){
    int id, idx;
    
    printf("Inserisci il codice del prodotto da cercare: ");
    scanf("%d", &id);

    idx = findProd(id);

    if(idx == -1){
        printf("Prodotto non trovato!\n", id);
        return;
    }

    printf("Nome: %s\nQuantita': %d\n", inventory[idx].name, inventory[idx].qta);

}

int findProd(int id){
    int idxFound = -1;

    for(int i = 0; id > 0 && i < cnProd; i++){
        if(inventory[i].id == id){
            idxFound = i;
            break;
        }
    }

    return idxFound;
}

void update(void){
    int id, idx, qtaSum;
    
    printf("Inserisci il codice del prodotto da aggiornare: ");
    scanf("%d", &id);

    idx = findProd(id);

    if(idx == -1){
        printf("Prodotto non trovato!\n", id);
        return;
    }

    printf("Quantita' attuale: %d\n", inventory[idx].qta);

    printf("Inserisci la quantita' da sommare: ");
    scanf("%d", &qtaSum);

    inventory[idx].qta += qtaSum;

    printf("Quantita' aggiornata: %d\n", inventory[idx].qta);
    
}

void print(void){
    
    printf(" -------------------------------------------\n");
    printf("| Prod. Id |        Nome        | Quantita' |\n");
    printf(" -------------------------------------------\n");

    for(int i = 0; i < cnProd; i++){
        printf("|%6d%4s|%20s|%6d%5s|\n", inventory[i].id, " ", inventory[i].name, inventory[i].qta, " ");
    }

    printf(" -------------------------------------------\n");
}

void printMenu(void){
    printf("\n");
    printf("Scegli un opzione\n");
    printf("i) Inserisci\ns) Cerca\nu) Aggiorna\np) Stampa inventario\nq) Esci\n>");
}
