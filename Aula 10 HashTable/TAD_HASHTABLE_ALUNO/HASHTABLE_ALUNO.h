#ifndef __HASHTABLE_ALUNO_H__
    #define __HASHTABLE_ALUNO_H__

    #define N 100

    struct aluno{
        int mat;
        char nome[81];
        char tel[13];
        char email[51];
        struct aluno* prox;
    };
    
    typedef struct aluno Aluno;

    Aluno* TABELA[N];

    // 1. Calcula o hash de uma chave primária
    static int hash(int mat);
    
    // 2. Busca um aluno por matrícula e retorna o ponteiro para a estrutura, caso exista.
    Aluno* hsh_busca(Aluno** tab, int mat);

    // 3. Insere um aluno na tabela de dispersão, caso a matrícula já exista, atualizar os dados do aluno.
    Aluno* hsh_insere(Aluno** tab, int mat, char* nome, char* tel, char* email);

    // 4. Remover aluno pela matrícula
    int hsh_remove(Aluno** tab, int mat);

    // 5. Atualizar dados de um aluno
    int hsh_atualiza(Aluno** tab, int mat, char* nome, char* tel, char* email);

    // 6. Listar todos os alunos
    void hsh_lista_todos(Aluno** tab);

    // 7. Contar número de alunos na tabela
    int hsh_conta_alunos(Aluno** tab);

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

    #include "HASHTABLE_ALUNO.c"
#endif