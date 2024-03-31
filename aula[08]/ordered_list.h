#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

typedef struct list List;

typedef struct node Node;

List* create_list();

void print_list(List* l);

bool remove(List* l, int value);

bool insert(List* l, int value);

void free_list(List** l);

#endif