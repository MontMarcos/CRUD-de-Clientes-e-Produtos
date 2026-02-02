#include "modulofunc.h"

//funcoes inicio


//funcoes meio
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

Produtos * criarlistaProdutos()
{
    Produtos *listaP;
    listaP = malloc(sizeof(Produtos));
    listaP->prox=NULL;

    return listaP;
};

//funções do cliente

void cadastrarCliente(Clientes *listaC)
{
    Clientes *novo;
    novo = malloc(sizeof(Clientes));
    printf("Insira os dados do cliente a ser cadastrado:\n");
    int j=0;
    do
    {
        if(j==1)
        {
            printf("cpf invalido (menos de 11 digitos)");
        }
        j=0;
        limpaBuffer();
        printf("digite o Cpf:");
        if(scanf(" %11[0-9]", novo->cpf)!=1)
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

void ListarCliente(Clientes *listaC)
{
    Clientes *imprime;
    int i;
    printf("\n");
    for (imprime=listaC->prox,i = 1;imprime!=NULL;imprime = imprime->prox, i++)
    {
        printf("%d - %s - cpf: %s - telefone: %s\n",i, imprime->nome, imprime->cpf, imprime->telefone);
    }
    printf("\n");
    return;
};

Clientes * buscarCliente(Clientes *listaC)
{
    Clientes *busca;
    char buscador[12];

    printf("Digite o cpf a ser buscado: ");
    scanf("%11s", buscador);

    busca = listaC->prox;

    while (busca != NULL && strcmp(buscador, busca->cpf) != 0) {
        busca = busca->prox;
    }

    return busca;
}

void editarCliente(Clientes *listaC)
{
    Clientes *atual = buscarCliente(listaC);

    if (atual == NULL) {
        printf("Cpf nao encontrado\n");
    } else 
    {
        int j=0;
        printf("Edite os dados do cliente:\n");
        do
        {
            if(j==1)
            {
                printf("cpf invalido (menos de 11 digitos)\n");
            }
            j=0;
            limpaBuffer();
            printf("digite o Cpf:");
            if(scanf("%11[0-9]", atual->cpf)!=1)
            {
                printf("CPF invalido\n");
                atual->cpf[0]= '\0';
                continue;
            }
            limpaBuffer();
            j++;
        }while(strlen(atual->cpf) != 11);
        free(atual->nome);
        atual->nome = NULL;
        printf("digite o novo Nome:");
        nomeDinamico(atual);
        if(atual->nome == NULL)
        {
            printf("Erro ao ler nome\n");
            return;
        }
        printf("digite o novo Telefone:");
        scanf("%s", atual->telefone);
    }
}

void removerCliente(Clientes *listaC)
{
    Clientes *atual = listaC;
    Clientes *anterior = NULL;
    char buscador[12];

    printf("Digite o cpf do cliente a ser removido: ");
    scanf("%11s", buscador);

    while (atual != NULL && strcmp(buscador, atual->cpf) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Cpf nao encontrado\n");
    } else {
        if (anterior == NULL) {
            listaC->prox = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual->nome);
        free(atual);
        printf("Cliente removido com sucesso\n");
    }
}

//funcoes do produto

void cadastrarProduto(Produtos *listaP)
{
    Produtos *novo;
    novo = malloc(sizeof(Produtos));
    printf("digite o codigo do produto:");
    if(scanf("%19s", novo->codigo)!=1)
    {
        printf("Codigo invalido\n");
        free(novo);
        return;
    }

    printf("digite o nome do produto:");
    if(scanf("%99s", novo->nome)!=1)
    {
        printf("Nome invalido\n");
        free(novo);
        return;
    }
    printf("digite o preco do produto:");
    scanf("%f", &novo->preco);

    printf("digite a quantidade do produto:");
    scanf("%d", &novo->quantidade);

    novo->prox=listaP->prox;
    listaP->prox=novo;
}

void listarProduto(Produtos *listaP)
{
    Produtos *imprime;
    int i;
    printf("\n");
    for (imprime=listaP->prox,i = 1;imprime!=NULL;imprime = imprime->prox, i++)
    {
        printf("%d - %s - codigo: %s - preco: %.2f - quantidade: %d\n",i, imprime->nome, imprime->codigo, imprime->preco, imprime->quantidade);
    }
    printf("\n");
    return;
}

Produtos * buscarProduto(Produtos *listaP)
{
    Produtos *busca;
    char buscador[20];

    printf("Digite o codigo do produto a ser buscado: ");
    scanf("%19s", buscador);

    busca = listaP->prox;

    while (busca != NULL && strcmp(buscador, busca->codigo) != 0) {
        busca = busca->prox;
    }
    return busca;
}

void editarProduto(Produtos *listaP)
{
    Produtos *atual = buscarProduto(listaP);
    if (atual == NULL) {
        printf("Codigo nao encontrado\n");
    } else {
        printf("Digite o novo nome do produto: ");
        scanf("%99s", atual->nome);
        printf("Digite o novo preco do produto: ");
        scanf("%f", &atual->preco);
        printf("Digite a nova quantidade do produto: ");
        scanf("%d", &atual->quantidade);
        printf("Produto editado com sucesso\n");
    }
}

void removerProduto(Produtos *listaP)
{
    Produtos *atual = listaP;
    Produtos *anterior = NULL;
    char buscador[20];

    printf("Digite o codigo do produto a ser removido: ");
    scanf("%19s", buscador);

    while (atual != NULL && strcmp(buscador, atual->codigo) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Codigo nao encontrado\n");
    } else {
        if (anterior == NULL) {
            listaP->prox = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
        printf("Produto removido com sucesso\n");
    }
}

//funcoes do menu

void menuClientes(Clientes *listaC)
{
    int selecionarClientes;
    Clientes *buscaCl;
    do
    {
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Buscar cliente\n");
        printf("4 - Editar cliente\n");
        printf("5 - Remover cliente\n");
        printf("6 - Retornar ao menu principal\n");
        if (scanf("%d", &selecionarClientes) != 1)
        {
            printf("Entrada invalida.\n");
            limpaBuffer();
            selecionarClientes = -1;
            continue;
        }
            switch (selecionarClientes)
            {
                case 1:
                cadastrarCliente(listaC);
                break;

                case 2:
                ListarCliente(listaC);
                break;

                case 3:
                buscaCl=buscarCliente(listaC);
                    if (buscaCl == NULL) 
                    {
                        printf("Cpf nao encontrado\n");
                    } 
                    else 
                    {
                    printf("cpf encontrado: %s\nnome: %s\ntelefone: %s\n",buscaCl->cpf, buscaCl->nome, buscaCl->telefone);
                    }
                break;

                case 4:
                editarCliente(listaC);
                break;

                case 5:
                removerCliente(listaC);
                break;

                case 6:
                break;

                default:
                printf("Comando nao encontrado\n");
                break;
            }

    }while(selecionarClientes!=6);
}

void menuProdutos(Produtos *listaP)
{
    int selecionarProdutos;
    Produtos *buscaPd;
    do
    {
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto\n");
        printf("4 - Editar produto\n");
        printf("5 - Remover produto\n");
        printf("6 - Retornar ao menu principal\n");
        if (scanf("%d", &selecionarProdutos) != 1)
        {
            printf("Entrada invalida.\n");
            limpaBuffer();
            selecionarProdutos = -1;
            continue;
        }
            switch (selecionarProdutos)
            {
                case 1:
                cadastrarProduto(listaP);
                break;

                case 2:
                listarProduto(listaP);
                break;

                case 3:
                buscaPd = buscarProduto(listaP);
                    if (buscaPd == NULL) 
                    {
                        printf("Codigo nao encontrado\n");
                    } 
                    else 
                    {
                        printf("Codigo encontrado: %s\nnome: %s\npreco: %.2f\nquantidade: %d\n",buscaPd->codigo, buscaPd->nome, buscaPd->preco, buscaPd->quantidade);
                    }
                break;

                case 4:
                editarProduto(listaP);
                break;

                case 5:
                removerProduto(listaP);
                break;

                case 6:
                break;

                default:
                printf("Comando nao encontrado\n");
                break;
            }

    }while(selecionarProdutos!=6);
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

void menuPrincipal(int *i, Clientes *listaC ,Produtos *listaP)
{
    int selecionar;
    printf("Selecione sua opcao:\n");
    printf("1 - Clientes\n");
    printf("2 - Produtos\n");
    printf("3 - Modo Comprador\n");
    printf("4 - Sair.\n");
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
            menuProdutos(listaP);
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