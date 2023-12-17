#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define LEN_MSG 40

int main(void){

    printf("*** Controlla se una frase e' palindroma ***\n\n");

    char message[LEN_MSG];
    char ch;
    char* revPtr;
    int idx = 0;
    bool palindroma = true, esci = false;

    while(!esci){
        idx = 0;
        palindroma = true;

        printf("Inserisci un messaggio: ");
        while((ch = getchar()) != '\n' && message + idx < message + LEN_MSG){
            ch = tolower(ch);

            if(isalpha(ch)){
                *(message + idx) = ch;
                idx++;
            }

            if(ch == 'x'){
                esci = true;
                break;
            }
        }

        if(!esci){
            revPtr = message + (idx - 1);
            for(int i = 0; message + i < revPtr && palindroma; i++, revPtr--){
                if(*(message + i) != *revPtr){
                    palindroma = false;
                }
            }

            if(palindroma){
                printf("La frase e' palindroma!\n");
            } else {
                printf("La frase non e' palindroma!\n");
            }

            printf("\n");
        }
    }

    printf("\n");
    return 0;
}