#ifndef GRAFOS_LISTA_H_INCLUDED
#define GRAFOS_LISTA_H_INCLUDED
#include <string.h>

#include "listadupla.h"
#define TAM 10

struct grafo
{
    int qtde_vertices;
    int direcionado; // 1 para direcionado 0 para bidirecional
    Listad *vertices;
};

typedef struct grafo Grafo;

struct vertice
{
    char nome[TAM];
    Listad *adjacentes;
};

typedef struct vertice Vertice;

struct aresta
{
    int peso;
    Vertice *destino;
};

typedef struct aresta Aresta;

Grafo *cria_grafo(int direcionado);
void add_vertice(Grafo *g, char nome[TAM]);
void add_aresta(Grafo *g, char ori[TAM], char dest[TAM], int peso);
void mostra_grafo(Grafo *g);

#endif // GRAFOS_LISTA_H_INCLUDED
