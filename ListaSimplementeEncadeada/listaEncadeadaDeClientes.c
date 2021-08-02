#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"
#include "listaEncadeadaDeClientes.h"

ListaEncadeadaDeClientes* criarListaEncadeada(){
    ListaEncadeadaDeClientes* li;
    li = (ListaEncadeadaDeClientes*) malloc(sizeof(ListaEncadeadaDeClientes));
    if(li != NULL)
    {
        li->inicio = NULL;
    }
    return li;
}

void inserirInicio(ListaEncadeadaDeClientes* lista, Cliente c){
   No* novo = (No*)malloc(sizeof(No));
   novo->cliente = c;
   novo->proximo = lista->inicio;
   lista->inicio = novo;
}


void inserirFinal(ListaEncadeadaDeClientes* lista, Cliente c){
    //implementar;
}

int buscarCliente(ListaEncadeadaDeClientes* lista, int cpf, Cliente* clienteEncontrado){
    //implementar
    return 0;
}

void removerCliente(ListaEncadeadaDeClientes* lista, int cpf){
    //implementar
}
void imprimirDadosDaLista(ListaEncadeadaDeClientes* lista){
    No* aux = lista->inicio;
    while(aux!=NULL){
        imprimirDadosCliente(&aux->cliente);
        aux = aux->proximo;
    }
    printf("\n\n");

}
