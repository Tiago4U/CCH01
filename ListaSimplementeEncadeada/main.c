#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//#include "cliente.h"
#include "listaSimplesmenteEncadeada.c"

NodoLSE* listaLSE;
FILE *arq;

//Criacao de Lista de usuarios
void CriarNovaLista(){
    if(listaLSE == NULL){
        listaLSE = criarLSE();
        printf("Lista criada com  Sucesso. %d\n\n", &listaLSE); //#REMOVER endereco
    }else{
        printf("Ja existe lista de Clientes criada.\n\n");
    }
}

void operacao(char *funcao, int qtd) {
    FILE *arq;
    arq = fopen("log-operacoes.txt", "a");
    if (arq != NULL) {
        printf("%s\n", funcao);
        fprintf(arq, "LSE,%s,%d\n", funcao, qtd);
    }
    fclose(arq);
}



int main(){
    char funcao[100];

    // Abre um arquivo TEXTO para LEITURA
    arq = fopen("operacoes.txt", "r");
    if (arq == NULL){
     printf("Problemas na abertura do arquivo\n");
     return;
    }

    CriarNovaLista();
    Cliente *clienteImportacao = alocarCliente();

    char buffer[300];
    int cpf=0;

    while(!feof(arq)){
        fgets(buffer, 300, arq);

        buffer[strlen(buffer) - 1] = '\0';
        sscanf(buffer, "%[a-zA-Z_]", funcao);
        if(strcmp(funcao, "inserir_inicio")==0){
            Cliente *clienteImportacao = alocarCliente();
            sscanf(buffer, "%[a-zA-Z_],%d,%[a-zA-Z '_],%d", funcao, &clienteImportacao->id, clienteImportacao->nome, &clienteImportacao->cpf);
            inserirInicio(listaLSE, clienteImportacao);
            operacao("inserir_inicio", 1);
        }else if(strcmp(funcao, "inserir_final")==0){
            Cliente *clienteImportacao = alocarCliente();
            sscanf(buffer, "%[a-zA-Z_],%d,%[a-zA-Z '_],%d", funcao, &clienteImportacao->id, clienteImportacao->nome, &clienteImportacao->cpf);
            inserirFinal(listaLSE, clienteImportacao);
            operacao("inserir_final", 1);
        }else if(strcmp(funcao, "remover")==0){
            sscanf(buffer, "%[a-zA-Z_ ],%d", funcao, &cpf);
            removerCliente(listaLSE, cpf);
            operacao("remover", 1);
        }else if(strcmp(funcao, "buscar")==0){
            sscanf(buffer, "%[a-zA-Z_ ],%d", funcao, &cpf);
            Cliente* clientePesquisa = alocarCliente();
            clientePesquisa = buscarCliente(listaLSE->inicio, cpf);
            operacao("buscar", 1);
            if(clientePesquisa!=NULL){
                //imprimirDadosCliente(clientePesquisa);
            }else{
                printf("nao encontrado\n");
            }
        }else if(strcmp(funcao, "obter_tamanho_lista")==0){
            imprimirTamanho(listaLSE);
            operacao("obter_tamanho_lista", 1);
        }
    }


    /*
    const char *FORMAT_SAIDA_OPERACOES = "LES,%s,%d\n";
    const char *FORMAT_LOG_CONTEUDO_LIST = "LES,%d,CPF:%d\n";



    void conteudoLista(LES *lista) {
    FILE *pf;

    pf = fopen("log-conteudo-lista.txt", "a");

    if (pf == NULL) {
        printf("Error!");

        return;
    } else {

        int posicao = 1;

        for (int i = 0; i < lista->index; i++) {
            fprintf(pf, FORMAT_LOG_CONTEUDO_LIST, posicao, lista->dados[i].cpf);

            posicao++;
        }

        fclose(pf);
    }
}
*/
    //while(!feof(arq)){
        //fscanf(arq, "%[a-zA-Z_],", funcao);
        //printf("\n%s\n", funcao);
        //if(strcmp(funcao, "inserir_inicio") == 0){
        //printf("pf%d\n", arq);


        //printf("pf%d\n", arq);
        //fscanf(arq, "%[a-zA-Z_],%d,%[a-zA-Z '-],%d", funcao, &clienteImportacao->id, clienteImportacao->nome, &clienteImportacao->cpf);
        //imprimirDadosCliente(clienteImportacao);
        //inserirInicio(listaLSE, clienteImportacao);
           // i++;
       // }
    //}




    /*
    fscanf(arq, "%d", clienteImportacao->id);
    fscanf(arq, "%[a-zA-Z]", clienteImportacao->nome);
    fscanf(arq, "%d", clienteImportacao->cpf);
*/
   // inserirInicio(listaLSE, clienteImportacao);


    //imprimirDadosLSE(listaLSE);

   // result = fgets(clienteImportacao, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
    //printf("Linha %d : %s",i,Linha);

    //fclose(arq);

    //printf("Linha %d : %s",i,Linha);

    /*
    Cliente *cliente1 = alocarCliente();
    Cliente *cliente2 = alocarCliente();
    Cliente *cliente3 = alocarCliente();
    Cliente *cliente4 = alocarCliente();

    strcpy(cliente1->nome, "TIAGO");
    cliente1->id = 1;
    cliente1->cpf = 123;

    strcpy(cliente2->nome, "Cliente2");
    cliente2->id = 2;
    cliente2->cpf = 321;

    strcpy(cliente3->nome, "Cliente3");
    cliente3->id = 3;
    cliente3->cpf = 444;

    strcpy(cliente4->nome, "Ultimo");
    cliente4->id = 80;
    cliente4->cpf = 333;

    inserirInicio(listaLSE, cliente1);
    inserirInicio(listaLSE, cliente2);
    inserirFinal(listaLSE, cliente3);
    inserirFinal(listaLSE, cliente4);

    //imprimirDadosLSE(listaLSE);

    removerCliente(listaLSE, 444);
    buscarClienteCPF(listaLSE, 333);

    imprimirTamanho(listaLSE);
*/
    /*
    do{
        printf("Selecione uma das opcoes abaixo:\n");
        printf("0 - Criar nova lista simplesmente encadeada;\n");  //OK
        printf("1 - Inserir novo cliente no FINAL da lista;\n");   //OK
        printf("2 - Inserir novo cliente no INICIO da lista;\n"); //OK
        printf("3 - Inserir novo cliente em uma posicao especifica;\n");  //OK
        printf("4 - Buscar cliente pelo CPF;\n");   //OK
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
        }

        switch(opcao){
            case 0:
                CriarNovaLista();
                break;
            case 1:
                //INSERIR NO FINAL
                inserirCliente(listaLSE, -1);
                tamanho++;
                break;
            case 2:
                //INSERIR NO INICIO
                inserirCliente(listaLSE, 1);
                tamanho++;
                break;
            case 3:
                //INSERIR EM POSICAO ESPECIFICA
                printf("Qual a posicao deseja inserir o cliente: \n");
                scanf("%d", &position);
                inserirCliente(listaLSE, position);
                break;
            case 4:
                if(buscarClientePorCpf(lista, &clienteBusca) > 0){
                    printf("Cliente encontrado:");
                    imprimirDadosCliente(&clienteBusca);
                }else{
                    printf("Cliente nao encontrado.");
                }
                break;
            case 5:
                printf("Informe o CPF do cliente\n");
                scanf("%d", &cpf);
                //removerLSE(listaLSE, cpf);
                break;
            case 6:
                imprimirDadosLSE(listaLSE);
                break;
            case 7:
                printf("O tamanho da lista e de %d.", tamanho);
                break;
            case 8:
                /*if(buscarClientePorCpf(lista, &clienteBusca) == 0){
                    printf("Cliente nao encontrado.");
                }*/
              //  break;
            //case 9:
                /*if(buscarPosicaoCliente(lista) == 0){
                    printf("Posicao nao possui cliente cadastrado.");
                }
                */
               // break;
            //case 10:
                /*if(alterarCliente(lista) > 0){
                    printf("Dados alterados com sucesso.");
                }else{
                    printf("Posicao nao possui cliente cadastrado.");
                }
                */
                //break;
            //case -1:
                //escape de exeucao
               // break;
       // }
    //}while(opcao != 11);

    printf("Programa Finalizado.");
}

