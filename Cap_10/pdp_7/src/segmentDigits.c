#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10
#define SEG_ROWS 4
#define SEG_COLS (MAX_DIGITS * 4)
#define NM_SEG 7

int segmentArray[][NM_SEG] = {{1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1},
                              {1,1,1,1,0,0,1}, {0,1,1,0,0,1,1}, {1,0,1,1,0,1,1},
                              {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0}, {1,1,1,1,1,1,1},
                              {1,1,1,1,0,1,1}};
char digits[SEG_ROWS][SEG_COLS];

void clearDigits(void);
void processDigit(int digit, int position);
void printDigitArray(void);

int main(void){

    printf("*** Stampa, una serie di cifre, a segmenti come negli orologi digitali ***\n\n");

    char ch = ' ';
    int position = 0, digit = -1;

    while(1){
        clearDigits();
        position = 0;

        printf("Inserisci un massimo di %d cifre: ", MAX_DIGITS);
        while((ch = getchar()) != '\n'){
            if(isdigit(ch) && position < MAX_DIGITS){
                digit = ch - '0';

                processDigit(digit, position);
                position++;
            }
        }

        printDigitArray();

    }

    printf("\n");
    return 0;
}

// Ripulisce il vettore digits
void clearDigits(void){
    for(int i = 0; i < SEG_ROWS; i++){
        for(int j = 0; j < SEG_COLS; j++){
            digits[i][j] = ' ';
        }
    }
}

// Memorizza, in digits, alla posizione passata in position, la rappresentazione del numero in digit
void processDigit(int digit, int position){
    int realCol = 0, row = 0;
    char ch = ' ';

    for(int i = 0; i < NM_SEG; i++){
        if(segmentArray[digit][i]){
            switch(i){
                case 0: row = 0; realCol = 1; ch = '_'; break;
                case 1: row = 1; realCol = 2; ch = '|'; break;
                case 2: row = 2; realCol = 2; ch = '|'; break;
                case 3: row = 2; realCol = 1; ch = '_'; break;
                case 4: row = 2; realCol = 0; ch = '|'; break;
                case 5: row = 1; realCol = 0; ch = '|'; break;
                case 6: row = 1; realCol = 1; ch = '_'; break;
            }
        }

        digits[row][realCol + (position * 4)] = ch;
    }
}

void printDigitArray(void){
    for(int i = 0; i < SEG_ROWS; i++){
        for(int j = 0; j < SEG_COLS; j++){
            printf("%c", digits[i][j]);
        }
        printf("\n");
    }
}