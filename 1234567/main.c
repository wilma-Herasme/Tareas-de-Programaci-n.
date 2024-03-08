#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;// 8 bit solo puede tener 256 0 a 255
    char n[50] = "Carlos Pichardo"
    int cnt = 0;
    n[49] = 'e';


    printf("\n %s \n",n);

    for(int i = 0;i<50;i++)
    {
        printf("\nn[%d]= %c",i,n[i]);

        if(n[i] == 'a' || n[i] == 'A')
        {
            cnt++;
        }
    }
    printf("\n Cantidad de a = %d",cnt);

    return 0;
}
