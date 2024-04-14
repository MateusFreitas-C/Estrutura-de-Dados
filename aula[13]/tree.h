#ifndef TREE_H
#define TREE_H

typedef struct node Node;

Node* create_node(int info);

bool insert_tree(Node **root, int info);

void free_tree(Node *root);

void print(Node *root);

bool search_preorder(Node *root, int value);

#endif