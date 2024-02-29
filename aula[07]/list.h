#ifndef LIST_H
#define LIST_H

typedef struct list List;

typedef struct node Node;

List* create_list();

bool push_front(List* l, int value);

bool push_back(List* l, int value);

bool pop_front(List* l);

bool pop_back(List* l);

bool insert(List* l, int value, int index);

bool remove(List* l, int index);

void print_list(List* l);

void free_list(List** l);

#endif