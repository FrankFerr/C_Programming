#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_EXT ".rel"
#define SIZE_BUFF 4

int main(int argc, char **argv){

    if(argc != 2){
        printf("ERRORE! Lancia: compress <nomefile>");
        exit(EXIT_FAILURE);
    }

    FILE *inFile, *outFile;
    size_t lenFileName = 0;
    char *compressFileName, buff[SIZE_BUFF + 1];
    int ch, lastCh = EOF, cntBytes = 0;

    if((inFile = fopen(argv[1], "rb")) == NULL){
        printf("Impossibile aprire %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    //calcolo la lunghezza del nome del file per allocare memoria per la stringa
    lenFileName = sizeof(char) * strlen(argv[1]) + sizeof(char) * strlen(FILE_EXT);
    compressFileName = (char *) malloc(lenFileName + 1);

    //genero il nome del file compresso
    strcpy(compressFileName, argv[1]);
    strcat(compressFileName, FILE_EXT);

    if((outFile = fopen(compressFileName, "wb")) == NULL){
        printf("Impossibile creare il file compresso\n");
        exit(EXIT_FAILURE);
    }

    //comprimo il file
    lastCh = ch = fgetc(inFile);
    while(ch != EOF){
        cntBytes++;
        ch = fgetc(inFile);
        
        if(lastCh != ch){
            //fprintf(outFile, "%.2d%.2X", cntBytes, lastCh);
            sprintf(buff, "%.2d%.2X", cntBytes, lastCh);
            fputs(buff, outFile);

            lastCh = ch;
            cntBytes = 0;
        }

    }

    fclose(inFile);
    fclose(outFile);

    printf("File compresso: %s\n", compressFileName);

    return 0;
}