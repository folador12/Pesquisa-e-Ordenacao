#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

int main()
{
    Arvoreb *tree;

    int vet[] =
        {
            50, 30, 40, 44, 88, 95, //6
            25, 91, 31, 52, 20, 60, //12
            70, 74, 78, 79, 22, 28, //18
            33, 39, 98, 85, 86, 87, //24
            90, 92, 93, 94, 35, 32, //30
            84, 99, 105, 110, 120, 5, //36
            18, 34, 29, 37, 38, 41, //42
            42, 23, 24, 27, 32, 36, // 48 NUMEROS
            130, 140, 150, 160, 170,  //53
            180, 190
            }; 

    int i = 0;
    int tam = 54; // 21 numeros provoca primeira quebra na raiz
    tree = cria_arvoreb(4);

    for (i = 0; i < tam; i++)
    {
        insercao_arvoreb(tree, vet[i]);
    }
    insercao_arvoreb(tree, vet[i]);

    system("cls || clear");

    //printf("INICIO\n");
    percurso_em_nivel_posicionado(tree);
       em_ordem(tree->raiz);
     system("pause");

    /*

        printf("INICIO\n");
        printf("\n\n\n");
        percurso_em_nivel_posicionado(tree);
        printf("\n\n\n");

      //  
        system("pause");
    */
libera_arvoreb(tree);
 printf("\n fim");
    return 0;
}
