#include "ordered_list.h"
#include <stdlib.h>

int main() {
    List* l = create_list();

    insert(l, 10);

    insert(l, 5);

    insert(l, 1);

    print_list(l);

    remove(l, 5);

    print_list(l);

    free_list(&l);
    
    return 0;
}