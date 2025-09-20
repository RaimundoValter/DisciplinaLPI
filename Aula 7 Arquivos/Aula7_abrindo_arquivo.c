#include <stdlib.h>
#include <stdio.h>


int main(){

    char* nome_arquivo = "..\\dados.txt";
    FILE* fp = fopen(nome_arquivo, "rt");
    char tipo = "";
    float v1, v2;
    char linha[121];

    if(!fp)
        {
            printf("Não conseguimos abrir o arquivo: %s", nome_arquivo);
            exit(1);
        }

    while(fgets(linha, 121, fp)){
        int n = sscanf(
            linha,
            "%c %f %f", 
            &tipo, 
            &v1, 
            &v2);
        
        if(n == 0)
            continue;
        
        switch (tipo)
        {
        case '#':
            printf("Encontrei um comentário...\n");
            break;
        case 'c':
        case 'C':
            printf("Encontramos um círculo de raio %.2f.\n", v1);
            break;
        case 't':
        case 'T':
            printf("Encontramos um triângulo de base %.2f e altura %.2f.\n", v1, v2);
            break;
        case 'r':
        case 'R':
            printf("Encontramos um triângulo de base %.2f e altura %.2f.\n", v1, v2);
            break;
        default:
            break;
        }
    }

    fclose(fp);

    return 0;
}