#include "grafo_matriz.h"

Grafo *cria_grafo(int n, int valorado, int direcionado)
{
    int i;
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));

    g->eh_direcionado = direcionado;
    g->eh_valorado = valorado;
    g->ordem = n;
    g->vertices = (int *)malloc(sizeof(int) * n);
    g->visitados = (int *)malloc(sizeof(int) * n);
    g->adjacencias = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        g->adjacencias[i] = (int *)malloc(sizeof(int) * n);
    return g;
}

void preenche_vertices(Grafo *g)
{
    int i;
    for (i = 0; i < g->ordem; i++)
    {
        g->vertices[i] = i + 1;
    }
}

void preenche_arestas(Grafo *g)
{
    int i, j;
    for (i = 0; i < g->ordem; i++)
        for (j = 0; j < g->ordem; j++)
        {
            scanf("%d", &g->adjacencias[i][j]);
        }
}

void mostra_grafo(Grafo *g)
{
    int i, j;
    for (i = 0; i < g->ordem; i++)
    {
        printf("%i -> ", g->vertices[i]);
        for (j = 0; j < g->ordem; j++)
        {
            if (g->adjacencias[i][j] != 0)
            {
                printf("%d - ", j + 1);
            }
        }
    }
}

void limpa(Grafo *g)
{
    int i;
    for (i = 0; i < g->ordem; i++)
    {
        g->visitados[i] = 0;
    }
}

void percurso_largura(Grafo *g)
{
    Fila *f = cria_fila();
    int *w;
    int i;

    limpa(g);
    g->visitados[0] = 1; // visitei o primeiro vertice
    w = (int *)malloc(sizeof(int));
    *w = 0;
    enqueue(f, (void *)w);

    while (!eh_vazia_fila(f))
    {
        w = (int *)dequeue(f);
        printf(" LARGURA %d \n", g->vertices[*w]);
        for (i = 0; i < g->ordem; i++)
        {
            if (g->adjacencias[*w][i] == 1)
            {
                if (!g->visitados[i])
                {
                    g->visitados[i] = 1; // visitei o primeiro vertice
                    w = (int *)malloc(sizeof(int));
                    *w = i;
                    enqueue(f, (void *)w);
                }
            }
        }
    }
}

void prof(int v, Grafo *g)
{
    int i;
    g->visitados[v] = 1;
    printf(" PROFUNDIDADE %d \n", v + 1);
    for (i = 0; i < g->ordem; i++)
    {
        if (g->adjacencias[v][i] && !g->visitados[i])
        {
            prof(i, g);
        }
    }
}

void profundidade(Grafo *g)
{
    int i;
    limpa(g);

    for (i = 0; i < g->ordem; i++)
    {

        if (!g->visitados[i])
        {
            prof(i, g);
        }
    }
}

// retorna 1 se existe caminho de origem para destino
int busca_largura(int origem, int destino, Grafo *g)
{
}

// retorna 1 se existe caminho de origem para destino
int busca_profundidade(int origem, int destino, Grafo *g)
{
}