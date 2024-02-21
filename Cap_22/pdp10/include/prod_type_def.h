#ifndef PROD_TYPE_DEF_H
#define PROD_TYPE_DEF_H

#define NAME_LEN 20

struct Prod{
    int id;
    char name[NAME_LEN + 1];
    int qta;
    double price;

    struct Prod* next;
};

#endif