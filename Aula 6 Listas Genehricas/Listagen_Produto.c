#include "TAD_LISTAGEN\TAD_LISTAGEN.h"
#include <stdlib.h>
#include <string.h>

// Produtos
struct produto{
    int pk;
    char* nome;
    float preco;
};

// Item
struct item{
    Produto* prod;
    int quantidade;
};


typedef struct produto Produto;
typedef struct item Item;

void* produto_cria(int pk);

int main(void){

    //1) Faça uma lista de produtos contendo 5 produtos.
    
    //2) Imprima a lista de produtos criada.

    //3) Crie uma lista filtrada a partir da lista inicial com produtos com preço menor que um valor (exemplo: R$ 3,00).

    //4) Crie uma lista que representa um carrinho de compras. Insira produtos (buscando pela chave pk) e suas quantidades.

    //5) Crie uma função para retornar o valor total dos produtos presentes no carrinho de compras.

    return 1;
}

void* produto_cria(int pk){
    Produto* novo = (Produto*)malloc(sizeof(Produto));
    if(!novo){
        printf("Sem memória para adicionar um novo produto à lista...\n");
        exit(1);
    }

    char buffer[51] = "";
    printf("ID produto: %d\n", pk);
    printf("Digite o nome: ");
    scanf("%50[^\n]", buffer);

    novo->nome = (char*)malloc(strlen(buffer)*sizeof(char));
    strcpy(novo->nome, buffer);

    printf("Digite o preço; ");
    scanf(" %f",&novo->preco);

    return (void*)novo;
}