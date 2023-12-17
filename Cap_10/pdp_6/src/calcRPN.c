#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define LEN_STACK 20
#define LEN_OPERATORI (int) (sizeof(operatori) / sizeof(operatori[0]))

int operandi[LEN_STACK];
int pos = 0;

void makeEmpty(void);
bool isEmpty(void);
bool isFull(void);
void push(int n);
int pop(void);
void eseguiOperazione(char op);
void stampaRisultato(void);

int main(void){

    printf("*** Simulazione di una calcolatrice RPN (Reverse Polish Notation) ***\n\n");

    char ch;
    char operatori[] = {'+', '-', '*', '/'};
    bool esci = false, nuovaEspr = false;

    while(!esci){

        printf("Inserisci un espressione: ");
        
        do{
            scanf(" %c", &ch);

            esci = true;

            if(isdigit(ch)){
                push(ch - '0');
                esci = false;
            } else if (ch == '='){
                stampaRisultato();
                nuovaEspr = true;
                esci = false;
            } else {
                for(int i = 0; i < LEN_OPERATORI; i++){
                    if(operatori[i] == ch){
                        esci = false;
                        eseguiOperazione(ch);
                    }
                }
            }
        }while(!esci && !nuovaEspr);

        getchar();
        printf("\n");
    }

    printf("\n");
    return 0;
}

void makeEmpty(void){
    pos = 0;
}

bool isEmpty(void){
    return pos == 0;
}

bool isFull(void){
    return pos == LEN_STACK;
}

void push(int n){
    if(isFull()){
        printf("Espressione troppo complessa!\n");
        exit(EXIT_SUCCESS);
    }

    operandi[pos++] = n;
}

int pop(void){
    if(isEmpty()){
        printf("Operandi insufficienti!\n");
        exit(EXIT_SUCCESS);
    }

    return operandi[--pos];
}

void eseguiOperazione(char op){
    int op1 = 0, op2 = 0, result = 0;

    op2 = pop();
    op1 = pop();

    switch(op){
        case '+': result = op1 + op2; break;
        case '-': result = op1 - op2; break;
        case '*': result = op1 * op2; break;
        case '/': result = op1 / op2; break;
    }

    push(result);
}

void stampaRisultato(void){
    printf("Risultato: %d\n", pop());

    makeEmpty();

}