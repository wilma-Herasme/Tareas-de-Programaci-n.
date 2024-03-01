#include <stdio.h>
#include <stdlib.h>

int main()
{
    double *ptrd;// variable tipo puntero
    void *ptrd2;
    int *num;
    int a[100];
    num = &a[0];
    *num = 10;
    num += 10;
    *num = 20;

    *num +=10;
    for(int i = 0;i < 20;i++)
    {
        printf("\nValor de a[%d]=%d",i,a[i]);
    }

    double d1 = 18.0;
    int int1 = 97;
    printf("\nValor de d1 = %if",d1);
    ptrd = &d1;//& operador de direccion
    *ptrd = 125.5;//* operador de in direcccion

        printf("\nValor de d1 = %if",d1);
        printf("\nValor de d1 = %if",*ptrd);

        printf("\nDireccion de d1; %p",&d1);
        //un puntero es un numero entero a 64 bits

        printf("\n di\\Dimencion de d1:%d",sizeof(d1));
        printf("\n di\\Dimencion de a[100]:%d",sizeof(a));
        printf("\n di\\Dimencion de a[1]:d1:%d",sizeof(*a));
        printf("\n di\\Dimencion de int:%d",sizeof(int1));
        return 0;
}
