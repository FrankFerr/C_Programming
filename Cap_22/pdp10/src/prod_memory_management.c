#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\include\prod_memory_management.h"
#include "..\include\readline.h"
#include "..\include\prod_linked_list.h"

#define DATA_PATH "../data"
#define FILENAME_LENGTH 25

struct DataProd{
    int id;
    char name[NAME_LEN + 1];
    int qta;
    double price;
};

// PROTOTIPI FUNZIONE **********************************
void dump(struct Prod *head);
void load(struct Prod **head);

static char *getFilename(void);
static int saveList(const struct Prod *p, FILE *fp);
static int loadList(struct Prod **head, FILE *fp);
// *****************************************************

void dump(struct Prod *head){
    char *filePath, *filename;
    FILE *fp;
    int resWrite = 0, lenFilepath = 0;
    struct Prod *cur, *prev;

    if(!head){
        printf("Nessun prodotto in memoria.\n");
        return;
    }

    filename = getFilename();
    if(filename == NULL){
        printf("Impossibile salvare i dati\n");
        return;
    }

    lenFilepath = strlen(DATA_PATH) + 1 + strlen(filename) + 1;
    filePath = (char *) malloc(sizeof(char) * lenFilepath);

    if(filePath == NULL){
        printf("Impossibile salvare i dati\n");
        return;
    }

    strcpy(filePath, DATA_PATH);
    strcat(strcat(filePath, "/"), filename);
    filePath[lenFilepath] = '\0';
    free(filename);

    printf("Sto tentando di aprire %s\n", filePath);

    if((fp = fopen(filePath, "wb")) == NULL){
        free(filePath);
        printf("Impossibile generare il file\n");
        return;
    }

    // salvataggio prodotti
    resWrite = saveList(head, fp);

    fclose(fp);

    if(resWrite){
        printf("Impossibile salvare i dati\n");
        remove(filePath);
    } else {
        printf("Salvataggio avvenuto con successo!\n");
    }
    
    free(filePath);
}

static char *getFilename(void){
    char *filename = (char *) malloc(sizeof(char) * (FILENAME_LENGTH + 1));

    if(filename != NULL){
        printf("Inserisci il nome del file (max %d caratteri): ", FILENAME_LENGTH);
        readLine(filename, FILENAME_LENGTH);
    }

    return filename;
}

static int saveList(const struct Prod *head, FILE *fp){
    int cnWrote = 0, result = 0;
    struct DataProd saveData;

    while(!result && head){
        saveData.id = head->id;
        strcpy(saveData.name, head->name);
        saveData.qta = head->qta;
        saveData.price = head->price;

        cnWrote = fwrite(&saveData, sizeof(struct DataProd), 1, fp);
        result = cnWrote == 1 ? 0 : 1;

        head = head->next;
    }

    return result;
}

void load(struct Prod **head){
    char *filePath, *filename;
    FILE *fp;
    int resWrite = 0, lenFilepath = 0;
    struct Prod *newList;

    filename = getFilename();
    if(filename == NULL){
        printf("Impossibile caricare i dati\n");
        return;
    }

    lenFilepath = strlen(DATA_PATH) + 1 + strlen(filename) + 1;
    filePath = (char *) malloc(sizeof(char) * lenFilepath);

    if(filePath == NULL){
        printf("Impossibile caricare i dati\n");
        return;
    }

    strcpy(filePath, DATA_PATH);
    strcat(strcat(filePath, "/"), filename);
    filePath[lenFilepath] = '\0';
    free(filename);
    
    printf("Sto tentando di aprire %s\n", filePath);

    if((fp = fopen(filePath, "rb")) == NULL){
        free(filePath);
        printf("Impossibile aprire il file!\n");
        return;
    }

    // salvataggio prodotti
    resWrite = loadList(newList, fp);

    fclose(fp);
    free(filePath);

    if(resWrite){
        printf("Impossibile caricare i dati\n");
    } else {
        printf("Caricamento avvenuto con successo!\n");
        *head = newList;
    }    
}

static int loadList(struct Prod **head, FILE *fp){
    int result = 0, cnRead = 0;
    struct Prod *p;

    while(1){
        struct DataProd data = {0};

        cnRead = fread(&data, sizeof(struct DataProd), 1, fp);
        if((!cnRead && !feof(fp)) || ferror(fp)){
            result = 1;
            break;
        }

        //finito di leggere tutto correttamente
        if(feof(fp))
            break;

        p = (struct Prod *) malloc(sizeof(struct Prod));
        if(!p){
            result = 1;
            clearList(*head);
            break;
        }

        p->id = data.id;
        strcpy(p->name, data.name);
        p->qta = data.qta;
        p->price = data.price;

        insertProd(head, p);
    }

    return result;
}