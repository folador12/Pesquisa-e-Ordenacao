#include <stdio.h>
#include <stdlib.h>


struct nod
{
    void* info;
    struct nod *ant;
    struct nod *prox;
};
typedef struct nod Nod;

struct listad
{
        Nod *ini;
        Nod *fim;
};
typedef struct listad Listad;

struct nob
{
    int folha; //1 se for folha, 0 caso contrario
    int qtd_chaves;
    struct nob* pai;
    Listad *lista_chaves;
};

typedef struct nob Nob;

typedef struct arvoreb
{
    Nob *raiz;
    int ordem;
    int altura;
}Arvoreb;

typedef struct chave
{
    int valor_chave;
    Nob *filho;
} Chave;

Listad* cria_listad()
{
    Listad* novalista;
    novalista = (Listad *)malloc(sizeof(Listad));
    novalista->ini = novalista->fim = NULL;
    return novalista;
}

Nod* cria_nod(void* valor)
{
    Nod* novo = (Nod*)malloc(sizeof(Nod));
    novo->ant = novo->prox = NULL;
    novo->info = valor;
    return novo;
}

Listad* insere_fim_listad(Listad* L, void* valor)
{
    Nod *novo = cria_nod(valor);

    if (L == NULL)
    {
        L = cria_listad();
        L->ini = L->fim = novo;
    }
    else
    {
        if(L->ini == NULL)
        {
            L->ini = L->fim = novo;
        }
        else
        {
            novo->ant = L->fim;
            L->fim->prox = novo;
            L->fim = novo;
        }
    }
    return L;
}

Listad* insere_Ordenado(Listad* L, void* valor)
{
    Nod *novo = cria_nod(valor);
    Listad *aux = L;
    Nod *aux2 = NULL;

    if (L == NULL)
    {
        L = cria_listad();
        L->ini = L->fim = novo;
    }
    else if (novo->info < L->ini->info)
    {
        novo->prox = L->ini;
        L->ini = novo;
    }
    
    

    return aux;
}
/*


void inserir_ordenado(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        
        if(*lista == NULL){ // a lista está vazia?
            novo->proximo = NULL;
            *lista = novo;
        }
        else if(novo->valor < (*lista)->valor){ // é o menor?
            novo->proximo = *lista;
            *lista = novo;
        }
        else{ // inserção no meio ou no final da lista
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
   
}
*/

Listad *separa_lista(Listad* L, int n){
    Nod* aux = L->ini;
    Listad* reserva = cria_listad();
    int cont = 0;
    int cont1 = 0;

    for (int i = 1; i <= n; i++)
    {
        aux = aux->prox;
    }

    reserva->ini = aux;
    reserva->fim = L->fim;

    L->fim = aux->ant;
    L->fim->prox=NULL;
     
    return reserva;
}

void mostralista(Listad * L){
    Nod* aux = L->ini;

    while (aux != NULL)
    {
        printf(" %d ", aux->info);
        aux = aux->prox;
    }
    
}

int main()
{



    Listad *tree;
    Listad *tree2;

    int vet[] =
    {
        50, 30, 40, 44, 88, 95,
        25, 91, 31, 52, 20, 60,
        70, 74, 78, 79, 22, 28,
        33, 39, 98, 85, 86, 87,
        90, 92, 93, 94, 35, 32,
        84, 99, 105, 110
    };

    int i=0;
    int tam=34;
    tree = cria_listad();
    tree2 = cria_listad();

    for (i=0; i<5; i++)
    {
        tree=insere_fim_listad(tree,vet[i]);
    }


    tree2 = separa_lista(tree, 3);

   mostralista(tree);

    printf("\n\nMostrando lista 2 \n");

    mostralista(tree2);

    return 0;
}