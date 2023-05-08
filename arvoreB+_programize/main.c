#include <stdio.h>
#include <stdlib.h>

#include "arvorebplus.h"

int main()
{
    Node *raiz;

    raiz = NULL;

    raiz = inserir(raiz, 5, 33, 3);
    raiz = inserir(raiz, 15, 21, 3);
    raiz = inserir(raiz, 25, 31, 3);
    raiz = inserir(raiz, 25, 41, 3);
    raiz = inserir(raiz, 45, 10, 3);

    printArvore(raiz);

    return 0;
}
