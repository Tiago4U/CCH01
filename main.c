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
        printf("Selecione uma das opcoes abaixo:\n");
        printf("0 - Criar nova lista simplesmente encadeada;\n");  //OK
        printf("1 - Inserir novo cliente no FINAL da lista;\n");   //OK
        printf("2 - Inserir novo cliente no INÍCIO da lista;\n");
        printf("3 - Inserir novo cliente em uma posição específica;\n");
        printf("4 - Buscar cliente pelo CPF;\n");
        printf("5 - Remover cliente pelo CPF;\n");
        printf("6 - Imprimir todos os clientes da lista;\n"); //OK
        printf("7 - Imprimir tamanho da lista;\n");
        printf("8 - Imprimir dados de um cliente específico;\n");
        printf("9 - Buscar posição do cliente na lista;\n");
        printf("10 - Editar informações de acordo com a posição do cliente;\n");
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
                inserirCliente(lista, c1, -1);
                inserirCliente(lista, c2, -1);

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
                if((lista->index) > 0){
                    for(int i=0; i<lista->index; i++){
                        imprimirDadosCliente(lista->dados);
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
