#include "modulofunc.h"

int main()
{
    Clientes *listaC = criarlistaClientes();
    Produtos *listaP = criarlistaProdutos();
<<<<<<< Updated upstream
    Carrinho *carrinhoC = criarCarrinho();
=======
>>>>>>> Stashed changes
    int i=0;
    while(i==0) menuPrincipal(&i,carrinhoC, listaC, listaP);
    // liberar toda a memoria free, criar funcoes liberaClientes, funcao liberaProdutos e (liberaCarrinho?)
    return 0;
}
