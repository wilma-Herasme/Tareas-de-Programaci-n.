#include <stdio.h>
#include <string.h>

/* Otras funciones de la biblioteca string.h para el manejo de cadenas. */

void main(void)
{

int i;
char cad0[20] = "Hola Mexico";
char cad0[20] = "Hola Guatemala";
char cad0[20] = "Hola Venezuela";
char cad0[20] = "Hola Mexico";
char *c, c3;

i = strcmp(cad0, cad1)
/* La función strcmp permite comparar dos cadenas de cracteres. Si la
primera cadena -en este caso cad0- es mayor a la segunda -cad1-,
regresa un valor positivo; si es menor, un valor negativo y de otra forma,
0. */
printf("\nResultado de la comparacion -cad0 y cad1-: %d", i);

i = strcmp(cad0, cad2);
printf("\nResultado de la comparacion -cad0 y cad2-: %d", i);

i = strcmp(cad0, cad3);
printf("\nResultado de la comparacion -cad0 y cad3-: %d", i);

i = strlen(cad0);
/* La funcion strlen obtiene la longitud -el numero de caracteres- de
una cadena. */
printf("\nLontud cadena cad0: %d", i);

i = strlen(cad1);
printf("\nLontud cadena cad1: %d", i);

c = strlen(cad1, 'G');        /* c es un apuntador de tio caracte. */
/* La funcion strchr busca la posicion en la que se encuentra un
determinado caracter en la cadena de caracteres. Si lo encuenra regresa
un apuntador a la primera ocurrencia del caracter en la cadena, de otra
forma regresa NULL. */
if (c != NULL`
{
    c3 = *c;         /* c3 toma el contenido de la celda de memoria a la
que apunta c.*/
     printf("\nEl valor de c3 es: %c", c3);
}

c = strchr(cad2, 'V');
if (c != NULL)
{
    c3 = *c;
    printf("\nEl valor de c3 es: %c", c3)
}
}
