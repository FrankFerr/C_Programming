#include <stdio.h>
#include "..\include\stackADT.h"

int main(void){

    
    Stack s1, s2;
    const char *str;
    
    s1 = stack_create();
    s2 = stack_create();
    
    stack_push(s1, "Hello s1!");
    printf("s1 length after push: %d\n", stack_length(s1));

    stack_push(s1, "Test s1");
    printf("s1 length after push: %d\n", stack_length(s1));

    str = stack_pop(s1);
    printf("Popped %s from s1\n", str);
    printf("s1 length after pop: %d\n", stack_length(s1));
    stack_push(s2, "Hello s2!");
    printf("s2 length after push: %d\n", stack_length(s2));

    str = stack_pop(s1);
    printf("Popped %s from s1\n", str);
    printf("s1 length after pop: %d\n", stack_length(s1));
    stack_push(s2, "Test s2");
    printf("s2 length after push: %d\n", stack_length(s2));

    stack_destroy(s1);

    while(!stack_is_empty(s2)){
        printf("Popped %s from s2\n", (char *) stack_pop(s2));
        printf("s2 length after pop: %d\n", stack_length(s2));
    }

    stack_push(s2, "Test s2 2");
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
