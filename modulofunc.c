#include "modulofunc.h"


//funcoes inicio 

void liberarMemoriaCarrinho(Carrinhos *carrinhoC)
{

    if (carrinhoC == NULL) return;

    ProdutosCarrinho *item = carrinhoC->items;

    while (item != NULL)
    {
        ProdutosCarrinho *aux = item;
        item = item->prox;
        free(aux);
    }

    free(carrinhoC);
};

void liberarMemoriaClientes(Clientes *listaC)
{
    Clientes *atual = listaC->prox;
    while(atual!=NULL)
    {
        Clientes *aux = atual;
        atual=atual->prox;
        liberarMemoriaCarrinho(aux->carrinhoC);
        free(aux->nome);
        free(aux);
    }

    free(listaC);
};


void liberarMemoriaProdutos(Produtos *listaP)
{
    Produtos *atual = listaP->prox;

    while(atual!=NULL)
    {
        Produtos *aux = atual;
        atual=atual->prox;
        free(aux->nome);
        free(aux);
    }
    free(listaP);
};





void limpaBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    // void que limpa o buffer inteiro caso algo que nao seja um int seja a entrada do menu
    // usar sempre que depois do scanf quando for entrada para os menus.
}

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void nomeDinamicoCliente(Clientes *novo)
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
};

void nomeDinamicoProduto(Produtos *novo)
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
};

Carrinhos * criarCarrinho()
{
    Carrinhos *carrinhoC;
    carrinhoC = malloc(sizeof(Carrinhos));
    if(carrinhoC==NULL) return NULL;
    carrinhoC->items=NULL;

    return carrinhoC;
};

Clientes * criarlistaClientes()
{
    Clientes *listaC;
    listaC = malloc(sizeof(Clientes));
    if(listaC==NULL) return NULL;
    listaC->prox=NULL;
    listaC->carrinhoC=NULL;

    return listaC;
};

Produtos * criarlistaProdutos()
{
    Produtos *listaP;
    listaP = malloc(sizeof(Produtos));
    if(listaP==NULL) return NULL;
    listaP->prox=NULL;

    return listaP;
};

//funções do cliente

void cadastrarCliente(Clientes *listaC)
{
    Clientes *novo;
    novo = malloc(sizeof(Clientes));
    novo->carrinhoC=NULL;
    printf("Insira os dados do cliente a ser cadastrado:\n");

    int j = 0;
    do
    {
        if(j == 1)
        {
            printf("cpf invalido (menos de 11 digitos)\n");
        }
        j = 0;
        limpaBuffer();
        printf("digite o Cpf: ");
        if(scanf(" %11[0-9]", novo->cpf) != 1)
        {
        printf("CPF invalido\n");
            novo->cpf[0] = '\0';
            continue;
        }
        limpaBuffer();
        j++;
    } while(strlen(novo->cpf) != 11);

    printf("digite o Nome: ");
    nomeDinamicoCliente(novo);
    if(novo->nome == NULL)
    {
            printf("Erro ao ler nome\n");
            free(novo);
            return;
    }
        
    int telefoneValido = 0;
    do
    {
        printf("Digite o telefone (11 numeros): ");
        scanf("%s", novo->telefone);
        limpaBuffer(); 

        int erro = 0;

        if (strlen(novo->telefone) != 11)
        {
            erro = 1;
        }
        else
        {
            for (int i = 0; i < 11; i++)
            {
                if (novo->telefone[i] < '0' || novo->telefone[i] > '9')
                {
                    erro = 1;
                    break;
                }
            }
        }

        if (erro)
        {
            printf("Ocorreu um erro no telefone.\n");
        }
        else
        {
            telefoneValido = 1;
        }

    } while (!telefoneValido);

    novo->prox = listaC->prox;
    listaC->prox = novo;
};

void ListarCliente(Clientes *listaC)
{
    Clientes *imprime;
    int i;

    printf("\n");
    if(listaC->prox == NULL)
    {
        printf("Nenhum cliente cadastrado\n\n");
        return;
    }
    for (imprime=listaC->prox,i = 1;imprime!=NULL;imprime = imprime->prox, i++)
    {
        printf("%d - Cliente: %s - Cpf: %s - Telefone: %s\n",i, imprime->nome, imprime->cpf, imprime->telefone);
    }
    printf("\n");
    return;
};

