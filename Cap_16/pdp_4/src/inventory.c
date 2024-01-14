#include <stdio.h>
#include "..\include\readline.h"
#include "..\include\inventory.h"

struct Prod{
    int id;
    char name[NAME_LEN + 1];
    int qta;
} inventory[MAX_PROD];

int cnProd = 0;

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
