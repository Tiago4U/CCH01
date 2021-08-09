#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "ListaSimplesmenteEncadeada.h"

//NodoLSE* ListaLSE;
//Cliente *clienteNovo;

NodoLSE* criarLSE(){
    NodoLSE* li;
    li = (NodoLSE*) malloc(sizeof(NodoLSE));
    if(li != NULL)
    {
        li->inicio = NULL;
    }
    return li;
}

Cliente *alocarCliente(){
    Cliente *cliente = (Cliente*)malloc(sizeof(Cliente));
    return cliente;
}

int criarCliente(Cliente* cliente){
    char nome[150];
    int id, cpf;

    printf("Informe o Nome:\n");
    scanf("%s", nome);
    strcpy(cliente->nome, nome);

    printf("Informe o ID:\n");
    scanf("%d", &id);

    printf("Informe o CPF:\n");
    scanf("%d", &cpf);

    cliente->id = id;
    cliente->cpf = cpf;

    return 1;
}

Cliente* buscarCliente(Cliente* cliente, int cpf){
    while(cliente!=NULL){
        if(cliente->cpf == cpf){
            return cliente;
        }
        cliente = cliente->proximo;
    }
    return cliente;
}

int removerCliente(NodoLSE* listaLSE, int cpf) {
    Cliente *cliente = buscarCliente(listaLSE->inicio, cpf);
    if(cliente->cpf != cpf) {
        printf("\nCPF nao encontrado.\n");
        return 0;
    } else {
        if(cliente == listaLSE->inicio) {
            listaLSE->inicio = cliente->proximo;
            cliente = NULL;
            return 1;
        }
        Cliente *inicio = listaLSE->inicio;

        while(inicio!=NULL) {
            if(inicio->proximo == cliente) {
                inicio->proximo = cliente->proximo;
                cliente = NULL;
                listaLSE->tamanho--;
                return 1;
            }
            inicio = inicio->proximo;
        }
        return 0;
    }

}

void imprimirDadosCliente(Cliente* c){
    printf("Nome: %s\n", c->nome);
	printf("ID: %d\n", c->id);
	printf("CPF: %d\n\n", c->cpf);
}

int inserirInicio(NodoLSE* listaLSE, Cliente* cliente) {
    cliente->proximo = listaLSE->inicio;
    listaLSE->inicio = cliente;
    listaLSE->tamanho++;
    return 1;
}

int inserirFinal(NodoLSE* listaLSE, Cliente* cliente) {
    Cliente* clienteAux = alocarCliente();
    cliente->proximo = NULL;
    if(listaLSE->inicio == NULL) {
        listaLSE->inicio = cliente;
    } else {
        clienteAux = listaLSE->inicio;
        while(clienteAux->proximo!=NULL) {
            clienteAux = clienteAux->proximo;
        }
        clienteAux->proximo = cliente;
    }
    listaLSE->tamanho++;
    return 1;
}

void buscarClienteCPF(NodoLSE* listaLSE, int cpf){
    Cliente *cliente = buscarCliente(listaLSE->inicio, cpf);
    if(cliente!=NULL){
        imprimirDadosCliente(cliente);
    }
}

void imprimirTamanho(NodoLSE* listaLSE){
    int tamanho=1;
    Cliente* clienteAux = alocarCliente();
    clienteAux = listaLSE->inicio;

    while(clienteAux->proximo!=NULL){
        clienteAux = clienteAux->proximo;
        tamanho++;
    }
    printf("Tamanho: %d\n", tamanho);
}

/*
int inserirCliente(NodoLSE* listaLSE, int posicao){
	//TODO: verificar se lista cheia
	if(listaLSE == NULL){
        printf("A lista de clientes esta cheia. ");
		return 0;
	}

    Cliente *clienteNovo = (Cliente*)malloc(sizeof(Cliente));
    criarCliente(clienteNovo);

	//para informar a posicao utilizamos -1 para inserir no final, 0 para inserir no inicio e demais valores para posicao
	//Inserir na ultima posicao
	if(posicao == -1 ){
        // inserir no final da lista
        Cliente *nodo = (Cliente*)malloc(sizeof(Cliente));
        clienteNovo->proximo = NULL;

        if(listaLSE->inicio == NULL){
            listaLSE->inicio = clienteNovo;
        } else {
            nodo = listaLSE->inicio;
            while(nodo->proximo != NULL){
                nodo = nodo->proximo;
            }
            nodo->proximo = clienteNovo;
        }
        printf("Cliente inserido na posicao: %d", listaLSE->tamanho);
        listaLSE->tamanho++;

        return 1;

	}else if(posicao == 1){
	    // inserir no inicio da lista
        clienteNovo->proximo = listaLSE->inicio;
        listaLSE->inicio = clienteNovo;
        printf("Cliente inserido na posicao: %d", listaLSE->tamanho);
        listaLSE->tamanho++;

        return 1;

	}else{
        int count=1;
	    Cliente* clienteAnterior;
	    Cliente* clienteInicial;

        clienteInicial = listaLSE->inicio;
        while(clienteInicial!=NULL) {
            if(count == posicao) {
                clienteAnterior->proximo = clienteNovo;
                clienteNovo->proximo = clienteInicial;
                printf("Cliente inserido na posicao: %d", listaLSE->tamanho);
                listaLSE->tamanho++;
                return 1;
            }
            count++;
            clienteAnterior = clienteInicial;
            clienteInicial = clienteInicial->proximo;
        }
    }

        return 0;
}
*/

/*
void removerLSE(LSE* lista, int cpf)
{
    if(lista != NULL){
        NodoLSE* auxAnterior;
        NodoLSE* aux = lista->inicio;
        while(aux != NULL && aux->cliente.cpf != cpf){
            auxAnterior = aux;
            aux = aux->proximo;
        }
        if(aux == NULL){
            printf("Erro: Cliente nao encontrado\n");
        }
        if(aux == lista->inicio){
            //printf("remover o primeiro\n");
            lista->inicio = aux->proximo;
        }
        else{
            auxAnterior->proximo = aux->proximo;
        }
        free(aux);
    }
    else{
        printf("Erro: Lista nao inicializada\n");
    }
}*/


void imprimirDadosLSE(NodoLSE* lista){
    Cliente* clienteAux = lista->inicio;
    while(clienteAux!=NULL){
        imprimirDadosCliente(clienteAux);
        clienteAux = clienteAux->proximo;
    }
}

