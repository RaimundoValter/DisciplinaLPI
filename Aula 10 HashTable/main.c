#include "TAD_HASHTABLE_ALUNO\HASHTABLE_ALUNO.h"
#include <stdio.h>

void* ler_linha_csv(char* linha);
char* escrever_linha_csv(void* aluno);

int main(){
    
    hsh_importa_arquivo(TABELA, "alunos.csv", ler_linha_csv);

    hsh_insere(TABELA, 1, "Valter", "112233", "@valter");
    hsh_insere(TABELA, 2, "Larissa", "442233", "@lalala");
    hsh_insere(TABELA, 3, "João", "552233", "@jojojo");
    hsh_insere(TABELA, 2, "Larissa", "442233", "@ladala");

    hsh_lista_todos(TABELA);

    hsh_remove(TABELA, 1);

    hsh_lista_todos(TABELA);

    printf("Quantidade de alunos: %d\n", hsh_conta_alunos(TABELA));

    hsh_exporta_arquivo(TABELA, "alunos.csv", escrever_linha_csv);

    return 0;
}

void* ler_linha_csv(char* linha){

    if(!linha){
        printf("Linha vazia...\n");
        return NULL;
    }

    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));

    char* token = strtok(linha, ",");
    int i = 0;

    while(token != NULL){
        switch(i){
            case 0:
                novo->mat = atoi(token);
            break;
            case 1:
                strcpy(novo->nome, token);
            break;
            case 2:
                strcpy(novo->tel, token);
            break;
            case 3:
                strcpy(novo->email, token);
                // Exclui o '\n' do final da linha.
                novo->email[(strlen(token)-1)>=0?(strlen(token)-1):0] = '\0';
            break;
            default:
                printf("Muitos atributos no arquivo CSV...\n");
                free(novo);
                return NULL;
        }
        i++;
        token = strtok(NULL, ",");
    }

    return (void*)novo;
}

char* escrever_linha_csv(void* aluno){
    
    char linha[121] = "";
    Aluno* info_aluno = (Aluno*)aluno;

    sprintf(linha, "%d,%s,%s,%s", info_aluno->mat, info_aluno->nome, info_aluno->tel, info_aluno->email);

    char* linha_csv = (char*)malloc((strlen(linha)+1)*sizeof(char));

    strcpy(linha_csv, linha);

    return linha_csv;
}