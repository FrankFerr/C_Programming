#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\include\compress.h"
#include "..\include\uncompress.h"

#define COMPRESS "compress"
#define UNCOMPRESS "uncompress"

int main(int argc, char **argv){

    if(argc != 3){
        printf("ERRORE! Lancia: pdp7 (compress/uncompress) <nomefile>\n");
        exit(EXIT_FAILURE);
    }

    char *result;

    if(strcmp(COMPRESS, argv[1]) == 0){
        result = compress(argv[2]);
    } 
    else if(strcmp(UNCOMPRESS, argv[1]) == 0){
        result = uncompress(argv[2]);       
    }

    printf("%s\n", result);

    return 0;
}
