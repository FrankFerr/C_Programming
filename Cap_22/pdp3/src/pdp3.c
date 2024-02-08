#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    if(argc < 2){
        printf("Lanciare: pdp3 <filename> [ <filename> ...]\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    int ch;

    for(int i = 1; i < argc; i++){
        if((fp = fopen(argv[i], "r")) == NULL){
            printf("Impossibile aprire il file %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }

        while((ch = fgetc(fp)) != EOF){
            putc(ch, stdout);
        }

        fclose(fp);
    }

    printf("\n");

    return 0;
}