#include "modulofunc.h"

//funcoes inicio


void limpaBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    // void que limpa o buffer inteiro caso algo que nao seja um int seja a entrada do menu
    // usar sempre que depois do scanf quando for entrada para os menus.
}


void nomeDinamico(Clientes *novo)
{
    int i=0;
    char c;
    novo->nome = NULL;
    while(scanf("%c", &c)==1 && c!='\n')
    {
        char *temp = realloc(novo->nome, i+2);
        if(temp == NULL)
        {
            free(novo->nome);
            novo->nome = NULL;
            return;
        }
        novo->nome = temp;
        novo->nome[i++] = c;
    };
    if(novo->nome!=NULL)
    {
        novo->nome[i] = '\0';
    }
}


Clientes * criarlistaClientes()
{
    Clientes *listaC;
    listaC = malloc(sizeof(Clientes));
    listaC->prox=NULL;

    return listaC;
};


void cadastrarCliente(Clientes *listaC)
{
    Clientes *novo;
    novo = malloc(sizeof(Clientes));
    int j=0;
    // refazer com fgets, com scanf ficou meio ruim
    do
    {
        if(j==1)
        {
            printf("cpf invalido (menos de 11 digitos)");
        }
        j=0;
        limpaBuffer();
        printf("digite o Cpf:");
        if(scanf("%11[0-9]", novo->cpf)!=1)
        {
            printf("CPF invalido\n");
            novo->cpf[0]= '\0';
            continue;
        }
        limpaBuffer();
        j++;
    }while(strlen(novo->cpf) != 11);

        printf("digite o Nome:");
        nomeDinamico(novo);
        if(novo->nome == NULL)
        {
            printf("Erro ao ler nome\n");
            free(novo);
            return;
        }
        printf("digite o Telefone:");
        scanf("%s", novo->telefone);
        novo->prox=listaC->prox;
        listaC->prox=novo;
};

// void ListarCliente(Clientes *listaC)
// {
//     Clientes *imprime;
//     int i;
//     printf("\n");
//     for (imprime=listaC->prox,i = 1;imprime!=NULL;imprime = imprime->prox, i++)
//     {
//         printf("%d - %s - cpf: %s - telefone: %s\n",i, imprime->nome, imprime->cpf, imprime->telefone);
//     }
//     printf("\n");
//     return;
// };


void buscarCliente(Clientes *listaC)
{
    Clientes *busca;
    char buscador[12];
    printf("Digite o cpf a ser buscado:");
    scanf("%s", buscador);
    for (busca=listaC->prox;strcmp(buscador,busca->cpf)!=0 || busca!=NULL ;busca=busca->prox);
    if(busca==NULL)
    {
        printf("Cpf nao encontrado");
    }
    else
    {
        printf("cpf encontrado: %s\n nome: %s\n telefone: %s\n", busca->cpf, busca->nome, busca->telefone);
    }
};


void menuClientes(Clientes *listaC)
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
            cadastrarCliente(listaC);
            break;

            case 2:
            ListarCliente(listaC);
            break;

            case 3:
//            buscarCliente(listaC);
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
    Clientes *listaC = criarlistaClientes();
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
            menuClientes(listaC);
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