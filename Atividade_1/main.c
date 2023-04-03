#include <stdio.h>
#include <stdlib.h>

struct noavl
{
    int info;
    int fb;
    struct noavl *esq, *dir;
};

typedef struct noavl Noavl;

void libera_avl(Noavl* raiz);
void em_ordem(Noavl* raiz, int *cont);
void recalcula_fb(Noavl *candidato,int info);
Noavl *insere_noavl(Noavl *tree, int info, Noavl **pai_candidato);
Noavl *insercao_geral(Noavl *tree,int info);
Noavl *cria_noavl(int info);

int main(int argc, char const *argv[])
{
    Noavl* tree = NULL;
    int N=0,M=0;
    int cont=0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        while (M!=-1)
        {
            scanf("%d",&M);
            if (M!=-1)
            {
                tree=insercao_geral(tree,M);
            }
        }
        em_ordem(tree,&cont);

        if (cont == 1)
        {
            printf("nao \n");
        }
        else{
            printf("sim \n");
        }
        
        libera_avl(tree);
        tree=NULL;
        M=0;
    }
    
    return 0;
}

Noavl *cria_noavl(int info)
{
    Noavl *novo = (Noavl *)malloc(sizeof(Noavl));
    novo->dir = novo->esq = NULL;
    novo->info = info;
    novo->fb = 0;

    return novo;
}

Noavl *insercao_geral(Noavl *tree,int info)
{
    Noavl *candidato = NULL;
    Noavl *pai_candidato = NULL;

    if (tree == NULL)
    {
        return cria_noavl(info);
    }
    else
    {
        candidato = insere_noavl(tree, info, &pai_candidato);
        recalcula_fb(candidato, info);
    }
    return tree;
}

Noavl *insere_noavl(Noavl *tree, int info, Noavl **pai_candidato)
{
    Noavl *aux = tree;
    Noavl *pai_aux = NULL;
    Noavl *novo = cria_noavl(info);
    Noavl *candidato = tree;

    while (aux != NULL)
    {
        if (aux->fb != 0)
        {
            candidato = aux;
            *pai_candidato = pai_aux;
        }
        pai_aux = aux;
        if (info < aux->info)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    if (info < pai_aux->info)
        pai_aux->esq = novo;
    else
        pai_aux->dir = novo;

    return candidato;
}

void recalcula_fb(Noavl *candidato,int info)
{
    Noavl *aux = candidato;
    while (aux->info != info)
    {
        if (info < aux->info)
        {
            aux->fb++;
            aux = aux->esq;
        }
        else
        {
            aux->fb--;
            aux = aux->dir;
        }
    }
}
//retorna a nova raiz da subarvore 

void em_ordem(Noavl* raiz, int *cont)
{
    if (raiz != NULL)
    {   
        em_ordem(raiz->esq,cont);
        if(raiz->fb == 2 || raiz->fb ==-2){
            *cont=1;
        }
        em_ordem(raiz->dir,cont);
    }
        
}
void libera_avl(Noavl* raiz)
{

        if (raiz != NULL)
        {
            libera_avl(raiz->esq);
            libera_avl(raiz->dir);
            free(raiz);
        }
}