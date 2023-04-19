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

struct arvore
{
    int grupo;
    int filhos;
    Listad *L;
};



Listad* cria_listad();
Nod* cria_nod(int valor);
void mostra_listad(Listad* L);
Listad* insere_fim_listad(Listad *L, int valor);
Listad* libera_listad(Listad *L);


int main(int argc, char const *argv[])
{
    int t = 0, n = 0, p = 0;
    Nod* L=NULL;

    scanf("%d",&t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d",&n);

        for(int j = 0; j < n-1; j++)
        {
            scanf("%d",&p);

            L = insere_fim_listad(L,p);
        }
        //mostra_lista(L);
        calculo_de_tempo(L);
        libera_listad(L);
        L=NULL;
    }
    
    return 0;
}

//------------------Calculo de tempo-------------//
/*
void calculo_de_tempo(Nod* L)
{
    int tempo_total = 1;
    int tempo_espalhamento = 0;
    int tempo_minimo = 0;
    Nod* aux = L;

    while (aux != NULL)
    {   
        if (aux != NULL)
        {
            tempo_total += aux->info;
            aux = aux->prox;
        }
        
    }
    aux = L;
    while (aux != NULL)
    {
        if (aux != NULL)
        {
            if (aux->info >= 2 && aux->info <5)
            {
                tempo_espalhamento += (aux->info - 1);
            }
            else if (aux->info >= 5)
            {
                tempo_espalhamento += (aux->info - 3);
            }
            
            aux = aux->prox;
            
        }
        
    }

    tempo_minimo = tempo_total - tempo_espalhamento;
    
    printf("%d \n", tempo_minimo);
    
} */

//------------------Lista Dupla------------------//
Listad* cria_listad()
{
    Listad* novalista;
    novalista = (Listad *)malloc(sizeof(Listad));
    novalista->ini = novalista->fim = NULL;
    return novalista;
}

Nod* cria_nod(int valor)
{
    Nod* novo = (Nod*)malloc(sizeof(Nod));
    novo->ant = novo->prox = NULL;
    novo->info = valor;
    return novo;
}

Listad* insere_fim_listad(Listad* L, int valor)
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
        free(aux);
        aux = L;
    }

    free(L);
    return NULL;
}

//----------------Arvore--------------//
