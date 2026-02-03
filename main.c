
#include "modulofunc.h"

int main()
{
    Clientes *listaC = criarlistaClientes();
    Produtos *listaP = criarlistaProdutos();
    Carrinhos *listaCar = criarlistaCarrinhos();
    int i=0;
    while(i==0) menuPrincipal(&i,listaCar, listaC, listaP);
    // liberar toda a memoria free, criar funcoes liberaClientes, funcao liberaProdutos e (liberaCarrinho?)
    return 0;
}