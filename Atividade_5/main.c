#include <stdlib.h>
#include <stdio.h>

typedef struct grafo
{
    int ordem;
    int *vertices;
    int **adjacencias;
    int eh_direcionado;
    int eh_valorado;
    int *visitados;
} Grafo;

// GRAFO
Grafo *cria_grafo(int n, int valorado, int direcionado);
void preenche_vertices(Grafo *g);
void limpa(Grafo *g);
void Busca_Largura(Grafo *g, int inicio);

int main(int argc, char const *argv[])
{
    int C = 0, E = 0, L = 0, P = 0;
    int X = 0, Y = 0;
    int cont = 1;
    Grafo *g = NULL;

    do
    {
        scanf("%d", &C);
        scanf("%d", &E);
        scanf("%d", &L);
        scanf("%d", &P);

        if (E != 0 && L != 0 && C != 0 && P != 0)
        {
            g = cria_grafo(C, 0, 0);
            preenche_vertices(g);
            for (int i = 0; i < E; i++)
            {
                scanf("%d", &X);
                scanf("%d", &Y);

                g->adjacencias[X - 1][Y - 1] = 1;
                g->adjacencias[Y - 1][X - 1] = 1;
            }
        }

        cont++;

    } while (E != 0 && L != 0 && C != 0 && P != 0);
    return 0;
}

Grafo *cria_grafo(int n, int valorado, int direcionado)
{
    int i;
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));

    g->eh_direcionado = direcionado;
    g->eh_valorado = valorado;
    g->ordem = n;
    g->vertices = (int *)malloc(sizeof(int) * n);
    g->visitados = (int *)malloc(sizeof(int) * n);
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

void Busca_Largura(Grafo *g, int inicio)
{
    int i, j, cont = 0;
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
                    cont++;
                }
            }
        }
    }

    limpa(g);
}