#include <stdlib.h>
#include "../aula[12]/queue.h"
#include <iostream>

int main() {
    Queue* q = create_queue();

    push(q, 10);

    push(q, 5);

    push(q, 1);

    print_queue(q);

    int size_queue = size(q);

    std::cout << size_queue << std::endl;

    pop(q);

    print_queue(q);

    free_queue(&q);
    
    return 0;
}