#include <stdio.h>
#include <stdlib.h>
#include "..\include\file_manager.h"

int main(int argc, char **argv){

    if(argc != 2){
        printf("ERRORE! Lancia: uncompress <nomefile>\n");
        exit(EXIT_FAILURE);
    }

    char *result;

    result = uncompress(argv[1]);

    if(result != NULL){
        printf("%s\n", result);
        exit(EXIT_FAILURE);
    }

    printf("File decompresso correttamente\n");

    return 0;
}

