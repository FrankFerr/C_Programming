#include <stdio.h>

#define LEN_MESI (int) (sizeof(mesi)/sizeof(*mesi))

int main(void){

    printf("*** Stampa una data in input (mm/gg/aaaa) nel formato \"mese gg, aaaa\" ***\n\n");

    int g = 0, m = 0, a = 0;
    char* mesi[] = {
        "Gennaio", "Febbraio", "Marzo", "Aprile", 
        "Maggio", "Giugno", "Luglio", "Agosto", 
        "Settembre", "Ottobre", "Novembre", "Dicembre"
    };

    printf("inserisci una data (gg/mm/aaaa): ");
    scanf("%d/%d/%d", &g, &m, &a);

    if(g < 1 || 31 < g || m < 1 || 12 < m || a < 1900){
        printf("Data errata!\n");
        return 0;
    }

    printf("Data inserita: %s %d, %d", mesi[m - 1], g, a);

    printf("\n");
    return 0;
}