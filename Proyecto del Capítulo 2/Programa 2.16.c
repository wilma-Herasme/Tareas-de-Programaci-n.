#include <stdio.h>

/* Empresa textil.
El programa, al recibir como datos decisivos la categoria y antiguedad de
un empleado, determina si el mismo reune las condiciones establecidas por
la empresa para ocupar un nuevo tcargo en una sucursal.

CLA, CAT, ANT, RES: variables de tipo entero.
SAL: variable de tito real. */

void main(void)
{

    int CLA, CAT, ANT, RES;
    printf("\Ingrese la clave, categoria y antiguedad del trabajador:");
    scanf("%d %d %d", &CLA, &CAR, &ANT);
    switch(CAT)
    {
        case 3:
        case 4: if (ANT >= 5)
                    RES = 1;
                else
                      RES = 0;
                break;
        case 2: if (ANT >= 7)
                         RES = 1;
                else
                            RES = 0;
                break;
        default: RES = 0;
               break;
    }
    if (RES)
            printf("\nEl trabajador con clave 5d reune las condiciones para el
            puesto", CLA);
    else
            printf("\nEl trabajador con clave %d no reune las condiciones para
            el puesto", CLA);
}
