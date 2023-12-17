#include <stdio.h>

#define LEN_MESSAGE 200

int main(void){

    printf("*** Inverte le parole di una frase inserita dall'utente, termina la frase con .|!|? ***\n\n");

    char message[LEN_MESSAGE];
    char ch;
    int idxMsg = 0, start = 0, end = 0;

    printf("Inserisci una frase: ");
    ch = (char) getchar();
    while(ch != '.' && ch != '!' && ch != '?'){
        message[idxMsg++] = ch;

        ch = (char) getchar();
    }

    printf("\n");
    printf("Al contrario: ");
    if(idxMsg != 0){
        for(int i = idxMsg - 1, start = i, end = idxMsg; i > 0; i--, start--){
            if(message[i] == ' '){
                for(int j = start + 1; j < end; j++){
                    printf("%c", message[j]);
                }

                printf("%c", message[i]);
                end = start;
            }
        }
        for(int j = 0; message[j] != ' '; j++){
            printf("%c", message[j]);
        }
    }
    
    printf("%c\n", ch);

    printf("\n");
    return 0;
}