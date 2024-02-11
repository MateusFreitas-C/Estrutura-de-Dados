#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct matriz Matriz;

Matriz* cria_matriz(int linhas, int colunas);

void inicializa_matriz(Matriz* m);

void libera_matriz(Matriz** m);

bool acessa_matriz(Matriz* m, int i, int j, float* valor);

bool atribui_matriz(Matriz* m, int i, int j, float valor);

void imprime_matriz(Matriz* m);

#endif