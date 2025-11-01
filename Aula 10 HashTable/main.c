#include "TAD_HASHTABLE_ALUNO\HASHTABLE_ALUNO.h"
#include <stdio.h>

int main(){
    
    hsh_insere(TABELA, 1, "Valter", "112233", "@valter");
    hsh_insere(TABELA, 2, "Larissa", "442233", "@lalala");
    hsh_insere(TABELA, 3, "João", "552233", "@jojojo");

    hsh_insere(TABELA, 2, "Larissa", "442233", "@ladala");

    hsh_lista_todos(TABELA);

    hsh_remove(TABELA, 1);

    hsh_lista_todos(TABELA);

    printf("Quantidade de alunos: %d\n", hsh_conta_alunos(TABELA));

    return 0;
}