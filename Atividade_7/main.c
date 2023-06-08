#include <stdlib.h>
#include <stdio.h>

typedef struct grafo
{
    int ordem;
    int *vertices;
    int **adjacencias;
    int *visitados;
    int *imposto;
    int carga_maxima;
} Grafo;

// GRAFO
Grafo *cria_grafo(int n, int c);
void preenche_vertices(Grafo *g);
void limpa(Grafo *g);
void Busca_Largura(Grafo *g, int inicio);

int main()
{
    int N = 0, CA = 0;
    int A = 0, B = 0, C = 0;

    scanf("%d", &N);
    scanf("%d", &CA);

    Grafo *g  = cria_grafo(N,CA);
    preenche_vertices(g);
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&g->imposto[i]);
    }
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A);
        scanf("%d", &B);
        scanf("%d", &C);

        g->adjacencias[A - 1][B - 1] = C;
        g->adjacencias[B - 1][A - 1] = C;
    }
    

    limpa(g);
    free(g);
    
}

// GRAFO
Grafo *cria_grafo(int n, int c)
{
    int i;
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->ordem = n;
    g->carga_maxima = c;
    g->vertices = (int *)malloc(sizeof(int) * n);
    g->visitados = (int *)malloc(sizeof(int) * n);
    g->imposto = (int *)malloc(sizeof(int) * n);
    g->adjacencias = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
        g->adjacencias[i] = (int *)malloc(sizeof(int) * n);
    return g;
}

void preenche_vertices(Grafo *g)
{
    int i;
    for (i = 0; i < g->ordem; i++)
        g->vertices[i] = i + 1;
}

void limpa(Grafo *g)
{
    int i;
    for (i = 0; i < g->ordem; i++)
        g->visitados[i] = 0;
}

void Busca_Largura(Grafo *g, int inicio)
{
    int i, j;
    for (i = 0; i < g->ordem; i++)
    {
        g->visitados[i] = 0;
    }
    g->visitados[inicio] = 1;
    for (i = 0; i < g->ordem; i++)
    {
        if (g->adjacencias[inicio][i] == 1 && !g->visitados[i])
        {
            g->visitados[i] = 1;
            for (j = 0; j < g->ordem; j++)
            {
                if (g->adjacencias[i][j] == 1 && !g->visitados[j])
                {
                    g->visitados[j] = 1;
                }
            }
        }
    }
}
