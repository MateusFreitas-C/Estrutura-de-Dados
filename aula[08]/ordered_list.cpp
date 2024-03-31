#include <stdlib.h>
#include <iostream>
#include "ordered_list.h"

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

void free_list(List** l) {
    if(!l || !(*l)){
        return;
    }

    Node* aux = (*l)->head;
    while(aux){
        Node* next = aux->next;
        free(aux);
        aux = next;
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

bool remove(List* l, int value) {
    if(!l || !l->head){
        return false;
    }

    Node* aux = l->head;
    Node* prev = NULL;
    while(aux && aux->value != value){
        prev = aux;
        aux = aux->next;
    }

    if(!aux){
        return false;
    }

    if(!prev){
        l->head = aux->next;
    } else {
        prev->next = aux->next;
    }

    free(aux);
    return true;
}

bool insert(List* l, int value){
    if(!l){
        return false;
    }

    Node* n = create_node(value);

    if(!n){
        return false;
    }

    if(!l->head || l->head->value > value){
        n->next = l->head;
        l->head = n;
        return true;
    }

    Node* aux = l->head;
    while(aux->next && aux->next->value < value){
        aux = aux->next;
    }

    n->next = aux->next;
    aux->next = n;
    return true;
}