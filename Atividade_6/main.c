#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct grafo
{
    int ordem;
    int **adjacencias;
    int *visitados;
    char ***atributos;
    int *tamanho_atributos;
    int *grau;
} Grafo;

//  GRAFO
Grafo *cria_grafo(int n);
void dfs(Grafo *grafo, int x, int t1, int t2, char *a1, char *a2, char *a3);

int main(int argc, char const *argv[])
{
    int N = 0, C = 0, T1 = 0, T2 = 0, T3 = 0, Count = 0, T = 0;
    int i = 0, j = 0;
    char nome[21];
    char Atr1[21], Atr2[21], Atr3[21];
    Grafo *g = NULL;

    do
    {
        scanf("%d", &N);
        g = cria_grafo(N + 1);

        for (i = 0; i < N; i++)
        {
            do
            {
                scanf("%d", &C);
                if (C != 0)
                {
                    g->adjacencias[i][C - 1] = 1; // montando matriz de adjacências
                }

            } while (C != 0);
        }

        do
        {
            scanf("%d", &T1);

            if (T1 != 0)
            {
                scanf("%d %d", &T2, &T3);
                scanf("%s %s %s", Atr1, Atr2, Atr3);

                for (int i = 1; i <= N; i++)
                {
                    g->visitados[i] = 0;
                    strcpy(g->atributos[i][g->tamanho_atributos[i]++], Atr1);
                }

                dfs(g, T1, T2, T3, Atr1, Atr2, Atr3);
            }

        } while (T1 != 0);

        for (i = 0; i < N; i++)
        {

            scanf("%s", nome);
            printf("%s: ", nome);

            for (j = 0; j < g->tamanho_atributos[i]; j++)
            {
                printf("%s ", g->atributos[i][j]);
            }

            printf("\n");
        }

        free(g);

    } while (N != 0);

    return 0;
}

Grafo *cria_grafo(int n)
{
    int i, j;
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->ordem = n;
    g->grau = (int *)calloc(n, sizeof(int));
    g->atributos = NULL;
    g->tamanho_atributos = (int *)calloc(n, sizeof(int));
    g->atributos = (char ***)malloc(n * sizeof(char **));
    g->adjacencias = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
        g->adjacencias[i] = (int *)malloc(sizeof(int) * n);

    return g;
}

void dfs(Grafo *grafo, int x, int t1, int t2, char *a1, char *a2, char *a3)
{
    grafo->visitados[x] = 1;
    grafo->tamanho_atributos[x]--;

    if (grafo->grau[x] < t1)
        strcpy(grafo->atributos[x][grafo->tamanho_atributos[x]++], a1);
    else if (grafo->grau[x] < t2)
        strcpy(grafo->atributos[x][grafo->tamanho_atributos[x]++], a2);
    else
        strcpy(grafo->atributos[x][grafo->tamanho_atributos[x]++], a3);

    for (int i = 0; i < grafo->ordem; i++)
    {
        for (int j = 0; j < grafo->ordem; j++)
        {
            if (grafo->visitados[i] == 0)
            {
                dfs(grafo, i, t1, t2, a1, a2, a3);
            }
        }
    }
}
