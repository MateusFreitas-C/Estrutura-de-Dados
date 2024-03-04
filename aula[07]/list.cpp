#include <stdlib.h>
#include <iostream>
#include "list.h"

struct node {
    int value;
    struct node* next;
};

struct list {
    struct node* head;
};

Node* create_node(int value) {
    Node* n = (Node*) malloc(sizeof(Node));
    if(!n){
        return NULL;
    }

    n->value = value;
    n->next = NULL;
    return n;
}

List* create_list() {
    List* l = (List*) malloc(sizeof(List));
    if(!l){
        return NULL;
    }

    l->head = NULL;
    return l;
}

bool push_front(List* l, int value) {
    if(!l){
        return false;
    }

    Node* n = create_node(value);

    if(!n){
        return false;
    }

    n->next = l->head;
    l->head = n;
    return true;
}

bool push_back(List* l, int value) {
    if(!l){
        return false;
    }

    Node* n = create_node(value);

    if(!n){
        return false;
    }

    if(!l->head){
        l->head = n;
        return true;
    }

    Node* aux = l->head;
    while(aux->next){
        aux = aux->next;
    }

    aux->next = n;
    return (aux->next != NULL);
}

bool pop_front(List* l) {
    if(!l || !l->head){
        return false;
    }

    Node* aux = l->head->next;

    free(l->head);
    l->head = aux;
    
    return true;
}

bool pop_back(List* l) {
    if(!l || !l->head){
        return false;
    }

    if(!l->head->next){
        pop_front(l);
        return true;
    }

    Node* aux = l->head;
    while(aux->next->next){
        aux = aux->next;
    }

    free(aux->next);
    aux->next = NULL;
    return true;
}

void free_list(List** l) {
    if(!l || !(*l)){
        return;
    }

    while((*l)->head != NULL){
        pop_front(*l);
    }
    free(*l);
    *l = NULL;
}

void print_list(List* l) {
    if(!l || !l->head){
        return;
    }

    Node* aux = l->head;
    while(aux){
        std::cout << aux->value << " ";
        aux = aux->next;
    }
    std::cout << std::endl;
}

bool list_size(List* l, int* size){
    if(!l || !size){
        return false;
    }

    int count = 0;

    Node* aux = l->head;

    while(aux){
        count++;
        aux = aux->next;
    }
    *size = count;

    return true;
}
