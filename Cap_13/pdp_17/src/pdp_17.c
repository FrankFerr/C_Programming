#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define LEN_MSG 40

bool isPalindrome(const char* str);

int main(void){

    printf("*** Controlla se una frase e' palindroma ***\n\n");

    char message[LEN_MSG + 1];
    char ch;
    int idx = 0;

    while(true){
        idx = 0;

        printf("Inserisci un messaggio: ");
        while((ch = getchar()) != '\n' && idx < LEN_MSG){
            ch = tolower(ch);

            if(ch == 'x'){
                return 0;
            }

            if(isalpha(ch)){
                message[idx++] = ch;
            }
        }
        message[idx++] = '\0';

        if(isPalindrome(message)){
            printf("La frase e' palindroma!\n");
        } else {
            printf("La frase non e' palindroma!\n");
        }

        printf("\n");
    }

    printf("\n");
    return 0;
}

bool isPalindrome(const char* str){
    const char* revPtr = str + (strlen(str) - 1);

    while(str < revPtr){
        if(*str++ != *revPtr--){
            return false;
        }
    }

    return true;
}