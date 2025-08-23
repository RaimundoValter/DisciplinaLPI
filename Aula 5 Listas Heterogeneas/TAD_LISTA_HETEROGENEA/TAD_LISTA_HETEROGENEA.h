#ifndef __TAD_LISTA_HETEROGENEA__
    #define __TAD_LISTA_HETEROGENEA__
    
    #include <stdlib.h>
    #include <stdio.h>

    #define RET 0
    #define TRI 1
    #define CIR 2

    #define PI 3.14F

    struct lista_het{
        char tipo;
        void* info;
        struct lista_het* prox;
    };

    struct retangulo{
        float b;
        float h;
    };

    struct triangulo{
        float b;
        float h;
    };

    struct circulo{
        float r;
    };

    typedef struct lista_het Lista_het;
    typedef struct retangulo Retangulo;
    typedef struct triangulo Triangulo;
    typedef struct circulo Circulo;

    Retangulo* cria_ret(float b, float h);
    Triangulo* cria_tri(float b, float h);
    Circulo* cria_cir(float r);

    Lista_het* lista_het_cria();
    Lista_het* lista_het_insere(Lista_het* lista, void* info, char tipo);
    int lista_het_vazia(Lista_het* lista);
    void lista_het_libera(Lista_het* lista);
    
    Retangulo* lista_het_recupera_ret(Lista_het* lista);
    Triangulo* lista_het_recupera_tri(Lista_het* lista);
    Circulo* lista_het_recupera_cir(Lista_het* lista);

    char lista_het_tipo_primeiro_elemento(Lista_het* lista);
    float area(Lista_het* elemento);
    float max_area(Lista_het* lista);

    void lista_het_imprime(Lista_het* lista);

    #include "TAD_LISTA_HETEROGENEA.c"
#endif