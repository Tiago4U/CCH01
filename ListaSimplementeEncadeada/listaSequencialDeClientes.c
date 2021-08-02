#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"
#include "listaSequencialDeClientes.h"

ListaSequencialDeClientes* criarLista()
{
    ListaSequencialDeClientes* li;
    li = (ListaSequencialDeClientes*) malloc(sizeof(ListaSequencialDeClientes));
    if(li != NULL)
    {
        li->index = 0;
    }
    return li;
}


void liberarListaSequencialDeClientes(ListaSequencialDeClientes* li)
{
    free(li);
}

int inserirClienteFinalLista(ListaSequencialDeClientes* lista, Cliente cliente)
{
    if(lista == NULL)
    {
        return 0;
    }
    lista->dados[lista->index] = cliente;
    lista->index++;
    return 1;
    //controlar se lista cheia!

}

int consultarClientePosicao(ListaSequencialDeClientes* lista, int pos, Cliente* clienteRetornado)
{
    printf("Procurando cliente na posicao: %d\n", pos);
    if(lista == NULL || pos <= 0 || pos > lista->index)
    {
        return 0;
    }
    *clienteRetornado = lista->dados[pos-1];
    return 1;
}

int consultarClientePorCpf(ListaSequencialDeClientes* lista, int cpf, Cliente* clienteRetornado)
{
    printf("Procurando cliente pelo CPF: %d\n", cpf);
    for(int i=0; i<=lista->index; i++)
    {
        if(lista->dados[i].cpf == cpf)
        {
            *clienteRetornado = lista->dados[i];
            return 1;
        }
    }
    return 0;
}

int removerClientePorCpf(ListaSequencialDeClientes* lista, int cpf)
{
    printf("Removendo cliente com CPF: %d\n", cpf);
    for(int i=0; i<lista->index; i++)
    {
        if(lista->dados[i].cpf == cpf)
        {
            printf("achou cpf para remocao\n");
            lista->dados[i] = lista->dados[lista->index-1];
            printf("i=%d index=%d\n", i, lista->index);
            lista->index--;
            return 1;
        }
    }
    return 0;
}

void imprimirListaDeClientes(ListaSequencialDeClientes* lista)
{
    printf("Clientes cadastrados:\n");
    for(int i=0; i<lista->index; i++)
    {
        Cliente c = lista->dados[i];
        imprimirDadosCliente(&c);
    }
}








