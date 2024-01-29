#ifndef VETOR_H
#define VETOR_H

typedef struct vetor Vetor;

void print(Vetor* v);

Vetor* cria_array(int n);

void libera_array(Vetor **v);

bool set_array_pos(Vetor *v, int pos, float valor);

bool get_array_pos(Vetor *v, int pos, float *valor);

bool realloc_array(Vetor *v, int n);

bool preenche_array(Vetor *v);

#endif
