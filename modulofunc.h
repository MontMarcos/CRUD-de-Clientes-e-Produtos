#ifndef crudfunc
#define crudfunc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "modulostruct.h"

void limpaBuffer();
void nomeDinamico(Clientes *novo);

Clientes * criarlistaClientes();
void cadastrarCliente(Clientes *listaC);
void ListarCliente(Clientes *listaC);
Clientes * buscarCliente(Clientes *listaC, int k);
void menuClientes(Clientes *listaC);
void editarCliente(Clientes *listaC);
void removerCliente(Clientes *listaC);

Produtos * criarlistaProdutos();
void cadastrarProduto(Produtos *listaP);
void listarProduto(Produtos *listaP);
Produtos * buscarProduto(Produtos *listaP);
void editarProduto(Produtos *listaP);
void removerProduto(Produtos *listaP);
void menuProdutos(Produtos *listaP);

<<<<<<< Updated upstream
Carrinho * criarCarrinho();
void cadastrarCarrinho(Carrinho *carrinhoC, Clientes *listaC);
void modoComprador(Carrinho *carrinhoC, Clientes *listaC, Produtos *listaP);

void menuPrincipal(int *i,Carrinho *carrinhoC,Clientes *listaC , Produtos *listaP);
=======
void modoComprador(Produtos *listaP, Clientes *listaC);
void incluirProdutoCarrinho(Produtos *listaP, Clientes *listaC);
void listarProdutosCarrinho(Produtos *listaP, Clientes *listaC);
void retirarProdutoCarrinho(Produtos *listaP, Clientes *listaC);
void menuPrincipal(int *i);
>>>>>>> Stashed changes

#endif