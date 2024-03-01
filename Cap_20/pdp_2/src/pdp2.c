#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "..\include\stackADT.h"

#define LEN_OPERATORI (int) (sizeof(operatori) / sizeof(operatori[0]))

void eseguiOperazione(Stack s, char op);

int main(void){

    printf("*** Simulazione di una calcolatrice RPN (Reverse Polish Notation) ***\n\n");

    char ch;
    char operatori[] = {'+', '-', '*', '/'};
    bool esci = false, nuovaEspr = false;
    Stack s = stack_create();

    while(!esci){

        printf("Inserisci un espressione: ");
        
        do{
            scanf(" %c", &ch);

            esci = true;

            if(isdigit(ch)){
                stack_push(s, ch - '0');
                esci = false;
            } else if (ch == '='){
                printf("Risultato: %d\n", stack_pop(s));
                stack_make_empty(s);
                nuovaEspr = true;
                esci = false;
            } else {
                for(int i = 0; i < LEN_OPERATORI; i++){
                    if(operatori[i] == ch){
                        esci = false;
                        eseguiOperazione(s, ch);
                    }
                }
            }
        }while(!esci && !nuovaEspr);

        getchar();
        printf("\n");
    }

    stack_destroy(s);

    return 0;
}

void eseguiOperazione(Stack s, char op){
    int op1 = 0, op2 = 0, result = 0;

    op2 = stack_pop(s);
    op1 = stack_pop(s);

    switch(op){
        case '+': result = op1 + op2; break;
        case '-': result = op1 - op2; break;
        case '*': result = op1 * op2; break;
        case '/': result = op1 / op2; break;
    }

    stack_push(s, result);
}
