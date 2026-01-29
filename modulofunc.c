#include "modulofunc.h"

//funcoes inicio


void limpaBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    // void que limpa o buffer inteiro caso algo que nao seja um int seja a entrada do menu
    // usar sempre que depois do scanf quando for entrada para os menus.
}


void menuClientes()
{
    int selecionarCliente;
    do
    {
        printf("1 - Cadastrar clientes\n");
        printf("2 - Listar clientes\n");
        printf("3 - Buscar clientes\n");
        printf("4 - Editar clientes\n");
        printf("5 - Remover clientes\n");
        printf("6 - Retornar ao menu principal\n");
        printf("\n");
        if (scanf("%d", &selecionarCliente) != 1)
        {
            printf("Entrada invalida.\n");
            limpaBuffer();
            selecionarCliente = -1;
            continue;
        }
        switch (selecionarCliente)
        {
            case 1:
            printf("bom dia 1\n");
            break;

            case 2:
            printf("bom dia 2\n");

            break;

            case 3:
            printf("bom dia 3\n");
            break;

            case 4:
            printf("bom dia 4\n");
            break;

            case 5:
            printf("bom dia 5\n");
            break;

            case 6:
            break;

            default:
            printf("Comando nao encontrado\n");
            break;
        }

    } while (selecionarCliente!= 6);
    
}

void menuProdutos()
{
    int selecionarProduto;
    do
    {
        printf("1 - Cadastrar produtos\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produtos\n");
        printf("4 - Editar produtos\n");
        printf("5 - Remover produtos\n");
        printf("6 - Retornar ao menu principal\n");
        printf("\n");

        if (scanf("%d", &selecionarProduto) != 1)
        {
            printf("Entrada invalida.\n");
            limpaBuffer();
            selecionarProduto = -1;
            continue;
        }

        switch (selecionarProduto)
        {
            case 1:
            printf("bom dia 1\n");
            break;

            case 2:
            printf("bom dia 2\n");
            break;

            case 3:
            printf("bom dia 3\n");
            break;

            case 4:
            printf("bom dia 4\n");
            break;

            case 5:
            printf("bom dia 5\n");
            break;

            case 6:
            break;

            default:
            printf("Comando nao encontrado\n");
            break;
        } 

    } while (selecionarProduto!= 6);
}

void modoComprador()
{
    // rodar funcao de listar e escolher cliente
    int selecionarCompras;

    do
    {
        printf("1 - Adicionar produto ao carrinho\n");
        printf("2 - listar produtos no carrinho\n");
        printf("3 - Remover produtos do carrinho\n");
        printf("4 - Retornar ao menu principal\n");
        printf("\n");
        if (scanf("%d", &selecionarCompras) != 1)
        {
            printf("Entrada invalida.\n");
            limpaBuffer();
            selecionarCompras = -1;
            continue;
        }
            switch (selecionarCompras)
            {
                case 1:
                printf("bom dia 1\n");
                break;

                case 2:
                printf("bom dia 2\n");
                break;

                case 3:
                printf("bom dia 3\n");
                break;

                case 4:
                break;

                default:
                printf("Comando nao encontrado\n");
                break;
            }

    }while(selecionarCompras!=4);
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
    if (scanf("%d", &selecionar) != 1)
    {
        printf("Entrada invalida.\n");
        limpaBuffer();
        selecionar = -1;
    }
    switch (selecionar)
        {
            case 1:
            menuClientes();
            break;

            case 2:
            menuProdutos();
            break;

            case 3:
            modoComprador();
            break;

            case 4:
            printf("Saindo do menu\n");
            *i=1;
            return;

            default:
            printf("Comando nao encontrado\n");
            break;
        }
    
}


//funcoes final