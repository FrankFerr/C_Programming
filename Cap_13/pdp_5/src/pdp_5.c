#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    printf("*** Somma gli argomenti della riga di comando ***\n\n");

    int sum = 0;

    if(argc - 1 == 0){
        printf("Errore: Nessun numero da sommare!\n");
    } else {
        for(int i = 1; i < argc; i++){
            sum += atoi(*(argv + i));
        }
        
        printf("Totale: %d", sum);
    }

    printf("\n");
    return 0;
}