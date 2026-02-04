#ifndef crudfunc
#define crudfunc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "modulostruct.h"

void limpaBuffer();
void limparTela();

void liberarMemoriaCarrinho(Carrinhos *carrinhoC);
void liberarMemoriaClientes(Clientes *listaC);
void liberarMemoriaProdutos(Produtos *listaP);
void nomeDinamicoCliente(Clientes *novo);
Clientes * criarlistaClientes();
void removerProdutoCarrinhos(Clientes *listaC, Produtos *atual);
void cadastrarCliente(Clientes *listaC);
void ListarCliente(Clientes *listaC);
Clientes * buscarCliente(Clientes *listaC, int k);
void menuClientes(Clientes *listaC);
void editarCliente(Clientes *listaC);
void removerCliente(Clientes *listaC);

Produtos * criarlistaProdutos();
void cadastrarProduto(Produtos *listaP);
void listarProduto(Produtos *listaP);
Produtos * buscarProduto(Produtos *listaP, int k);
void editarProduto(Produtos *listaP);
void removerProduto(Produtos *listaP, Clientes *listaC);
void menuProdutos(Produtos *listaP, Clientes *listaC);
void nomeDinamicoProduto(Produtos *novo);

Carrinhos * criarCarrinho();
void adicionarProdutoCarrinho(Clientes *listaC, Produtos *listaP);
void listarCarrinhoCliente(Clientes *listaC);
void removerProdutoCarrinho(Clientes *listaC, Produtos *listaP);
void modoComprador(Clientes *listaC, Produtos *listaP);

void menuPrincipal(int *i,Clientes *listaC , Produtos *listaP);

#endif