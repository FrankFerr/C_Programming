#include <stdio.h>
#include <stdbool.h>
#include "..\include\readline.h"

#define MAX_PROD 100
#define NAME_LEN 20

void insert(void);
void search(void);
int findProd(int code);
void update(void);
void print(void);
void printMenu(void);

typedef struct {
    int code;
    char name[NAME_LEN + 1];
    int qta;
} Prod;

int cnProd = 0;

int main(void){

    Prod inventory[MAX_PROD];
    bool continuare = true;
    char op;

    printf("*** Gestione inventario ***\n");
    while(continuare){
        printMenu();
        scanf(" %c", &op);

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