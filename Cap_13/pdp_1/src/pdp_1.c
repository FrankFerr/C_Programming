#include <stdio.h>
#include <string.h>

#define LEN_WORD 20

int readLine(char str[], int n);

int main(void){

    printf("*** Cerca la parola piu' piccola e la piu' grande, in base all'ordine alfabetico, tra quelle in input ***\n\n");

    char strInput[LEN_WORD + 1] = {'\0'}, minore[LEN_WORD + 1] = {'\0'}, maggiore[LEN_WORD + 1] = {'\0'};
    
    printf("Inserisci una parola (4 lettere per terminare): ");
    readLine(strInput, LEN_WORD);

    strcpy(minore, strInput);
    strcpy(maggiore, strInput);
    
    while(1){
        printf("Inserisci una parola (4 lettere per terminoreare): ");
        readLine(strInput, LEN_WORD);

        if(strlen(strInput) == 4)
            break;

        if(strcmp(minore, strInput) < 0){
            strcpy(minore, strInput);
        }
        
        if(strcmp(maggiore, strInput) > 0){
            strcpy(maggiore, strInput);
        }
    }

    printf("\nMinore: %s\nMaggiore: %s", minore, maggiore);

    printf("\n");
    return 0;
}

int readLine(char str[], int n){
    int i = 0;
    char ch;

    while((ch = getchar()) != '\n')
        if(i < n)
            str[i++] = ch;

    str[i] = '\0';

    return i;
}