#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "..\include\readline.h"
#include "..\include\prod_linked_list.h"

int cnProd = 0;

/*cerca, all'interno di una lista concatenata puntata da head, un nodo con id uguale a pId.
  Restituisce un puntatore all'elemento cercato se esiste, altrimenti un puntatore nullo*/
struct Prod* findProd(struct Prod* head, int pId){

    while(head && pId > head->id)
        head = head->next;

    return (head && head->id == pId) ? head : NULL;
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
void printProd(struct Prod *p){
    // printf(FORMAT_STR, p->id, p->name, p->qta, p->price);
    printf(FORMAT_STR, p->id, p->name, p->qta, p->price);
}

//Inserisce un nuovo prodotto con le informazioni fornite dall'utente 
struct Prod *insert(struct Prod *head){
    struct Prod *prev, *cur;

    struct Prod *newProd = malloc(sizeof(struct Prod));

    if(!newProd){
        printf("Database pieno!\n");
        return NULL;
    }

    printf("Inserimento nuovo prodotto\n");
    printf("Codice: ");
    scanf("%d", &newProd->id);

    if(newProd->id < 1)
        newProd->id = cnProd + 1;

    //ciclo su tutta la lista per trovare il punto in cui inserire il nuovo prodotto oridnandoli per id crescente
    for(prev = NULL, cur = head; 
        cur && newProd->id > cur->id; 
        prev = cur, cur = cur->next)
        ;

    if(cur && cur->id == newProd->id){
        printf("Prodotto gia' inserito!\n");
        free(newProd);
        return NULL;
    }

    printf("Nome: ");
    readLine(newProd->name, NAME_LEN);

    printf("Quantita': ");
    scanf("%d", &newProd->qta);

    if(newProd->qta < 0)
        newProd->qta = 0;

    printf("Prezzo: ");
    scanf("%lf", &newProd->price);

    if(newProd->price < 0)
        newProd->price = 0;

    newProd->next = cur;
    //se prev e' NULL allora la lista e' vuota
    if(!prev)
        head = newProd;
    else
        prev->next = newProd;

    cnProd++;
    printf("Prodotto inserito correttamente!\n");
    
    return head;
}

//cerca e scrive un prodotto in base all'id inserito dall'utente
void search(struct Prod *head){
    int id;
    
    printf("Inserisci il codice del prodotto da cercare: ");
    scanf("%d", &id);
    getchar();

    head = findProd(head, id);

    if(!head){
        printf("Prodotto non trovato!\n");
        return;
    }

    printHeader();
    printProd(head);
    printFooter();
}

// aggiorna il nome di un prodotto
void updateName(struct Prod *p){
    printf("Nome attuale: %s\n", p->name);

    printf("Nuovo Nome: ");
    readLine(p->name, NAME_LEN);

    printf("Nome aggiornato!\n");
}

// aggiorna la quantita' di un prodotto
void updateQta(struct Prod *p){
    int inQta = 0;

    printf("Quantita' attuale: %d\n", p->qta);

    printf("Inserisci la quantita' da sommare: ");
    scanf("%d", &inQta);

    p->qta += inQta;

    printf("Quantita' aggiornata: %d\n", p->qta);
}

// aggiorna il prezzo di un prodotto
void updatePrice(struct Prod *p){
    
    printf("Prezzo attuale: %.2f\n", p->price);

    printf("Inserisci il nuovo prezzo: ");
    scanf("%lf", &p->price);

    if(p->price < 0)
        p->price = 0;

    printf("Prezzo aggiornato!\n");
}

//permette di aggiornare una qualsiasi proprieta' di un prodotto
void update(struct Prod *head){
    int id, idx;
    char ch;
    bool exit = false;
    
    printf("Inserisci il codice del prodotto da aggiornare: ");
    scanf("%d", &id);
    getchar();

    head = findProd(head, id);

    if(!head){
        printf("Prodotto non trovato!\n");
        return;
    }

    printHeader();
    printProd(head);
    printFooter();

    while(!exit){
        printf("Cosa vuoi modificare?\n");
        printf("1) Nome\n2) Quantita'\n3) Prezzo\nx) Esci\n>");
        ch = (char) getchar();
        getchar();

        printf("\n");
        switch(ch){
            case '1': updateName(head);
                break;
            case '2': updateQta(head);
                break;
            case '3': updatePrice(head);
                break;
            default: exit = true;
        }

        if(!exit){
            printHeader();
            printProd(head);
            printFooter();
        }
    }
}

//scrive tutto l'inventario
void print(struct Prod *head){
    
    printHeader();

    while(head){
        printProd(head);
        head = head->next;
    }

    printFooter();
}

//Elimina un prodotto dalla lista se esiste
struct Prod *delete(struct Prod *head){
    int id;
    struct Prod *prev, *cur;
    
    printf("Inserisci il codice del prodotto da eliminare: ");
    scanf("%d", &id);
    getchar();
    
    //ciclo su tutta la lista per trovare il punto in cui inserire il nuovo prodotto oridnandoli per id crescente
    for(prev = NULL, cur = head; 
        cur && id > cur->id; 
        prev = cur, cur = cur->next)
        ;

    if(!cur)
        return head;
    if(!prev)
        head = head->next;
    else
        prev->next = cur->next;
    
    free(cur);
    cnProd--;
    printf("Prodotto eliminato correttamente!\n");

    return head;
}