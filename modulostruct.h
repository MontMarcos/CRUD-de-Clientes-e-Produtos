#ifndef crudstruct
#define crudstruct

#include <stdlib.h>

typedef struct produtos
{
    char codigo[20];
    char *nome;
    float preco;
    int quantidade;
    struct produtos *prox;
}Produtos;

typedef struct produtosCarrinho
{
    Produtos *produto;
    int quantidade;
    struct produtosCarrinho *prox;
    // usar para a lista encadeada de produtos dentro do carrinho
}ProdutosCarrinho;

typedef struct carrinhos
{
    ProdutosCarrinho *items;
}Carrinhos;

typedef struct clientes
{
    char cpf[12];
    char telefone[100];
    char *nome;
    struct clientes *prox;
    Carrinhos *carrinhoC;
}Clientes;



#endif
