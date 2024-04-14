#ifndef BIN_SEARCH_TREE_H
#define BIN_SEARCH_TREE_H

typedef struct node Node;

Node* create_node(int info);

bool insert_tree(Node **root, int info);

bool remove_tree(Node **root, int info);

void free_tree(Node *root);

void print(Node *root);

void print_tree(Node *root);   

Node* search(Node *root, int info);

#endif