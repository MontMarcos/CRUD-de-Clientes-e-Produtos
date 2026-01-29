#ifndef crud
#define crud

//structs inicio

struct Pessoas
{
    char cpf[14];
    char telefone[14];
    char *nome;
};

void menuClientes();
void menuProdutos();
void modoComprador();
void menuPrincipal(int *i);

#endif