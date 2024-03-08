#include <stdio.h>

#define N 3 // Tamaño de la matriz

int main()
{
    int matriz[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int suma_diagonal = 0;

    // Calcula la suma de los elementos en la diagonal
    for (int i = 0; i < N; i++)
        {
        suma_diagonal += matriz[i][i];
        }

    printf("La suma de los elementos en la diagonal es: %d\n", suma_diagonal);

    return 0;
}
