#include "vetor_dinamico.h"
#include <iostream>

using namespace std;

int main(void){
    int tamanho;
    cout << "Insira o tamanho do array: ";
    cin >> tamanho;

    int *v = cria_array(tamanho);
    
    inicializa(v, tamanho, 0);

    preenche(v, tamanho);
    print(v, tamanho);
    libera_array(&v);

    return 0;
}