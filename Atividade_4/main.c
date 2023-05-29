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

struct nod
{
    void *info;
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

typedef Listad Fila;

// LISTA
Listad *cria_listad();
Nod *cria_nod(void *valor);
Listad *insere_fim_listad(Listad *L, void *valor);
void *remove_inicio_listad(Listad *L);
int eh_vazia_listad(Listad *L);

// FILA
Fila *cria_fila();
Fila *enqueue(Fila *f, void *elemento);
void *dequeue(Fila *f);
int eh_vazia_fila(Fila *f);

// GRAFO
Grafo *cria_grafo(int n, int valorado, int direcionado);
void preenche_vertices(Grafo *g);
void preenche_arestas(Grafo *g);
void mostra_grafo(Grafo *g);
int busca_largura(int origem, int destino, Grafo *g);
int busca_profundidade_recursao(int origem, int destino, Grafo *g);
int busca_profundidade(int origem, int destino, Grafo *g);

int main()
{
    int E = 0, L = 0;
    int lin = 0, col = 0;
    int cont = 0;
    int parametro = 1;

    Grafo *g = NULL;

    do
    {
        scanf("%d", &E);
        scanf("%d", &L);

        cont++;

        if (E != 0 && L != 0)
        {
            g = cria_grafo(E, 0, 0);
            preenche_vertices(g);
            for (int i = 0; i < L; i++)
            {
                scanf("%d", &lin);
                scanf("%d", &col);

                g->adjacencias[lin - 1][col - 1] = 1;
                g->adjacencias[col - 1][lin - 1] = 1;
            }
            // mostra_grafo(g);

            parametro = busca_largura(0, E - 1, g);

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
        }
        g = NULL;
    } while (E != 0 && L != 0);
}

// LISTA
Listad *cria_listad()
{
    Listad *novalista;
    novalista = (Listad *)malloc(sizeof(Listad));
    novalista->ini = novalista->fim = NULL;
    return novalista;
}

Nod *cria_nod(void *valor)
{
    Nod *novo = (Nod *)malloc(sizeof(Nod));
    novo->ant = novo->prox = NULL;
    novo->info = valor;
    return novo;
}

Listad *insere_fim_listad(Listad *L, void *valor)
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
void *remove_inicio_listad(Listad *L)
{
    Nod *aux;
    void *resposta = NULL; // quando nao tem nada pra remover
    if (L != NULL)
        if (L->ini != NULL)
        {
            aux = L->ini;

            if (L->ini != L->fim)
            {
                L->ini->prox->ant = NULL;
                L->ini = L->ini->prox;
            }
            else
                L->ini = L->fim = NULL;

            resposta = aux->info;
            free(aux);
        }
    return resposta;
}

int eh_vazia_listad(Listad *L)
{
    if (L == NULL || L->ini == NULL)
        return 1;
    else
        return 0;
}

// FILA
Fila *cria_fila()
{
    return cria_listad();
}

Fila *enqueue(Fila *f, void *elemento)
{
    return insere_fim_listad(f, elemento);
}

void *dequeue(Fila *f)
{
    return remove_inicio_listad(f);
}

int eh_vazia_fila(Fila *f)
{
    return eh_vazia_listad(f);
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
