#include "listasimples.h"
#include "listasimples.h"



No* cria_no(int valor)
{
    No* novo;
    novo = (No*) malloc(sizeof(No));

//inicializar campos
    novo->prox = NULL;
    novo->info = valor;

    return novo;
}


No* insere_inicio(No *L, int valor)
{
    No* nuevo = cria_no(valor);
    if (L != NULL)
    {
        nuevo->prox = L;
    }
    return nuevo;
}


void mostra_lista(No* L)
{
    No* aux = L;

    while (aux != NULL)
    {
        printf("%i ", aux->info);
        aux = aux->prox;// (*aux).prox
    }
    printf("\n");
}



No* libera_lista(No *L)
{
    No *aux = L;

    while (aux != NULL)
    {
        L = L->prox;
        free(aux);
        aux = L;
    }
    return NULL;
}

No* insere_fim(No* L, int valor)
{
    No* novo = cria_no(valor);
    No* aux = L;

    if (L == NULL)
    {
        L = novo;
    }
    else
    {
        //  for (aux = L; aux->prox != NULL; aux = aux->prox)

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return L;
}

//insere após o elemento

No* insere_meio(No* L, int elemento, int valor)
{

    No* aux = L;
    No* novo = cria_no(valor);

    if (L == NULL)
    {
        L = novo;
    }
    else
    {
        while (aux->info != elemento)
        {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    return L;
}

No* remove_elemento(No* L, int elemento)
{

    No* aux = L;
    No* anterior = NULL;
    if (L != NULL)
    {
        while (aux->info != elemento)
        {
            anterior = aux;
            aux = aux->prox;
        }
        if (anterior == NULL)//remove o primeiro elemento
        {
            L = aux->prox;
        }
        else
        {
            anterior->prox = aux->prox;
        }
        free(aux);
    }
    return L;//se nao removeu o primeiro elemento, retorna o mesmmo L
}

int remove_inicio(No** L)
{
    No* aux = *L;
    int pont;

    if (*L != NULL)
    {
        *L = aux->prox;
    }
    pont = aux->info;
    free(aux);
    return pont;
}
