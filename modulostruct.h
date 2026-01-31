#ifndef crudstruct
#define crudstruct

#include <stdlib.h>

typedef struct clientes
{
    char cpf[12];
    char telefone[100];
    char *nome;
    struct clientes *prox;
}Clientes;

typedef struct produtos
{
    char codigo[20];
    char nome[100];
    float preco;
    int quantidade;
    struct produtos *prox;
}Produtos;

#endif