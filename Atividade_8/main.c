#include <stdlib.h>
#include <stdio.h>

void bubble_sort(int intercambio[], int N, int M);

int main()
{

    int N = 0, M = 0, i = 0;
    int *X;

    do
    {
        scanf("%d %d", &N, &M);

        if (N != 0)
        {
            X = (int *)malloc(M * sizeof(int));

            for (i = M - 1; i >= 0; i--)
            {

                scanf("%d", &X[i]);
            }

            bubble_sort(X, N, M);
            printf("\n");
            free(X);
        }

    } while (N != 0);

    return 0;
}

void bubble_sort(int vetor[], int N, int M)
{

    int cont = M, aux = 0, flag = 0, k = 0;
    int indice[N];

    for (int i = 0; i < N; i++)
    {
        indice[i] = i + 1;
    }

    for (int i = 0; i < M; i++)
    {

        for (int j = N - 1; j >= 0; j--)
        {

            if (indice[j] == cont)
            {

                k = j;

                while (flag < vetor[i])
                {

                    aux = indice[k];
                    indice[k] = indice[k + 1];
                    indice[k + 1] = aux;

                    flag++;
                    k++;
                }
            }
        }

        cont--;
        flag = 0;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%i ", indice[i]);
    }
}