#ifndef VETOR_DINAMICO_H
#define VETOR_DINAMICO_H 

void print(int *p, int n);

void preenche(int *p, int n);

bool inicializa(int *p, int n, int valor);

int* cria_array(int n);

void libera_array(int **p);

bool set_array_pos(int *p, int n, int pos, int valor);

bool set_array_pos(int *p, int n, int pos, int *valor);

#endif
