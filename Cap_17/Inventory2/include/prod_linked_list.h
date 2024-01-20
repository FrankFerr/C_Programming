#ifndef PROD_LINKED_LIST_H
#define PROD_LINKED_LIST_H

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

struct Prod *insert(struct Prod *head);
void search(struct Prod *head);
void update(struct Prod *head);
void print(struct Prod *head);
struct Prod * delete(struct Prod *head);

#endif