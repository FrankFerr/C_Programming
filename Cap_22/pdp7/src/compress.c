#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_BUFF 4

static const char *REL_EXT = ".rel";

char *compress(const char *filename){

    FILE *inFile, *outFile;
    size_t lenFileName = 0;
    char *compressFileName, buff[SIZE_BUFF + 1];
    int ch, lastCh = EOF, cntBytes = 0;

    if((inFile = fopen(filename, "rb")) == NULL){
        return "Impossibile aprire il file";
    }

    //calcolo la lunghezza del nome del file per allocare memoria per la stringa
    lenFileName = sizeof(char) * strlen(filename) + sizeof(char) * strlen(REL_EXT);
    compressFileName = (char *) malloc(lenFileName + 1);

    //genero il nome del file compresso
    strcpy(compressFileName, filename);
    strcat(compressFileName, REL_EXT);

    if((outFile = fopen(compressFileName, "wb")) == NULL){
        return "Impossibile creare il file compresso";
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

    free(compressFileName);
    fclose(inFile);
    fclose(outFile);

    return "File compresso!";
}