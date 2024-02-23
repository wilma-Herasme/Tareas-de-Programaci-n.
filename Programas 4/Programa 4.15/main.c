#include <stdio.h>

/* Productora.
El programa calcula la productoria de los N numeros naturales. */

int Productoria(int);

void main(void)
{
int NUM;

/* Se escribe un do-while para verificar que el número del cual se
quiere calcular la productoria sea correcto. */
do
{
    printf("Ingresa el número del cual quieres calcular la
           productoria: ");
    scanf("%d", &NUM);
}
while (NUM >100 || NUM < 1);
printf("\nLa productoria de %d es: %d", NUM, productoria(NUM));
}

int Productoria(int N)
/* La función calcula la productoria de N. */
{
    int I, PRO = 1;
    for (I = 1; I <= N; I++)
        PRO *= I;
    return (PRQ);
}
