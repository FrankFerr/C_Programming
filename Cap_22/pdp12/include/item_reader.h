#ifndef ITEM_READER_H
#define ITEM_READER_H

#include <stdio.h>

#define DATA_PATH "../data/"

struct Item{
    int id;
    double price;
    int day;
    int month;
    int year;

    struct Item *next;
};

struct Item *readItems(FILE *fp);
// void readItems(struct Item **head, FILE *fp);
void printItems(struct Item *head);
void clearList(struct Item *head);

#endif