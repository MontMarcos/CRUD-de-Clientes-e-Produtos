
#include "modulofunc.h"

int main()
{
    Clientes *listaC = criarlistaClientes();
    Produtos *listaP = criarlistaProdutos();
    int i=0;
    while(i==0) menuPrincipal(&i, listaC, listaP);
    liberarMemoriaClientes(listaC);
    liberarMemoriaProdutos(listaP);
    return 0;
}