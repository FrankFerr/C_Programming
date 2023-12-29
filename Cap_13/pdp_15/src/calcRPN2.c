#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define LEN_STACK 20
#define LEN_OPERATORI (int) (sizeof(operatori) / sizeof(operatori[0]))

const char operatori[] = {'+', '-', '*', '/'};
int operandi[LEN_STACK];
int pos = 0;

void makeEmpty(void);
bool isEmpty(void);
bool isFull(void);
void push(int n);
int pop(void);
void eseguiOperazione(char op);
void stampaRisultato(int res);
int evaluateRPNExpression(const char* expr);

int main(void){

    printf("*** Simulazione di una calcolatrice RPN (Reverse Polish Notation) ***\n\n");

    char expression[100 + 1];
    int result = 0;

    while(true){

        printf("Inserisci un espressione: ");
        gets(expression);

        if(!isdigit(expression[0]))
            break;

        result = evaluateRPNExpression(expression);
        stampaRisultato(result);
        
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

void stampaRisultato(int res){
    printf("Risultato: %d\n", res);

    makeEmpty();
}

int evaluateRPNExpression(const char* expr){
    int result = 0;

    while(*expr != '\0'){
        if(isdigit(*expr)){
            push(*expr - '0');
        } 
        else if (*expr == '='){
            result = pop();
            break;
        } 
        else {
            for(int i = 0; i < LEN_OPERATORI; i++){
                if(operatori[i] == *expr){
                    eseguiOperazione(*expr);
                }
            }
        }

        expr++;
    }

    return result;
}