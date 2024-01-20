#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_PROD 100
#define NAME_LEN 20

#define FORMAT_STR " | %8d | %-" GET_STR_LEN(NAME_LEN) "s | %9d | %8.2f |\n"
#define GET_STR_LEN(len) STR_LEN(len)
#define STR_LEN(l) #l

struct Prod{
    int id;
    char name[NAME_LEN + 1];
    int qta;
    double price;

    struct Prod* next;
};

void insert(struct Prod* inventory);
void search(struct Prod* inventory);
void update(struct Prod* inventory);
void print(struct Prod* inventory);

#endif