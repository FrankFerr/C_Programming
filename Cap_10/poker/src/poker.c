#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NM_VALORI 13
#define NM_SEMI 4
#define NM_CARTE_MANO 5

int cnValoriMano[NM_VALORI];
int cnSemiMano[NM_SEMI];
bool poker, colore, scala, tris;
int coppie;

void leggiCarte(void);
void decretaPunteggio(void);
void stampaPunteggio(void);

int main(void){

    printf("*** Decreata il punteggio di una mano di Poker ***\n\n");

    while(true){
        leggiCarte();
        decretaPunteggio();
        stampaPunteggio();
    }

    printf("\n");
    return 0;
}

void leggiCarte(void){
    int carteLette = 0;
    int val = 0, seme = 0;
    char cVal = '0',  cSeme = ' ', ch = ' ';
    bool cartaErrata = false;
    bool carteMano[NM_VALORI][NM_SEMI] = {false};

    for(int v = 0; v < NM_VALORI; v++){
        cnValoriMano[v] = 0;
        for(int s = 0; s < NM_SEMI; s++){
            carteMano[v][s] = false;
        }
    }

    for(int s = 0; s < NM_SEMI; s++){
        cnSemiMano[s] = 0;
    }

    while(carteLette < NM_CARTE_MANO){
        cartaErrata = false;

        printf("Scrivi una carta (%d): ", carteLette + 1);
        
        cVal = (char) getchar();
        switch(cVal){
            case '0': exit(EXIT_SUCCESS);
            case '2': val = 0; break;
            case '3': val = 1; break;
            case '4': val = 2; break;
            case '5': val = 3; break;
            case '6': val = 4; break;
            case '7': val = 5; break;
            case '8': val = 6; break;
            case '9': val = 7; break;
            case 't': case 'T': val = 8; break;
            case 'j': case 'J': val = 9; break;
            case 'q': case 'Q': val = 10; break;
            case 'k': case 'K': val = 11; break;
            case 'a': case 'A': val = 12; break;
            default: cartaErrata = true;
        }

        cSeme = (char) getchar();
        switch(cSeme){
            case 'h': case 'H': seme = 0; break;
            case 'd': case 'D': seme = 1; break;
            case 'c': case 'C': seme = 2; break;
            case 's': case 'S': seme = 3; break;
            default: cartaErrata = true;
        }

        while((ch = getchar()) != '\n')
            ;

        if(cartaErrata){
            printf("Carta errata!\n");
            continue;
        } else if(carteMano[val][seme]){
            printf("Carta gia' inserita!\n");
            continue;
        }

        carteMano[val][seme] = true;
        cnValoriMano[val]++;
        cnSemiMano[seme]++;

        carteLette++;
    }
}

void decretaPunteggio(void){
    poker = colore = scala = tris = false;
    coppie = 0;
    int carteConsecutive = 0;

    //controllo Colore
    for(int i = 0; i < NM_SEMI; i++){
        if(cnSemiMano[i] == 5){
            colore = true;
        }
    }

    for(int i = 0; i < NM_VALORI; i++){
        //controllo Scala
        if(cnValoriMano[i] == 1){
            carteConsecutive++;

            if(carteConsecutive == 5){
                scala = true;
            }
        }
        else{
            carteConsecutive = 0;
        }
        
        //controllo Poker, Tris, Doppia Coppia e Coppia
        switch(cnValoriMano[i]){
            case 2: coppie++; break;
            case 3: tris = true; break;
            case 4: poker = true; break;
        }
    }
}

void stampaPunteggio(void){
    if(colore && scala){
        printf("Scala a Colore!");
    } else if(poker){
        printf("Poker!");
    } else if(tris && coppie == 1){
        printf("Full!");
    } else if(colore){
        printf("Colore!");
    } else if(scala){
        printf("Scala!");
    } else if(tris){
        printf("Tris!");
    } else if(coppie == 2){
        printf("Doppia Coppia!");
    } else if(coppie == 1){
        printf("Coppia!");
    } else{
        printf("Non hai niente!");
    }

    printf("\n\n");
}