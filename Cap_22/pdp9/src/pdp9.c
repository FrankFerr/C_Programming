#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\include\merge.h"

struct Prod* resolve(const struct Prod* obj1, const struct Prod* obj2);

int main(int argc, char **argv){

    if(argc != 4){
        printf("Errore: lanciare pdp9 <inFile1> <inFile2> <outFile>\n");
        exit(EXIT_FAILURE);
    }

    int result = mergeFile(argv[1], argv[2], argv[3], resolve);

    if(result != 0){
        printf("Unione dei file fallita!\n");
    } else {
        printf("File uniti con successo!\n");
    }

    return result;
}

struct Prod* resolve(const struct Prod* obj1, const struct Prod* obj2){
    struct Prod* result = NULL;

    if(obj1->id == obj2->id){
        if(strcmp(obj1->name, obj2->name) != 0){
            printf("Impossibile unire prodotti con stesso codice ma con nome diverso!\n");
            return result;
        }

        result = (struct Prod *) malloc(sizeof(struct Prod));
        
        if(result){
            result->id = obj1->id;
            strcpy(result->name, obj1->name);
            result->qta = obj1->qta + obj2->qta;
        }
    }

    return result;
}