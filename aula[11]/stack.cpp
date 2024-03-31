#include <stdlib.h>
#include <iostream>
#include "stack.h"

#define MAX 10

struct stack{
    int info[MAX];
    int top;
};

Stack* create_stack(){
    Stack* s = (Stack*) malloc(sizeof(Stack));

    if(s != NULL){
        s->top = -1;
    }

    return s;
}

void print_stack(Stack* s){
    if(s != NULL){
        for(int i = 0; i <= s->top; i++){
            std::cout << s->info[i] << " ";
        }
        std::cout << std::endl;
    }
}

void free_stack(Stack** s){
    if(!s){
        return;
    }

    free(*s);
    *s = NULL;
}

bool push(Stack* s, int value){
    if(s == NULL || s->top == MAX - 1){
        return false;
    }

    s->top++;
    s->info[s->top] = value;
    return true;
}

bool pop(Stack* s, int* value){
    if(!s || s->top == -1 || !value){
        return false;
    }

    *value = s->info[s->top];
    s->top --;
    return true;
}

bool is_empty(Stack* s){
    if(s == NULL){
        return false;
    }

    return s->top == -1;
}

int size(Stack* s){
    if(s == NULL){
        return -1;
    }

    return s->top + 1;
}