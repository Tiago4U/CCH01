#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "cliente.h"
#include "listaSimplesmenteEncadeada.c"

NodoLSE* listaLSE;

//Criacao de Lista de usuarios
void CriarNovaLista(){
    if(listaLSE == NULL){
        listaLSE = criarLSE();
        printf("Lista criada com  Sucesso. %d", &listaLSE); //#REMOVER endereco
    }else{
        printf("Ja existe lista de Clientes criada.");
    }
}

void Finaliza(){
    printf("\n\n");
}

int main()
{
    int cpf;
    int opcao;
    int position;
    int tamanho=0;
    //Cliente usado para busca
    Cliente clienteBusca;

    //Cliente usado para inclusao
    Cliente cliente;

    do{
        printf("Selecione uma das opcoes abaixo:\n");
        printf("0 - Criar nova lista simplesmente encadeada;\n");  //OK
        printf("1 - Inserir novo cliente no FINAL da lista;\n");   //OK
        printf("2 - Inserir novo cliente no INICIO da lista;\n"); //OK
        printf("3 - Inserir novo cliente em uma posicao especifica;\n");  //OK
        //printf("4 - Buscar cliente pelo CPF;\n");   //OK
        printf("5 - Remover cliente pelo CPF;\n");  //OK
        printf("6 - Imprimir todos os clientes da lista;\n"); //OK
        printf("7 - Imprimir tamanho da lista;\n"); //OK
        //printf("8 - Imprimir dados de um cliente especifico;\n"); //OK
        //printf("9 - Buscar posicao do cliente na lista;\n");
        //printf("10 - Editar informacoes de acordo com a posicao do cliente;\n");
        printf("11 - Sair.\n");
        scanf("%d", &opcao);

        //Nao deixa executar nenhuma funcao sem ter lista cria
        if(listaLSE == NULL && opcao != 0 && opcao != 11){
            printf("Atencao! Sistema nao possui uma lista de clientes.");
            opcao = -1;
            Finaliza();
        }

        switch(opcao){
            case 0:
                CriarNovaLista();
                Finaliza();
                break;
            case 1:
                //INSERIR NO FINAL
                inserirCliente(listaLSE, -1);
                tamanho++;
                Finaliza();
                break;
            case 2:
                //INSERIR NO INICIO
                inserirCliente(listaLSE, 1);
                tamanho++;
                Finaliza();
                break;
            case 3:
                //INSERIR EM POSICAO ESPECIFICA
                printf("Qual a posicao deseja inserir o cliente: \n");
                scanf("%d", &position);
                inserirCliente(listaLSE, position);
                Finaliza();
                break;
            case 4:
                /*if(buscarClientePorCpf(lista, &clienteBusca) > 0){
                    printf("Cliente encontrado:");
                    imprimirDadosCliente(&clienteBusca);
                }else{
                    printf("Cliente nao encontrado.");
                }
                Finaliza();*/
                break;
            case 5:
                printf("Informe o CPF do cliente\n");
                scanf("%d", &cpf);
                //removerLSE(listaLSE, cpf);
                Finaliza();
                break;
            case 6:
                imprimirDadosLSE(listaLSE);
                Finaliza();
                break;
            case 7:
                printf("O tamanho da lista e de %d.", tamanho);
                Finaliza();
                break;
            case 8:
                /*if(buscarClientePorCpf(lista, &clienteBusca) == 0){
                    printf("Cliente nao encontrado.");
                }
                Finaliza();*/
                break;
            case 9:
                /*if(buscarPosicaoCliente(lista) == 0){
                    printf("Posicao nao possui cliente cadastrado.");
                }
                Finaliza();*/
                break;
            case 10:
                /*if(alterarCliente(lista) > 0){
                    printf("Dados alterados com sucesso.");
                }else{
                    printf("Posicao nao possui cliente cadastrado.");
                }
                Finaliza();*/
                break;
            case -1:
                //escape de exeucao
                break;
        }
    }while(opcao != 11);

    printf("Programa Finalizado.");
}

