#include "TAD_LISTA_HETEROGENEA.h"

/*
* CRIA RETANGULO
*   Cria um elemento do tipo retângulo.
*/
Retangulo* cria_ret(float b, float h){
    Retangulo* r = (Retangulo*)malloc(sizeof(Retangulo));

    if(!r){
        printf("Não há mais memória...");
        exit(1);
    }
        
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

    if(!t){
        printf("Não há mais memória...");
        exit(1);
    }
        

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

    if(!c){
        printf("Não há mais memória...");
        exit(1);
    }
        
    
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
    
    Lista_het* novo = (Lista_het*)malloc(sizeof(Lista_het));

    if(!novo){
        printf("Não temos mais memória...");
        exit(1);
    }

    novo->tipo = tipo;
    novo->info = info;
    novo->prox = NULL;

    if (lista_het_vazia(lista))
       lista = novo;
    else{
        novo->prox = lista;
        lista = novo;
    } 

    return lista;
}

/*
* LIBERA LISTA
*   Libera uma lista heterogênea alocada na memória.
*/
void lista_het_libera(Lista_het* lista){
    Lista_het* p;
    Lista_het* temp;

    for(p = lista; p != NULL; p = temp){
        if(p->info) free(p->info);
        temp = p->prox;
        free(p);
    }
}

/*
* RECUPERE O PRIMEIRO RETÂNGULO
*   Recupera a referência (endereço de memória) do primeiro retângulo na lista.
*   Caso não haja nenhum, retorna NULL.
*/
Retangulo* lista_het_recupera_ret(Lista_het* lista){
    Lista_het* p = lista;
    while(p!= NULL){
        if(p->tipo == RET)
            return (Retangulo*)p;
    }

    return NULL;
}

/*
* RECUPERE O PRIMEIRO TRIÂNGULO
*   Recupera a referência (endereço de memória) do primeiro triângulo na lista.
*   Caso não haja nenhum, retorna NULL.
*/
Triangulo* lista_het_recupera_tri(Lista_het* lista){
    Lista_het* p = lista;
    while(p!= NULL){
        if(p->tipo == TRI)
            return (Triangulo*)p;
    }

    return NULL;
}

/*
* RECUPERE O PRIMEIRO CÍRCULO
*   Recupera a referência (endereço de memória) do primeiro círculo na lista.
*   Caso não haja nenhum, retorna NULL.
*/
Circulo* lista_het_recupera_cir(Lista_het* lista){
    Lista_het* p = lista;
    while(p!= NULL){
        if(p->tipo == CIR)
            return (Circulo*)p;
    }

    return NULL;
}

/*
* TIPO DO PRIMEIRO ELEMENTO
*   Retorna o tipo do elemento que está na cabeça da lista.
*   Em caso de lista vazia, retorna -1.
*/
char lista_het_tipo_primeiro_elemento(Lista_het* lista){
    if(lista)
        return lista->tipo;
    else
        return -1;
}

/*
* AREA DO ELEMENTO
*   Retorna o valor da área do elemento passado como parâmetro.
*/
float area(Lista_het* elemento){

    switch(elemento->tipo){
        case RET:
            Retangulo* r = (Retangulo*)elemento->info;
            return (r->b * r->h);
        break;
        case TRI:
            Triangulo* t = (Triangulo*)elemento->info;
            return (t->b * t->h)/2;
        break;
        case CIR:
            Circulo* c = (Circulo*)elemento->info;
            return (PI * c->r * c->r);
        break;
    }
}

/*
* MAIOR ÁREA
*   Retorna o valor da maior área presente na lista.
*   Em caso de lista vazia, retorna -1.
*/
float max_area(Lista_het* lista){
    
    if(!lista) return -1;

    float maior_area = 0.0F;
    for(Lista_het* p = lista; p != NULL; p = p->prox){
        float area_elemento = area(p);
        if(area_elemento > maior_area)
            maior_area = area_elemento;
    }

    return maior_area;
}

/*
* IMPRIME LISTA HETEROGÊNEA
*   
*/

void lista_het_imprime(Lista_het* lista){
    int i = 1;

    if(!lista_het_vazia(lista)){
        printf("\n\n++++++ LISTA HETEROGÊNEA ++++++\n");
        for(Lista_het* p = lista; p != NULL; p = p->prox, i++)
            switch(p->tipo){
                case TRI:
                    Triangulo* t = (Triangulo*)p->info;
                    printf("Elemento %d: Triângulo\n", i);
                    printf("base: %.2f\n", t->b);
                    printf("altura: %.2f\n", t->h);
                    printf("=====================\n");
                break;
                case RET:
                    Retangulo* r = (Retangulo*)p->info;
                    printf("Elemento %d: Triângulo\n", i);
                    printf("base: %.2f\n", r->b);
                    printf("altura: %.2f\n", r->h);
                    printf("=====================\n");
                break;
                case CIR:
                    Circulo* c = (Circulo*)p->info;
                    printf("Elemento %d: Triângulo\n", i);
                    printf("raio: %.2f\n", c->r);
                    printf("=====================\n");
                break;
            }
    }
}