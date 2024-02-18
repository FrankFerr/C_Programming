#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "..\include\merge.h"

#define LEN_BUFFER 20
#define DEBUG 1
#define DATA_PATH "data/"

// PROTOTIPI ***********************************
int mergeFile(
    const char *inFilename1, 
    const char *inFilename2, 
    const char *outFilename, 
    struct Prod *(*resolve)(const struct Prod *obj1, const struct Prod *obj2)
);
static char *getFilenameWithPath(const char *filename);
static FILE *openFile(const char* filename, const char *mode);
//******************************************************

int mergeFile(
    const char *inFilename1, 
    const char *inFilename2, 
    const char *outFilename, 
    struct Prod *(*resolve)(const struct Prod *obj1, const struct Prod *obj2)
){
    FILE *inFile1, *inFile2, *outFile;
    struct Prod buffer1[LEN_BUFFER], buffer2[LEN_BUFFER], *pElem1 = NULL, *pElem2 = NULL, *pToWrite = NULL;
    int cntElem1 = 0, cntElem2 = 0, idx1 = 0, idx2 = 0, cntWrote = 0;
    const size_t sizeElem = sizeof(struct Prod);
    bool bFreeStruct = false;

    inFile1 = openFile(inFilename1, "rb");
    if(!inFile1){
        printf("Impossibile aprire %s\n", inFilename1);
        return 1;
    }

    inFile2 = openFile(inFilename2, "rb");
    if(!inFile2){
        printf("Impossibile aprire %s\n", inFilename2);
        return 1;
    }

    cntElem1 = fread(buffer1, sizeElem, LEN_BUFFER, inFile1);
    cntElem2 = fread(buffer2, sizeElem, LEN_BUFFER, inFile2);

    if((cntElem1 + cntElem2) == 0){
        printf("I file sono vuoti\n");
        fclose(inFile1);
        fclose(inFile2);
        return 1;
    }

    outFile = openFile(outFilename, "wb");
    if(!outFile){
        printf("Impossibile aprire %s\n", outFilename);
        return 1;
    }

    while((cntElem1 + cntElem2) != 0){
        idx1 = 0;
        idx2 = 0;
        
        while(idx1 < cntElem1 || idx2 < cntElem2){
            if(idx1 < cntElem1 && !pElem1){
                pElem1 = &buffer1[idx1];
                idx1++;
            }

            if(idx2 < cntElem2 && !pElem2){
                pElem2 = &buffer2[idx2];
                idx2++;
            }

            if(pElem1)
                pToWrite = pElem1;

            if(pElem2)
                pToWrite = pElem2;

            if(pElem1 && pElem2){
                if(pElem1->id == pElem2->id){
                    pToWrite = (*resolve)(pElem1, pElem2);
                    bFreeStruct = true;
                } 
                else if(pElem1->id < pElem2->id){
                    pToWrite = pElem1;
                }
                else{
                    pToWrite = pElem2;
                }
            }

            if(!pToWrite){
                printf("Errore durante l'unione dei file.\n");
                fclose(inFile1);
                fclose(inFile2);
                fclose(outFile);
                return 1;
            }

            cntWrote = fwrite(pToWrite, sizeElem, 1, outFile);

            if(pToWrite == pElem1)
                pElem1 = NULL;
            else if(pToWrite == pElem2)
                pElem2 = NULL;
            else
                pElem1 = pElem2 = NULL;

            if(bFreeStruct){
                free(pToWrite);
                bFreeStruct = false;
            }

            if(cntWrote == 0){
                printf("Errore durante l'unione dei file.\n");
                fclose(inFile1);
                fclose(inFile2);
                fclose(outFile);
                return 1;
            }

        }

        cntElem1 = fread(buffer1, sizeElem, LEN_BUFFER, inFile1);
        cntElem2 = fread(buffer2, sizeElem, LEN_BUFFER, inFile2);

    }

    return 0;
}

static char *getFilenameWithPath(const char *filename){
    int lenNewFilename = 0;
    char *newFilename = NULL;

    lenNewFilename = strlen(filename) + strlen(DATA_PATH) + 1;
    newFilename = (char *) malloc(sizeof(char) * lenNewFilename);

    if(newFilename){
        strcpy(newFilename, DATA_PATH);
        strcat(newFilename, filename);
    }

    return newFilename;
}

static FILE *openFile(const char* filename, const char *mode){
    char* newInFilename;
    FILE *fp = NULL;

    newInFilename = getFilenameWithPath(filename);

    fp = fopen(newInFilename, mode);
    free(newInFilename);

    return fp;
}