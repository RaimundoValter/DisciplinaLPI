#include <stdio.h>
#include <ctype.h>


int main(){
    char entrada[121];
    char saida[121];

    printf("Digite o caminho para o arquivo de entrada: ");
    gets(entrada);
       
    printf("Digite o caminho para o arquivo de entrada: ");
    gets(saida);

    FILE* e = fopen(entrada, "rt");
    if(!e) exit(1);
    
    FILE* s = fopen(saida, "wt");
    if(!s) exit(1);

    int c;

    while((c = fgetc(e))!= EOF){
        printf("%c", c);
        fputc(toupper(c), s);}

    fclose(e);

    return 0;
}