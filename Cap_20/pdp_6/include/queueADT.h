#ifndef QUEUE_ADT_H
#define QUEUE_ADT_H
#include <stdbool.h>

typedef struct queue_type *Queue;
typedef int Item;

Queue queue_create(int size);
void queue_destroy(Queue q);
void queue_make_empty(Queue q);
void queue_push(Queue q, Item obj);
Item queue_pop(Queue q);
Item queue_first(Queue q);
Item queue_last(Queue q);
bool queue_is_empty(Queue q);
bool queue_is_full(Queue q);
int queue_length(Queue q);

#endif