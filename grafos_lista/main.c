#include <stdio.h>
#include <stdlib.h>
#include "grafos_lista.h"

int main()
{

    Grafo *g = cria_grafo(0);
    char vertices[10][10] ={{"A"},{"B"},{"C"},{"D"},{"E"},{"F"},{"G"},{"H"}};//grafo do slide 33


    int i;
    for (i=0; i<8; i++)
    {
        add_vertice(g,vertices[i]);
    }

    add_aresta(g,"A", "B",2);
    add_aresta(g,"A", "E",3);
    add_aresta(g,"A", "C",1);
    add_aresta(g,"B", "F",2);
    add_aresta(g,"B", "E",2);
    add_aresta(g,"E", "D",3);
    add_aresta(g,"C", "D",2);
    add_aresta(g,"C", "G",4);
    add_aresta(g,"F", "D",1);
    add_aresta(g,"D", "H",2);
    add_aresta(g,"G", "D",2);
    add_aresta(g,"G", "H",3);
    add_aresta(g,"F", "H",3);

    mostra_grafo(g);

    // fazer trabalho 25 pontos
    // somente com essas estruturas
    //individual
    //para email danielaorbolato@iftm.edu.br
    //busca em largura
    //busca em profundidade
    //dijkstra
    //data de entrega: 1/7


    return 0;
}
