#ifndef crudstruct
#define crudstruct

#include <stdlib.h>

typedef struct clientes
{
    char cpf[12];
    char telefone[100];
    char *nome;
    struct clientes *prox;
}Clientes;

#endif