#ifndef MATRIZ_CPP
#define MATRIZ_CPP

#include "matriz.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

struct matriz
{
    int linhas;
    int colunas;
    float *valor;
};

Matriz* cria_matriz(int linhas, int colunas){
    
    if(linhas <= 0 || colunas <= 0){
        return NULL;
    }
    
    Matriz *m = (Matriz*) malloc(sizeof(matriz));

    if(m){
        m->linhas = linhas;
        m->colunas = colunas;
        m->valor = (float*) malloc(linhas*colunas*sizeof(float));

        if(!m->valor){
            free(m);
            return NULL;
        }

        return m;
    }else{
        return NULL;
    }
}

void inicializa_matriz(Matriz* m){
    srand(time(NULL));

    for (int i=0; i < m->linhas; i++){
        for (int j=0; j < m->colunas; j++){
            m->valor[i*m->colunas+j] = rand() % 100;
        }
    }
}

void libera_matriz(Matriz** m){
    if(*m){
        free((*m)->valor);
        free(*m);
        *m = NULL;
    }
}

bool acessa_matriz(Matriz* m, int i, int j, float* valor){
    if(i < 0 || i >= m->linhas || j < 0 || j >= m->colunas){
        return false;
    }

    *valor = m->valor[i*m->colunas+j];
    return true;
}

bool atribui_matriz(Matriz* m, int i, int j, float valor){
    if(i < 0 || i >= m->linhas || j < 0 || j >= m->colunas){
        return false;
    }

    m->valor[i*m->colunas+j] = valor;
    return true;
}

void imprime_matriz(Matriz* m){
    for (int i=0; i < m->linhas; i++){
        for (int j=0; j < m->colunas; j++){
            std::cout << m->valor[i*m->colunas+j] << " ";
        }
        std::cout << std::endl;
    }
}

#endif