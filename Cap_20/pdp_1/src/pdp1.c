#include <stdio.h>
#include "..\include\stackADT.h"

int main(void){

    printf("*** Controlla se l'ordine delle parentesi (aperta/chiusa) e' corretto ***\n\n");

    Stack s = stack_create();
    Item ch, lastInserted;
    bool combaciano = true;

    printf("Inserisci una serie di parentesi: ");
    while(ch != '\n' && combaciano){
        scanf("%c", &ch);

        switch(ch){
            case '(': case '[': case '{': 
                stack_push(s, ch); 
                break;
            case ')': case ']': case '}': {
                lastInserted = stack_pop(s);

                if((ch == ')' && lastInserted != '(') || 
                   (ch == ']' && lastInserted != '[') ||
                   (ch == '}' && lastInserted != '{')){
                    combaciano = false;
                }

                break;
            }
        }
    }
    
    if(!combaciano || !stack_is_empty(s)){
        printf("Oridne parentesi errato!\n");
    } else{
        printf("Ordine parentesi corretto!\n");
    }

    stack_destroy(s);

    return 0;
}
