#include <stdio.h>

#define LEN_VALORI ((int) sizeof(valori) / sizeof(valori[0]))
#define NM_MESI 12

int main(void){

    printf("*** Calcola l'interesse su un importo mensilmente per un tot di anni ***\n\n");

    int tasso, anni;
    float importo;

    printf("Inserisci l'importo: ");
    scanf("%f", &importo);
    printf("Inserisci il tasso da applicare: ");
    scanf("%d", &tasso);
    printf("Per quanti anni calcolarlo?: ");
    scanf("%d", &anni);

    double valori[5];

    printf("\nAnni");
    for(int i = 0; i < LEN_VALORI; i++){
        printf("%8d%%  ", tasso + i);
        valori[i] = importo;
    }
    
    for(int i = 0; i < anni; i++){
        printf("\n%3d ", i + 1);
        
        for(int j = 0; j < LEN_VALORI; j++){

            for(int z = 0; z < NM_MESI; z++){
                valori[j] += (valori[j] / 100) * (tasso + j);
            }
            
            printf("%11.2f", valori[j]); 
        }
    }

    printf("\n");

    return 0;
}