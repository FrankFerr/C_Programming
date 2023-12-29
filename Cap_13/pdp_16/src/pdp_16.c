#include <stdio.h>
#include <string.h>

#define LEN_MSG 20

void reverse(char* message);

int main(void){

    printf("*** Stampa, al contrario, un messaggio inserito dall'utente ***\n\n");

    char message[LEN_MSG];

    printf("Inserisci un messaggio: ");
    fgets(message, LEN_MSG, stdin);
    //la fgets memorizza anche il carattere newLine '\n'
    message[strlen(message) - 1] = '\0';

    reverse(message);

    printf("Al contrario: %s", message);
    
    printf("\n");
    return 0;
}

void reverse(char* msg){
    char temp;
    char* rMsg = msg + strlen(msg) - 1;

    while(rMsg > msg){
        temp = *rMsg;
        *rMsg = *msg;
        *msg = temp;

        rMsg--;
        msg++;
    }
}