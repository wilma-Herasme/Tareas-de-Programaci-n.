#include <stdio.h>

int main()
{
    char letra;
    printf("Introduce una letra: ");
    scanf("%c", &letra);

    // Si la letra es 'z' may�scula, convi�rtela a min�scula
    if (letra == 'Z')
        {
        letra = 'z';
        }
    // Si la letra es 'z' min�scula, convi�rtela a may�scula
    else if (letra == 'z')
        {
        letra = 'Z';
        }

    printf("La letra convertida es: %c\n", letra);

    return 0;
}
