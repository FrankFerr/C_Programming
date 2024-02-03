#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    if(argc != 2){
        printf("Lanciare: canopen <filename>\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;

    if((fp = fopen(argv[1], "r")) == NULL){
        printf("%s non puo' essere aperto\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("%s puo' essere aperto\n", argv[1]);
    fclose(fp);

    printf("\n");
    return 0;
}