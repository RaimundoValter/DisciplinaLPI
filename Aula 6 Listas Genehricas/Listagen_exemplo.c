#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_LISTAGEN\TAD_LISTAGEN.h"

typedef struct cliente{
    int id;
    char nome[81];
    char telefone[12];
} Cliente;

void cliente_imprime(void* info);
void* cliente_cria(int id);
void* cliente_duplica(void* info);
int cliente_ordena_crescente(void* cliente1, void* cliente2);

int main(){

    Listagen* minha_lista = lstgen_cria();

    minha_lista = lstgen_insere(minha_lista, cliente_cria(1));
    minha_lista = lstgen_insere(minha_lista, cliente_cria(2));
    minha_lista = lstgen_insere(minha_lista, cliente_cria(3));
    minha_lista = lstgen_insere(minha_lista, cliente_cria(4));
    minha_lista = lstgen_insere(minha_lista, cliente_cria(5));

    printf("\n### LISTA GENÉRICA ###\n");
    
    lstgen_percorre(minha_lista, cliente_imprime);

    minha_lista = lstgen_ordena(minha_lista, cliente_ordena_crescente);

    printf("\n### LISTA GENÉRICA ####\n");
    printf("\n### Ordenada por ID ###\n");
    
    lstgen_percorre(minha_lista, cliente_imprime);

    Listagen* minha_lista_dupllicada = lstgen_duplica(minha_lista, cliente_duplica);

    printf("\n### LISTA GENÉRICA ####\n");
    printf("\n###### DUPLICADA ######\n");
    
    lstgen_percorre(minha_lista_dupllicada, cliente_imprime);

    lstgen_libera(minha_lista);
    lstgen_libera(minha_lista_dupllicada);
    
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

void* cliente_duplica(void* info){
    Cliente* original = (Cliente*)info;
    Cliente* copia = (Cliente*)malloc(sizeof(Cliente));

    copia->id = original->id;
    strcpy(copia->nome, original->nome);
    strcpy(copia->telefone, original->telefone);

    return copia;
}

int cliente_ordena_crescente(void* cliente1, void* cliente2){
    Cliente* cli1 = (Cliente*)cliente1;
    Cliente* cli2 = (Cliente*)cliente2;

    if(cli1->id > cli2->id)
        return 1;
    else
        return 0;
}