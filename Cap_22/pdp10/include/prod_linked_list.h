#ifndef PROD_LINKED_LIST_H
#define PROD_LINKED_LIST_H

#include "..\include\prod_type_def.h"

void insert(struct Prod **head);
void insertProd(struct Prod **head, struct Prod *newProd);
void search(struct Prod *head);
void update(struct Prod *head);
void print(struct Prod *head);
void delete(struct Prod **head);
void clearList(struct Prod *head);

#endif