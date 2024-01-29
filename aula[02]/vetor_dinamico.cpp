#ifndef VETOR_DINAMICO_CPP
#define VETOR_DINAMICO_CPP

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "vetor_dinamico.h"

void print(int *p, int n){
    for (int i=0; i < n; i++){
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}

bool inicializa(int *p, int n, int valor){
    if(!p){
        return false;
    }

    for (int i = 0; i < n; i++){
       p[i] = valor;
    }
    return true;
}

void preenche(int *p, int n){
    srand(time(NULL));

     for (int i=0; i < n; i++){
        p[i] = rand() % 100; 
    }
}

int* cria_array(int n){
    return (int*) malloc(n * sizeof(int));
}

void libera_array(int **p){
    free(*p);
    *p = NULL;
}

bool set_array_pos(int *p, int n, int pos, int valor){

    if (pos < 0 || pos >= n || p==NULL){
        return false;
    }


    p[pos] = valor;

    return true;
}

bool set_array_pos(int *p, int n, int pos, int *valor){

    if (pos < 0 || pos >= n || p==NULL || valor==NULL){
        return false;
    }


    *valor = p[pos];

    return true;
}

#endif