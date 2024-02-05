#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;

void print(Ponto* p);

Ponto* cria_ponto(int x, int y);

void libera_ponto(Ponto** p);

bool set_ponto_pos(Ponto* p, int x, int y);

bool get_ponto_pos(Ponto* p, int x, int y);

float distancia(Ponto* p1, Ponto* p2);

#endif
