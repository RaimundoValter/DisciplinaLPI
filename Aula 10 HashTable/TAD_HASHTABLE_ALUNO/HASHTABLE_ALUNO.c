#include "HASHTABLE_ALUNO.h"
#include <stdlib.h>
#include <string.h>

static int hash(int mat){
    return mat%N;
}

Aluno* hsh_busca(Aluno** tab, int mat){

    Aluno* p = tab[hash(mat)];

    while(p != NULL){
        if(p->mat == mat)
            break;
        p = p->prox;
    }
    
    return p;
}

Aluno* hsh_insere(Aluno** tab, int mat, char* nome, char* tel, char* email){
    int id_hash = hash(mat);

    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    
    if(!novo){
        printf("Não temos memória para adicionar um aluno...\n");
        return NULL;
    }

    novo->mat = mat;
    strcpy(novo->nome, nome);
    strcpy(novo->tel, tel);
    strcpy(novo->email, email);
    
    if(tab[id_hash] == NULL){
        novo->prox = NULL;
    }
    else{    
        novo->prox = tab[id_hash];
    }

    tab[id_hash] = novo;

    return novo;
}