Clientes * buscarCliente(Clientes *listaC, int k)
{
    if(listaC->prox == NULL)
    {
        printf("Nenhum cliente cadastrado\n");
        return NULL;
    }

        Clientes *busca;
        char buscador[12];

        if (k == 0) printf("Digite o cpf do cliente a ser buscado: ");
        scanf("%11s", buscador);
        limpaBuffer();
        
        busca = listaC->prox;

    while (busca != NULL && strcmp(buscador, busca->cpf) != 0) {
        busca = busca->prox;
    }

    return busca;
}

void editarCliente(Clientes *listaC)
{
    if(listaC->prox == NULL)
    {
        printf("Nenhum cliente cadastrado\n");
        return;
    }
    Clientes *atual = buscarCliente(listaC,0);

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
        nomeDinamicoCliente(atual);
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
    if(listaC->prox == NULL)
    {
        printf("Nenhum cliente cadastrado\n");
        return;
    }
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
        liberarMemoriaCarrinho(atual->carrinhoC);
        free(atual);
        printf("Cliente removido com sucesso\n");
    }
}

//funcoes do produto

void cadastrarProduto(Produtos *listaP)
{
    Produtos *novo;
    novo = malloc(sizeof(Produtos));

    limpaBuffer();
    
    printf("digite o nome do produto:");
    nomeDinamicoProduto(novo);

    printf("digite o codigo do produto:");
    if(scanf("%19s", novo->codigo)!=1)
    {
        printf("Codigo invalido\n");
        free(novo);
        return;
    }
    do 
    {
        limpaBuffer();
        printf("digite o preco do produto:");
        if (scanf("%f", &novo->preco)!=1)
        {
            novo->preco=-1;
            continue;
        }

    }while(novo->preco==-1);   

    do 
    {
        limpaBuffer();
        printf("digite a quantidade do produto:");
        if (scanf("%d", &novo->quantidade)!=1)
        {
            novo->quantidade=-1;
            continue;
        }
    }while(novo->quantidade==-1); 

    novo->prox=listaP->prox;
    listaP->prox=novo;
}

void listarProduto(Produtos *listaP)
{
    Produtos *imprime;
    if(listaP->prox == NULL)
    {
        printf("Nenhum produto cadastrado\n\n");
        return;
    }
    int i;
    printf("\n");
    for (imprime=listaP->prox,i = 1;imprime!=NULL;imprime = imprime->prox, i++)
    {
        printf("%d - Produto: %s - codigo: %s - preco: %.2f - quantidade: %d\n",i, imprime->nome, imprime->codigo, imprime->preco, imprime->quantidade);
    }
    printf("\n");
    return;
}

Produtos * buscarProduto(Produtos *listaP, int k)
{
    if(listaP->prox == NULL)
    {
        printf("Nenhum produto cadastrado\n");
        return NULL;
    }
    Produtos *busca;
    char buscador[20];

    if (k == 0) printf("Digite o codigo do produto a ser buscado: ");
    scanf("%19s", buscador);
    limpaBuffer();

    busca = listaP->prox;

    while (busca != NULL && strcmp(buscador, busca->codigo) != 0) {
        busca = busca->prox;
    }
    return busca;
}

void editarProduto(Produtos *listaP)
{
    if(listaP->prox == NULL)
    {
        printf("Nenhum produto cadastrado\n");
        return;
    }
    Produtos *novo = buscarProduto(listaP, 0);
    if (novo == NULL) {
        printf("Codigo nao encontrado\n");
    } 
    else 
    {

        limpaBuffer();
    
        printf("digite o novo nome do produto:");
        nomeDinamicoProduto(novo);

        printf("digite o novo codigo do produto:");
        if(scanf("%19s", novo->codigo)!=1)
        {
            printf("Codigo invalido\n");
            return;
        }
        do 
        {
            limpaBuffer();
            printf("digite o novo preco do produto:");
            if (scanf("%f", &novo->preco)!=1)
            {
                novo->preco=-1;
                continue;
            }

        }while(novo->preco==-1);   

        do 
        {
            limpaBuffer();
            printf("digite a nova quantidade do produto:");
            if (scanf("%d", &novo->quantidade)!=1)
            {
                novo->quantidade=-1;
                continue;
            }

        }while(novo->quantidade==-1); 
    }
}

