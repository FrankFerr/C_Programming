#include "..\include\queueADT.h"
#include <stdlib.h>
#include <stdio.h>

struct node{
    Item data;
    struct node *next;
};

struct queue_type{
    struct node *first, *last;
    int len;
};

Queue queue_create(void);
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

Queue queue_create(void){
    Queue q = malloc(sizeof(struct queue_type));
    if(!q)
        queue_terminate("Error in create: queue can't be created");
    
    q->first = q->last = NULL;
    q->len = 0;

    return q;
}

void queue_destroy(Queue q){
    queue_make_empty(q);
    free(q);
}

void queue_make_empty(Queue q){
    while(!queue_is_empty(q))
        queue_pop(q);
}

void queue_push(Queue q, Item obj){
    struct node *newNode;

    if(queue_is_full(q)){
        queue_destroy(q);
        queue_terminate("Error in push: queue is full");
    }

    newNode = malloc(sizeof(struct node));
    newNode->data = obj;

    if(queue_is_empty(q)){
        q->first = q->last = newNode;
    } else {
        q->last->next = newNode;
        q->last = newNode;
    }
    
    q->len++;

}

Item queue_pop(Queue q){
    struct node *oldNode;
    Item obj;

    if(queue_is_empty(q)){
        queue_destroy(q);
        queue_terminate("Error in pop: queue is empty");
    }

    oldNode = q->first;
    obj = oldNode->data;
    q->first = oldNode->next;

    free(oldNode);
    q->len--;

    return obj;
}

Item queue_first(Queue q){
    if(queue_is_empty(q)){
        queue_destroy(q);
        queue_terminate("Error in first: queue is empty");
    }
    
    return q->first->data;
}

Item queue_last(Queue q){
    if(queue_is_full(q)){
        queue_destroy(q);
        queue_terminate("Error in last: queue is full");
    }

    return q->last->data;
}

bool queue_is_empty(Queue q){
    return q->len == 0;
}

bool queue_is_full(Queue q){
    return false;
}

static void queue_terminate(const char *msg){
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

int queue_length(Queue q){
    return q->len;
}