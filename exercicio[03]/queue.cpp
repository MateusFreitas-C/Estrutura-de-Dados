#include "../aula[12]/queue.h"
#include "../exercicio[02]/list.h"
#include <stdlib.h>
#include <iostream>

struct queue{
    List *list;
};

Queue* create_queue(){
    Queue *q = (Queue*) malloc(sizeof(Queue));

    if(!q){
        return NULL;
    }

    q->list = create_list();
    return q;
}

void free_queue(Queue **q){
    if(*q)
    {
        free_list(&(*q)->list);
        free(*q);
        *q = NULL;
    }
}

bool push(Queue *q, int value){
    if(!q)
    {
        return false;
    }

    return insert_back(q->list, value);
}

bool pop(Queue *q){
    if(!q){
        return false;
    }

    return remove_front(q->list);
}

int size(Queue *q){
    int size = 0;
    if(!q){
        return -1;
    }

    list_size(q->list, &size);

    return size;
}

void print_queue(Queue* q){
    if(!q){
        return;
    }

    print_list(q->list);
}