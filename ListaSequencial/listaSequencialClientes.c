#include "listaSequencialClientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cliente clienteNovo;

//Impressao de dados por usuario
void imprimirDadosCliente(Cliente* cliente){
	printf("ID: %d\n", cliente->id);
	printf("Nome: %s\n", cliente->nome);
	printf("CPF: %d\n", cliente->cpf);
}

int criarCliente(Cliente* cliente){
    char nome[150];
    printf("Informe o Nome:\n");
    scanf("%s", nome);
    strcpy(cliente->nome, nome);

    printf("Informe o ID:\n");
    scanf("%d", &cliente->id);

    printf("Informe o CPF:\n");
    scanf("%d", &cliente->cpf);

    return 1;
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
int inserirCliente(ListaSequencialClientes* lista, int posicao){
	//TODO: verificar se lista cheia
	if(lista == NULL){
        printf("A lista de clientes esta cheia. ");
		return 0;
	}

    criarCliente(&clienteNovo);

	//para informar a posicao utilizamos -1 para inserir no final, 0 para inserir no inicio e demais valores para posicao
	//Inserir na ultima posicao
	if(posicao == -1 ){
        printf("Inserindo cliente na posicao: %d\n", lista->index);
        lista->dados[lista->index] = clienteNovo;
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

        lista->dados[0] = clienteNovo;
        lista->index++;
        return 1;
	}else{
        printf("Inserindo cliente na posicao: %d\n", posicao);

        for(int i=lista->index; i>=posicao; i--){
            lista->dados[i+1] = lista->dados[i];
            //printf("posicao %d recebe dados da posicao %d\n", i+1, i);
        }

        lista->dados[posicao] = clienteNovo;
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

//Remover dados cliente
int removerDadosCliente(ListaSequencialClientes* lista){
	int cpf, position=0;
	printf("Informe o CPF do cliente\n");
	scanf("%d", &cpf);


	for(int i=0; i<lista->index; i++){
		if(lista->dados[i].cpf == cpf){
           position = i;
		}
	}

    if(position=0){
        return 0;
    }

    for(int i=position; i<=lista->index; i++){
        lista->dados[i] = lista->dados[i+1];
    }

    lista->index--;
    return 1;
}

int buscarPosicaoCliente(ListaSequencialClientes* lista){
	int position=0;
	printf("Informe a posicao do cliente: \n");
	scanf("%d", &position);

    if(lista->index-1 < position){
        return 0;
    }

    imprimirDadosCliente(&lista->dados[position]);
    return 1;
}

int alterarCliente(ListaSequencialClientes* lista){
	int position=0;
	printf("Informe a posicao do cliente: \n");
	scanf("%d", &position);

    if(lista->index-1 < position){
        return 0;
    }

    if(&lista->dados[position] != NULL){
        char nome[150];
        printf("Informe o novo Nome:\n");
        scanf("%s", nome);
        strcpy(lista->dados[position].nome, nome);

        printf("Informe o novo ID:\n");
        scanf("%d", &lista->dados[position].id);

        printf("Informe o novo CPF:\n");
        scanf("%d", &lista->dados[position].cpf);
    }else{
        return 0;
    }
    return 1;
}


