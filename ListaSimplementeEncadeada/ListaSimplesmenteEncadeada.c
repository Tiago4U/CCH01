#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "ListaSimplesmenteEncadeada.h"

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
    if(cliente == NULL){
        return 0;
    }

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

void imprimirDadosLSE(NodoLSE* lista){
    Cliente* clienteAux = lista->inicio;
    while(clienteAux!=NULL){
        imprimirDadosCliente(clienteAux);
        clienteAux = clienteAux->proximo;
    }
}

