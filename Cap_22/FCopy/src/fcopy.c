#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    if(argc != 3){
        fprintf(stderr, "Lanciare: fcopy <input file> <output file>\n");
        exit(EXIT_FAILURE);
    }

    FILE *src, *dest;
    int ch;

    if((src = fopen(argv[1], "r")) == NULL){
        fprintf(stderr, "%s non puo' essere aperto\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if((dest = fopen(argv[2], "w")) == NULL){
        fprintf(stderr, "%s non puo' essere aperto\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while((ch = getc(src)) != EOF){
        putc(ch, dest);
    }

    // non necesarie **********************************
    if(feof(src))
        fprintf(stderr, "Raggiunta la fine del file sorgente!\n");
    else if(ferror(src))
        fprintf(stderr, "Errore durante la lettura dal sorgente!\n");
    // ************************************************

    fclose(src);
    fclose(dest);
    
    printf("\n");
    return 0;
}