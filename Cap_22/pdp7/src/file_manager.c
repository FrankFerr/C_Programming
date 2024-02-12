#include <stdlib.h>
#include <string.h>
#include "..\include\file_manager.h"

static const char *REL_EXT = ".rel";
static const char *TXT_EXT = ".txt";

static int hasExtension(const char *filename, const char *ext);
static char *getFilenameWhitoutExt(const char *filename);
char *uncompress(const char *filename);

/// @brief Controlla se filename ha come estensione ext
/// @param filename nome del file da controllare
/// @param ext estensione del file da controllare
/// @return Un valore diverso da 0 se filename ha come estensione ext, altrimenti 0
static int hasExtension(const char *filename, const char *ext){
    int result = 0, lenFileName = 0, lenExt = 0;
    
    if(filename != NULL && ext != NULL){
        lenFileName = strlen(filename);
        lenExt = strlen(ext);

        if(lenFileName > lenExt){
            result = 1;

            while(lenExt > 0){
                if(filename[lenFileName - 1] != ext[lenExt - 1]){
                    result = 0;
                    break;
                }

                lenExt--;
                lenFileName--;
            }
        }
    }

    return result;
}

/// @brief Alloca memoria per il nome del file senza estensione e restituisce il puntatore al primo carattere
/// @param filename stringa da cui estrapolare il nome del file
/// @return un puntatore al nome del file senza estensione, altrimenti NULL
static char *getFilenameWhitoutExt(const char *filename){
    char *newFilename = NULL;
    int lenFilename;

    if(filename != NULL && hasExtension(filename, REL_EXT)){
        lenFilename = strlen(filename);

        while(lenFilename > 0 && filename[lenFilename] != '.')
            lenFilename--;

        if(lenFilename > 0){
            newFilename = (char *) malloc(sizeof(char) * lenFilename);
            
            if(newFilename != NULL){
                strncpy(newFilename, filename, lenFilename);
                newFilename[lenFilename] = '\0';
            }
        }
    }

    return newFilename;
}

/// @brief Decomprime un file, indicato dal parametro filename, con estensione '.rel'. Il risultato viene salvato in un file omonimo con estensione '.txt'
/// @param filename percorso completo del file
/// @return Una stringa rappresentante il messaggio di errore, altrimenti NULL
char *uncompress(const char *filename){
    FILE *inFile, *outFile;
    int ch, cntChar = 0, lenOutFile = 0;
    char *outFilename, *temp;

    //controllo l'estensione del file
    if(!hasExtension(filename, REL_EXT)){
        return "File non valido!";
    }

    //recupero il nome del file
    if((outFilename = getFilenameWhitoutExt(filename)) == NULL){
        return "Errore durante la generazione del file di output";
    }

    //se non ha l'estensione .txt, la aggiungo
    if(!hasExtension(outFilename, TXT_EXT)){
        lenOutFile = strlen(outFilename) + strlen(TXT_EXT) + 1;
        
        //cerco di allocare spazio per l'estensione
        temp = realloc(outFilename, lenOutFile);
        if(temp == NULL){
            free(outFilename);
            return"Errore durante la generazione del file di output";
        }
        outFilename = temp;
        temp = NULL;

        strcat(outFilename, TXT_EXT);
    }

    //provo ad aprire i file
    if((inFile = fopen(filename, "rb")) == NULL){
        free(outFilename);
        return "Impossibile aprire il file in input";
    }

    if((outFile = fopen(outFilename, "w")) == NULL){
        free(outFilename);
        return "Impossibile salvare il file decompresso";
    }

    //decomprimo il file
    while(fscanf(inFile, "%2d%2X", &cntChar, &ch) != EOF){
        for(int i = 0; i < cntChar; i++)
            fputc((char) ch, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    free(outFilename);

    return NULL;
}