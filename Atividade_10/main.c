#include <stdlib.h>
#include <stdio.h>

struct grafo
{
    int ordem;
    int *vertices;
    int **adjacencias;
};

typedef struct grafo Grafo;

Grafo *cria_grafo(int n);

void DFS(Grafo *g, int origem, int destino, int visitados[], int visitadosFinal[]);

int main()
{
    int N = 0, Q = 0;
    int U = 0, V = 0;
    int A = 0, B = 0, C = 0, D = 0, cont = 0;

    scanf("%d", &N);
    scanf("%d", &Q);

    Grafo *g = cria_grafo(N);

    int *visitados1 = (int *)malloc(N * sizeof(int));
    int *visitados2 = (int *)malloc(N * sizeof(int));
    int *visitados11 = (int *)malloc(N * sizeof(int));
    int *visitados22 = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        visitados1[i] = 0;
        visitados2[i] = 0;
        visitados11[i] = 0;
        visitados22[i] = 0;
    }

    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d", &U);
        scanf("%d", &V);

        g->adjacencias[U - 1][V - 1] = 1;
        g->adjacencias[V - 1][U - 1] = 1;
    }

    for (int i = 0; i < Q; i++)
    {
        scanf("%d", &A);
        scanf("%d", &B);
        scanf("%d", &C);
        scanf("%d", &D);

        DFS(g, (A - 1), (B - 1), visitados1, visitados11);
        DFS(g, (C - 1), (D - 1), visitados2, visitados22);

        for (int i = 0; i < N; i++)
        {
            if (visitados11[i] == visitados22[i] && visitados11[i] != 0 && visitados22[i] != 0)
            {
                cont++;
            }
        }

        printf("%d\n", cont);

        cont = 0;

        for (int i = 0; i < N; i++)
        {
            visitados1[i] = 0;
            visitados2[i] = 0;
            visitados11[i] = 0;
            visitados22[i] = 0;
        }
    }

    free(visitados1);
    free(visitados2);
    free(visitados11);
    free(visitados22);
}

// GRAFO
Grafo *cria_grafo(int n)
{
    int i, j;
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->ordem = n;
    g->vertices = (int *)malloc(sizeof(int) * n);
    g->adjacencias = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
    {
        g->adjacencias[i] = (int *)malloc(sizeof(int) * n);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            g->adjacencias[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        g->vertices[i] = i + 1;
    }

    return g;
}

void DFS(Grafo *g, int origem, int destino, int visitados[], int visitadosFinal[])
{

    visitados[origem] = 1;

    if (origem == destino)
    {

        for (int i = 0; i < g->ordem; i++)
        {
            if (visitados[i] == 1)
            {
                visitadosFinal[i] = i + 1;
            }
        }
    }
    else
    {

        for (int i = 0; i < g->ordem; i++)
        {

            if (g->adjacencias[origem][i] > 0 && visitados[i] == 0)
            {

                DFS(g, i, destino, visitados, visitadosFinal);

                visitados[i] = 0;
            }
        }
    }
}