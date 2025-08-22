#include "TAD_LISTA_HETEROGENEA.h"
#include <stdlib.h>

/*
* CRIA RETANGULO
*   Cria um elemento do tipo retângulo.
*/
Retangulo* cria_ret(float b, float h){
    Retangulo* r = (Retangulo*)malloc(sizeof(Retangulo));
    
    r->b = b;
    r->h = h;

    return r;
}

/*
* CRIA TRIANGULO
*   Cria um elemento do tipo triângulo.
*/
Triangulo* cria_tri(float b, float h){
    Triangulo* t = (Triangulo*)malloc(sizeof(Triangulo));
    
    t->b = b;
    t->h = h;

    return t;
}

/*
* CRIA CÍRCULO
*   Cria um elemento do tipo círculo.
*/
Circulo* cria_cir(float r){
    Circulo* c = (Circulo*)malloc(sizeof(Circulo));

    if(!c)
    
    c->r = r;

    return c;
}

/*
* CRIA LISTA HETEROGÊNEA
*   Cria uma lista heterogênea vazia.
*/
Lista_het* lista_het_cria(){
    return NULL;
}

/*
* LISTA VAZIA?
*   Verifica se uma lista heterogênea é vazia.
*   Retorna 1 caso for, 0 do contrário.
*/
int lista_het_vazia(Lista_het* lista){
    return lista == NULL;
}

/*
* INSERE UM ELEMENTO NA LISTA
*   Insere um elmento na lista heterogênea.
*/
Lista_het* lista_het_insere(Lista_het* lista, void* info, char tipo){

}


/*
* LIBERA LISTA
*   Libera uma lista heterogênea alocada na memória.
*/
void lista_het_libera(Lista_het* lista);

/*
* RECUPERE O PRIMEIRO RETÂNGULO
*   Recupera a referência (endereço de memória) do primeiro retângulo na lista.
*   Caso não haja nenhum, retorna NULL.
*/
Retangulo* lista_het_recupera_ret(Lista_het* lista);

/*
* RECUPERE O PRIMEIRO TRIÂNGULO
*   Recupera a referência (endereço de memória) do primeiro triângulo na lista.
*   Caso não haja nenhum, retorna NULL.
*/
Triangulo* lista_het_recupera_tri(Lista_het* lista);

/*
* RECUPERE O PRIMEIRO CÍRCULO
*   Recupera a referência (endereço de memória) do primeiro círculo na lista.
*   Caso não haja nenhum, retorna NULL.
*/
Circulo* lista_het_recupera_cir(Lista_het* lista);

/*
* TIPO DO PRIMEIRO ELEMENTO
*   Retorna o tipo do elemento que está na cabeça da lista.
*/
char lista_het_tipo_primeiro_elemento(Lista_het* lista);

/*
* AREA DO ELEMENTO
*   Retorna a valor área do elemento passado como parâmetro.
*/
float area(Lista_het* elemento);

/*
* MAIOR ÁREA
*   Retorna o valor da maior área presente na lista.
*/
float max_area(Lista_het* lista);