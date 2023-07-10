#include <stdlib.h>
#include <stdio.h>

typedef struct grafo
{
    int ordem;
    int *vertices;
    int **adjacencias;
    int *imposto;
    int carga_maxima;
} Grafo;

Grafo *cria_grafo(int n, int c);
int dfs(int v, int p, int f, Grafo *g);

int main()
{
    int N = 0, CM = 0;
    int A = 0, B = 0, C = 0;
    int V = -1;

    scanf("%d", &N);
    scanf("%d", &CM);

    Grafo *g = cria_grafo(N, CM);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &g->imposto[i]);
    }

    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d", &A);
        scanf("%d", &B);
        scanf("%d", &C);

        g->adjacencias[A - 1][B - 1] = C;
        g->adjacencias[B - 1][A - 1] = C;
    }
    V = dfs(0, -1, -1, g);

    printf("%d\n", V * 2);
}

// GRAFO
Grafo *cria_grafo(int n, int c)
{
    int i, j;
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->ordem = n;
    g->carga_maxima = c;
    g->vertices = (int *)malloc(sizeof(int) * n);
    g->imposto = (int *)malloc(sizeof(int) * n);
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

int dfs(int v, int p, int f, Grafo *g)
{
    int custo = 0;
    for (int i = 0; i < g->ordem; i++)
    {
        if (g->adjacencias[v][i] != 0)
        {
            int u = i;
            int peso = g->adjacencias[v][i];

            if (u == p)
            {
                continue;
            }
            custo += dfs(u, v, peso, g);
        }
    }

    if (v == 0)
    {
        return custo;
    }

    custo += f * (g->imposto[v] / g->carga_maxima);
    if (g->imposto[v] % g->carga_maxima != 0)
    {
        custo += f;
    }
    g->imposto[p] += g->imposto[v];
    return custo;
}