#include "doubly_linked_list.h"
#include <stdlib.h>
#include <iostream>

struct node {
    int value;
    struct node* next;
    struct node* prev;
};

struct list{
    struct node* head;
    struct node* tail;
};

Node* create_node(int value) {
    Node* n = (Node*) malloc(sizeof(Node));
    if(!n){
        return NULL;
    }

    n->value = value;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

List* create_list() {
    List* l = (List*) malloc(sizeof(List));

    if(!l){
        return NULL;
    }

    l->head = NULL;
    l->tail = NULL;
    return l;
}

bool insert_front(List* l, int value) {
    if(!l){
        return false;
    }

    Node* n = create_node(value);
    if(!n){
        return false;
    }

    if(!l->head){
        l->head = n;
        l->tail = n;
        return true;
    }

    n->next = l->head;
    l->head->prev = n;
    l->head = n;
    return true;
}

bool insert_back(List* l, int value) {
    if(!l){
        return false;
    }

    Node* n = create_node(value);
    if(!n){
        return false;
    }

    if(!l->tail){
        l->head = n;
        l->tail = n;
        return true;
    }

    n->prev = l->tail;
    l->tail->next = n;
    l->tail = n;
    return true;
}

Node* search(List* l, int value) {
    if(!l){
        return NULL;
    }

    Node* current = l->head;
    while(current){
        if(current->value == value){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

bool remove(List* l, int value){
    Node* n = search(l, value);

    if(!n){
        return false;
    }

    if(n == l->head){
        l->head = n->next;
    } else {
        n->prev->next = n->next;
    }

    if(n == l->tail){
        l->tail = n->prev;
    } else {
        n->next->prev = n->prev;
    }

    free(n);
    return true;
}

void print_list(List* l) {
    if(!l){
        return;
    }

    Node* current = l->head;
    while(current){
        std::cout << current->value << " ";
        current = current->next;
    }
    printf("\n");
}

void free_list(List** l) {
    if(!l || !(*l)){
        return;
    }

    Node* current = (*l)->head;
    while(current){
        Node* aux = current;
        current = current->next;
        free(aux);
    }

    free(*l);
    *l = NULL;
}

int list_size(List* l){
    if(!l){
        return 0;
    }

    int size = 0;
    Node* current = l->head;
    while(current){
        size++;
        current = current->next;
    }
    return size;
}