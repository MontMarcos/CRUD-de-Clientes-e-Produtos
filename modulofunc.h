#ifndef crudfunc
#define crudfunc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "modulostruct.h"

void limpaBuffer();

void nomeDinamicoCliente(Clientes *novo);
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
void nomeDinamicoProdutos(Produtos *novo);

Carrinhos * criarlistaCarrinhos();
void cadastrarCarrinho(Carrinhos *listaCar, Clientes *listaC);
void modoComprador(Carrinhos *listaCar, Clientes *listaC, Produtos *listaP);

void menuPrincipal(int *i,Carrinhos *listaCar,Clientes *listaC , Produtos *listaP);

#endif