#include "grafo_matriz.h"

int main()
{
    Grafo *g = cria_grafo(5, 0, 0);

    preenche_vertices(g);
    int i, j;

    for (i = 0; i < g->ordem; i++)
    {
        for (j = 0; j < g->ordem; j++)
        {
            scanf("%d", &g->adjacencias[i][j]);
        }
    }

    mostra_grafo(g);

    int busca = 7;

    busca = busca_largura(1, 3, g);
    printf(" %d \n", busca);

    busca = busca_profundidade(1, 3, g);
    printf(" %d \n", busca);
}