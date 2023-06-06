#include "grafos_lista.h"

Grafo* cria_grafo(int direcionado)
{
    Grafo *g = (Grafo*)malloc (sizeof(Grafo));
    g->direcionado = 0;
    g->vertices = cria_listad();

    return g;
}


Vertice* cria_vertice(char nome[TAM])
{
    Vertice *v = (Vertice*)malloc(sizeof(Vertice));
    v->adjacentes = cria_listad();
    strcpy(v->nome, nome);
    return v;
}

void add_vertice(Grafo *g, char nome[TAM])
{
    Vertice *v= cria_vertice(nome);
    insere_inicio_listad(g->vertices,(void*)v );
    g->qtde_vertices++;
}


Aresta* cria_aresta(int peso, Vertice *dest)
{
    Aresta *a = (Aresta*)malloc(sizeof(Aresta));
    a->peso = peso;
    a->destino = dest;
    return a;
}

char* get_nome(Nod* aux)
{
    return ((Vertice*)aux->info)->nome;
}

Vertice* localiza_vertice (Grafo *g, char nome[TAM])
{
    Nod *aux = g->vertices->ini;

    while (aux != NULL && strcmp(get_nome(aux), nome) != 0)
        aux=aux->prox;


    return (Vertice*) aux->info;
}

void add_aresta(Grafo *g, char ori[TAM], char dest[TAM], int peso)
{
    Vertice *o, *d;
    o = localiza_vertice(g, ori);
    d = localiza_vertice(g, dest);
    Aresta *a = cria_aresta(peso,d);
    insere_inicio_listad(o->adjacentes,(void*)a);

    if (g->direcionado == 0)
    {
        a = cria_aresta(peso,o);
        insere_inicio_listad(d->adjacentes, (void*)a);
    }

}


void mostra_grafo(Grafo *g)
{
    Nod* aux = g->vertices->ini;
    Nod* auxAdj;
    Aresta *a;
    while(aux != NULL)
    {
        printf("%s :", get_nome(aux));
        auxAdj = ((Vertice*)aux->info)->adjacentes->ini;

        while (auxAdj != NULL)
        {
            a =((Aresta*)auxAdj->info);
            printf ("[%s,%d]", a->destino->nome, a->peso);
            auxAdj = auxAdj->prox;
        }
        aux = aux->prox;

    }



}
