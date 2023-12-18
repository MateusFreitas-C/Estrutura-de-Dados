#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "vetor_estatico.h"

void print(int *v, int n){
    for (int i=0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void preenche(int *v, int n){
    srand(time(NULL));

     for (int i=0; i < n; i++){
        v[i] = rand() % 100; 
    }
}