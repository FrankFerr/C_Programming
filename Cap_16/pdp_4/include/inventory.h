#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_PROD 100
#define NAME_LEN 20

#define FORMAT_STR " |%6d%4s|%" GET_STR_LEN(NAME_LEN) "s|%6d%5s|\n"
#define GET_STR_LEN(len) STR_LEN(len)
#define STR_LEN(l) #l

typedef struct{
    int id;
    char name[NAME_LEN + 1];
    int qta;
}  Prod;

void insert(void);
void search(void);
void update(void);
void print(void);

#endif