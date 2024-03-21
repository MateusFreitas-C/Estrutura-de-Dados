#include <stdlib.h>
#include <iostream>
#include "stack.h"
#include "list.h"

struct stack {
    List* l;
};

Stack* create_stack() {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    if(!s){
        return NULL;
    }

    s->l = create_list();
    if(!s->l){
        free(s);
        return NULL;
    }

    return s;
}

void print_stack(Stack* s) {
    print_list(s->l);
}

void free_stack(Stack** s) {
    if(!s || !(*s)){
        return;
    }

    free_list(&(*s)->l);
    free(*s);
    *s = NULL;
}

bool push(Stack* s, int value) {
    return insert_back(s->l, value);
}

bool pop(Stack* s) {
    return remove_back(s->l);
}

bool is_empty(Stack* s) {
    int size;
    list_size(s->l, &size);
    return size == 0;
}

int size(Stack* s) {
    int size;
    list_size(s->l, &size);
    return size;
}
