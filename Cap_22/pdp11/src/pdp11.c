#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN_DATA 11
#define LEN_MESE 9

int main(void){
    printf("*** Stampa una data inserita dall'utente nel formato mese gg, aaaa ***\n\n");

    int giorno = 0, mese = 0, anno = 0, numRead = 0;
    char data[LEN_DATA + 1];
    static const char *FORMAT_1 = "%2d /%2d /%4d";
    static const char *FORMAT_2 = "%2d -%2d -%4d";
    static const char *MESI[] = {
        "Gennaio", "Febbraio", "Marzo", "Aprile",
        "Maggio", "Giugno", "Luglio", "Agosto",
        "Settembre", "Ottobre", "Novembre", "Dicembre"
    };

    printf("Inserisci una data nel formato gg/mm/aaaa o gg-mm-aaaa: ");
    fgets(data, LEN_DATA, stdin);
    data[strlen(data)] = '\0';

    numRead = sscanf(data, FORMAT_1, &giorno, &mese, &anno);
    if(numRead != 3)
        numRead = sscanf(data, FORMAT_2, &giorno, &mese, &anno);
    
    if(numRead != 3 ||
       (giorno < 1 || 31 < giorno) ||
       (mese < 1 || 12 < mese) ||
       (anno < 1900 || 2099 < anno)){
        printf("Formato data errato\n");
        exit(EXIT_FAILURE);
    }

    printf("%s %d, %d", MESI[mese - 1], giorno, anno);

    return 0;
}