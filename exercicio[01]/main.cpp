#include <stdlib.h>
#include <iostream>
#include "complex.h"

int main(){
    Complex *c1 = cria_complex(1, 2);
    Complex *c2 = cria_complex(3, 4);

    std::cout << "C1: ";
    imprime_complex(c1);

    std::cout << "C2: ";
    imprime_complex(c2);

    Complex *resultado = soma_complex(c1, c2);
    std::cout << "C1 + C2 = ";
    imprime_complex(resultado);

    resultado = subtrai_complex(c1, c2);
    std::cout << "C1 - C2 =  ";
    imprime_complex(resultado);

    resultado = multiplica_complex(c1, c2);
    std::cout << "C1 * C2 =  ";
    imprime_complex(resultado);

    resultado = divide_complex(c1, c2);
    std::cout << "C1 / C2 =  ";
    imprime_complex(resultado);


    libera_complex(&c1);
    libera_complex(&c2);
    libera_complex(&resultado);

    return 0;
}