#include <stdio.h>
#include ".\TAD_FILA_FLOAT\TAD_FILA_FLOAT.h"

int main(void){

    Fila* minha_fila = fila_cria();

    for(float v = 0.0; v < 6; v+=1.0)
        fila_insere(minha_fila, v);

    printf("## FILA DE FLOATS... ##\n");
    
    fila_imprime(minha_fila);

    printf("\n\nRetirando os dois primeiros elementos...\n");
    printf("Elemento 1: %.2f\n", fila_retira(minha_fila));
    printf("Elemento 2: %.2f\n", fila_retira(minha_fila));

    printf("\n\n## FILA DE FLOATS restantes... ##\n");
    
    fila_imprime(minha_fila);

    fila_libera(minha_fila);
}