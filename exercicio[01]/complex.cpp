#ifndef COMPLEX_CPP
#define COMPLEX_CPP

#include "complex.h"
#include <stdlib.h>
#include <iostream>

struct complex
{
    float real;
    float imag;
};

Complex* cria_complex(float real, float imag){
    Complex *c = (Complex*) malloc(sizeof(complex));

    if(c){
        c->real = real;
        c->imag = imag;

        return c;
    }else{
        return NULL;
    }
}

void libera_complex(Complex** c){
    if(*c){
        free(*c);
        *c = NULL;
    }
}

Complex* soma_complex(Complex* c1, Complex* c2){
    float real = c1->real + c2->real;

    float imag = c1->imag + c2->imag;

    return cria_complex(real, imag);
}

Complex* subtrai_complex(Complex* c1, Complex* c2){
    float real = c1->real - c2->real;

    float imag = c1->imag - c2->imag;

    return cria_complex(real, imag);
}

Complex* multiplica_complex(Complex* c1, Complex* c2){
    float real = (c1->real * c2->real) - (c1->imag * c2->imag);

    float imag = (c1->real * c2->imag) + (c1->imag * c2->real);

    return cria_complex(real, imag);
}

Complex* divide_complex(Complex* c1, Complex* c2){
    float real = ((c1->real * c2->real) + (c1->imag * c2->imag)) / ((c2->real * c2->real) + (c2->imag * c2->imag));

    float imag = ((c1->imag * c2->real) - (c1->real * c2->imag)) / ((c2->real * c2->real) + (c2->imag * c2->imag));

    return cria_complex(real, imag);
}

void imprime_complex(Complex* c){
    if(!c){
        return;
    }

    std::cout << c->real << " + " << c->imag << "i";

    std::cout << std::endl;
}

#endif