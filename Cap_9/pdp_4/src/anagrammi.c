#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define LEN_PAROLA 15
#define LEN_OCCORRENZE 26

void readWord(int occorrenze[]);
bool equalsArray(int occorrenze1[], int occorrenze2[]);

int main(void){

    printf("*** Controlla se due parole sono anagrammi ***\n\n");

    int occorrenze1[LEN_OCCORRENZE] = {0}, occorrenze2[LEN_OCCORRENZE] = {0};
    
    printf("Inserisci la prima parola: ");
    readWord(occorrenze1);

    printf("Inserisci la seconda parola: ");
    readWord(occorrenze2);
    
    if(equalsArray(occorrenze1, occorrenze2))
        printf("Le parole sono anagrammi!\n");
    else
        printf("Le parole non sono anagrammi!\n");

    printf("\n");
    return 0;
}

void readWord(int occorrenze[]){
    char ch;
    int idx = 0;

    while((ch = getchar()) != '\n'){
        if(isalpha(ch)){
            idx = tolower(ch) - 'a';
            occorrenze[idx]++;
        }
    }
}

bool equalsArray(int occorrenze1[], int occorrenze2[]){
    bool result = true;

    for(int i = 0; i < LEN_OCCORRENZE; i++){
        if(occorrenze1[i] != occorrenze2[i]){
            result = false;
            break;
        }
    }

    return result;
}