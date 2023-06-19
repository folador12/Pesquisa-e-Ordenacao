#include <stdlib.h>
#include <stdio.h>

int bubble_sort(int vetor[], int n);

int main()
{

    int N = 0, C = 0, i = 0;
    int *X;

    do
    {
        scanf("%d", &N);

        if (N != 0)
        {
            X = (int *)malloc(N * sizeof(int));

            for (i = 0; i < N; i++)
            {

                scanf("%d", &X[i]);
            }

            C = bubble_sort(X, N);

            if (C % 2 == 0)
            {
                printf("Carlos");
            }
            else
            {
                printf("Marcelo");
            }

            printf("\n");
            free(X);
        }

    } while (N != 0);

    return 0;
}

int bubble_sort(int vetor[], int n)
{
    int k, j, aux, cont = 0;

    for (k = 1; k < n; k++)
    {

        for (j = 0; j < n - 1; j++)
        {

            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                cont++;
            }
        }
    }
    return cont;
}