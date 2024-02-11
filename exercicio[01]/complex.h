#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complex Complex;

Complex* cria_complex(float real, float imag);

void libera_complex(Complex** c);

Complex* soma_complex(Complex* c1, Complex* c2);

Complex* subtrai_complex(Complex* c1, Complex* c2);

Complex* multiplica_complex(Complex* c1, Complex* c2);

Complex* divide_complex(Complex* c1, Complex* c2);

void imprime_complex(Complex* c);

#endif