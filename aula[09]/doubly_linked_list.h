#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct list List;

typedef struct node Node;

List* create_list();

bool insert_front(List* l, int value);

bool insert_back(List* l, int value);

Node* search(List* l, int value);

bool remove(List* l, int value);

bool remove_front(List* l);

void print_list(List* l);

void free_list(List** l);

int list_size(List* l);

#endif