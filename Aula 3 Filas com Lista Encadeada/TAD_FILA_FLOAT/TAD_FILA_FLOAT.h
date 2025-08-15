#ifndef __TAD_FILA_FLOAT__
    #define __TAD_FILA_FLOAT__

    struct lista {
        float v;
        struct lista* prox;
    };

    typedef struct lista Lista;
    
    struct fila{
        Lista* ini;
        Lista* fim;
    };

    typedef struct fila Fila;

    Fila* fila_cria(void);
    void fila_insere(Fila* f, float v);
    float fila_retira(Fila* f);
    int fila_vazia(Fila* f);
    void fila_libera(Fila* f);
    void fila_imprime(Fila* f);

    #include "TAD_FILA_FLOAT.c"
#endif