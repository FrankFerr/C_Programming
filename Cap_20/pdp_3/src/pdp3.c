#include <stdio.h>
#include "..\include\stackADT.h"

int main(void){

    
    Stack s1, s2;
    int n = 0;
    
    s1 = stack_create();
    s2 = stack_create();
    
    stack_push(s1, 1);
    printf("s1 length after push: %d\n", stack_length(s1));

    stack_push(s1, 2);
    printf("s1 length after push: %d\n", stack_length(s1));

    n = stack_pop(s1);
    printf("Popped %d from s1\n", n);
    printf("s1 length after pop: %d\n", stack_length(s1));
    stack_push(s2, n);
    printf("s2 length after push: %d\n", stack_length(s2));

    n = stack_pop(s1);
    printf("Popped %d from s1\n", n);
    printf("s1 length after pop: %d\n", stack_length(s1));
    stack_push(s2, n);
    printf("s2 length after push: %d\n", stack_length(s2));

    stack_destroy(s1);

    while(!stack_is_empty(s2)){
        printf("Popped %d from s2\n", stack_pop(s2));
        printf("s2 length after pop: %d\n", stack_length(s2));
    }

    stack_push(s2, n);
    printf("s2 length after push: %d\n", stack_length(s2));

    stack_make_empty(s2);
    printf("s2 length after make_empty: %d\n", stack_length(s2));
    if(stack_is_empty(s2))
        printf("s2 is empty\n");
    else
        printf("s2 is not empty\n");

    stack_destroy(s2);

    return 0;
}
