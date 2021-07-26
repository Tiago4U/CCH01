#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "cliente.c"

//Lista sequencial
#include "listaSequencialClientes.c"

ListaSequencialClientes* lista;

//Criacao de Lista de usuarios
void CriarNovaLista(){
    if(lista == NULL){
        lista = criarLista();
        printf("Lista criada com  Sucesso. %d\n", &lista);
    }else{
        printf("Ja existe lista de usuarios criada.\n");
    }
}


int main(){
    int opcao;
    //printf("teste");

    Cliente c1;
	strcpy(c1.nome, "Joao");
	c1.id = 1;
	c1.cpf = 123;

	Cliente c2;
	strcpy(c2.nome, "Maria");
	c2.id = 2;
	c2.cpf = 345;

    do{
        printf("Selecione uma das opções abaixo:\n");
        printf("0 - Criar nova lista simplesmente encadeada;\n");
        printf("1 - Inserir novo cliente no FINAL da lista;\n");
        printf("2 - Inserir novo cliente no INÍCIO da lista;\n");
        printf("3 - Inserir novo cliente em uma posição específica;\n");
        printf("4 - Buscar cliente pelo CPF;\n");
        printf("5 - Remover cliente pelo CPF;\n");
        printf("6 - Imprimir todos os clientes da lista;\n");
        printf("7 - Imprimir tamanho da lista;\n");
        printf("8 - Imprimir dados de um cliente específico;\n");
        printf("9 - Buscar posição do cliente na lista;\n");
        printf("10 - Editar informações de acordo com a posição do cliente;\n");
        printf("11 - Sair.\n");
        scanf("%d", &opcao);


        switch(opcao){
            case 0:
                CriarNovaLista();
                break;

            case 1:
                inserirCliente(lista, c1);
                imprimirDadosCliente(&c1);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
        }
    }while(opcao != 11);

    printf("Programa Finalizado.");
}
