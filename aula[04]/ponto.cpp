#ifndef PONTO_CPP
#define PONTO_CPP

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "ponto.h"

struct ponto
{
    int x;
    int y;
};

Ponto* cria_ponto(int x, int y){
    Ponto *p = (Ponto*) malloc(sizeof(ponto));

    if (p){
        p->x = x;
        p->y = y;

        return p;
    }else{
        return NULL;
    }
}

void libera_ponto(Ponto** p){
    if(*p){
        free(*p);
        *p = NULL;
    }
}

bool set_ponto_pos(Ponto* p, int x, int y){
    if(!x || !y){
        std::cout<<"Erro" << std::endl;
        return false;
    }

    p->x = x;
    p->y = y;

    return true;
}

bool get_ponto_pos(Ponto* p, int x, int y){
    if(!x || !y){
        std::cout<<"Erro" << std::endl;
        return false;
    }

    x = p->x;
    y = p->y;

    return true;
}

void print(Ponto* p){
    if(!p){
        return;
    }

    std::cout << "Ponto: (" << p->x << ", " << p->y << ")";

    std::cout << std::endl;
}

float distancia(Ponto* p1, Ponto* p2){
    if(!p1 || !p2){
        return -1;
    }

    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

#endif