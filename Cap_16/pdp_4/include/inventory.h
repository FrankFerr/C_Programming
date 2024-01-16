#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_PROD 100
#define NAME_LEN 20

#define FORMAT_STR " | %8d | %" GET_STR_LEN(NAME_LEN) "s | %9d |\n"
#define GET_STR_LEN(len) STR_LEN(len)
#define STR_LEN(l) #l

typedef struct{
    int id;
    char name[NAME_LEN + 1];
    int qta;
} Prod;

void insert(Prod inventory[], int* cnProd);
void search(Prod inventory[], const int* cnProd);
void update(Prod inventory[], const int* cnProd);
void print(Prod inventory[], const int* cnProd);

#endif