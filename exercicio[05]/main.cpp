#include "binary_search_tree.h"
#include <stdlib.h>
#include <iostream>

int main(){
    Node *root = NULL;
    
    insert_tree(&root, 10);
    insert_tree(&root, 5);
    insert_tree(&root, 15);
    insert_tree(&root, 3);
    insert_tree(&root, 7);
    insert_tree(&root, 12);
    insert_tree(&root, 20);
    
    print_tree(root);
    
    Node *node = search(root, 7);
    
    if(node != NULL){
        std::cout << "Node found: ";
        print(node);
    }
    else{
        std::cout << "Node not found" << std::endl;
    }

    remove_tree(&root, 5);
    
    print_tree(root);

    free_tree(root);
    
    return 0;
}