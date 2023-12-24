#include <stdio.h>
#include <string.h>

#define LEN_PLANETS (int) (sizeof(planets)/sizeof(planets[0]))

int main(int argc, char *argv[]){

    printf("*** Controlla se tra gli argomenti della riga di comando ci sono dei pianeti ***\n\n");

    char *planets[] = { "Mercurio", "Venere", "Terra", 
                        "Marte", "Giove", "Saturno", 
                        "Urano", "Nettuno", "Plutone"};
    char **ppStrInput;
    int numPlanet = 0;
    
    if(argc == 1){
        printf("Errore, non ci sono argomenti nella riga di comando.\nCome usare: planets \"str1\" ...\n");
        return 0;
    }

    for(ppStrInput = &argv[1]; ppStrInput != NULL; ppStrInput++){
        for(numPlanet = 0; numPlanet < LEN_PLANETS; numPlanet++){
            if(strcmp(*ppStrInput, planets[numPlanet]) == 0){
                printf("%s e' il pianeta %d\n", *ppStrInput, numPlanet + 1);
                break;
            }
        }
        if(numPlanet == LEN_PLANETS){
            printf("%s non e' un pianeta\n", *ppStrInput);
        }
    }

    printf("\n");
    return 0;
}