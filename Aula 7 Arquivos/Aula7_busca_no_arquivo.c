#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE* fp = fopen("..\\entrada.txt", "rt");

    if(!fp){
        printf("Deu ruim!\n");
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
        printf("Encontrei \"%s\" ocorendo na linha %d...", 
            subcadeia, 
            n_linha);
    else
        printf("Não está no arquivo...\n");

    return 1;
}