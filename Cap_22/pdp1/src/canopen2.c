#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv){

    if(argc < 2){
        printf("Lanciare: canopen <filename> [ <filename>...]\n");
        exit(EXIT_FAILURE);
    }

    bool bFail = false;
    FILE *fp;

    for(int i = 1; i < argc; i++){
        if((fp = fopen(argv[i], "rb")) == NULL){
            printf("%s non puo' essere aperto\n", argv[i]);
            bFail = true;
        } else {
            printf("%s puo' essere aperto\n", argv[i]);
            fclose(fp);
        }
    }

    printf("\n");

    if(bFail){
        printf("Exit fail\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}