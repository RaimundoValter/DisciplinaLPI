#include "TAD_LISTA_PRODUTOS.h"
#include <stdlib.h>

Lista* lst_cria(void){
    return NULL;
}

Lista* lst_novo_elemento(void){
    Lista* novo_elemento = (Lista*)malloc(sizeof(Lista));
    
    if(novo_elemento == NULL){
        printf("Não temos memória suficiente...");
        exit(1);
    }

    novo_elemento->prox = NULL;

    printf("## Cadastro de Produto ##\n");
    printf("id: ");
    scanf("%d%*c", &novo_elemento->id);
    printf("Descrição: ");
    scanf(" %80[^\n]", novo_elemento->descricao);
    printf("Estoque: ");
    scanf(" %f%*c", &novo_elemento->estoque);
    printf("Unidade: ");
    scanf(" %30[^\n]%*c", novo_elemento->unidade);
    printf("Preço: ");
    scanf(" %f%*c", &novo_elemento->preco);

    return novo_elemento;

}

Lista* lst_insere(Lista* cabeca_da_lista, Lista* novo_elemento){
    novo_elemento->prox = cabeca_da_lista;
    return novo_elemento;
}

Lista* lst_retira_id(Lista* cabeca_da_lista, int id){
    Lista* ant = NULL;
    Lista* p = cabeca_da_lista;

    // Busca pelo elemento com o id
    while(p != NULL && p->id != id){
        ant = p;
        p = p->prox;
    }
    
    // Encontramos o elemento a ser retirado.
    if (p != NULL){

        // O elemento a ser retirado está na cabeça da lista.
        if(ant == NULL){
            cabeca_da_lista = p->prox;
            free(p);
        }
        // O elemento a ser retirado está no corpo ou no final da lista.
        else{
            ant->prox = p->prox;
            free(p);
        }
    }

    return cabeca_da_lista;
}

Lista* lst_busca_id(Lista* cabeca_da_lista, int id){
    Lista* p = cabeca_da_lista;

    // Busca pelo elemento com o id
    while(p != NULL && p->id != id)
        p = p->prox;

    return p;

}

void lst_imprime(Lista* cabeca_da_lista){
    Lista* elemento;

    printf("\n### LISTA DE PRODUTOS ###\n");

    for(elemento = cabeca_da_lista; elemento != NULL; elemento = elemento->prox){
        printf("## Produto [%d] ##\n", elemento->id);
        printf("Descrição: %s\n", elemento->descricao);
        printf("Estoque: %.2f\n", elemento->estoque);
        printf("Unidade: %s\n", elemento->unidade);
        printf("Preço: %.2f\n-----------\n", elemento->preco);
    }
}

void lst_libera(Lista* cabeca_da_lista){
    Lista* p = cabeca_da_lista;
    Lista* aux;
       
    while(p != NULL){
        aux = p;
        p = p->prox;
        free(aux);
    }

}