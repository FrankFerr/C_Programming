#include <stdio.h>
#include <string.h>

#define MAX_REMINDER 30
#define MSG_LEN 40
#define DT_LEN 11

int readLine(char str[], int n);

int main(void){

    printf("*** Stampa una serie di promemoria ordinati per giorno ***\n\n");

    char reminders[MAX_REMINDER][DT_LEN + MSG_LEN + 1] = {'\0'}, str[MSG_LEN + 1] = {'\0'};
    char dateTimeStr[DT_LEN + 1];
    int month = 0, day = 0, hour = 0, minute = 0, nm_reminder = 0, idxInsert;

    while(1){
        if(nm_reminder == MAX_REMINDER){
            printf("Non c'e' piu' spazio\n");
            break;
        }

        printf("Inserisci giorno (mm/gg), ora (hh:mm) e promemoria: ");
        //lettura e validazione data
        scanf("%d", &month);
        
        if(month == 0){
            break;
        } 
        
        scanf("%d", &day);

        if(day < 0 || 31 < day || month < 1 || 12 < month){
            printf("Data errata!\n");
            
            //ripulisco il buffer in input
            while(getchar() != '\n');
            
            continue;
        }

        //lettura e validazione orario
        scanf("%d:%d", &hour, &minute);
        if(hour < 0 || 23 < hour || minute < 0 || 59 < minute){
            printf("Orario errato!\n");
            continue;
        }

        sprintf(dateTimeStr, "%02d/%02d %02d:%02d", month, day, hour, minute);

        readLine(str, MSG_LEN);

        for(idxInsert = 0; idxInsert < nm_reminder; idxInsert++){
            if(strcmp(dateTimeStr, reminders[idxInsert]) < 0){
                break;
            }
        }

        for(int i = nm_reminder; i > idxInsert; i--){
            strcpy(reminders[i], reminders[i - 1]);
        }

        strcpy(reminders[idxInsert], dateTimeStr);
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