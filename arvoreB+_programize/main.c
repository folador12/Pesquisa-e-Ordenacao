#include <stdio.h>
#include <stdlib.h>

#include "arvorebplus.h"

int main()
{
    Node *raiz;

    raiz = NULL;

    raiz = inserir(raiz, 5, 0, 3);
    raiz = inserir(raiz, 15, 0, 3);
    raiz = inserir(raiz, 25, 0, 3);
    raiz = inserir(raiz, 25, 0, 3);
    raiz = inserir(raiz, 45, 0, 3);

    printArvore(raiz);

    return 0;
}
