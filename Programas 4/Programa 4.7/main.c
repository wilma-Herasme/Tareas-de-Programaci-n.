#include <stdio.h>

/* Prueba de par�metros por valor. */

int f1 (int);       /* Prototipo de funci�n. El par�metro es por valor
                       y de tipo entero. */

void main(void)
{
    int I, K = 4;
    for (I= 1; I <= 3; I++)
    {
        printf("\n\nValor de K antes de llamar a la funcion: %d", ++K);
        printf("\nValor de K despues de llamar a la funcion: %d", f1(K));
        /* Llamada a la funci�n f1. Se pasa una copia de la variable K. */
    }
}

int f1(int R)
{
    R += R;
    return (R);
}
