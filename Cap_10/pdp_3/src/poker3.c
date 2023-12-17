#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define NM_VALORI 13
#define NM_SEMI 4
#define NM_CARTE_MANO 5
#define NM_COL_MANO 2

bool poker, colore, scala, tris;
int idxVal = 0, idxSeme = 1, coppie = 0;

void leggiCarte(int mano[][NM_COL_MANO]);
void decretaPunteggio(int mano[][NM_COL_MANO]);
void stampaPunteggio(void);
void selectionSort(int a[][NM_COL_MANO], int n);

int main(void){

    printf("*** Decreata il punteggio di una mano di Poker ***\n\n");

    int mano[NM_CARTE_MANO][NM_COL_MANO];
    
    while(true){
        leggiCarte(mano);
        decretaPunteggio(mano);
        stampaPunteggio();
    }

    printf("\n");
    return 0;
}

void leggiCarte(int mano[][NM_COL_MANO]){
    int carteLette = 0, iVal = 0, iSeme = 0;
    char val = '0',  seme = ' ', ch = ' ';
    bool cartaErrata = false, cartaDuplicata = false;
    
    for(int row = 0; row < NM_CARTE_MANO; row++){
        for(int col = 0; col < NM_COL_MANO; col++){
            mano[row][col] = 0;
        }
    }

    while(carteLette < NM_CARTE_MANO){
        cartaErrata = false;
        cartaDuplicata = false;
        
        printf("Scrivi una carta (%d): ", carteLette + 1);
        
        //lettura valore
        val = (char) tolower(getchar());
        //validazione valore
        switch(val){
            case '0': exit(EXIT_SUCCESS);
            case '2': iVal = 0; break;
            case '3': iVal = 1; break;
            case '4': iVal = 2; break;
            case '5': iVal = 3; break;
            case '6': iVal = 4; break;
            case '7': iVal = 5; break;
            case '8': iVal = 6; break;
            case '9': iVal = 7; break;
            case 't': iVal = 8; break;
            case 'j': iVal = 9; break;
            case 'q': iVal = 10; break;
            case 'k': iVal = 11; break;
            case 'a': iVal = 12; break;
            default: cartaErrata = true;
        }

        //lettura seme
        seme = (char) tolower(getchar());
        // validazione seme
        switch(seme){
            case 'h': iSeme = 0; break;
            case 'd': iSeme = 1; break;
            case 'c': iSeme = 2; break;
            case 's': iSeme = 3; break;
            default: cartaErrata = true;
        }
        // scarta i caratteri rimasti
        while((ch = getchar()) != '\n')
            ;

        // controllo carta errata
        if(cartaErrata){
            printf("Carta errata!\n");
            continue;
        }

        // controllo carta duplicata
        for(int i = 0; i < carteLette; i++){
            if(mano[i][idxVal] == iVal && mano[i][idxSeme] == iSeme){
                cartaDuplicata = true;
                break;
            }
        }
        if(cartaDuplicata){
            printf("Carta gia' inserita!\n");
            continue;
        }

        // salvo la carta
        mano[carteLette][idxVal] = iVal;
        mano[carteLette][idxSeme] = iSeme;
        carteLette++;
    }
}

void decretaPunteggio(int mano[][NM_COL_MANO]){
    poker = scala = tris = false;
    coppie = 0;
    int carteConsecutive = 1, carteUguali = 1;

    //controllo Colore 
    colore = true;
    for(int carta = 0; carta < NM_CARTE_MANO - 1; carta++){
        if(mano[carta][idxSeme] != mano[carta + 1][idxSeme]){
            colore = false;
            break;
        }
    }
    
    // ordino l'array per controllare gli altri punteggi
    selectionSort(mano, NM_CARTE_MANO);
    
    for(int carta = 0; carta < NM_CARTE_MANO - 1; carta++){
        
        // controllo se sono valori consecutivi per determinare la Scala
        if(mano[carta][idxVal] == mano[carta + 1][idxVal] - 1){
            carteConsecutive++;

            //controllo Scala
            if(carteConsecutive == 5){
                scala = true;
            }
        }else{
            carteConsecutive = 1;
        }

        // controllo se sono valori uguali per determinare Poker, Tris, Doppia Coppia e Coppia
        if(mano[carta][idxVal] == mano[carta + 1][idxVal]){
            carteUguali++;

            // controllo Coppia e Doppia Coppia
            if(carteUguali == 2){
                coppie++;
            }
            // controllo Tris
            if(carteUguali == 3){
                tris = true;
                coppie--;
            }
            // controllo Poker
            if(carteUguali == 4){
                poker = true;
                tris = false;
            }
        }else{
            carteUguali = 1;
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

void selectionSort(int a[][NM_COL_MANO], int n){
    if(n == 0)
        return;

    int idxMax = 0, tempVal = 0, tempSeme = 0;

    for(int i = 0; i < n; i++){
        if(a[idxMax][idxVal] < a[i][idxVal]){
            idxMax = i;
        }
    }

    tempVal = a[n - 1][idxVal];
    tempSeme = a[n - 1][idxSeme];

    a[n - 1][idxVal] = a[idxMax][idxVal];
    a[n - 1][idxSeme] = a[idxMax][idxSeme];
    
    a[idxMax][idxVal] = tempVal;
    a[idxMax][idxSeme] = tempSeme;

    selectionSort(a, n - 1);
}