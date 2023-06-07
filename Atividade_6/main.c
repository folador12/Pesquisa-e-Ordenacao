#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct nod
{
    char nome[21];
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

typedef struct atr
{
    char atr[21];
    int Peso;
    int valor;
    struct atr *prox;
} Atr;

typedef struct grafo
{
    int ordem;
    int **adjacencias;
    int *visitados;
    Listad *nomes;
    Atr *atributos;
} Grafo;

// LISTA
Listad *cria_listad();
Nod *cria_nod(char valor[]);
Listad *insere_fim_listad(Listad *L, char valor[]);

//  GRAFO
Grafo *cria_grafo(int n);
void mostra_grafo(Grafo *g);
void dfs(Grafo *grafo, int p);
Atr *cria_atr(char atr[], int peso, int valor);
Atr *insere_fim(Atr *L, char atr[], int peso, int valor);
void mostra_lista(Atr *L);

int main(int argc, char const *argv[])
{
    int N = 0, C = 0, T1 = 0, T2 = 0, T3 = 0, Count = 0;
    int i = 0, j = 0;
    char nome[21];
    char Atr1[21], Atr2[21], Atr3[21];
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

        do
        {
            scanf("%d", &T1);

            if (T1 != 0)
            {
                scanf("%d %d", &T2, &T3);
                scanf("%s %s %s", Atr1, Atr2, Atr3);

                g->atributos = insere_fim(g->atributos, Atr1, T1, Count);
                g->atributos = insere_fim(g->atributos, Atr2, T2, Count);
                g->atributos = insere_fim(g->atributos, Atr3, T3, Count);

                Count++;
            }

        } while (T1 != 0);

        for (i = 0; i < N; i++)
        {
            scanf("%s", nome);
            g->nomes = insere_fim_listad(g->nomes, nome);
        }

        // mostra_grafo(g);
        mostra_lista(g->atributos);
        // printf("\n\n");

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
    int i, j;
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->ordem = n;
    g->visitados = (int *)calloc(n, sizeof(int));
    g->nomes = cria_listad();
    g->atributos = NULL;
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

void dfs(Grafo *grafo, int p)
{
    if (grafo->visitados[p])
        return;
    grafo->visitados[p] = 1;
    for (int i = 0; i < grafo->ordem; i++)
    {
        if (grafo->adjacencias[p][i])
        {
            dfs(grafo, i);
        }
    }
}

Atr *cria_atr(char atr[], int peso, int valor)
{
    Atr *novo;
    novo = (Atr *)malloc(sizeof(Atr));
    novo->prox = NULL;
    novo->valor = valor;
    novo->Peso = peso;
    strcpy(novo->atr, atr);
    return novo;
}

Atr *insere_fim(Atr *L, char atr[], int peso, int valor)
{
    Atr *novo = cria_atr(atr, peso, valor);
    Atr *aux = L;

    if (L == NULL)
    {
        L = novo;
    }
    else
    {

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return L;
}
void mostra_lista(Atr *L)
{
    Atr *aux = L;

    while (aux != NULL)
    {
        printf("%s %i %i ", aux->atr, aux->Peso, aux->valor);
        printf("\n");
        aux = aux->prox;
    }
    printf("\n");
}