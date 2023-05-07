#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

int main()
{
    Arvoreb *tree;

    int vet[] =
        {
            50, 30, 40, 44, 88, 95,
            25, 91, 31, 52, 20, 60,
            70, 74, 78, 79, 22, 28,
            33, 39, 98, 85, 86, 87,
            90, 92, 93, 94, 35, 32,
            84, 99, 105, 110};

    int i = 0;
    int tam = 10; // 34;
    tree = cria_arvoreb(5);

    for (i = 0; i < tam; i++)
    {
        insercao_arvoreb(tree, vet[i]);
    }
    insercao_arvoreb(tree, vet[i]);

    // em_ordem(tree->raiz);
    printf("\n\n\n");
    percurso_em_nivel_posicionado(tree);
        printf("\n\n\n");
    tree = libera_arvoreb(tree);

    return 0;
}
