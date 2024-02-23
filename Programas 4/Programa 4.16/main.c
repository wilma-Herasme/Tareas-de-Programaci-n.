#include <stdio.h>
#inclide <math.h>

/* Temperaturas.
El programa recibe como datos 24 n�meros reales que representan las
temperaturas en el exterior en un periodo de 24 horas. Calcula el
promedio del dia y las temperaturas m�xima y m�nima con la hora en la
que se registraron. */

void Acutem(float);
void Maxima(float, int);      /* Prototipo de funciones. */
void Minima(float, int);

float ACT = 0.0;
float MAX = -50.0;            /* Variables globales. */
float MIN = 60.0;
int HMAX;
int HMIN;
/* Variables globales. ACT se utiliza para acumular las temperaturas,
por esa razon se inicializa en cero. MAX se utiliza para calcular la
m�xima; se inicializa en -50 para que el primer valor que se ingrese
modifique su contenido. MIN se usa para calcular la m�nima; se
inicializa con un valor muy alto  para que el primer valor ingresado
modifique su contenido. HMAX y HMIN se utilizan para almacenar  el
horario en que se produjeron las temperaturas m�xima y m�nima,
respectivamente. */

void main(void)
{

    float TEM;
    int I;
    for (I = 1; I <= 24; I++)
    {
        printf("Ingresa la temperatura de la hora %d: ", I);
        scanf("%f", &TEM);
        Acutem(TEM);
        Maxima(TEM, I);     /* Llamada a las funciones. Paso de par�metros
                            por valor. */
        Minima(TEM, I);
    }
    printf("\nPromedio del dia: %5.2f", (ACT / 24));
    printf("\nMaxima del dia: %5.2f", \tHora: %d", MAX, HMAX);
    printf("\nMinima del dia: %5.2f",  \tHora: %d", MIN, HMIN);
}

void Acutem(float T)
/* Esta funcion acumula las temperaturas e la variable global ACT
para posteriormente calcular el promedio. */
{
    ACT += T;
}

void Maxima(float T, int H)
/* Esta funcion almacena la temperatura maxima y la hora en que se
produjo en las variables globales MAX y HMAX, respectivamente. */
{
if (MAX < T)
{
    MAX = T;
    HMAX = H;
}
}

void Minima(float T, int H)
/* Esta funcion almacena la temperatura maxima y la hora en que se
produjo en las variables globales MIN y HMIN. */
{
if (MIN > T)
{
    MIN = T;
    HMAX = H;
}
}
