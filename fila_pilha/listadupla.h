#ifndef LISTADUPLA_H_INCLUDED
#define LISTADUPLA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct nod
{
    int info;
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

Listad* cria_listad();
Nod* cria_nod(int valor);
Listad* insere_inicio_listad(Listad *L, int valor);
void mostra_listad(Listad* L);
Listad* insere_fim_listad(Listad *L, int valor);
Nod* localiza_elemento(Listad *L, int valor);
void insere_apos_elemento(Listad* L, int valor, int elemento);
int remove_elemento_listad(Listad *L, int valor);
int remove_fim_listas(Listad *L);
int remove_inicio_listad(Listad *L);

Listad* libera_listad(Listad *L);

#endif // LISTADUPLA_H_INCLUDED
