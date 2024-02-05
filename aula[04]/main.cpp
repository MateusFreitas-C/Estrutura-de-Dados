#include <stdlib.h>
#include "ponto.h"
#include <iostream>

int main() {
    Ponto *p1 = cria_ponto(1, 2);

    Ponto *p2 = cria_ponto(5, 3);
    
    print(p1);

    print(p2);

    std::cout << "Distancia: " << distancia(p1, p2) << std::endl;

    libera_ponto(&p1);
    libera_ponto(&p2);

    return 0;
}
