#include "..\include\stackADT.h"
#include <stdlib.h>
#include <stdio.h>

struct node{
    Item data;

    struct node *next;
};

struct stack_type{
    struct node *top;
    int len;
};

Stack stack_create(void);
void stack_destroy(Stack s);
void stack_make_empty(Stack s);
void stack_push(Stack s, Item obj);
Item stack_pop(Stack s);
bool stack_is_empty(Stack s);
bool stack_is_full(Stack s);
static void stack_terminate(const char *msg);
int stack_length(Stack s);

Stack stack_create(void){
    Stack s = malloc(sizeof(struct stack_type));
    if(!s)
        stack_terminate("Error in create: stack can't be created");
    
    s->top = NULL;
    s->len = 0;

    return s;
}

void stack_destroy(Stack s){
    stack_make_empty(s);
    free(s);
}

void stack_make_empty(Stack s){
    while(!stack_is_empty(s))
        stack_pop(s);
}

void stack_push(Stack s, Item obj){
    struct node *newNode;
    
    newNode = malloc(sizeof(struct node));
    if(newNode == NULL)
        stack_terminate("Error in push: stack is full");

    newNode->data = obj;
    newNode->next = s->top;
    s->top = newNode;
    s->len++;
}

Item stack_pop(Stack s){
    struct node *oldNode;
    Item obj;

    if(stack_is_empty(s))
        stack_terminate("Error in pop: stack is empty");

    oldNode = s->top;
    obj = oldNode->data;
    s->top = oldNode->next;
    s->len--;

    free(oldNode);

    return obj;
}

bool stack_is_empty(Stack s){
    return s->len == 0;
}

bool stack_is_full(Stack s){
    return false;
}

static void stack_terminate(const char *msg){
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

int stack_length(Stack s){
    return s->len;
}