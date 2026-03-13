#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char nome_arquivo[] = "..\\entrada.txt";

    FILE* fp = fopen(nome_arquivo, "rt");

    if(!fp){
        exit(1);
    }

    char linha[121];
    char achou = 0;
    char* subcadeia = "Valter";
    int n_linha = 0;

    while(fgets(linha, 121, fp) != NULL){
        n_linha++;
        if(strstr(linha, subcadeia) != NULL){
            achou = 1;
            break;
        }
    }

    if(achou)
        printf("Encontrei a subcadeia \"%s\" ocorendo na linha %d do arquivo %s...", 
            subcadeia, 
            n_linha,
            nome_arquivo);
    else
        printf("Não está no arquivo...\n");

    return 1;
}