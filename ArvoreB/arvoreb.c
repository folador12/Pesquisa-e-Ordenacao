#include "arvoreb.h"

Arvoreb *cria_arvoreb(int ordem)
{
    Arvoreb *nova = (Arvoreb *)malloc(sizeof(Arvoreb));

    nova->raiz = NULL;
    nova->ordem = ordem;
    nova->altura = 0;
    return nova;
}

Nob *cria_nob()
{
    Nob *novo = (Nob *)malloc(sizeof(Nob)), novo2;

    novo->folha = 1;
    novo->pai = NULL;
    novo->qtd_chaves = 0;
    novo->lista_chaves = cria_listad();

    return novo;
}

Chave *cria_chave(int valor)
{
    Chave *ch = (Chave *)malloc(sizeof(Chave));
    ch->filho = NULL;
    ch->valor_chave = valor;
    return ch;
}

Listad *divide_lista(Listad *L, int n)
{
    Listad *L2 = cria_listad();
    Nod *aux = L->ini;
    while (n > 1)
    {
        aux = aux->prox;
        n--;
    }
    L2->fim = L->fim;
    L->fim = aux;
    L2->ini = aux->prox;
    L2->ini->ant = NULL;
    L->fim->prox = NULL;
    return L2;
}

Listad* insere_ordenado_lista(Listad* lista_nos, Chave *chave_nova)
{

    Nod *aux = lista_nos->ini;
   
    while (aux != NULL  && chave_nova->valor_chave > get_valor_chave(aux)) 
    {
        aux = aux->prox;
    }
    if (aux == lista_nos->ini)
    {
        lista_nos = insere_inicio_listad(lista_nos,(void*)chave_nova);
    }
    else
    {
        if (aux == NULL){
            lista_nos = insere_fim_listad(lista_nos,(void*)chave_nova);
        }
        else
        {
            Nod* novo = cria_nod((void*)chave_nova);
            novo->prox = aux;
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            aux->ant = novo;
        }
    }
    return lista_nos;
}
Listad* insere_inicio_listad(Listad *L, void* valor){
    Nod *novo= cria_nod(valor);

    if (L == NULL)
    {
        L = cria_listad();
        L->ini = L->fim = novo;

    }
    else
    {
        if (L->ini == NULL)
            L->ini = L->fim = novo;
        else
        {
            novo->prox = L->ini;
            L->ini->ant = novo;
            L->ini = novo;
        }
    }
    return L;

}


Chave* cria_chave(int valor){
    Chave* ch = (Chave*)malloc(sizeof(Chave));
    ch->filho = NULL;
    ch->valor_chave = valor;
    return ch;
}

int get_valor_chave(Nod* aux){
    return ((Chave*)aux->info)->valor_chave;
}

Nob* get_filho(Nod* aux){
    Chave* aux2 = ((Chave*)aux->info);

    return(aux2->filho);
}

Nob* set_filho(Nod* aux,Nob* novo_filho){
    Chave* aux2 = ((Chave*)aux->info);

    return(aux2->filho = novo_filho);
}

Nob* cria_nova_raiz(Chave* ch, Nob* folha, Nob* novo){

    Nob *raiz = cria_nob();

    raiz->lista_chaves = insere_inicio_listad(raiz->lista_chaves, (void *)ch);
    raiz->qtd_chaves = 1;
    raiz->folha = 0;
    raiz->pai = NULL;

    folha->pai = raiz;
    novo->pai = raiz;

    set_filho(raiz->lista_chaves->ini, folha);
    set_filho(raiz->lista_chaves->ini->prox, novo);

    return raiz;
}

void insercao_arvoreb(Arvoreb *tree, int chave){
    Chave *ch = cria_chave(chave);

    Nob *folha = localiza_folha(tree,chave);
    Nob *novo = NULL;

    int tem_valor = 1;

    if (tree->raiz == NULL)
    {
        tree->raiz->lista_chaves = insere_inicio_listad(tree->raiz->lista_chaves, (void*)ch);
    }
    else{
        while (tem_valor)
        {
            folha->lista_chaves = insere_ordenado_lista(folha->lista_chaves, ch);
            folha->qtd_chaves++;
            if(folha->qtd_chaves < tree->ordem)
            {
                tem_valor = 0;
            }
            else{
                novo = divide_no (folha);
                ch = get_ultima_chave(folha);
                if (folha == tree->raiz)
                {
                   tree->raiz = cria_nova_raiz(ch,folha,novo);
                   tem_valor = 0;
                }
                else
                {
                    folha = folha->pai;
                }
                
            }
        }
        
    }
    
}

Nob* localiza_folha(Arvoreb *tree, int chave)
{
    Nob* aux = tree->raiz;

    while (aux->folha == 0) 
    {
        Nod* aux_lista = aux->lista_chaves->ini;
        while (aux_lista->prox != NULL && chave > get_valor_chave(aux_lista))
        {
            aux_lista = aux_lista->prox;
        }

        aux = get_filho(aux_lista); 
        
    }
    
    return aux;
}

Nob* divide_no(Nob* no_dividir){
    Nob* novo = cria_nob();

    int n = ceil(no_dividir->qtd_chaves / 2.0);

    novo->lista_chaves = divide_lista(no_dividir->lista_chaves, n);

    novo->folha = no_dividir->folha;
    novo->qtd_chaves = no_dividir->qtd_chaves - n;
    novo->pai = no_dividir->pai;

    no_dividir->qtd_chaves = n;

    Chave* ch_subir = get_ultima_chave(no_dividir);
    ch_subir->filho = no_dividir;

    Nod* aux = no_dividir->pai->lista_chaves->ini;

    while (get_filho(aux) != no_dividir)
    {
        aux = aux->prox;
    }
    set_filho(aux, novo);

}