#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "listaEncadeadaDeClientes.h"

int main()
{
    Cliente c1;
	strcpy(c1.nome, "Joao");
	c1.id = 1;
	c1.cpf = 123;

	Cliente c2;
	strcpy(c2.nome, "Maria");
	c2.id = 2;
	c2.cpf = 345;

	ListaEncadeadaDeClientes* lista;
	lista = criarListaEncadeada();

	inserirInicio(lista, c1);
	inserirInicio(lista, c2);
	imprimirDadosDaLista(lista);

    //implementar menu para;
    //criação e cadastro de clientes(final e inicio da lista);
    //localizar e imprimir um cliente
    //remover um cliente
    //imprimir todos os clientes da lista
    //opcao de sair

    return 0;
}
