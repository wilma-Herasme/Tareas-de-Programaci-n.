#include <stdio.h>
#include <stdlib.h>

/* Suma cuadrados.
El programa, al recibir como datos un grupo de enteros positivos, obtiene el
cuadrado de los mismos y la suma correspondiente a dichos cuadrados. */

void main(void)
{
int NUM;
long CUA, SUC = 0;
printf("\nIngrese un numero entero -0 para terminar-:\t");
scanf("%d", &NUM);
    while (NUM)
/* Observa que la condici�n es verdadera mientras el entero es diferente de cero. */
{
    CUA = pow (NUM, 2);
    printf("%d al cubo es %Id", NUM, CUA);
    SUC = SUC + CUA;
    printf("\nIngrese un numero entero entero -0 para terminar-:\t");
    scanf("%d", &NUM);
}
printf("\nLa suma de los cuadrados es %Id", SUC);
}
