#include "tree.h"
#include <iostream>

int main(){
    Node *root = create_node(10);
    
    insert_tree(&root, 5);
    insert_tree(&root, 15);
    insert_tree(&root, 3);
    insert_tree(&root, 7);
    insert_tree(&root, 12);
    insert_tree(&root, 17);
    
    if(search_preorder(root, 8))
        std::cout << "8 found" << std::endl;
    else
        std::cout << "8 not found" << std::endl;
    
    free_tree(root);
    
    return 0;
}