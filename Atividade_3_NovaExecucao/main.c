#include <stdio.h>
#include <stdlib.h>

struct nod
{
    void* info;
    struct nod *ant;
    struct nod *prox;
};
typedef struct nod Nod;

struct listad
{   
    int tamanho;
    Nod *ini;
    Nod *fim;
};
typedef struct listad Listad;

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
//------------------Arvore-----------------------//
void insere(Nom *tree, int info, int pai);
Nom *localiza_pai(Nom *raiz, int pai);
Nom *cria_nom(int info);
void mostra(Nom *raiz);
void libera_arvorem(Nom *raiz);
void mais_filhos(Nom *raiz, Nom **maior);
void infecta(Nom *raiz, int nro_nos);
void espalha_irmao(Nom *raiz, int *nro_infectados);

//------------------Lista Dupla------------------//

Listad* cria_listad();
Nod* cria_nod(void* valor);
void mostra_listad(Listad* L);
Listad* insere_inicio_listad(Listad *L, void* valor);
Listad* insere_fim_listad(Listad* L, void* valor);
Listad* libera_listad(Listad *L);

int compara (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
    
    Nom* tree;
    int nro_casos;
    int nro_nos;
    int *pais;
    int i;
    Nom *maior;

    scanf("%d", &nro_casos);
    while (nro_casos > 0)
    {
        scanf("%d", &nro_nos);
        tree = cria_nom(1);
        pais = (int*)malloc(sizeof(int)*(nro_casos)-1);
        for (i=0;i<nro_nos-1; i++)
         scanf("%d", &pais[i]);
        
        qsort(pais,nro_nos-1, sizeof(int), compara);
        for (i=0; i<nro_nos-1; i++)
            insere(tree, i+2, pais[i]);


        nro_casos--;
        //infecta(tree,nro_nos);
        mostra(tree);
        //printf("MAIS filhos: %d",maior->info);

        libera_arvorem(tree);
        tree=NULL;
    }
    
    return 0;
}

//------------------Lista Dupla------------------//
Listad* cria_listad()
{
    Listad* novalista;
    novalista = (Listad *)malloc(sizeof(Listad));
    novalista->ini = novalista->fim = NULL;
    novalista->tamanho=0;
    return novalista;
}

Nod* cria_nod(void* valor)
{
    Nod* novo = (Nod*)malloc(sizeof(Nod));
    novo->ant = novo->prox = NULL;
    novo->info = valor;
    return novo;
}

Listad* insere_inicio_listad(Listad *L, void* valor)
{
    Nod *novo= cria_nod(valor);

    if (L == NULL)
    {
        L = cria_listad();
        L->ini = L->fim = novo;

    }
    else
    {
        if (L->ini == NULL)
            L->ini = L->fim = novo;
        else
        {
            novo->prox = L->ini;
            L->ini->ant = novo;
            L->ini = novo;
        }
    }
    return L;

}

Listad* insere_fim_listad(Listad* L, void* valor)
{
    Nod *novo = cria_nod(valor);

    if (L == NULL)
    {
        L = cria_listad();
        L->ini = L->fim = novo;
    }
    else
    {


        if(L->ini == NULL)
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
    return L;
}

Listad* libera_listad(Listad *L)
{
    Nod *aux = L->ini;

    while (aux != NULL)
    {
        L->ini = L->ini->prox;
        free(aux->info);
        free(aux);
        aux = L->ini;
    }

    free(L);
    return NULL;
}

//------------------Arvore-----------------------//
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
        ppai->filhos = insere_fim_listad(ppai->filhos, (void *)novo);
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
        maior->nro_filhos_infec++;
        nro_infectados++;

        // espalhamento
        if (nro_infectados < nro_nos)
        {
            if (raiz->nro_filhos_infec > 0)
            {
                espalha_irmao(raiz, &nro_infectados);
            }

            aux= raiz->filhos->ini;
            
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
        printf("%d(%d) ", raiz->info, raiz->nro_filhos);
        aux = raiz->filhos->ini;
        while (aux != NULL)
        {
            mostra(get_filho(aux));
            aux = aux->prox;
        }
    }
}