#include <stdio.h>

#define LEN_MSG 20

int main(void){

    printf("*** Stampa, al contrario, un messaggio inserito dall'utente ***\n\n");

    char message[LEN_MSG];
    char ch;
    int idx = 0;
    // char* messPtr = message;
    
    printf("Inserisci un messaggio: ");
    // while((ch = getchar()) != '\n' && messPtr < message + LEN_MSG){
    //     *messPtr++ = ch;
    // }
    
    while((ch = getchar()) != '\n' && message + idx < message + LEN_MSG){
        *(message + idx) = ch;
        idx++;
    }

    printf("Al contrario: ");
    // while(messPtr >= message){
    //     printf("%c", *--messPtr);
    // }

    while(message + idx >= message){
        printf("%c", *(message + --idx));
    }

    printf("\n");
    return 0;
}