#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define LEN_STACK 20

char stack[LEN_STACK];
int pos = 0;

void makeEmpty(void);
bool isEmpty(void);
bool isFull(void);
void push(char ch);
char pop(void);

int main(void){

    printf("*** Controlla se l'ordine delle parentesi (aperta/chiusa) e' corretto ***\n\n");

    char ch = ' ', lastInserted = ' ';
    bool combaciano = true;

    printf("Inserisci una serie di parentesi: ");
    while(ch != '\n'){
        scanf("%c", &ch);

        switch(ch){
            case '(': case '[': case '{': push(ch); break;
            case ')': case ']': case '}': {
                lastInserted = pop();

                if((ch == ')' && lastInserted != '(') || 
                   (ch == ']' && lastInserted != '[') ||
                   (ch == '}' && lastInserted != '{')){
                    combaciano = false;
                    break;
                }
            }
        }
    }

    if (pos != 0){
        combaciano = false;
    }
    
    if(combaciano){
        printf("Ordine parentesi corretto!\n");
    } else{
        printf("Oridne parentesi errato!\n");
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

void push(char ch){
    if(isFull()){
        printf("Stack overflow!\n");
        exit(EXIT_SUCCESS);
    }

    stack[pos++] = ch;
}

char pop(void){
    if(isEmpty()){
        printf("Stack underflow!\n");
        exit(EXIT_SUCCESS);
    }

    return stack[--pos];
}