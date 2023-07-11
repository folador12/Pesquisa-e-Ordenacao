#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int vertice;
    struct no *proximo;
} No;

typedef struct grafo
{
    int ordem;
    No **adjacencias;
} Grafo;

Grafo *cria_grafo(int n)
{
    int i;
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->ordem = n;
    g->adjacencias = (No **)malloc(sizeof(No *) * n);
    for (i = 0; i < n; i++)
    {
        g->adjacencias[i] = NULL;
    }

    return g;
}

void adiciona_aresta(Grafo *g, int origem, int destino)
{
    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->vertice = destino;
    novo_no->proximo = g->adjacencias[origem];
    g->adjacencias[origem] = novo_no;

    novo_no = (No *)malloc(sizeof(No));
    novo_no->vertice = origem;
    novo_no->proximo = g->adjacencias[destino];
    g->adjacencias[destino] = novo_no;
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

        for (No *v = g->adjacencias[origem]; v != NULL; v = v->proximo)
        {
            int vizinho = v->vertice;

            if (visitados[vizinho] == 0)
            {
                DFS(g, vizinho, destino, visitados, visitadosFinal);
            }
        }
    }

    visitados[origem] = 0;
}

int contar_estacoes_comuns(int visitados1[], int visitados2[], int N)
{
    int count = 0;

    for (int i = 0; i < N; i++)
    {

        if (visitados1[i] == visitados2[i] && visitados1[i] != 0 && visitados2[i] != 0)
        {

            count++;
        }
    }

    return count;
}

int main()
{
    int N = 0, Q = 0;
    int U = 0, V = 0;
    int A = 0, B = 0, C = 0, D = 0;

    scanf("%d %d", &N, &Q);

    Grafo *g = cria_grafo(N);

    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &U, &V);
        adiciona_aresta(g, U - 1, V - 1);
    }

    // cria vetores de visitados
    int *visitados1 = (int *)malloc(N * sizeof(int));
    int *visitados2 = (int *)malloc(N * sizeof(int));
    int *visitados11 = (int *)malloc(N * sizeof(int));
    int *visitados22 = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        visitados1[i] = 0;
        visitados11[i] = 0;
        visitados2[i] = 0;
        visitados22[i] = 0;
    }

    // recebe as consultas
    for (int i = 0; i < Q; i++)
    {
        // recebe as estações
        scanf("%d %d %d %d", &A, &B, &C, &D);

        DFS(g, A - 1, B - 1, visitados1, visitados11);
        DFS(g, C - 1, D - 1, visitados2, visitados22);

        int count = contar_estacoes_comuns(visitados11, visitados22, N);
        printf("%d\n", count);

        for (int i = 0; i < N; i++)
        {
            visitados1[i] = 0;
            visitados11[i] = 0;
            visitados2[i] = 0;
            visitados22[i] = 0;
        }
    }

    return 0;
}