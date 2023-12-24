#include <stdio.h>
#include <string.h>

#define MAX_REMINDER 30
#define MSG_LEN 40

int readLine(char str[], int n);

int main(void){

    printf("*** Stampa una serie di promemoria ordinati per giorno ***\n\n");

    char reminders[MAX_REMINDER][MSG_LEN + 3] = {'\0'}, str[MSG_LEN + 1] = {'\0'};
    char dayStr[3];
    int day = 0, nm_reminder = 0, idxInsert;

    while(1){
        if(nm_reminder == MAX_REMINDER){
            printf("Non c'e' piu' spazio\n");
            break;
        }

        printf("Inserisci giorno e promemoria: ");
        scanf("%2d", &day);

        if(day < 1){
            break;
        }

        sprintf(dayStr, "%2d", day);

        readLine(str, MSG_LEN);

        for(idxInsert = 0; idxInsert < nm_reminder; idxInsert++){
            if(strcmp(dayStr, reminders[idxInsert]) < 0){
                break;
            }
        }

        for(int i = nm_reminder; i > idxInsert; i--){
            strcpy(reminders[i], reminders[i - 1]);
        }

        strcpy(reminders[idxInsert], dayStr);
        strcat(reminders[idxInsert], str);

        nm_reminder++;
    }

    printf("\nPromemoria ordinati\n");
    for(int i = 0; i < nm_reminder; i++){
        printf(" %s\n", reminders[i]);
    }

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