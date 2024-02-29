#include <stdlib.h>
#include "list.h"
#include <iostream>
#include  <list>

int main() {
    List* l = create_list();

    push_front(l, 1);
    push_front(l, 2);
    push_back(l, 3);

    print_list(l);

    pop_back(l);

    print_list(l);

    free_list(&l);

    return 0;
}