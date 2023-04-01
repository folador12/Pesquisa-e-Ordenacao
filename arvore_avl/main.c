#include "arvore_avl.h"

int main()
{
    Noavl* raiz=NULL;
   // int vet[] = {23,45,65,28,33,64, 7, 34,9, 87, 90, 25};//12
    int vet[] = {28,33,64,7,34,9,87,90,14,54,38,10,3,25,40,13,76, 75, 72};//19
    int tam = 19;
    int i=0;

    for (i=0; i < tam; i++)
    {
        raiz =  insercao_geral(raiz, vet[i]);
    }
  // raiz =  insere_noavl(raiz, vet[i]);

    em_ordem(raiz);
    libera_avl(raiz);
    return 0;
}
