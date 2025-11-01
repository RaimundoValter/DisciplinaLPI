#include "HASHTABLE_ALUNO.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 1. Calcula o hash de uma chave primária
static int hash(int mat){
    return mat%N;
}

// 2. Busca um aluno por matrícula e retorna o ponteiro para a estrutura, caso exista.
Aluno* hsh_busca(Aluno** tab, int mat){

    Aluno* p = tab[hash(mat)];

    while(p != NULL){
        if(p->mat == mat)
            break;
        p = p->prox;
    }
    
    return p;
}

// 3. Insere um aluno na tabela de dispersão, caso a matrícula já exista, atualizar os dados do aluno.
Aluno* hsh_insere(Aluno** tab, int mat, char* nome, char* tel, char* email){
    int id_hash = hash(mat);

    Aluno* p= tab[id_hash];
    Aluno* ant = NULL;

    while(p != NULL){
        if(p->mat == mat)
            break;
        p = p->prox;
    }

   
    if(p){ // Caso encontremos o aluno com a matrícula que queremos inserir
        strcpy(p->nome, nome);
        strcpy(p->tel, tel);
        strcpy(p->email, email);
        return p;
    }
    else  // Caso não encontremos um aluno com matrícula igual.
    {
        Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
        
        if(!novo){
            printf("Não temos memória para adicionar um aluno...\n");
            return NULL;
        }

        novo->mat = mat;
        strcpy(novo->nome, nome);
        strcpy(novo->tel, tel);
        strcpy(novo->email, email);
        novo->prox = NULL;

        if(ant){ // Caso em que a lista de colisões não esteja vazia.
            ant->prox = novo;
        }
        else{ // Caso a lista de colisões esteja vazia.
            tab[id_hash] = novo;
        }
        return novo;
    }
}

// 4. Remover aluno pela matrícula
int hsh_remove(Aluno** tab, int mat){
    Aluno* p = tab[hash(mat)];
    Aluno* ant = NULL;

    // Busca por matrículas iguais na tabela hash.
    while(p!= NULL){
        if(p->mat == mat)
            break;
        
        ant = p;
        p = p->prox;
    }

    // Não encontrou nada.
    if(!p)
        return 0;

    // Encontrou matrícula igual na tabela.
    if(ant)
        // Havia uma lista de elementos que colidiram.
        ant->prox = p->prox;
    else
        // Havia apenas um elemento que será excluído.
        tab[hash(mat)] = NULL;
    
    free(p);
    return 1;
}

// 5. Atualizar dados de um aluno
int hsh_atualiza(Aluno** tab, int mat, char* nome, char* tel, char* email){
    int id_hash = hash(mat);

    Aluno* p= tab[id_hash];
    Aluno* ant = NULL;

    while(p != NULL){
        if(p->mat == mat)
            break;
        p = p->prox;
    }

    if(p){ // Caso encontremos o aluno com a matrícula que queremos inserir
        strcpy(p->nome, nome);
        strcpy(p->tel, tel);
        strcpy(p->email, email);
        return p;
    }
    else  // Caso não encontremos um aluno com matrícula igual.
    {
        return NULL;
    }
}

// 6. Listar todos os alunos
void hsh_lista_todos(Aluno** tab){

    Aluno* p = NULL;

    printf("\n$$ Lista de Todos os Alunos $$\n");
    for(int i =0; i< N; i++){
        if(tab[i]){
            p = tab[i];
            while(p){
                printf("\n###Matrícula: %5d ###\n", p->mat);
                printf("Aluno(a): %s\n", p->nome);
                printf("tel: %s\n", p->tel);
                printf("e-mail: %s\n", p->email);

                p = p->prox;
            }
        }
    }
}

// 7. Contar número de alunos na tabela
int hsh_conta_alunos(Aluno** tab){
    int qtd_alunos = 0;
    Aluno* p = NULL;
    for(int i = 0; i < N; i++){
        p = tab[i];
        while(p != NULL){
            qtd_alunos++;
            p = p->prox;
        }
    }

    return qtd_alunos;
}

// 8. Buscar aluno por nome (busca parcial)
Aluno* hsh_busca_por_nome(Aluno** tab, char* nome);

// 9. Limpar/liberar toda a tabela
void hsh_limpa_tabela(Aluno** tab);

// 10. Calcular fator de carga da tabela
float hsh_fator_carga(Aluno** tab);

// 11. Verificar se tabela está vazia
int hsh_vazia(Aluno** tab);

// 12. Exportar dados para arquivo
int hsh_exporta_arquivo(Aluno** tab, char* filename, char* (*escrever_linha_csv)(void*));

// 13. Importar dados de arquivo
int hsh_importa_arquivo(Aluno** tab, char* filename, void* (*ler_linha_csv)(char*));