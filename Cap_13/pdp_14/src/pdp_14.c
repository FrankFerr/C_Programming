#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define LEN_PAROLA 15
#define LEN_OCCORRENZE 26

bool areAnagrams(const char* str1, const char* str2);

int main(void){

    printf("*** Controlla se due parole sono anagrammi ***\n\n");

    char parola1[LEN_PAROLA + 1], parola2[LEN_PAROLA + 1];

    while(true){
        printf("Inserisci la prima parola: ");
        fgets(parola1, LEN_PAROLA, stdin);

        if(tolower(parola1[0]) == 'x')
            break;

        printf("Inserisci la seconda parola: ");
        fgets(parola2, LEN_PAROLA, stdin);

        if(areAnagrams(parola1, parola2))
            printf("Le parole sono anagrammi!\n");
        else
            printf("Le parole non sono anagrammi!\n");

        printf("\n");
    }

    printf("\n");
    return 0;
}

bool areAnagrams(const char* str1, const char* str2){
    int occorrenze[LEN_OCCORRENZE] = {0};

    while(*str1 != '\0')
        occorrenze[tolower(*str1++) - 'a']++;

    while(*str2 != '\0')
        occorrenze[tolower(*str2++) - 'a']--;

    for(int i = 0; i < LEN_OCCORRENZE; i++)
        if(occorrenze[i] != 0)
            return false;

    return true;
}