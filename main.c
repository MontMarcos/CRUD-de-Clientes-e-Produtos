
#include "modulofunc.h"

int main()
{
    Clientes *listaC = criarlistaClientes();
    Produtos *listaP = criarlistaProdutos();
    int i=0;
    while(i==0) menuPrincipal(&i, listaC, listaP);
    // liberar toda a memoria free, criar funcoes liberaClientes, funcao liberaProdutos e (liberaCarrinho?)
    return 0;
}
