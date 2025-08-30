#include "TAD_LISTAGEN.h"
#include <stdlib.h>

/*
*   CRIA LISTA
*       Cria uma lista genérica vazia retornando NULL.
*/
Listagen* lstgen_cria(){
    return NULL;
}

/*
*   LISTA VAZIA?
*       Retorna 1 caso a lista esteja vazia, do contrário, 0.
*/
int lstgen_vazia(Listagen* l){
    return l == NULL;
}

/*
*   INSERE UM ELEMENTO NA LISTA
*       Retorna a cabeça da lista atualizada (Listagen*).
*/
Listagen* lstgen_insere(Listagen* l, void* elemento){
    Listagen* novo = (Listagen*)malloc(sizeof(Listagen));
    
    if(!novo){
        printf("\nAcabou memória para guardarmos o próximo elemento na lista...\n");
        exit(1);
    }

    novo->info = elemento;
    novo->prox = l;

    return novo;
}

/*
*   PERCORRE A LISTA
*       Percorre todos os elemento da lista, o processamento.
*/
void lstgen_percorre(Listagen* l, void (*processa)(void*)){

    while(l != NULL){
        processa(l->info);
        l = l->prox;
    }

}

void* lstgen_busca(Listagen* l, int (*compara)(void*, void*), void* dado);
Listagen* lstgen_retira(Listagen* l,  int (*compara)(void*, void*), void* dado);
Listagen* lstgen_duplica(Listagen* l, void* (*duplica)(void*));
void lstgen_libera(Listagen* l);
