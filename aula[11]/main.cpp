#include <stdlib.h>
#include "stack.h"
#include <iostream>

int main() {
    Stack* s = create_stack();

    push(s, 10);

    push(s, 5);

    push(s, 1);

    print_stack(s);

    int size_stack = size(s);

    std::cout << size_stack << std::endl;

    int valor;

    pop(s, &valor);

    print_stack(s);

    free_stack(&s);
    
    return 0;
}