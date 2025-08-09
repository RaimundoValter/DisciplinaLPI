#include ".\TAD_LISTA_PRODUTOS\TAD_LISTA_PRODUTOS.h"

int main(){

    Lista* produtos = lst_cria();

    // Inserindo 3 elmentos na lista.
    for(int i = 0; i < 3; i++)
        produtos = lst_insere(produtos, lst_novo_elemento());

    // Imprimindo a lista de produtos.
    lst_imprime(produtos);

    lst_libera(produtos);
    
    return 0;
}