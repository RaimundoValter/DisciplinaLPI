#include <stdlib.h>
#include <stdio.h>


int main(){

    char* nome_arquivo = "..\\entrada.txt";
    FILE* fp = fopen(nome_arquivo, "rt");
    int nlinhas = 1;
    char c;

    if(!fp)
        {
            printf("Não conseguimos abrir o arquivo: %s", nome_arquivo);
            exit(1);
        }

    while((c = fgetc(fp)) != EOF){
        if(c == '\n')
            nlinhas++;
    }

    fclose(fp);

    printf("\n>> O arquivo tinha %d linhas.\n", nlinhas);

    return 0;
}