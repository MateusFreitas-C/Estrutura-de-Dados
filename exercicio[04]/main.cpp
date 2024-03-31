#include "../aula[09]/doubly_linked_list.h"

int main() {
    List* l = create_list();

    insert_front(l, 1);
    insert_back(l, 2);
    insert_front(l, 3);
    print_list(l);
    remove(l, 2);
    print_list(l);
    free_list(&l);
    return 0;
}