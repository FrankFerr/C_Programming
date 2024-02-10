#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define OFFSET 10

void printHeader(int len);

int main(int argc, char **argv){

    if(argc != 2){
        printf("Errore! Lanciare: pdp6 <nomefile>\n");
        exit(EXIT_FAILURE);
    }

    printf("*** Stampa il contenuto di un file sotto forma di numeri esadecimali ***\n\n");

    int offset = 0, campoEx = 3, i = 0;
    char line[OFFSET + 1];
    FILE *fp;

    if((fp = fopen(argv[1], "rb")) == NULL){
        printf("Impossibile aprire %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    printHeader(campoEx * OFFSET);

    while(1){
        for(i = 0; i < OFFSET && (line[i] = fgetc(fp)) != EOF; i++)
            ;
        line[i] = '\0';

        //stampa offset
        printf("%6d%4c", offset, ' ');

        //stampa caratteri sotto forma di numeri esadecimali
        for(i = 0; line[i] != '\0'; i++){
            printf("%-3.2X", line[i]);
        }

        //se gli ultimi caratteri non riempiono tutta la linea, aggiungo degli spazi per riempire
        if(OFFSET - i != 0){
            printf("%*c", (OFFSET - i) * campoEx, ' ');
        }

        printf("%4c", ' ');

        //stampa i caratteri
        for(i = 0; line[i] != '\0'; i++){
            if(!isprint(line[i]))
                line[i] = '.';

            printf("%c", line[i]);
        }

        printf("\n");
        offset += OFFSET;

        //se sono alla fine del file, esco
        if(feof(fp))
            break;
    }

    fclose(fp);

    return 0;
}

void printHeader(int len){
    printf("Offset%4c%*s%-*s%4cCharacters\n", ' ', len / 2, "By", len / 2, "tes", ' ');
    printf("------%4c", ' ');
    
    for(int i = 0; i < len; i++)
        printf("-");
    
    printf("%4c----------\n", ' ');
}