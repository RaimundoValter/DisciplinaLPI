#include "TAD_LISTAGEN\TAD_LISTAGEN.h"
#include <stdlib.h>
#include <string.h>

// Produtos
typedef struct produto{
    int pk;
    char* nome;
    float preco;
} Produto;

// Item
struct item{
    Produto* prod;
    int quantidade;
};


typedef struct produto Produto;
typedef struct item Item;

void* produto_cria(int pk);
void imprime_produto(void* elemento);
int valores_menores_3_00(void* elemento);
int produto_pk_igual(void* elemento1, void* elemento2);
void imprime_item_carrinho(void* elemento);


int main(void){

    //1) Faça uma lista de produtos contendo 5 produtos.
    Listagen* lista_produtos = lstgen_cria();
    lista_produtos = lstgen_insere(lista_produtos,produto_cria(1));
    lista_produtos = lstgen_insere(lista_produtos,produto_cria(2));
    lista_produtos = lstgen_insere(lista_produtos,produto_cria(3));
    lista_produtos = lstgen_insere(lista_produtos,produto_cria(4));
    lista_produtos = lstgen_insere(lista_produtos,produto_cria(5));
    //2) Imprima a lista de produtos criada.
    printf("## TODOS OS PRODUTOS ##\n");
    lstgen_percorre(lista_produtos, imprime_produto);

    //3) Crie uma lista filtrada a partir da lista inicial com produtos com preço menor que um valor (exemplo: R$ 3,00).
    Listagen* lista_filtrada = lstgen_filtra(lista_produtos, valores_menores_3_00);
    printf("## PRODUTOS FILTRADOS ##\n");
    lstgen_percorre(lista_filtrada, imprime_produto);

    //4) Crie uma lista que representa um carrinho de compras. Insira produtos (buscando pela chave pk) e suas quantidades.
    Listagen* carrinho = lstgen_cria();

    Produto* produto_encontrado = NULL;
    Produto produto_busca;
    int quantidade_produto = 0;

    do{
        printf("Qual o ID do produto devo inserir no carrinho (0 para parar)?\n> ");
        scanf("%d%*c", &produto_busca.pk);
        produto_encontrado = lstgen_busca(lista_produtos, produto_pk_igual, &produto_busca);
        
        if (produto_encontrado != NULL){
            
            Item* novo_item_carrinho = (Item*)malloc(sizeof(Item));
            novo_item_carrinho->prod = produto_encontrado;
            printf("Qual quantidade do produto %s desejas inserir no carrinho: ", produto_encontrado->nome);
            scanf("%d%*c", &quantidade_produto);
            novo_item_carrinho->quantidade = quantidade_produto;
            carrinho = lstgen_insere(carrinho, novo_item_carrinho);
        }
    }while(produto_busca.pk != 0);    
    
    printf("\n\n## PRODUTOS NO CARRINHO##\n");
    lstgen_percorre(carrinho, imprime_item_carrinho);


    //5) Crie uma função para retornar o valor total dos produtos presentes no carrinho de compras.

    return 1;
}

void* produto_cria(int pk){
    Produto* novo = (Produto*)malloc(sizeof(Produto));
    if(!novo){
        printf("Sem memória para adicionar um novo produto à lista...\n");
        exit(1);
    }

    novo->pk = pk;

    char buffer[51] = "";
    printf("ID produto: %d%*c\n", pk);

    printf("Digite o nome: ");
    scanf("%50[^\n]", buffer);

    novo->nome = (char*)malloc(strlen(buffer)*sizeof(char));
    strcpy(novo->nome, buffer);

    printf("Digite o preço: ");
    scanf(" %f%*c", &novo->preco);

    return (void*)novo;
}

void imprime_produto(void* elemento){
    Produto* prod_recuperado = (Produto*)elemento;

    printf("ID produto: %d\n", prod_recuperado->pk);
    printf("Nome: %s\n", prod_recuperado->nome);
    printf("Preço: %.2f\n", prod_recuperado->preco);
    printf("###############\n");
}

int valores_menores_3_00(void* elemento){
    Produto* prod_recuperado = (Produto*)elemento;
    return prod_recuperado->preco < 3.00;
}

int produto_pk_igual(void* elemento1, void* elemento2){
    Produto* p1 = (Produto*)elemento1;
    Produto* p2 = (Produto*)elemento2;
    return p1->pk == p2->pk;
}

void imprime_item_carrinho(void* elemento){
    Item* item_recuperado = (Item*)elemento;
    Produto *prod_recuperado = (Produto*)item_recuperado->prod;
    printf("########");
    printf("ID: %d\n", prod_recuperado->pk);
    printf("NOME: %s\n", prod_recuperado->nome);
    printf("PREÇO: %.2f\n", prod_recuperado->preco);
    printf("quantidade: %d\n", item_recuperado->quantidade);
    printf("Subtotal: %.2f\n", prod_recuperado->preco * item_recuperado->quantidade);
}