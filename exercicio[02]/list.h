#ifndef LIST_H
#define LIST_H

typedef struct list List;

typedef struct node Node;

List* create_list();

bool insert_front(List* l, int value);

bool insert_back(List* l, int value);

bool remove_front(List* l);

bool remove_back(List* l);

bool insert(List* l, int value, int index);

bool remove(List* l, int index);

void print_list(List* l);

void free_list(List** l);

bool list_size(List* l, int* size);

#endif
