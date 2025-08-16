#include "TAD_PILHA_LINKS.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
PILHA VAZIA?
    Retorna zero caso contenha algo, do contrário, retorna 1.
*/
int pilha_vazia(Pilha* p){
    return p->prim == NULL;
}

/*
CRIA UMA PILHA VAZIA
    Retorna o ponteiro para uma pilha vazia.
*/
Pilha* pilha_cria(void){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));

    if(!p){
        printf("Não temos memória suficiente...\n");
        exit(1);
    }

    p->prim = NULL;

    return p;
}

/*
EMPILHA
    Empilha um link em nossa pilha.
    Deves passar a referência de uma string em link_push.
*/
void pilha_push(Pilha* p, char* link_push){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if(!novo){
        printf("Não temos memória suficiente...\n");
        exit(1);
    }

    novo->link = (char*)malloc(sizeof(strlen(link_push))+1);
    strcpy(novo->link, link_push);

    novo->prox = p->prim;

    p->prim = novo;

}

/*
DESEMPILHA
    Desempilha um link em nossa pilha.
    Deves passar a referência link_pop para onde queres que seja copiado o link.
*/
void pilha_pop(Pilha* p, char* link_pop){
    if(!pilha_vazia(p)){
        Lista* t = p->prim;
        strcpy(link_pop, t->link);
        free(t->link);
        p->prim = t->prox;
        free(t);
    }
}

/*
IMPRIME A PILHA
    Imprime todos os links presentes na pilha.
*/
void pilha_imprime(Pilha* p){
    printf("\n## LINKS ##\n");
    for(Lista* t = p->prim; t != NULL; t = t->prox){
        printf("%s\n", t->link);
    }
}

/*
LIBERA PILHA
    Libera a memória da pilha.
*/
void pilha_libera(Pilha* p){

    if(!pilha_vazia(p)){
        Lista* aux;
        for(Lista* t = p->prim; t != NULL; t = aux){
            aux = t->prox;
            free(t);
        }
    }

}