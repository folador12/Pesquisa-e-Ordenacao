#include "listadupla.h"
/*
LISTA DUPLAMENTE ENCADEADA GEN�RICA
Funcao: cria_no
Objetivo: alocar mem�ria para um novo n� da lista duplamente encadeada
que ainda inicializa os campos do n�
Parametros: valor (inteiro) que � a informa��o do novo n�
Retorno: devolve o ponteiro para o novo n� alocado ou NULL se nao h�
espacao para aloca��o
Data: 15/3/22
Autor: Daniela O
*/
Nod* cria_nod(void* valor)
{
    Nod *novo = (Nod*)malloc(sizeof(Nod));
    if (novo == NULL)//nao tem espaco para nova alocacao
    {
        printf("Nao h� espaco para aloca�ao de mem�ria\n");
    }
    else
    {
        novo->info = valor;
        novo->prox = novo->ant = NULL;
    }
    return novo;
}

Listad* cria_listad()
{
    Listad *L = (Listad*)malloc(sizeof(Listad));
    L->ini = L->fim = NULL;
    return L;
}

void insere_inicio_listad(Listad *L, void* valor)
{

    Nod *novo = cria_nod(valor);
//    if (novo == NULL)
//        return NULL;
    if (L->ini == NULL)//lista vazia
    {
        L->ini = L->fim = novo;
    }
    else
    {
        L->ini->ant = novo;
        novo->prox = L->ini;

        L->ini = novo;
    }
}


void insere_fim_listad(Listad *L, void* valor)
{
    Nod* novo = cria_nod(valor);

    if(L->fim == NULL)
    {
        L->ini = L->fim = novo;
    }
    else
    {
        novo->ant = L->fim;
        L->fim->prox = novo;
        L->fim = novo;
    }
}




void libera_listad(Listad *L)
{

    while (L->ini->prox != NULL)
    {
        L->ini = L->ini->prox;
        free(L->ini->ant);
        L->ini->ant = NULL;
    }
    free(L->fim);//libera o �ltimo elemento
    free(L);
}





int lista_vazia(Listad *L)
{
    int resp = 0;

    if (L == NULL)
        resp = 1; //lista esta vazia
    else if(L->ini == NULL)
        resp = 1; //lista esta vazia
    else
        resp = 0; //lista nao esta vazia
    return resp;
}





void* remove_inicio_listad(Listad *L)
{
    Nod* aux = L->ini;
    void* removido;
    if (aux != NULL)
    {
        if (L->ini == L->fim)//unico elemento
        {
            L->ini = L->fim = NULL;
        }
        else
        {
            L->ini = L->ini->prox;
            L->ini->ant = NULL;

        }
        removido = aux->info;
        free(aux);
    }
    return removido;
}

void* remove_fim_listad(Listad *L)
{
    Nod* aux = L->fim;
    void* removido;
    if (aux != NULL)
    {
        if (L->ini == L->fim)//unico elemento
        {
            L->ini = L->fim = NULL;
        }
        else
        {
            L->fim = L->fim->ant;
            L->fim->prox = NULL;

        }
        removido = aux->info;
        free(aux);
    }
    return removido;
}
/*
Fun��o que dada uma lista e um n�mero de elementos,
divide a lista em duas, sendo que a lista inicial
deve manter somente o n�mero de elementos informado no
par�metro e a nova lista deve conter o restante dos
elementos e ter seu ponteiro retornado
*/
Listad* divide_lista(Listad *L, int nro_elementos)
{
    Nod *aux = L->ini;
    Listad *L2 = cria_listad();
    while (nro_elementos > 0)
    {
        aux = aux->prox;
        nro_elementos--;
    }
    L2->ini = aux;
    L2->fim = L->fim;
    L->fim = aux->ant;
    L->fim->prox = NULL;
    L2->ini->ant = NULL;

    return L2;
}






