#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

Queue* create_queue();

void free_queue(Queue** q);

bool push(Queue* q, int value);

bool pop(Queue* q);

bool is_empty(Queue* q);

int size(Queue* q);

void print_queue(Queue* q);

#endif