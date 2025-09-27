#include "TAD_LISTAGEN.h"
#include <stdlib.h>
#include <stdio.h>

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

/*
*   BUSCA ELEMENTO DA LISTA
*       Retorna o ponteiro para a informação, caso ela esteja na lista,
*       do contrário, retorna NULL.
*/
void* lstgen_busca(Listagen* l, int (*compara)(void*, void*), void* dado){
    Listagen* p = l;

    while(p != NULL){
        if(compara(p->info, dado)) return p->info;
        p= p->prox;
    }

    return NULL;
}

/*
*   RETIRA ELEMENTO DA LISTA
*       Retira o primeiro elemento da lista encontrado que retorna 1 ao 
*       comparar dado com info do elemento presente na lista.
*/
Listagen* lstgen_retira(Listagen* l,  int (*compara)(void*, void*), void* dado){
    Listagen* p = l;
    Listagen *ant = NULL;

    while(p!= NULL){

        if(compara(p->info, dado)){

            if(ant == NULL){
                Listagen* temp = p->prox;
                free(p);
                l=temp;
            }
            else{
                ant->prox = p->prox;
                free(p);
            }

            return l;
        }

        ant = p;
        p = p->prox;
    }

    return l;
}


/*
*   LIBERA 
*       libera a memória ocupada pela lista genérica.
*/
void lstgen_libera(Listagen* l){

    Listagen* p = l;

    while(p != NULL){
        free(p->info);
        Listagen* temp = p->prox;
        free(p);
        p = temp; 
    }

}

/*
*   FILTRA ELEMENTOS DE UMA LISTA
*       Retorna uma lista contendo apenas os elementos filtrados pelo critério.
*       Esta função não copia as informações.
*       Retorna o ponteiro para uma lista contendo a referência aos elementos da lista original.
*/
Listagen* lstgen_filtra(Listagen* l, int (*criterio)(void*)){
    Listagen* nova_lista = lstgen_cria();
    Listagen* p = l;

    while(p != NULL){
        if(criterio(p->info))
            nova_lista = lstgen_insere(nova_lista, p->info);
        p = p->prox;
    }

    return nova_lista;
}

/*
*   DUPLICA UMA LISTA
*       Retorna o ponteiro para a nova lista passada por parâmetro.
*/
Listagen* lstgen_duplica(Listagen* l, void* (*duplica)(void*)){
    Listagen* nova_lista= lstgen_cria();
    for(Listagen* p = l; p != NULL; p = p->prox)
        nova_lista = lstgen_insere(nova_lista, duplica(p->info));
    
    return nova_lista;
}

/*
* ORDENA
*   Ordena a lista genérica de acordo com a função compara.
*   Caso compara retorne 1, a troca de posição entre os elementos 
*   será realizada, do contrário, não.
*   Esta função usa o algoritmo selection sort.
*/
Listagen* lstgen_ordena(Listagen* l, int (*compara)(void*, void*)){

    for(Listagen* p = l; p != NULL; p = p->prox){
        Listagen* q = p->prox;
        while(q != NULL){
            if(compara(p->info, q->info)){
                void* aux = q->info;
                q->info = p->info;
                p->info = aux;
            }
            q = q->prox;
        }
    }

    return l;
}


/*
* GRAVA ARQUIVO PARA CSV
*   Grava um arquivo CSV contendo as informações da lista genérica.
*   @params: lista l, nome_arquivo e callback para criar uma string 
*   no formato CSV a partir de um elemento da lista.
*   @return: 1 caso deu certo e 0 caso contrário.
*/
int lstgen_grava_csv(Listagen* l, char* nome_arquivo_csv, char* (*cria_linha_csv)(void*)){
    FILE* saida_csv = fopen(nome_arquivo_csv, "wt");
    char* string_csv;

    if(!saida_csv){
        printf("Não conseguimos abrir o arquivo no caminho %s...\n", nome_arquivo_csv);
        return 0;
    }

    for(Listagen* p = l; p!= NULL; p =p->prox){
        string_csv = cria_linha_csv(p->info);
        int i = 0;
        while(string_csv[i] != '\0'){
            fputc(string_csv[i], saida_csv);
            i++;
        }
        fputc('\n', saida_csv);
    }

    free(string_csv);

    fclose(saida_csv);

    return 1;
}

/*
* CARREGA ARQUIVO DO CSV
*   Recupera os registro de uma lista genérica a partir de um arquivo CSV.
*   @params: nome do arquivo CSV, callback para formar um elemento da lista
*   a partir da string recuperada do arquivo contendo uma linha.
*   Observação: caso o callback retorne NULL, esta função considerará que a linha será descartada.
*   @return: ponteiro para uma lista genérica carregada na memória principal.
*   Returna NULL caso não consiga carregar ou o arquivo esteja vazio.    
*/
Listagen* lstgen_carrega_csv(char* nome_arquivo_csv, void* (*cria_elemento)(char* linha_csv)){
    FILE* entrada = fopen(nome_arquivo_csv, "rt");
    char linha[121];
    Listagen* l = lstgen_cria();

    if(!entrada){
        printf("Não pude abrir o arquivo %s...", nome_arquivo_csv);
        return NULL;
    }
    
    while(fgets(linha,121,entrada) != NULL){
        
        void* novo_elemento = cria_elemento(linha);
        
        // Caso o callback do cliente retorna NULL, significa dizer que a linha será descartada.
        if(!novo_elemento)
            continue;
        
        l = lstgen_insere(l, novo_elemento);
        
    }

    return l;
}

