#ifndef VETOR_CPP
#define VETOR_CPP

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "vetor.h"

struct vetor
{
    float *valor;
    int tam;
};

Vetor* cria_array(int n){
    Vetor *v = (Vetor*) malloc(sizeof(vetor));

    if (v){
        v->valor = (float*) malloc(n * sizeof(float));
        v->tam = n;

        return v;
    }
    free(v);
    return NULL;
}

void libera_array(Vetor **v){
    if (*v){
        free((*v)->valor);
        free(*v);
        *v = NULL;
    }
}

bool set_array_pos(Vetor *v, int pos, float valor){
    if(!v || pos < 0){
        return false;
    }

    if(pos >= v->tam){
        if(!realloc_array(v, pos + 1)){
            return false;
        }else{
            v->valor[pos] = valor;
            return true;
        }
    }

    std::cout<<valor << std::endl;
    v->valor[pos] = valor;
    return true;
        
}

bool get_array_pos(Vetor *v, int pos, float *valor){
    if(!v || pos < 0){
        return false;
    }

    if(pos >= v->tam || !valor){
        return false;
    }

    *valor = v->valor[pos];
    return true;
}

void print(Vetor* v){
    if(!v){
        return;
    }

    for(int i = 0; i < v->tam; i++){
        std::cout << v->valor[i] << " ";
    }

    std::cout << std::endl;
}

bool realloc_array(Vetor *v, int n){
    if(!v || n < v->tam){
        return false;
    }

    float *aux = (float*) realloc(v->valor, n * sizeof(float));

    if(!aux){
        return false;
    }

    v->valor = aux;
    v->tam = n;

    return true;
}

bool preenche_array(Vetor *v){
    if(!v){
        return false;
    }

    srand(time(NULL));

    for(int i = 0; i < v->tam; i++){
        v->valor[i] = rand() % 100;
    }

    return true;
}

#endif