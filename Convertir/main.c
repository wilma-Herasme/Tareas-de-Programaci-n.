#include <stdio.h>

int main()
{
    char letra;
    printf("Introduce una letra: ");
    scanf("%c", &letra);

    // Si la letra es 'z' mayúscula, conviértela a minúscula
    if (letra == 'Z')
        {
        letra = 'z';
        }
    // Si la letra es 'z' minúscula, conviértela a mayúscula
    else if (letra == 'z')
        {
        letra = 'Z';
        }

    printf("La letra convertida es: %c\n", letra);

    return 0;
}
