#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "..\include\readline.h"
#include "..\include\inventory.h"

int qtaAttuale = 0;

void insert(Prod inventory[], int* cnProd);
void search(Prod inventory[], const int* cnProd);
void update(Prod inventory[], const int* cnProd);
void print(Prod inventory[], const int* cnProd);
int findProd(Prod inventory[], const int* cnProd, int id);
void initList(Prod **list, int qtaIniziale);
void resizeList(Prod **list);
void printHeader(void);
void printFooter(void);
void printProd(Prod* p);
void updateName(Prod* p);
void updateQta(Prod* p);
void updatePrice(Prod* p);
int compareProd(const void *p1, const void *p2);

//Alloca n bytes di memoria moltiplicati per qtaIniziale per inizializzare la lista e 
//memorizza la qtaAttuale nella variabile globale
void initList(Prod **list, int qtaIniziale){
    *list = malloc(sizeof(Prod) * qtaIniziale);

    if(!*list){
        printf("ERRORE: Non e' stato possibile inizializzare la lista!\n");
        exit(EXIT_FAILURE);
    }

    qtaAttuale = qtaIniziale;
}

//Espande la lista allocando il doppio della memoria attualmente in uso
void resizeList(Prod **list){
    qtaAttuale *= 2;

    *list = realloc(*list, sizeof(Prod) * qtaAttuale);

    if(!*list){
        printf("ERRORE: Non e' stato possibile espandere la lista!\n");
        exit(EXIT_FAILURE);
    }
}


//funzione per l'inserimento di un nuovo prodotto con le informazioni inserite dall'utente
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

//ritorna l'indice corrispondente all'id passato, -1 se non lo trova
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

//scrive tutto l'inventario ordinato per Id
void print(Prod inventory[], const int* cnProd){
    qsort(inventory, *cnProd, sizeof(Prod), compareProd);

    printHeader();

    for(int i = 0; i < *cnProd; i++){
        printProd(&inventory[i]);
    }

    printFooter();
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
void printProd(Prod* p){
    // printf(FORMAT_STR, p->id, p->name, p->qta, p->price);
    printf(FORMAT_STR, (*p).id, (*p).name, (*p).qta, (*p).price);
}

//Descrive come devono essere ordinati gli oggetti Prod
int compareProd(const void *p1, const void *p2){
    return ((Prod *) p1)->id - ((Prod *) p2)->id;
}
