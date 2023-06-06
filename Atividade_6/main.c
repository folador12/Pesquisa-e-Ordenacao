#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct nod
{
    char nome[20];
    struct nod *ant;
    struct nod *prox;
};
typedef struct nod Nod;

struct listad
{
    Nod *ini;
    Nod *fim;
};
typedef struct listad Listad;

typedef struct grafo
{
    int ordem;
    int **adjacencias;
    Listad *nomes;
} Grafo;

// LISTA
Listad *cria_listad();
Nod *cria_nod(char valor[]);
Listad *insere_fim_listad(Listad *L, char valor[]);

//  GRAFO
Grafo *cria_grafo(int n);
void mostra_grafo(Grafo *g);

int main(int argc, char const *argv[])
{
    int N = 0, C = 0, Cont = 0;
    int i = 0;
    char nome[20];
    Grafo *g = NULL;

    do
    {
        scanf("%d", &N);
        g = cria_grafo(N);

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

        for (i = 0; i < N; i++)
        {
            scanf("%s", nome);
            g->nomes = insere_fim_listad(g->nomes, nome);
        }

        mostra_grafo(g);

        free(g);

    } while (N != 0);

    return 0;
}

Listad *cria_listad()
{
    Listad *novalista;
    novalista = (Listad *)malloc(sizeof(Listad));
    novalista->ini = novalista->fim = NULL;
    return novalista;
}

Nod *cria_nod(char valor[])
{
    Nod *novo = (Nod *)malloc(sizeof(Nod));
    novo->ant = novo->prox = NULL;
    strcpy(novo->nome, valor);
    return novo;
}

Listad *insere_fim_listad(Listad *L, char valor[])
{
    Nod *novo = cria_nod(valor);

    if (L == NULL)
    {
        L = cria_listad();
        L->ini = L->fim = novo;
    }
    else
    {

        if (L->ini == NULL)
        {
            L->ini = L->fim = novo;
        }
        else
        {
            novo->ant = L->fim;
            L->fim->prox = novo;
            L->fim = novo;
        }
    }
    return L;
}

Grafo *cria_grafo(int n)
{
    int i;
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->ordem = n;
    g->nomes = cria_listad();
    g->adjacencias = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
        g->adjacencias[i] = (int *)malloc(sizeof(int) * n);
    return g;
}

void mostra_grafo(Grafo *g)
{
    int i, j;
    Nod *aux = g->nomes->ini;
    for (i = 0; i < g->ordem; i++)
    {

        if (aux != NULL)
        {
            printf("%s ", aux->nome);
            aux = aux->prox;
        }

        for (j = 0; j < g->ordem; j++)
        {
            if (g->adjacencias[i][j] == 1)
            {
                printf("%d - ", j + 1);
            }
        }
        printf("\n");
    }
}
