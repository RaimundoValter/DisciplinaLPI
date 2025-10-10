#include <stdio.h>
#include "TAD_TREE\TAD_TREE.h"

int main(){
    Arv* Ab = arv_cria('A',
        arv_cria('B',
            arv_criavazia(),
            arv_cria('D',
                arv_criavazia(),
                arv_criavazia())),
        arv_cria('c',
            arv_cria('E', 
            arv_criavazia(),
            arv_criavazia()),
            arv_cria('F', 
            arv_criavazia(),
            arv_criavazia()))
        );

    arv_imprime(Ab);
    
    
    char letra = 'A';
    
    printf(" A letra \" %c \"", letra);
    
    if(arv_pertence(Ab, letra))
        printf("pertence à árvore...\n");
    else
        printf("não pertence à árvore...\n");

    printf("\nA altura da árvore é: %d.\n", arv_altura(Ab));

    printf("\n Possui %d letras minúsculas.", arv_qtd_letra_min(Ab));

    printf("\n Total de folhas: %d", arv_qtd_folhas(Ab));
    return 1;
}