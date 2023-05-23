#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct grafo
{
    int ordem;
    int *vertices;
    int **adjacencias;
    int eh_direcionado;
    int eh_valorado;
    int *visitados;
} Grafo;

Grafo *cria_grafo(int n, int valorado, int direcionado);
void preenche_vertices(Grafo *g);
void preenche_arestas(Grafo *g);
void mostra_grafo(Grafo *g);
int busca_largura(int origem, int destino, Grafo *g);
int busca_profundidade_recursao(int origem, int destino, Grafo *g);
int busca_profundidade(int origem, int destino, Grafo *g);
int menorDistancia(float *distancia, int *visitado, int ordem);
void Dijkstra(Grafo *g, int inicial, int *anterior, float *distancia, int ultimo);

#endif
