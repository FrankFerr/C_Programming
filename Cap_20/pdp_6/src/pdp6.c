#include <stdio.h>
#include "..\include\queueADT.h"

int main(void){

    Queue q1;
    Item obj;
    
    q1 = queue_create(10);
    
    for(int i = 0; i < 6; i++){
        queue_push(q1, i + 1);
        printf("Pushed %d in q1\n", i + 1);
    }
    printf("\n");

    printf("q1 length after push: %d\n", queue_length(q1));
    printf("q1 first: %d\n", queue_first(q1));
    printf("q1 last: %d\n", queue_last(q1));
    printf("\n");

    obj = queue_pop(q1);
    printf("Popped %d from q1\n", obj);
    obj = queue_pop(q1);
    printf("Popped %d from q1\n", obj);
    obj = queue_pop(q1);
    printf("Popped %d from q1\n", obj);
    obj = queue_pop(q1);
    printf("Popped %d from q1\n", obj);
    printf("\n");

    printf("q1 length after pop: %d\n", queue_length(q1));
    printf("q1 first: %d\n", queue_first(q1));
    printf("q1 last: %d\n", queue_last(q1));
    printf("\n");

    for(int i = 10; i < 16; i++){
        queue_push(q1, i + 1);
        printf("Pushed %d in q1\n", i + 1);
    }
    printf("\n");

    printf("q1 length after push: %d\n", queue_length(q1));
    printf("q1 first: %d\n", queue_first(q1));
    printf("q1 last: %d\n", queue_last(q1));
    printf("\n");

    queue_make_empty(q1);
    printf("q1 length after make_empty: %d\n", queue_length(q1));
    if(queue_is_empty(q1))
        printf("q1 is empty\n");
    else
        printf("q1 is not empty\n");

    queue_destroy(q1);

    return 0;
}
