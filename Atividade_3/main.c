#include <stdio.h>
#include <stdlib.h>


struct no
{
    int info;
    int grupo;
    struct no *prox;
};

typedef struct no No;


No* cria_no(int valor);
No* libera_lista(No *L);
No* insere_fim(No* L, int valor);
void calculo_de_tempo(No* L);
void mostra_lista(No* L);


int main(int argc, char const *argv[])
{
    int t = 0, n = 0, p = 0;
    No* L=NULL;

    scanf("%d",&t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d",&n);

        for(int j = 0; j < n-1; j++)
        {
            scanf("%d",&p);

            L = insere_fim(L,p);
        }
        //mostra_lista(L);
        calculo_de_tempo(L);
        libera_lista(L);
        L=NULL;
    }
    
    return 0;
}

No* cria_no(int valor)
{
    No* novo;
    novo = (No*) malloc(sizeof(No));

    novo->prox = NULL;
    novo->grupo = valor;
    novo->info = 1;

    return novo;
}


void mostra_lista(No* L)
{
    No* aux = L;

    while (aux != NULL)
    {
        printf("G: %i , F: %i   \n",aux->grupo, aux->info);
        aux = aux->prox;// (*aux).prox
    }
    printf("\n");
}


No* libera_lista(No *L)
{
    No *aux = L;

    while (aux != NULL)
    {
        L = L->prox;
        free(aux);
        aux = L;
    }
    return NULL;
}

No* insere_fim(No* L, int valor)
{
    No* novo = cria_no(valor);
    No* aux = L;
    int m=0;

    if (L == NULL)
    {
        L = novo;
    }
    else
    {
        
        if(aux->grupo == valor)
        {
            aux->info++;
            m=-1;
        }

        while (aux->prox != NULL)
        {  
            aux = aux->prox;

            if(aux->grupo == valor)
            {
                aux->info++;
                m=-1;
            }             
        }

        if (m == 0)
        {   
            aux->prox = novo;
        }
    
    }
    return L;
}

void calculo_de_tempo(No* L)
{
    int tempo_total = 1;
    int tempo_espalhamento = 0;
    int tempo_minimo = 0;
    No* aux = L;

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
    
}

