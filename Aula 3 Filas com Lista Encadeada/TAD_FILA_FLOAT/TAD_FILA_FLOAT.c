#include "TAD_FILA_FLOAT.h"
#include <stdlib.h>
/* CRIA UMA FILA
    Cria uma fila vazia.
*/
Fila* fila_cria(void){
    Fila* fila = (Fila*)malloc(sizeof(Fila));

    fila->ini = fila->fim = NULL;

    return fila;
}

/* INSERE UM FLOAT NA FILA
    Insere um float ao final da fila.
*/
void fila_insere(Fila* f, float v){

    Lista* novo_elemento = (Lista*)malloc(sizeof(Lista));

    novo_elemento->v = v;
    novo_elemento->prox = NULL;

    if(f->fim != NULL)
        f->fim->prox = novo_elemento;
    else
        f->ini = novo_elemento;
    
    f->fim = novo_elemento;
}

/* RETIRA UM FLOAT DA FILA
    Retira um elemento do início da fila.
*/
float fila_retira(Fila* f){

    if(fila_vazia(f)){
        printf("Não existem elementos na fila para retirar...\n");
        exit(1);
    }

    Lista* elemento_a_retirar = f->ini;
    float valor_retirado = elemento_a_retirar->v;

    f->ini = f->ini->prox;
    free(elemento_a_retirar);

    // Caso o elemento retirado seja o último.
    if(f->ini == NULL) f->fim = NULL;

    return valor_retirado;
}
/* FILA VAZIA?
    Caso sim, retorna um número diferente de zero. 
    Do contrário, para fila com elementos, retorna zero.
*/
int fila_vazia(Fila* f){
    return f->ini == NULL && f->fim == NULL;
}

/* LIBERA A FILA DA MEMÓRIA
    Libera a memória ocupada pela fila.
*/
void fila_libera(Fila* f){
    Lista* p = f->ini;

    while(p != NULL){
        Lista* aux = p->prox;
        free(p);
        p = aux;
    }

    free(f);
}

/* IMPRIME A FILA
    Imprime os elementos da fila em um formato específico.
*/
void fila_imprime(Fila* f){

    Lista* p = f->ini;
    int contador = 1;

    while(p != NULL){
        printf("Posicao %d: %.2f\n", contador, p->v);
        contador++;
        p = p->prox;
    }
}