void removerProduto(Produtos *listaP)
{
    if(listaP->prox == NULL)
    {
        printf("Nenhum produto cadastrado\n");
        return;
    }
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

//funcoes do carrinho

void adicionarProdutoCarrinho(Clientes *listaC, Produtos *listaP)
{
    if(listaC->prox == NULL)
    {
        printf("Nenhum cliente cadastrado\n");
        return;
    }
    ListarCliente(listaC);
    printf("Digite o cpf do cliente associado ao carrinho:");
    Clientes *cliente = buscarCliente(listaC, 1);
    if (cliente == NULL)
    {
        printf("Cliente nao encontrado\n");
        return;
    }
    listarProduto(listaP);
    printf("Digite o codigo do produto a ser adicionado:");
    Produtos *produto = buscarProduto(listaP, 1);
    if (produto == NULL)
    {
        printf("Produto nao encontrado\n");
        return;
    }

    int quantidade;
    do
    {
        printf("Digite a quantidade: ");
        if (scanf("%d", &quantidade) != 1)
        {
            limpaBuffer();
            quantidade = -1;
            continue;
        }
        if (quantidade <= 0)
        {
            printf("Quantidade deve ser positiva\n");
            quantidade = -1;
        }
        else if (quantidade > produto->quantidade)
        {
            printf("Estoque insuficiente. Disponivel: %d\n", produto->quantidade);
            quantidade = -1;
        }
    } while (quantidade == -1);


    if (cliente->carrinhoC == NULL)
    {
        cliente->carrinhoC = criarCarrinho();
        if (cliente->carrinhoC == NULL)
        {
            printf("Erro ao criar carrinho\n");
            return;
        }
    }

    

    ProdutosCarrinho *item = cliente->carrinhoC->items;

    while (item != NULL)
    {
        if (strcmp(item->produto->codigo, produto->codigo) == 0)
        {
            item->quantidade += quantidade;
            produto->quantidade -= quantidade;
            printf("Quantidade atualizada no carrinho\n");
            return;
        }
        item = item->prox;
    }


    ProdutosCarrinho *novoItem = malloc(sizeof(ProdutosCarrinho));
    if (novoItem == NULL)
    {
        printf("Erro de alocacao\n");
        return;
    }
    novoItem->produto = produto;
    novoItem->quantidade = quantidade;
    novoItem->prox = cliente->carrinhoC->items;
    cliente->carrinhoC->items = novoItem;

    produto->quantidade -= quantidade;
    printf("Produto adicionado ao carrinho\n");
}

void listarCarrinhoCliente(Clientes *listaC)
{
    
    if(listaC->prox == NULL)
    {
        printf("Nenhum cliente cadastrado\n");
        return;
    }

    ListarCliente(listaC);
    printf("Digite o cpf do cliente associado ao carrinho:");
    Clientes *cliente = buscarCliente(listaC, 1);
    if (cliente == NULL)
    {
        printf("Cliente nao encontrado\n");
        return;
    }

    if (cliente->carrinhoC == NULL || cliente->carrinhoC->items == NULL)
    {
        printf("Carrinho vazio\n");
        return;
    }

    ProdutosCarrinho *item = cliente->carrinhoC->items;
    float valorTotal = 0;
    int qtdItens = 0;

    printf("\n--- Carrinho de %s ---\n", cliente->nome);
    while (item != NULL)
    {
        float subtotal = item->quantidade * item->produto->preco;
        printf("Produto: %s | Qtd: %d | Preco Unit: %.2f | Subtotal: %.2f\n",
               item->produto->nome, item->quantidade, item->produto->preco, subtotal);
        valorTotal += subtotal;
        qtdItens += item->quantidade;
        item = item->prox;
    }
    printf("----------------------------\n");
    printf("Total de Itens: %d\n", qtdItens);
    printf("Valor Total da Compra: %.2f\n", valorTotal);
}

void removerProdutoCarrinho(Clientes *listaC)
{
    if(listaC->prox == NULL)
    {
        printf("Nenhum cliente cadastrado\n");
        return;
    }
    Clientes *cliente = buscarCliente(listaC, 0);
    if (cliente == NULL)
    {
        printf("Cliente nao encontrado\n");
        return;
    }

    if (cliente->carrinhoC == NULL || cliente->carrinhoC->items == NULL)
    {
        printf("Carrinho vazio\n");
        return;
    }

    char codigo[20];
    printf("Digite o codigo do produto a ser removido:");
    scanf("%19s", codigo);

    ProdutosCarrinho *atual = cliente->carrinhoC->items;
    ProdutosCarrinho *anterior = NULL;

    while (atual != NULL)
    {
        if (strcmp(atual->produto->codigo, codigo) == 0)
        {
            atual->produto->quantidade += atual->quantidade;

            if (anterior == NULL)
            {
                cliente->carrinhoC->items = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Produto removido do carrinho\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Produto nao encontrado no carrinho\n");
}


//funcoes do menu

void menuClientes(Clientes *listaC)
{
    int selecionarClientes;
    Clientes *buscaCl;
    
    limparTela(); 

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
            limpaBuffer();
            selecionarClientes = -1;
            continue;
        }

        switch (selecionarClientes)
        {
            case 1:
                limparTela();
                cadastrarCliente(listaC);
                break;

            case 2:
                limparTela();
                ListarCliente(listaC);
                break;

            case 3:
                limparTela();
                if (listaC->prox == NULL) {
                    printf("Nenhum cliente cadastrado\n");
                }
                else {
                    buscaCl = buscarCliente(listaC, 0); 
                    
                    if (buscaCl == NULL) 
                    {
                        printf("Cpf nao encontrado\n");
                    } 
                    else 
                    {
                        printf("CPF encontrado: %s\nNome: %s\nTelefone: %s\n", buscaCl->cpf, buscaCl->nome, buscaCl->telefone);
                    }
                }
                break;

            case 4:
                limparTela();
                editarCliente(listaC);
                break;

            case 5:
                limparTela();
                removerCliente(listaC);
                break;

            case 6:
                limparTela();
                break;

            default:
                printf("Comando nao encontrado\n");
                break;
        }

    } while(selecionarClientes != 6);
}

void menuProdutos(Produtos *listaP)
{
    int selecionarProdutos;
    Produtos *buscaPd;
    
    limparTela();

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
            limpaBuffer();
            selecionarProdutos = -1;
            continue;
        }

        switch (selecionarProdutos)
        {
            case 1:
                limparTela();
                cadastrarProduto(listaP);
                break;

            case 2:
                limparTela();
                listarProduto(listaP);
                break;

            case 3:
                limparTela();
                if (listaP->prox == NULL) 
                {
                    printf("Nenhum produto cadastrado\n");
                } 
                else 
                {
                    buscaPd = buscarProduto(listaP, 0);
                    
                    if (buscaPd == NULL) 
                    {
                        printf("Codigo nao encontrado\n");
                    } 
                    else 
                    {
                        printf("Codigo encontrado: %s\nNome: %s\nPreco: %.2f\nQuantidade: %d\n", 
                            buscaPd->codigo, buscaPd->nome, buscaPd->preco, buscaPd->quantidade);
                    }
                }
                break;

            case 4:
                limparTela();
                editarProduto(listaP);
                break;

            case 5:
                limparTela();
                removerProduto(listaP);
                break;

            case 6:
                limparTela();
                break;

            default:
                printf("Comando nao encontrado\n");
                break;
        }

    } while(selecionarProdutos != 6);
}

