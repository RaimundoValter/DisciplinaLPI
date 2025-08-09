#ifndef __TAD_LISTA_PRODUTOS__
    #define __TAD_LISTA_PRODUTOS__

    struct lista{
        int id;
        char descricao[81];
        float estoque;
        char unidade[31];
        float preco;
        struct lista* prox;
    };
    
    typedef struct lista Lista;

    Lista* lst_cria(void);
    Lista* lst_novo_elemento(void);
    Lista* lst_insere(Lista* cabeca_da_lista, Lista* novo_elemento);
    Lista* lst_retira_id(Lista* cabeca_da_lista, int id);
    Lista* lst_busca_id(Lista* cabeca_da_lista, int id);
    void lst_imprime(Lista* cabeca_da_lista);
    void lst_libera(Lista* cabeca_da_lista);

    #include "TAD_LISTA_PRODUTOS.c"
#endif