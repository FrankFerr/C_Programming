#include <stdio.h>
#include <string.h>

#define LEN_WORDS 20
#define NUM_WORDS 30

int main(void){

    printf("*** Inverte le parole di una frase inserita dall'utente, termina la frase con .|!|? ***\n\n");

    char msgWords[NUM_WORDS][LEN_WORDS];
    char ch;
    char formatStr[4 + 1];
    int countWords = 0;

    sprintf(formatStr, "%%%ds", LEN_WORDS);

    printf("Inserisci una frase: ");
    while(countWords < NUM_WORDS){
        scanf(formatStr, msgWords[countWords]);

        ch = msgWords[countWords][strlen(msgWords[countWords]) - 1];

        if(ch == '.' || ch == '!' || ch == '?'){
            msgWords[countWords][strlen(msgWords[countWords]) - 1] = '\0';
            break;
        }

        countWords++;
    }

    printf("\n");
    printf("Al contrario:");
    if(countWords > 0){
        for(int i = countWords; i >= 0; i--){
            printf(" %s", msgWords[i]);
        }
    }
    
    putchar(ch);

    printf("\n");
    return 0;
}