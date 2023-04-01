#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include "listasimples.h"

typedef No Pilha;

Pilha* cria_pilha();
Pilha* push(Pilha *p, int elemento);
int pop(Pilha **p);
int top(Pilha *p);//consulta o primeiro elemento
int eh_vazia_pilha(Pilha *p);



#endif // PILHA_H_INCLUDED
