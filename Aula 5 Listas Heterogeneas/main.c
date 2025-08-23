#include <stdio.h>
#include ".\TAD_LISTA_HETEROGENEA\TAD_LISTA_HETEROGENEA.h"

int main(void){
    
    Lista_het* lista = lista_het_cria();

    printf("## LISTA HETEROGÊNEA ##\n");
    printf("Criando 5 elementos e inserindo na lista...");

    lista = lista_het_insere(lista, cria_ret(2,3), RET);
    lista = lista_het_insere(lista, cria_tri(4,5), TRI);
    lista = lista_het_insere(lista, cria_cir(6), CIR);
    lista = lista_het_insere(lista, cria_ret(6,7), RET);
    lista = lista_het_insere(lista, cria_tri(8,9), TRI);

    lista_het_imprime(lista);

    printf("A maior área é %.2f unid^2...", max_area(lista));

    lista_het_libera(lista);

    return 1;
}