void modoComprador(Clientes *listaC, Produtos *listaP)
{
    int selecionarCompras;
    
    limparTela();

    do
    {
        printf("1 - Adicionar produto ao carrinho\n");
        printf("2 - Listar produtos no carrinho\n");
        printf("3 - Remover produtos do carrinho\n");
        printf("4 - Retornar ao menu principal\n");
        
        if (scanf("%d", &selecionarCompras) != 1)
        {
            limpaBuffer();
            selecionarCompras = -1;
            continue;
        }

        switch (selecionarCompras)
        {
            case 1:
                limparTela();
                adicionarProdutoCarrinho(listaC, listaP);
                break;

            case 2:
                limparTela();
                listarCarrinhoCliente(listaC);
                break;

            case 3:
                limparTela();
                removerProdutoCarrinho(listaC);
                break;

            case 4:
                limparTela();
                break;

            default:
                printf("Comando nao encontrado\n");
                break;
        }

    } while(selecionarCompras != 4);
}

void menuPrincipal(int *i, Clientes *listaC, Produtos *listaP)
{
    int selecionar;
    
    limparTela();

    printf("Selecione sua opcao:\n");
    printf("1 - Clientes\n");
    printf("2 - Produtos\n");
    printf("3 - Modo Compras\n");
    printf("4 - Sair.\n");
    
    if (scanf("%d", &selecionar) != 1)
    {
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
            modoComprador(listaC, listaP);
            break;

        case 4:
            limparTela();
            printf("Saindo do menu\n");
            *i = 1;
            return;

        default:
            printf("Comando nao encontrado\n");
            break;
    }
}

//funcoes final