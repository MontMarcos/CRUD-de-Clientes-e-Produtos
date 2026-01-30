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
void menuClientes(Clientes *listaC);
void menuProdutos();
void modoComprador();
void menuPrincipal(int *i);

#endif