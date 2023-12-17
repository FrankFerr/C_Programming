#include <stdio.h>
#include <ctype.h>

#define LEN_MESSAGE 100

int main(void){

    printf("*** Converte un messaggio in input, nel linguaggio di B1FF! ***\n\n");

    char message[LEN_MESSAGE];
    char ch;
    int idx = 0;

    printf("Scrivi una frase\n> ");
    while((message[idx] = (char) toupper(getchar())) != '\n')
        idx++;

    printf("\nB1FF: ");
    for(int i = 0; i < idx; i++){

        switch (message[i]){
            case 'A':
                message[i] = '4';
                break;
            case 'B':
                message[i] = '8';
                break;
            case 'E':
                message[i] = '3';
                break;
            case 'I':
                message[i] = '1';
                break;
            case 'O':
                message[i] = '0';
                break;
            case 'S':
                message[i] = '5';
                break;

            default:
                break;
        }

        printf("%c", message[i]);
    }

    printf("!!!!!!!!!!\n");

    printf("\n");
    return 0;
}