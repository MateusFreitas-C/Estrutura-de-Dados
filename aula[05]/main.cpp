#include "matriz.h"
#include <iostream>

int main(){
    Matriz *m = cria_matriz(3, 3);
    inicializa_matriz(m);
    imprime_matriz(m);
    libera_matriz(&m);

    if(m == NULL){
        std::cout << "Matriz liberada com sucesso!" << std::endl;
    }
}