#include <stdio.h>
#include <stdlib.h>
#include "TAD_LISTAGEN\TAD_LISTAGEN.h"

typedef struct cliente{
    int id;
    char nome[81];
    char telefone[12];
} Cliente;

void cliente_imprime(void* info);
void* cliente_cria(int id);

int main(){

    Listagen* minha_lista = lstgen_cria();

    minha_lista = lstgen_insere(minha_lista, cliente_cria(1));
    minha_lista = lstgen_insere(minha_lista, cliente_cria(2));
    minha_lista = lstgen_insere(minha_lista, cliente_cria(3));

    printf("\n### LISTA GENÉRICA ###\n");
    
    lstgen_percorre(minha_lista, cliente_imprime);

    return 0;
}

void* cliente_cria(int id){

    Cliente* novo_cliente = (Cliente*)malloc(sizeof(Cliente));
    
    if(!novo_cliente){
        printf("Não foi possível cadastrar novo cliente: falta de memória...\n");
        exit(1);
    }

    novo_cliente->id = id;

    printf("\nNome: ");
    scanf(" %80[^\n]", novo_cliente->nome);
    printf("Telefone: ");
    scanf(" %11[^\n]", novo_cliente->telefone);

    return novo_cliente;
}

void cliente_imprime(void* info){
    Cliente* p = (Cliente*)info;

    printf("\nID: %d", p->id);
    printf("\nNome: %s", p->nome);
    printf("\nTelefone: %s\n", p->telefone);
}