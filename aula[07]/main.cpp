#include <stdlib.h>
#include "list.h"
#include <iostream>
#include  <list>

int main() {
    List* l = create_list();

    insert_front(l, 1);
    insert_front(l, 2);
    insert_back(l, 3);

    print_list(l);

    remove_back(l);

    print_list(l);

    free_list(&l);
    
    return 0;
}