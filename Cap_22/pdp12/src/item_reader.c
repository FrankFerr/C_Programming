#include <stdlib.h>
#include "..\include\item_reader.h"

#define LEN_BUFFER 100
#define NM_TO_READ 5

struct Item *readItems(FILE *fp);
void printItems(struct Item *head);
void clearList(struct Item *head);
// void readItems(struct Item **head, FILE *fp);

static void insertItem(struct Item **head, struct Item *newItem);
static void printHeader(void);

struct Item * readItems(FILE *fp){
    if(!fp)
        return NULL;

    struct Item *newItem = NULL, **head = (struct Item **) calloc(1, sizeof(struct Item*));
    char buffer[LEN_BUFFER + 1];
    static const char *FORMAT_STR = "%d, %lf, %2d /%2d /%4d";
    int cnRead = 0;

    while(fgets(buffer, LEN_BUFFER, fp) != NULL){

        newItem = (struct Item *) malloc(sizeof(struct Item));
        if(!newItem){
            printf("Errore nell'allocazione di memoria per un nuovo prodotto\n");
            clearList(*head);
            return NULL;
        }

        cnRead = sscanf(buffer, FORMAT_STR, &(newItem->id), &(newItem->price), &(newItem->day), &(newItem->month), &(newItem->year));
        if(cnRead != NM_TO_READ){
            printf("Errore nella lettura dei prodotti\n");
            clearList(*head);
            return NULL;
        }

        insertItem(head, newItem);
    }

    return *head;
}

static void insertItem(struct Item **head, struct Item *newItem){
    struct Item *prev, *cur;

    //ciclo su tutta la lista per trovare il punto in cui inserire il nuovo prodotto oridnandoli per id crescente
    for(prev = NULL, cur = *head; cur && newItem->id > cur->id; prev = cur, cur = cur->next)
        ;

    newItem->next = cur;
    //se prev e' NULL allora la lista e' vuota
    if(!prev)
        *head = newItem;
    else
        prev->next = newItem;

}

void clearList(struct Item *head){
    if(!head)
        return;

    struct Item *cur;
    while(head){
        cur = head;
        head = head->next;
        free(cur);
    }
}

void printItems(struct Item *head){
    printf("\n");
    printHeader();

    while(head){
        printf("%-20d$ %-18.2f%.2d/%.2d/%.4d\n", head->id, head->price, head->day, head->month, head->year);
        head = head->next;
    }

    printf("------------------------------------------------------------\n");
}

static void printHeader(void){
    static const char *HEADER_ITEM = "Item";
    static const char *HEADER_UNIT_PRICE = "Unit Price";
    static const char *HEADER_DATE = "Purchase Date";

    printf("%-20s%-20s%-20s\n", HEADER_ITEM, HEADER_UNIT_PRICE, HEADER_DATE);
}