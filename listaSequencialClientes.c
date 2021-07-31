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
int inserirCliente(ListaSequencialClientes* lista, Cliente cliente, int posicao){
	//TODO: verificar se lista cheia
	if(lista == NULL){
		return 0;
	}

	//para informar a posicao utilizamos -1 para inserir no final, 0 para inserir no inicio e demais valores para posicao
	//Inserir na ultima posicao

	if(posicao == -1 ){
        printf("Inserindo cliente na posicao: %d\n", lista->index);
        lista->dados[lista->index] = cliente;
        lista->index++;
        return 1;
	}
	//Inserir no inicio
	else if(posicao == 0){
	    printf("Inserindo cliente na posicao: 0\n");

        for(int i=lista->index; i>-1; i--){
            lista->dados[i+1] = lista->dados[i];
            //printf("posicao %d recebe dados da posicao %d\n", i+1, i);
        }

        lista->dados[0] = cliente;
        lista->index++;
        return 1;
	}else{
        printf("Inserindo cliente na posicao: %d\n", posicao);

        for(int i=lista->index; i>=posicao; i--){
            lista->dados[i+1] = lista->dados[i];
            //printf("posicao %d recebe dados da posicao %d\n", i+1, i);
        }

        lista->dados[posicao] = cliente;
        lista->index++;
        return 1;
	}


}

//Busca usuario na lista
int buscarClientePorCpf(ListaSequencialClientes* lista, Cliente* clienteRetornado){
	int cpf;
	printf("Informe o CPF do cliente\n");
	scanf("%d", &cpf);

	int i;
	for(i=0; i<lista->index; i++){
		if(lista->dados[i].cpf == cpf){
            *clienteRetornado = lista->dados[i];
			return 1;
		}
	}
	return 0;
}
