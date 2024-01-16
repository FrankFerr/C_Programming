#include <stdio.h>
#include "..\include\readline.h"
#include "..\include\inventory.h"
#include "..\include\quicksort.h"
#include "..\include\selection_sort.h"

int findProd(Prod inventory[], const int* cnProd, int id){
    int idxFound = -1;

    for(int i = 0; id > 0 && i < *cnProd; i++){
        if(inventory[i].id == id){
            idxFound = i;
            break;
        }
    }

    return idxFound;
}

void insert(Prod inventory[], int* cnProd){
    int id = 0;

    if(*cnProd == MAX_PROD){
        printf("Database pieno!\n");
        return;
    }

    printf("Inserimento nuovo prodotto\n");
    printf("Codice: ");
    scanf("%d", &id);

    if(id < 1)
        id = *cnProd + 1;

    if(findProd(inventory, cnProd, id) != -1){
        printf("Prodotto gia' inserito!\n");
        return;
    }

    inventory[*cnProd].id = id;

    printf("Nome: ");
    readLine(inventory[*cnProd].name, NAME_LEN);

    printf("Quantita': ");
    scanf("%d", &inventory[*cnProd].qta);

    if(inventory[*cnProd].qta < 0)
        inventory[*cnProd].qta = 0;

    (*cnProd)++;
}

void search(Prod inventory[], const int* cnProd){
    int id, idx;
    
    printf("Inserisci il codice del prodotto da cercare: ");
    scanf("%d", &id);

    idx = findProd(inventory, cnProd, id);

    if(idx == -1){
        printf("Prodotto non trovato!\n");
        return;
    }

    printf("Nome: %s\nQuantita': %d\n", inventory[idx].name, inventory[idx].qta);

}

void update(Prod inventory[], const int* cnProd){
    int id, idx, qtaSum;
    
    printf("Inserisci il codice del prodotto da aggiornare: ");
    scanf("%d", &id);

    idx = findProd(inventory, cnProd, id);

    if(idx == -1){
        printf("Prodotto non trovato!\n");
        return;
    }

    printf("Quantita' attuale: %d\n", inventory[idx].qta);

    printf("Inserisci la quantita' da sommare: ");
    scanf("%d", &qtaSum);

    inventory[idx].qta += qtaSum;

    printf("Quantita' aggiornata: %d\n", inventory[idx].qta);
    
}

void print(Prod inventory[], const int* cnProd){
    selectionSort(inventory, *cnProd);
    
    printf("  ---------------------------------------------\n");
    printf(" | Prod. Id |        Nome          | Quantita' |\n");
    printf("  ---------------------------------------------\n");

    for(int i = 0; i < *cnProd; i++){
        // printf("|%6d%4s|%20s|%6d%5s|\n", inventory[i].id, " ", inventory[i].name, inventory[i].qta, " ");
        printf(FORMAT_STR, inventory[i].id, inventory[i].name, inventory[i].qta);
    }

    printf("  ---------------------------------------------\n");
}
