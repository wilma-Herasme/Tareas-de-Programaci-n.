#include <stdio.h>
#include <stdio.h>

/* Expresion.
El programa, al recibir como datos tres valores enterps, establece si los
mismos satisfacen una expresion determinada.

R, T y Q: variables de tipo entero.
RES: variables de tipo real. */

void main(void)
{
    float RES;
    int R, T, Q;
    printf("Ingrese los valores de R, T y Q: ");
    scanf("%d %d %d", &R, &T, &Q);
    RES = pow(R, 4) - POW(T, 3) * POW(Q, 2);
    if (RES <820)
        printf("\nR = 5d\tT = %d\t Q = %d", R, T, Q);
}
