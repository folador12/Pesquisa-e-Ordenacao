#include "arvore_multipla.h"
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
        infecta(tree,nro_nos);
        printf("MAIS filhos: %d",maior->info);

        tree=NULL;
    }


    return 0;
}

