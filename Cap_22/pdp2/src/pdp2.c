#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char **argv){

    if(argc != 2){
        printf("Lanciare: canopen <filename>\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    int ch;

    if((fp = fopen(argv[1], "r")) == NULL){
        printf("Impossibile aprire il file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fp)) != EOF){
        if(isalpha(ch)){
            ch = toupper(ch);
        }

        putchar(ch);
    }

    fclose(fp);

    printf("\n");

    return 0;
}