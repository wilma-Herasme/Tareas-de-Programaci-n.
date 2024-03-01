#include <stdio.h>
#include <stdlib.h>

#define ERR_OK 0
#define ERR_DBZ 100
#define ERR_DESC 500

//responsabilodad dividir el  codigo en modulos funcionales
float Div(float,float);
int Div2(float,float,float)

int main()
{
    float num;
    float den;
    float result;
    int ERR_COD;
    while(1)
    {
        printf("\nIngresa el Numerador:\n")
        scanf("%f",&num);
        printf("\nIngresa el Denominador:\n")
        scanf("%f",&den);

        ERR_COD = Div2(num,den,&result);//operador de direccion
        if(ERR_COD == ERR_OK)
        {
            printtf("\NDivi entre %f / %f = %f",num,de,result);
        }
        else
        {
            printf("\nError durante la Division");
        }

    }

    return 0;
}

float Div(float n,float d)
{
    return n/d;
}
//responsabilidad de dividir
int Div 2(float n,float d,float *r)
{
    float tmp;
    if(d != 0)
    {
        tmp = n/d;
        *r = tmp;//operador de indireccion
        return ERR_OK;
    }
    else
    {
        return ERR_DBZ;
    }
}
