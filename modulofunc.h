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
Clientes * buscarCliente(Clientes *listaC);
void menuClientes(Clientes *listaC);
void editarCliente(Clientes *listaC);
void removerCliente(Clientes *listaC);

Produtos * criarlistaProdutos();
void cadastrarProduto(Produtos *listaP);
void ListarProduto(Produtos *listaP);
Produtos * buscarProduto(Produtos *listaP);
void editarProduto(Produtos *listaP);
void removerProduto(Produtos *listaP);
void menuProdutos(Produtos *listaP);

void modoComprador();
void menuPrincipal(int *i,Clientes *listaC , Produtos *listaP);

#endif