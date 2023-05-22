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
void percurso_largura(Grafo *g);
void prof(int v, Grafo *g);
void profundidade(Grafo *g);

#endif
