#ifndef __TAD_LISTAGEN__
    #define __TAD_LISTAGEN__


    struct listagen{
        void* info;
        struct listagen* prox;
    };

    typedef struct listagen Listagen;

    Listagen* lstgen_cria();
    int lstgen_vazia(Listagen* l);
    Listagen* lstgen_insere(Listagen* l, void* elemento);
    void lstgen_percorre(Listagen* l, void (*processa)(void*));
    void* lstgen_busca(Listagen* l, int (*compara)(void*, void*), void* dado);
    Listagen* lstgen_retira(Listagen* l,  int (*compara)(void*, void*), void* dado);
    Listagen* lstgen_duplica(Listagen* l, void* (*duplica)(void*));
    void lstgen_libera(Listagen* l);
    Listagen* lstgen_filtra(Listagen* l, int (*criterio)(void*));
    Listagen* lstgen_ordena(Listagen* l, int (*compara)(void*, void*));

    #include "TAD_LISTAGEN.c"
#endif