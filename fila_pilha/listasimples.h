#ifndef LISTASIMPLES_H_INCLUDED
#define LISTASIMPLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


struct no
{
    int info;
    struct no *prox;
};

typedef struct no No;


No* cria_no(int);

No* insere_inicio(No*, int);

void mostra_lista(No*);

No* libera_lista(No *L);


No* insere_fim(No* L, int valor);

No* insere_meio(No* L, int elemento, int valor);

No* remove_elemento(No* L, int elemento);

int remove_inicio(No** L);


#endif // LISTASIMPLES_H_INCLUDED
