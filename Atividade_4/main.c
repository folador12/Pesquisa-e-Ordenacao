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
void bfs(Grafo *g, int inicio, int cont);

int main()
{
    int E = 0, L = 0;
    int lin = 0, col = 0;
    int cont = 1;
    int parametro = 1;

    do
    {
        scanf("%d", &E);
        scanf("%d", &L);

        if (E != 0 && L != 0)
        {
            Grafo *g = cria_grafo(E, 0, 0);
            preenche_vertices(g);
            for (int i = 0; i < L; i++)
            {
                scanf("%d", &lin);
                scanf("%d", &col);

                g->adjacencias[lin - 1][col - 1] = 1;
                g->adjacencias[col - 1][lin - 1] = 1;
            }
            bfs(g, 0, cont);

            free(g);
            cont++;
        }

    } while (E != 0 && L != 0);
}

// GRAFO
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

void limpa(Grafo *g)
{
    int i;
    for (i = 0; i < g->ordem; i++)
        g->visitados[i] = 0;
}

void bfs(Grafo *g, int inicio, int cont)
{
    int i, j, parametro = 1;
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
    for (int i = 0; i < g->ordem; i++)
    {
        if (!g->visitados[i])
        {
            parametro = 0;
        }
    }

    if (parametro == 1)
    {
        printf("Teste %d\n", cont);
        printf("normal\n");
        printf("\n");
    }
    else
    {
        printf("Teste %d\n", cont);
        printf("falha\n");
        printf("\n");
    }
    limpa(g);
}
