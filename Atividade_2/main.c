#include <stdio.h>
#include <stdlib.h>

struct noavl
{
    int info;
    int fb;
    struct noavl *esq, *dir;
};

typedef struct noavl Noavl;

void imprimir_nivel(Noavl* raiz, int nivel);
int altura(Noavl* raiz);
void libera_avl(Noavl* raiz);
Noavl* rotacao_dir_esq(Noavl* candidato);
Noavl* rotacao_esq_dir(Noavl* candidato);
Noavl* rotacao_esq(Noavl* candidato);
Noavl* rotacao_dir(Noavl* candidato);
Noavl* rotacao_geral(Noavl* candidato);
void recalcula_fb(Noavl *candidato,int info);
Noavl *insere_noavl(Noavl *tree, int info, Noavl **pai_candidato);
Noavl *insercao_geral(Noavl *tree,int info);
Noavl *cria_noavl(int info);

int main(int argc, char const *argv[])
{
    Noavl* tree = NULL;
    int M = 0;
    int alt = 0;


    while (M!=-1)
    {
        scanf("%d",&M);
        if (M!=-1)
        {
            tree=insercao_geral(tree,M);
        }
    }
    
    alt = altura(tree);

    for (int i = 0; i < alt; i++)
    {
        imprimir_nivel(tree, i);
        printf("\n");
    }
    
    libera_avl(tree);
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
        if (candidato->fb == -2 || candidato->fb == +2)
        {
            if (candidato == tree)
                tree = rotacao_geral(candidato);
            else 
                if (pai_candidato->esq == candidato)
                pai_candidato->esq = rotacao_geral(candidato);
            else
                pai_candidato->dir = rotacao_geral(candidato);
        }
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

Noavl* rotacao_geral(Noavl* candidato)
{
    Noavl* nova_raiz=NULL;
    if(candidato->fb == +2)
        if (candidato->esq->fb == +1)
            nova_raiz = rotacao_dir(candidato);
        else
            nova_raiz = rotacao_esq_dir(candidato);
    else // fb cand -2
        if(candidato->dir->fb == -1)
            nova_raiz = rotacao_esq(candidato);
        else
            nova_raiz = rotacao_dir_esq(candidato);
    return nova_raiz;
}

Noavl* rotacao_dir(Noavl* candidato)
{
    Noavl* filho=candidato->esq;
    Noavl* neto=filho->dir;

    filho->dir = candidato;
    candidato->esq = neto;
   //recalculo fb
    candidato->fb = filho->fb = 0;
    
    return filho;
}

Noavl* rotacao_esq(Noavl* candidato)
{
    Noavl* filho=candidato->dir;
    Noavl* neto=filho->esq;

    filho->esq = candidato;
    candidato->dir = neto;
    candidato->fb = filho->fb = 0;
    
    return filho;
}

Noavl* rotacao_esq_dir(Noavl* candidato)
{
    Noavl* filho = candidato->esq;
    Noavl* neto = filho->dir;
    candidato->esq = rotacao_esq(candidato->esq);
    Noavl* nova_raiz = rotacao_dir(candidato);
    
    if (neto->fb == 1)
    {
        candidato->fb = -1;
        filho->fb = neto->fb = 0;
    }    
    if (neto->fb == -1)
    {
        candidato->fb = neto->fb = 0;
        filho->fb = 1;
    }

    return nova_raiz;
}

Noavl* rotacao_dir_esq(Noavl* candidato)
{
    Noavl* filho = candidato->dir;
    Noavl* neto = filho->esq;
    candidato->dir = rotacao_dir(candidato->dir);
    Noavl* nova_raiz = rotacao_esq(candidato);

   
    if (neto->fb == 1)
    {
        candidato->fb = -1;
        filho->fb = neto->fb = 0;
    }    
    if (neto->fb == -1)
    {
        candidato->fb = neto->fb = 0;
        filho->fb = 1;
    }
 
    return nova_raiz;
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

int altura(Noavl* raiz){

    int alt = 0;

    if(raiz == NULL)
    {
        alt = 0;
    }
    else
    {
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);

        if(esq > dir){
            alt = esq + 1;
        }
        else{
            alt =  dir + 1;
        }
    }

    return alt;
}

void imprimir_nivel(Noavl* raiz, int nivel){
    if (raiz != NULL)
    {
        if (nivel == 0)
        {
            printf("%d ", raiz->info);
        }
        else{
            imprimir_nivel(raiz->esq, nivel-1);
            imprimir_nivel(raiz->dir, nivel-1);
        } 
    }
}

//Luiz Antonio