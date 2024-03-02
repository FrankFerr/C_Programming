#include "..\include\queueADT.h"
#include <stdlib.h>
#include <stdio.h>

struct queue_type{
    Item *queue;
    int len, size, first, last;
};

Queue queue_create(int size);
void queue_destroy(Queue q);
void queue_make_empty(Queue q);
void queue_push(Queue q, Item obj);
Item queue_pop(Queue q);
Item queue_first(Queue q);
Item queue_last(Queue q);
bool queue_is_empty(Queue q);
bool queue_is_full(Queue q);
static void queue_terminate(const char *msg);
int queue_length(Queue q);

Queue queue_create(int size){
    Queue q = malloc(sizeof(struct queue_type));
    if(!q)
        queue_terminate("Error in create: queue can't be created");
    
    q->queue = malloc(size * sizeof(Item));
    if(!q->queue){
        free(q);
        queue_terminate("Error in create: queue can't be created");
    }
    q->first = 0;
    q->last = 0;
    q->len = 0;
    q->size = size;

    return q;
}

void queue_destroy(Queue q){
    free(q->queue);
    free(q);
}

void queue_make_empty(Queue q){
    while(!queue_is_empty(q))
        queue_pop(q);
}

void queue_push(Queue q, Item obj){

    if(queue_is_full(q)){
        queue_destroy(q);
        queue_terminate("Error in push: queue is full");
    }

    q->queue[q->last++] = obj;
    q->len++;
    
    if(q->last == q->size)
        q->last = 0;
}

Item queue_pop(Queue q){
    Item obj;

    if(queue_is_empty(q)){
        queue_destroy(q);
        queue_terminate("Error in pop: queue is empty");
    }

    obj = q->queue[q->first++];
    q->len--;

    if(q->first == q->size)
        q->first = 0;

    return obj;
}

Item queue_first(Queue q){
    if(queue_is_empty(q)){
        queue_destroy(q);
        queue_terminate("Error in first: queue is empty");
    }
    
    return q->queue[q->first];
}

Item queue_last(Queue q){
    if(queue_is_full(q)){
        queue_destroy(q);
        queue_terminate("Error in last: queue is full");
    }

    int idx = q->last;

    if(idx == 0)
        idx = q->size;

    return q->queue[idx - 1];
}

bool queue_is_empty(Queue q){
    return q->len == 0;
}

bool queue_is_full(Queue q){
    return q->len == q->size;
}

static void queue_terminate(const char *msg){
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

int queue_length(Queue q){
    return q->len;
}