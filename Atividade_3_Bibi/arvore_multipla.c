#include "arvore_multipla.h"

Nom *cria_nom(int info)
{
    Nom *novo = (Nom *)malloc(sizeof(Nom));
    novo->info = info;
    novo->pai = NULL;
    novo->infectada = 0;
    novo->nro_filhos_infec = 0;
    novo->nro_filhos = 0;
    novo->filhos = cria_listad();
    return novo;
}

void insere(Nom *tree, int info, int pai)
{

    Nom *novo = cria_nom(info);
    Nom *ppai = localiza_pai(tree, pai);
    if (ppai != NULL)
    {
        novo->pai = ppai;
        ppai->filhos = insere_inicio_listad(ppai->filhos, (void *)novo);
        ppai->nro_filhos++;
    }
    else
        printf("sem pai");
}

Nom *get_filho(Nod *aux)
{
    return ((Nom *)aux->info);
}

Nom *localiza_pai(Nom *raiz, int pai)
{
    Nod *aux;
    Nom *resp = raiz;
    if (raiz != NULL)
    {
        if (raiz->info != pai)
        {
            aux = raiz->filhos->ini;
            while (aux != NULL)
            {
                return localiza_pai(get_filho(aux), pai);
                // printf("%d ", get_filho(aux)->info);
                aux = aux->prox;
            }
        }
    }
    return resp;
}

void mais_filhos(Nom *raiz, Nom **maior)
{
    Nod *aux;
    if (raiz != NULL)
    {
        if (raiz->nro_filhos >= (*maior)->nro_filhos)
        {
            *maior = raiz;
        }
        aux = raiz->filhos->ini;
        while (aux != NULL)
        {
            mais_filhos(get_filho(aux), maior);
            aux = aux->prox;
        }
    }
}

void infecta(Nom *raiz, int nro_nos)
{
    Nod *aux;
    Nom *maior;
    int nro_infectados = 0;
    if (raiz != NULL)
    {
        // 1a. injecao
        mais_filhos(raiz, &maior);
        ((Nom *)maior->filhos->ini->info)->infectada = 1;
        maior->pai->nro_filhos_infec++;
        nro_infectados++;

        // espalhamento
        if (nro_infectados < nro_nos)
        {
            if (raiz->nro_filhos_infec > 0)
                espalha_irmao(raiz, &nro_infectados);
            while (aux != NULL)
            {
                infecta(get_filho(aux), nro_nos);
                aux = aux->prox;
            }
        }
        mostra(raiz);
    }
}
void espalha_irmao(Nom *raiz, int *nro_infectados)
{
    Nod *aux;
    int infectou = 0;
    if (raiz != NULL)
    {
        aux = raiz->filhos->ini;
        while (aux != NULL && !infectou)
        {
            if (!((Nom *)aux->info)->infectada)
            {
                ((Nom *)aux->info)->infectada = 1;
                (*nro_infectados)++;
                infectou = 1;
            }
            //       espalha_irmao(get_filho(aux), nro_infectados);
            aux = aux->prox;
        }
    }
}
void libera_arvorem(Nom *raiz)
{
    Nod *aux;
    if (raiz != NULL)
    {
        aux = raiz->filhos->ini;
        while (aux != NULL)
        {
            libera_arvorem(get_filho(aux));
            aux = aux->prox;
        }
        free(raiz);
    }
}
void mostra(Nom *raiz)
{   Nod *aux;
    if (raiz != NULL)
    {
        printf("%d(%d) ", raiz->info, raiz->infectada);
        aux = raiz->filhos->ini;
        while (aux != NULL)
        {
            mostra(get_filho(aux));
            aux = aux->prox;
        }
    }
}