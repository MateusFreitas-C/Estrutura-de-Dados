#include <stdlib.h>
#include "vetor.h"
#include <iostream>

int main() {
    Vetor *vetor = cria_array(10);
    float valor;

    if(preenche_array(vetor)){
        print(vetor);
    }

    get_array_pos(vetor, 0, &valor);

    std::cout << "Valor: " << valor << std::endl;
    
    set_array_pos(vetor, 10, 12);
    set_array_pos(vetor, 11, 12);
    set_array_pos(vetor, 0, 12);
    

    print(vetor);

    libera_array(&vetor);

    return 0;
}
