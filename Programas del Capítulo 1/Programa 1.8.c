#include <stdio.h>
#include <stdio.h>

/* Volumen y área del cilindro
El programa, al recibir como datos el radio y la altura de un cilindro,
calcula su área y su volumen.

RAD, ALT, VOL y ARE: variables de tipo real.  */

void main (void)
{
    float RAD, ALT, VOL, ARE;
    printf("Ingrese el radio y la altura del cilindro: ");
    sacnf("%f %f", &RAD, &ALT);
    /* M_PI es una constante definida en math.h que contiene el valor de PI */
    VOL = M_PI * pow (RAD, 2) * ALT;
    ARE = 2 * M_PI * RAD *ALT;
    printf("\nEl volumen es: %6.2f  \t El área es: %6.22f", VOL, ARE);
}
