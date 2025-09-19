#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char arquivo_entrada[121];
    char arquivo_saida[121];
    char c;

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%120s", arquivo_entrada);

    printf("Digite o nome do arquivo de saída: ");
    scanf("%120s", arquivo_saida);

    FILE* e = fopen(arquivo_entrada, "rt");
    if(!e){
        printf("Problemas ao abrir o arquivo: %s\n", arquivo_entrada);
        exit(1);
        }

    FILE* s = fopen(arquivo_saida, "wt");
    if(!e){
        printf("Problema ao abrir o arquivo: %s\n", arquivo_saida);
        exit(1);
    }

    while((c = fgetc(e)) != EOF){
        fputc(toupper(c), s);
    }

    fclose(e);
    fclose(s);

    return 1;
}