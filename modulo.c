#include "modulo.h"
#include <stdio.h>

//funcoes inicio


void menuClientes()
{
    int selecionarCliente;
    printf("1 - Cadastrar clientes\n");
    printf("2 - Listar clientes\n");
    printf("3 - Buscar clientes\n");
    printf("4 - Editar clientes\n");
    printf("5 - Remover clientes\n");
    printf("6 - Retornar ao menu principal\n");
    printf("\n");
    scanf("%d", &selecionarCliente);
    while(selecionarCliente!=6)
    {
        if(selecionarCliente==1) printf("bom dia\n");
        if(selecionarCliente==2);
        if(selecionarCliente==3);
        if(selecionarCliente==4);
        if(selecionarCliente==5);
        printf("1 - Cadastrar clientes\n");
        printf("2 - Listar clientes\n");
        printf("3 - Buscar clientes\n");
        printf("4 - Editar clientes\n");
        printf("5 - Remover clientes\n");
        printf("6 - Retornar ao menu principal\n");
        printf("\n");
        scanf("%d", &selecionarCliente);
    }


}


void menuProdutos()
{
    int selecionarProduto;
    printf("1 - Cadastrar produtos\n");
    printf("2 - Listar produtos\n");
    printf("3 - Buscar produtos\n");
    printf("4 - Editar produtos\n");
    printf("5 - Remover produtos\n");
    printf("6 - Retornar ao menu principal\n");
    printf("\n");
    scanf("%d", &selecionarProduto);
    while(selecionarProduto!=6)
    {
        if(selecionarProduto==1) printf("bom dia\n");
        if(selecionarProduto==2);
        if(selecionarProduto==3);
        if(selecionarProduto==4);
        if(selecionarProduto==5);
        printf("1 - Cadastrar produtos\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produtos\n");
        printf("4 - Editar produtos\n");
        printf("5 - Remover produtos\n");
        printf("6 - Retornar ao menu principal\n");
        printf("\n");
        scanf("%d", &selecionarProduto);
    }
}


void modoComprador()
{
    // rodar funcao de listar e escolher cliente
    int selecionarCompras;
    printf("1 - Adicionar produto ao carrinho\n");
    printf("2 - listar produtos no carrinho\n");
    printf("3 - Remover produtos do carrinho\n");
    printf("4 - Retornar ao menu principal\n");
    printf("\n");
    scanf("%d", &selecionarCompras);
    while(selecionarCompras!=4)
    {
        if(selecionarCompras==1) printf("bom dia\n");
        if(selecionarCompras==2);
        if(selecionarCompras==3);
        printf("1 - Adicionar produto ao carrinho\n");
        printf("2 - listar produtos no carrinho\n");
        printf("3 - Remover produtos do carrinho\n");
        printf("4 - Retornar ao menu principal\n");
        printf("\n");
        scanf("%d", &selecionarCompras);
    }
}


void menuPrincipal(int *i)
{
    int selecionar;
    printf("Selecione sua opcao:\n");
    printf("1 - Clientes\n");
    printf("2 - Produtos\n");
    printf("3 - Modo Comprador\n");
    printf("4 - Sair.\n");
    printf("\n");
    scanf("%d", &selecionar);
    if(selecionar==1) menuClientes();
    if(selecionar==2) menuProdutos();
    if(selecionar==3) modoComprador();
    if(selecionar==4)
    {
    *i=1;
    return;
    }
}


//funcoes final