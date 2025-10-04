#include <stdio.h>
#include "TAD_TREE\TAD_TREE.h"

int main(){
    Arv* Ab = arv_cria('A',
        arv_cria('B',
            arv_criavazia(),
            arv_cria('D',
                arv_criavazia(),
                arv_criavazia())),
        arv_cria('C',
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

    return 1;
}