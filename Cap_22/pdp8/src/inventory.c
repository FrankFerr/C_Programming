#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\include\readline.h"
#include "..\include\inventory.h"

#define DATA_PATH "data"
#define FILENAME_LENGTH 25

struct Prod{
    int id;
    char name[NAME_LEN + 1];
    int qta;
} inventory[MAX_PROD];

int cnProd = 0;

int findProd(int id){
    int idxFound = -1;

    for(int i = 0; id > 0 && i < cnProd; i++){
        if(inventory[i].id == id){
            idxFound = i;
            break;
        }
    }

    return idxFound;
}

void insert(void){
    int id = 0;

    if(cnProd == MAX_PROD){
        printf("Database pieno!\n");
        return;
    }

    printf("Inserimento nuovo prodotto\n");
    printf("Codice: ");
    scanf("%d", &id);

    if(id < 1)
        id = cnProd + 1;

    if(findProd(id) != -1){
        printf("Prodotto gia' inserito!\n");
        return;
    }

    inventory[cnProd].id = id;

    printf("Nome: ");
    readLine(inventory[cnProd].name, NAME_LEN);

    printf("Quantita': ");
    scanf("%d", &inventory[cnProd].qta);

    if(inventory[cnProd].qta < 0)
        inventory[cnProd].qta = 0;

    cnProd++;
}

void search(void){
    int id, idx;
    
    printf("Inserisci il codice del prodotto da cercare: ");
    scanf("%d", &id);

    idx = findProd(id);

    if(idx == -1){
        printf("Prodotto non trovato!\n");
        return;
    }

    printf("Nome: %s\nQuantita': %d\n", inventory[idx].name, inventory[idx].qta);

}

void update(void){
    int id, idx, qtaSum;
    
    printf("Inserisci il codice del prodotto da aggiornare: ");
    scanf("%d", &id);

    idx = findProd(id);

    if(idx == -1){
        printf("Prodotto non trovato!\n");
        return;
    }

    printf("Quantita' attuale: %d\n", inventory[idx].qta);

    printf("Inserisci la quantita' da sommare: ");
    scanf("%d", &qtaSum);

    inventory[idx].qta += qtaSum;

    printf("Quantita' aggiornata: %d\n", inventory[idx].qta);
    
}

void print(void){
    printf(" -------------------------------------------\n");
    printf("| Prod. Id |        Nome        | Quantita' |\n");
    printf(" -------------------------------------------\n");

    for(int i = 0; i < cnProd; i++){
        printf("|%6d%4s|%20s|%6d%5s|\n", inventory[i].id, " ", inventory[i].name, inventory[i].qta, " ");
    }

    printf(" -------------------------------------------\n");
}

char *getFilename(void){
    char *filename = (char *) malloc(sizeof(char) * (FILENAME_LENGTH + 1));

    if(filename != NULL){
        printf("Inserisci il nome del file (max %d caratteri): ", FILENAME_LENGTH);
        readLine(filename, FILENAME_LENGTH);
    }

    return filename;
}

void save(void){
    char *filePath, *filename;
    FILE *fp;
    int cntElem = 0, lenFilepath = 0;

    if(cnProd == 0){
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

    cntElem = fwrite(inventory, sizeof(struct Prod), cnProd, fp);

    if(cntElem != cnProd || ferror(fp)){
        printf("Impossibile salvare i dati\n");
    } else {
        printf("Salvataggio avvenuto con successo!\n");
    }

    free(filePath);
    fclose(fp);

}

void load(void){
    char *filePath, *filename;
    FILE *fp;
    int cntElem = 0, lenFilepath = 0;

    filename = getFilename();
    if(filename == NULL){
        printf("Impossibile salvare i dati\n");
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

    cntElem = fread(inventory, sizeof inventory[0], MAX_PROD, fp);

    if(ferror(fp)){
        printf("Impossibile caricare i dati\n");
    } else if(cntElem == 0){
        printf("File vuoto!\n");
    } else {
        printf("Caricamento di %d elementi avvenuto con successo!\n", cntElem);
        cnProd = cntElem;
    }

    free(filePath);
    fclose(fp);
}