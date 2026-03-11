#include <stdio.h>
#include <stdlib.h>

int main(){

    int c = 0, nlinhas = 0;

    
    FILE* fp = fopen("..\\entrada.txt", "rt");
    
    if(!fp) exit(2);
    
    printf("\nEOF >> %d\n\n", EOF);
    
    while((c = fgetc(fp)) != EOF){
        if(nlinhas == 0 && c != EOF)
            nlinhas++;

        if(c == '\n')
            nlinhas++;
        
        printf("%c", c);
    }
    
    printf("\n\nEste texto tem %d linhas...\n", nlinhas);

    fclose(fp);

    return 0;
}