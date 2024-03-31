#include "queue.h"
#include <iostream>
#include <stdlib.h>

#define MAX 10

struct queue{
    int info[MAX];
    int front;
    int rear;
};

Queue* create_queue(){
    Queue* q = (Queue*) malloc(sizeof(Queue));

    if(!q){
        return NULL;
    }

    q->front = 0;
    q->rear = 0;
    return q;
}

void free_queue(Queue** q){
    if(*q){
        free(*q);
        *q = NULL;
    }
}

bool push(Queue* q, int value){
    if(!q){
        return false;
    }

    if(q->rear == MAX){
        return false;
    }

    q->info[q->rear++] = value;
    return true;
}

bool pop(Queue* q){
    if(!q){
        return false;
    }

    if(q->front == q->rear){
        return false;
    }

    q->front++;
    return true;
}

bool is_empty(Queue* q){
    if(!q){
        return false;
    }

    return q->front == q->rear;
}

bool is_full(Queue* q){
    if(!q){
        return false;
    }

    return q->rear == MAX;
}

int size(Queue* q){
    if(!q){
        return -1;
    }

    return q->rear - q->front;
}

void print_queue(Queue* q){
    if(!q){
        return;
    }

    for(int i = q->front; i < q->rear; i++){
        std::cout << q->info[i] << " ";
    }
    std::cout << std::endl;
}