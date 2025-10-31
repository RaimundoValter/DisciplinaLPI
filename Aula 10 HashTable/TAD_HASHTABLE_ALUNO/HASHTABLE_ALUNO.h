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

    static int hash(int mat);
    Aluno* hsh_busca(Aluno** tab, int mat);
    Aluno* hsh_insere(Aluno** tab, int mat, char* nome, char* tel, char* email);

    #include "HASHTABLE_ALUNO.c"
#endif