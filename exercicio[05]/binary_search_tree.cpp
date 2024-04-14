#include "binary_search_tree.h"
#include <stdlib.h>
#include <iostream>

struct node{
    int info;
    struct node *left;
    struct node *right;
};

Node* create_node(int info){
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->info = info;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
}

bool insert_tree(Node **root, int info){
    if(*root == NULL){
        *root = create_node(info);
        return true;
    }
    
    if(info < (*root)->info){
        return insert_tree(&(*root)->left, info);
    }
    else if(info > (*root)->info){
        return insert_tree(&(*root)->right, info);
    }
    
    return false;
}

Node* search(Node *root, int info){
    if(root == NULL)
        return NULL;
    
    if(info < root->info){
        return search(root->left, info);
    }
    else if(info > root->info){
        return search(root->right, info);
    }
        
    return root;
}

bool remove_tree(Node **root, int info){
    if(*root == NULL)
        return false;
    
    if(info < (*root)->info){
        return remove_tree(&(*root)->left, info);
    }
    else if(info > (*root)->info){
        return remove_tree(&(*root)->right, info);
    }
    
    Node *aux = *root;
    
    if(aux->left == NULL && aux->right == NULL){
        free(aux);
        *root = NULL;
    }
    else if(aux->left == NULL){
        *root = aux->right;
        free(aux);
    }
    else if(aux->right == NULL){
        *root = aux->left;
        free(aux);
    }
    else{
        Node *successor = aux->left;
        while(successor->right != NULL){
            successor = successor->right;
        }
        
        aux->info = successor->info;
        return remove_tree(&aux->left, successor->info);
    }
    
    return true;
}

void free_tree(Node *root){
    if(root == NULL)
        return;
    
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void print(Node *root){
    if(root == NULL)
        return;
    
    std::cout << root->info << std::endl;
}

void print_tree(Node *root){
    if(root == NULL)
        return;
    
    print_tree(root->left);
    print(root);
    print_tree(root->right);
}