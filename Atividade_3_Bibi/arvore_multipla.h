#ifndef ARVORE_MULTIPLA_H
#define ARVORE_MULTIPLA_H
#include "listadupla.h"

struct nom
{
    int info;
    int nro_filhos;
    int infectada;
    int nro_filhos_infec;
    struct nom *pai;
    Listad *filhos;
};

typedef struct nom Nom;
void insere(Nom *tree, int info, int pai);
Nom *localiza_pai(Nom *raiz, int pai);
Nom *cria_nom(int info);
void mostra(Nom *raiz);
void libera_arvorem(Nom *raiz);
void mais_filhos(Nom *raiz, Nom **maior);
void infecta(Nom *raiz, int nro_nos);
void espalha_irmao(Nom *raiz, int *nro_infectados);

#endif