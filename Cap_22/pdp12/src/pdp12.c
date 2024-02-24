#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/item_reader.h"

int main(int argc, char **argv){
    
    FILE *fp;
    struct Item *head = NULL;
    char filepath[30];

    if(argc != 2){
        printf("Errore: lanciare -> pdp12 <nome_file>\n");
        exit(EXIT_FAILURE);
    }

    strcpy(filepath, DATA_PATH);
    strcat(filepath, argv[1]);

    if((fp = fopen(filepath, "r")) == NULL){
        printf("Errore: impossibile aprire %s\n", filepath);
        exit(EXIT_FAILURE);
    }

    head = readItems(fp);

    if(head){
        printItems(head);
    }

    clearList(head);
    fclose(fp);

    return 0;
}