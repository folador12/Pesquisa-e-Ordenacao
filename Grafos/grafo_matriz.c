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
    {
        for (j = 0; j < g->ordem; j++)
        {
            scanf("%d", &g->adjacencias[i][j]);
        }
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
        printf("\n");
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

// retorna 1 se existe caminho de origem para destino
int busca_largura(int origem, int destino, Grafo *g)
{
    Fila *f = cria_fila();
    int *w;
    int i;

    limpa(g);
    g->visitados[origem] = 1;
    w = (int *)malloc(sizeof(int));
    *w = origem;
    enqueue(f, (void *)w);

    while (!eh_vazia_fila(f))
    {
        w = (int *)dequeue(f);
        if (*w == destino)
        {
            printf("\nentrouuu\n");
            return 1;
        }
        for (i = 0; i < g->ordem; i++)
        {
            if (g->adjacencias[*w][i] == 1)
            {
                if (!g->visitados[i])
                {
                    g->visitados[i] = 1;
                    w = (int *)malloc(sizeof(int));
                    *w = i;
                    enqueue(f, (void *)w);
                }
            }
        }
    }

    return 0;
}

int busca_profundidade_recursao(int origem, int destino, Grafo *g)
{
    if (origem == destino)
    {
        return 1;
    }

    g->visitados[origem] = 1;

    for (int i = 0; i < g->ordem; i++)
    {
        if (g->adjacencias[origem][i] >= 1 && !g->visitados[i])
        {
            printf(" PROFUNDIDADE %d \n", origem + 1);
            if (busca_profundidade_recursao(i, destino, g))
            {
                return 1;
            }
        }
    }

    return 0;
}

// retorna 1 se houver um caminho e 0 se nao houver
int busca_profundidade(int origem, int destino, Grafo *g)
{
    limpa(g);
    return busca_profundidade_recursao(origem, destino, g);
}

int menorDistancia(float *distancia, int *visitado, int ordem)
{
    int i, menor = INT_MAX, primeiro = 1;
    for (i = 0; i < ordem; i++)
    {
        if (distancia[i] < menor && visitado[i] == 0)
        {
            menor = i;
            primeiro = 0;
        }
        else
        {
            if (distancia[menor] > distancia[i])
            {
                menor = i;
            }
        }
        return menor;
    }
}

void Dijkstra(Grafo *g, int inicial, int *anterior, float *distancia, int ultimo)
{
    int i, count = 0, NaoVisitado = 0, soma = 0, vertice_pc = 0;
    count = g->ordem;
    NaoVisitado = g->ordem;

    for (i = 0; i < NaoVisitado; i++)
    {
        anterior[i] = -1;
        distancia[i] = INT_MAX;
        g->visitados[i] = 0;
    }

    distancia[inicial] = 0;

    while (count > 0)
    {
        vertice_pc = menorDistancia(distancia, g->visitados, NaoVisitado);

        g->visitados[vertice_pc] = 1;

        count--;

        int vizinho;

        for (vizinho = 0; vizinho < g->ordem; vizinho++)
        {
            if (g->adjacencias[vertice_pc][vizinho] > 0)
            {
                soma = g->adjacencias[vertice_pc][vizinho] + distancia[vertice_pc];
                if (soma < distancia[vizinho])
                {
                    anterior[vizinho] = vertice_pc;
                    distancia[vizinho] = soma;
                }
                soma = 0;
            }
        }
    }

    int aux = ultimo;

    printf("\nCaminho -");
    while (aux != inicial)
    {
        printf("%d / ", aux);
        aux = anterior[aux];
    }
    printf("%d", inicial);
}