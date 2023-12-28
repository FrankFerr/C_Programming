#include <stdio.h>

int main(int argc, char** argv){
    printf("*** Scrive gli argomenti della riga di comando al contrario ***\n\n");

    if(argc - 1 < 2){
        printf("Errore: Pochi argomenti per eseguire il programma!\n");
    } else {
        for(int i = argc - 1; i > 0; i--){
            printf("%s ", *(argv + i));
        }
    }

    printf("\n");
    return 0;
}