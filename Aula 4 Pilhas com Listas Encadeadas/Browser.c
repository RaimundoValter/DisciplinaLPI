#include <stdio.h>
#include ".\TAD_PILHA_LINKS\TAD_PILHA_LINKS.h"

int main(){

    char link[81];
    Pilha* UNDO = pilha_cria();
    Pilha* REDO = pilha_cria();

    printf("$$$ BROWSER $$$\n");

    for(int i = 1; i <= 3; i++){
        printf("Digite o link %d para navegar: ", i);
        scanf("%80[^\n]%*c", link);
    
        pilha_push(UNDO, link);
    }

    printf("-- Imprimindo a Pilha UNDO --\n");

    pilha_imprime(UNDO);

    printf("Desfazendo...\n");

    pilha_pop(UNDO, link);
    pilha_push(REDO, link);

    printf("-- Imprimindo a Pilha UNDO --");

    pilha_imprime(UNDO);

    printf("-- Imprimindo a Pilha REDO --");

    pilha_imprime(REDO);

    printf("Liberando as pilhas...\n");

    pilha_libera(UNDO);

    pilha_libera(REDO);


    return 0;
}