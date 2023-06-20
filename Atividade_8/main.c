#include <stdlib.h>
#include <stdio.h>

void merge(int vet[], int l, int m, int r, int *c);
void mergeSort(int vet[], int l, int r, int *c);

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

            mergeSort(X, 0, N - 1, &C);

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
            C = 0;
        }

    } while (N != 0);

    return 0;
}

void merge(int vet[], int l, int m, int r, int *c)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = vet[l + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = vet[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vet[k] = L[i];
            i++;
        }
        else
        {
            vet[k] = R[j];
            (*c) += n1 - i;
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vet[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vet[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int vet[], int l, int r, int *c)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(vet, l, m, c);

        mergeSort(vet, m + 1, r, c);
        
        merge(vet, l, m, r, c);
    }
}
