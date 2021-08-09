#include "cliente.h"
#include <stdio.h>
#include "ListaSimplesmenteEncadeada.h"

void imprimirDadosCliente(Cliente* c){
    printf("Nome: %s\n", c->nome);
	printf("ID: %d\n", c->id);
	printf("CPF: %d\n\n", c->cpf);

}

