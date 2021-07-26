#include "listaSequencialClientes.h"
#include <stdio.h>
#include <stdlib.h>

//Impressao de dados por usuario
void imprimirDadosCliente(Cliente* cliente){
	printf("Nome: %s\n", cliente->nome);
	printf("ID: %d\n", cliente->id);
	printf("CPF: %d\n", cliente->cpf);
}

//Criar lista de usuarios
ListaSequencialClientes* criarLista(){
	ListaSequencialClientes* lista;
	lista = (ListaSequencialClientes*) malloc(sizeof(Cliente));
	if(lista != NULL){
		lista->index=0;
	}
	return lista;
}

//Inserir cliente a lista de usuario
int inserirCliente(ListaSequencialClientes* lista, Cliente cliente){
	//TODO: verificar se lista cheia
	if(lista == NULL){
		return 0;
	}
	printf("Inserindo cliente na posicao: %d\n", lista->index);
	lista->dados[lista->index] = cliente;
	lista->index++;
	return 1;
}

//Busca usuario na lista
int buscarClientePorCpf(ListaSequencialClientes* lista, int cpf, Cliente* clienteRetornado){
	printf("Procurando cliente com CPF: %d\n", cpf);
	int i;
	for(i=0; i<lista->index; i++){
		if(lista->dados[i].cpf == cpf){
			*clienteRetornado = lista->dados[i];
			return 1;
		}
	}
	return 0;
}

