#include "tree.h"
#include <stdlib.h>
#include <iostream>

struct node{
    int info;
    struct node *left;
    struct node *right;
};

struct node* create_node(int info){
    struct node *n = (struct node*) malloc(sizeof(struct node));
    n->info = info;
    n->left = NULL;
    n->right = NULL;
    return n;
}

bool insert_tree(struct node **root, int info){
    if(*root == NULL){
        *root = create_node(info);
        return true;
    }
    
    if(rand() % 2)
        return insert_tree(&(*root)->left, info);
    else
        return insert_tree(&(*root)->right, info);

    return false;
}

void free_tree(struct node *root){
    if(root == NULL)
        return;
    
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print(Node *root){
    if(root == NULL)
        return;
    
    print(root->left);
    std::cout << root->info << std::endl;
    print(root->right);
}

bool search_preorder(Node *root, int value){
    if(root == NULL)
        return false;
    
    if(root->info == value){
        return true;
    }
    
    return search_preorder(root->left, value) || search_preorder(root->right, value);
}
