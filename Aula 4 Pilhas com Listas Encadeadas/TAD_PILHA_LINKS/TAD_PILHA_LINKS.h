#ifndef __TAD_PILHA_LINKS__
    #define __TAD_PILHA_LINKS__

    struct lista{
        char* link;
        struct lista* prox;
    };
    typedef struct lista Lista;

    struct pilha {
        Lista* prim;
    };

    typedef struct pilha Pilha;

    int pilha_vazia(Pilha* p);
    Pilha* pilha_cria(void);
    void pilha_push(Pilha* p, char* link_push);
    void pilha_pop(Pilha* p, char* link_pop);
    void pilha_libera(Pilha* p);
    void pilha_imprime(Pilha* p);


    #include "TAD_PILHA_LINKS.c"
#endif