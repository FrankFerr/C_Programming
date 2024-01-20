#include <stdio.h>
#include <stdbool.h>
#include "..\include\readline.h"
#include "..\include\inventory.h"

/*findProd: cerca, all'interno di una lista concatenata puntata da head, un nodo con id uguale a pId.
            Restituisce un puntatore */
struct Prod* findProd(struct Prod* head, int pId){

    while(head != NULL && pId > head->id)
        head = head->next;

    return head->id == pId ? head : NULL;
}

//scrive l'intestazione del prodotto
void printHeader(void){
    printf("\n");
    printf("  --------------------------------------------------------\n");
    printf(" | Prod. Id |        Nome          | Quantita' |  Prezzo  |\n");
    printf("  --------------------------------------------------------\n");
}

// scrive il footer
void printFooter(void){
    printf("  --------------------------------------------------------\n\n");
}

// scrive il prodotto formattato
void printProd(struct Prod* p){
    // printf(FORMAT_STR, p->id, p->name, p->qta, p->price);
    printf(FORMAT_STR, p->id, p->name, p->qta, p->price);
}

//funzione per l'inserimento di un nuovo prodotto con le informazioni inserite dall'utente
void insert(struct Prod* head){
    

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

    printf("Prezzo: ");
    scanf("%lf", &inventory[*cnProd].price);

    if(inventory[*cnProd].price < 0)
        inventory[*cnProd].price = 0;

    ++*cnProd;
}

//cerca e scrive un prodotto in base all'id inserito dall'utente
void search(Prod inventory[], const int* cnProd){
    int id, idx;
    
    printf("Inserisci il codice del prodotto da cercare: ");
    scanf("%d", &id);

    idx = findProd(inventory, cnProd, id);

    if(idx == -1){
        printf("Prodotto non trovato!\n");
        return;
    }

    printHeader();
    printProd(&inventory[idx]);
    printFooter();
}

// aggiorna il nome di un prodotto
void updateName(Prod* p){
    printf("Nome attuale: %s\n", (*p).name);

    printf("Nuovo Nome: ");
    readLine((*p).name, NAME_LEN);

    printf("Nome aggiornato!\n");
}

// aggiorna la quantita' di un prodotto
void updateQta(Prod* p){
    int inQta = 0;

    printf("Quantita' attuale: %d\n", (*p).qta);

    printf("Inserisci la quantita' da sommare: ");
    scanf("%d", &inQta);

    (*p).qta += inQta;

    printf("Quantita' aggiornata: %d\n", (*p).qta);
}

// aggiorna il prezzo di un prodotto
void updatePrice(Prod* p){
    
    printf("Prezzo attuale: %.2f\n", (*p).price);

    printf("Inserisci il nuovo prezzo: ");
    scanf("%lf", &(*p).price);

    printf("Prezzo aggiornato!\n");
}

//permette di aggiornare una qualsiasi proprieta' di un prodotto
void update(Prod inventory[], const int* cnProd){
    int id, idx;
    char ch;
    bool exit = false;
    
    printf("Inserisci il codice del prodotto da aggiornare: ");
    scanf("%d", &id);
    getchar();

    idx = findProd(inventory, cnProd, id);

    if(idx == -1){
        printf("Prodotto non trovato!\n");
        return;
    }

    printHeader();
    printProd(&inventory[idx]);
    printFooter();

    while(!exit){
        printf("Cosa vuoi modificare?\n");
        printf("1) Nome\n2) Quantita'\n3) Prezzo\nx) Esci\n>");
        ch = (char) getchar();
        getchar();

        printf("\n");
        switch(ch){
            case '1': updateName(&inventory[idx]);
                break;
            case '2': updateQta(&inventory[idx]);
                break;
            case '3': updatePrice(&inventory[idx]);
                break;
            default: exit = true;
        }

        printHeader();
        printProd(&inventory[idx]);
        printFooter();
    }
}

//scrive tutto l'inventario
void print(Prod inventory[], const int* cnProd){
    selectionSort(inventory, *cnProd);
    
    printHeader();

    for(int i = 0; i < *cnProd; i++){
        printProd(&inventory[i]);
    }

    printFooter();
}
