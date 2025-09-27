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
char* cria_linha_cliente(void* info);
void* cria_cliente_da_linha(char* linha);

int main(){

    // Listagen* minha_lista = lstgen_cria();

    // minha_lista = lstgen_insere(minha_lista, cliente_cria(1));
    // minha_lista = lstgen_insere(minha_lista, cliente_cria(2));
    // minha_lista = lstgen_insere(minha_lista, cliente_cria(3));
    // minha_lista = lstgen_insere(minha_lista, cliente_cria(4));
    // minha_lista = lstgen_insere(minha_lista, cliente_cria(5));

    Listagen* minha_lista = lstgen_carrega_csv("listagen_cliente.csv", cria_cliente_da_linha);
    printf("\n### LISTA GENÉRICA ###\n");
    
    lstgen_percorre(minha_lista, cliente_imprime);

    minha_lista = lstgen_ordena(minha_lista, cliente_ordena_crescente);

    printf("\n### LISTA GENÉRICA ####\n");
    printf("\n### Ordenada por ID ###\n");
    
    lstgen_percorre(minha_lista, cliente_imprime);

    Listagen* minha_lista_duplicada = lstgen_duplica(minha_lista, cliente_duplica);

    printf("\n### LISTA GENÉRICA ####\n");
    printf("\n###### DUPLICADA ######\n");
    
    lstgen_percorre(minha_lista_duplicada, cliente_imprime);

    
    printf("Gravando no arquivo...");
    
    if(lstgen_grava_csv(minha_lista, "listagen_cliente.csv", cria_linha_cliente))
        printf("Deu certo!\n");
    else
        printf("Não conseguimos gravar no arquivo...\n");
    
    lstgen_libera(minha_lista);
    lstgen_libera(minha_lista_duplicada);
    
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

char* cria_linha_cliente(void* info){

    char linha[121];
    Cliente* info_cliente = (Cliente*)info;

    sprintf(linha, "%d;%s;%s", info_cliente->id, info_cliente->nome, info_cliente->telefone);

    char* linha_csv = (char*)malloc((strlen(linha)+1)*sizeof(char));

    strcpy(linha_csv, linha);

    return linha_csv;
}

void* cria_cliente_da_linha(char* linha){
    
    Cliente* novo = malloc(sizeof(Cliente));
    if (!novo) return NULL;

    char* token;
    int i = 1;

    token = strtok(linha, ";");
    
    while (token != NULL) {
        switch (i) {
            case 1:
                novo->id = atoi(token);
                break;
            case 2:
                strncpy(novo->nome, token, sizeof(novo->nome) - 1);
                novo->nome[sizeof(novo->nome) - 1] = '\0';
                break;
            case 3:
                strncpy(novo->telefone, token, sizeof(novo->telefone) - 1);
                novo->telefone[sizeof(novo->telefone) - 1] = '\0';
                break;
            default:
                printf(">> Erro: linha com mais de 3 campos.\n");
                free(novo);
                return NULL;
        }
        token = strtok(NULL, ";");
        i++;
    }

    if (i <= 3) { // não preencheu todos os campos
        printf(">> Erro: linha com campos faltando.\n");
        free(novo);
        return NULL;
    }

    return novo;
}
