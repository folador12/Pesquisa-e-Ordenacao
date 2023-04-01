#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include <stdio.h>
#include <stdlib.h>

struct noavl
{
    int info;
    int fb;
    struct noavl *esq, *dir;
    //struct noavl *pai;
};

typedef struct noavl Noavl;

void libera_avl(Noavl* raiz);
void em_ordem(Noavl* raiz);
Noavl* rotacao_dir_esq(Noavl* candidato);
Noavl* rotacao_esq_dir(Noavl* candidato);
Noavl* rotacao_esq(Noavl* candidato);
Noavl* rotacao_dir(Noavl* candidato);
Noavl* rotacao_geral(Noavl* candidato);
void recalcula_fb(Noavl *candidato,int info);
Noavl *insere_noavl(Noavl *tree, int info, Noavl **pai_candidato);
Noavl *insercao_geral(Noavl *tree,int info);
Noavl *cria_noavl(int info);








#endif
