#include <stdio.h>
#include <ctype.h>

#define LEN_PAROLA 15
#define LEN_OCCORRENZE 26

int main(void){

    printf("*** Controlla se due parole sono anagrammi ***\n\n");

    int idx = 0;
    int occorrenze[LEN_OCCORRENZE] = {0};
    char ch;

    printf("Inserisci la prima parola: ");
    while((ch = getchar()) != '\n'){
        if(isalpha(ch)){
            idx = tolower(ch) - 'a';
            occorrenze[idx]++;
        }
    }

    printf("Inserisci la seconda parola: ");
    while((ch = getchar()) != '\n'){
        if(isalpha(ch)){
            idx = tolower(ch) - 'a';
            occorrenze[idx]--;
        }
    }

    for(idx = 0; idx < LEN_OCCORRENZE; idx++){
        if(occorrenze[idx] != 0)
            break;
    }

    printf("\n");
    if(idx == LEN_OCCORRENZE)
        printf("Le parole sono anagrammi!\n");
    else
        printf("Le parole non sono anagrammi!\n");

    printf("\n");
    return 0;
}