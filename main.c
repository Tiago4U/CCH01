#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "cliente.c"

//Lista sequencial
#include "listaSequencialClientes.c"

ListaSequencialClientes* lista;

//Incrementa duas quebras de linha para seprar blocos de texto
void Finaliza(){
    printf("\n\n");
}

//Criacao de Lista de usuarios
void CriarNovaLista(){
    if(lista == NULL){
        lista = criarLista();
        printf("Lista criada com  Sucesso. %d", &lista); //#REMOVER endereco
        Finaliza();
    }else{
        printf("Ja existe lista de Clientes criada.");
        Finaliza();
    }
}

int main(){
    int opcao;
    int position;
    //printf("teste");

    //Cliente usado para busca
    Cliente clienteBusca;

    Cliente c1;
	strcpy(c1.nome, "Joao");
	c1.id = 1;
	c1.cpf = 123;

	Cliente c2;
	strcpy(c2.nome, "Maria");
	c2.id = 2;
	c2.cpf = 345;

    Cliente c3;
	strcpy(c3.nome, "Ze");
	c3.id = 3;
	c3.cpf = 111;

    Cliente c4;
	strcpy(c4.nome, "Tiago");
	c4.id = 4;
	c4.cpf = 222;

    do{
        printf("Selecione uma das opcoes abaixo:\n");
        printf("0 - Criar nova lista simplesmente encadeada;\n");  //OK
        printf("1 - Inserir novo cliente no FINAL da lista;\n");   //OK
        printf("2 - Inserir novo cliente no INICIO da lista;\n"); //OK
        printf("3 - Inserir novo cliente em uma posicao especifica;\n");  //OK
        printf("4 - Buscar cliente pelo CPF;\n");
        printf("5 - Remover cliente pelo CPF;\n");
        printf("6 - Imprimir todos os clientes da lista;\n"); //OK
        printf("7 - Imprimir tamanho da lista;\n"); //OK
        printf("8 - Imprimir dados de um cliente especifico;\n"); //OK
        printf("9 - Buscar posicao do cliente na lista;\n");
        printf("10 - Editar informacoes de acordo com a posicao do cliente;\n");
        printf("11 - Sair.\n");
        scanf("%d", &opcao);

        if(lista == NULL && opcao != 0){
            printf("Atencao! Sistema nao possui uma lista de clientes.");
            opcao = -1;
            Finaliza();
        }

        switch(opcao){
            case 0:
                CriarNovaLista();
                break;
            case 1:
                inserirCliente(lista, c1, -1);
                inserirCliente(lista, c2, -1);

                break;
            case 2:
                inserirCliente(lista, c3, 0);
                break;
            case 3:
                printf("Qual a posicao deseja inserir o cliente: \n");
                scanf("%d", &position);
                inserirCliente(lista, c4, position);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                if((lista->index) > 0){
                    for(int i=0; i<lista->index; i++){
                        printf("Posicao %d\n", i);
                        imprimirDadosCliente(&lista->dados[i]);
                        printf("\n");
                    }
                }else{
                    printf("Lista nao possui nenhum cliente cadastrado.");
                }
                Finaliza();
                break;
            case 7:
                printf("O tamanho da lista e de %d.", lista->index);
                Finaliza();
                break;
            case 8:
                if(buscarClientePorCpf(lista, &clienteBusca) > 0){

                }else{
                    printf("Cliente nao encontrado.");
                }
                Finaliza();
                break;
            case 9:
                break;
            case 10:
                break;
            case -1:
                //escape de exeucao
                break;
        }
    }while(opcao != 11);

    printf("Programa Finalizado.");
}
