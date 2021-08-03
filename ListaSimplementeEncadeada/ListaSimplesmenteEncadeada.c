#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[100];
    int id;
    int cpf;
}Cliente;

typedef struct{
    Cliente cliente;
    struct NodoLSE* proximo;
}NodoLSE;

typedef struct{
    NodoLSE* inicio;
}LSE;

LSE* ListaLSE;
Cliente clienteNovo;

LSE* criarLSE(){
    LSE* li;
    li = (LSE*) malloc(sizeof(LSE));
    if(li != NULL)
    {
        li->inicio = NULL;
    }
    return li;
}


void imprimirDadosCliente(Cliente* c){
    printf("Nome: %s\n", c->nome);
	printf("ID: %d\n", c->id);
	printf("CPF: %d\n\n", c->cpf);
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


int inserirCliente(LSE* listaLSE, int posicao){
	//TODO: verificar se lista cheia
	if(listaLSE == NULL){
        printf("A lista de clientes esta cheia. ");
		return 0;
	}

    criarCliente(&clienteNovo);

	//para informar a posicao utilizamos -1 para inserir no final, 0 para inserir no inicio e demais valores para posicao
	//Inserir na ultima posicao
	if(posicao == -1 ){

        // inserir no final da lista
        NodoLSE* novo = (NodoLSE*)malloc(sizeof(NodoLSE));
        novo->cliente = clienteNovo;
        novo->proximo = NULL;

        if(listaLSE->inicio == NULL){
            listaLSE->inicio = novo;
        } else {
            novo = listaLSE->inicio;
            while(novo->proximo != NULL){
                novo = novo->proximo;
            }
        }

        return 1;
	}else if(posicao == 0){
	    printf("Inserindo cliente na posicao: 0\n");

        NodoLSE* novo = (NodoLSE*)malloc(sizeof(NodoLSE));
        novo->cliente = clienteNovo;
        novo->proximo = listaLSE->inicio;
        listaLSE->inicio = novo;
        return 1;}
        /*
	}else{
        printf("Inserindo cliente na posicao: %d\n", posicao);

        for(int i=listaLSE->index; i>=posicao; i--){
            listaLSE->dados[i+1] = listaLSE->dados[i];
            //printf("posicao %d recebe dados da posicao %d\n", i+1, i);
        }

        listaLSE->dados[posicao] = clienteNovo;
        listaLSE->index++;
        return 1;
	}*/
}


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
}


void imprimirDadosLSE(LSE* lista)
{
    if(lista != NULL)
    {
        if(lista->inicio == NULL)
        {
            printf("Erro, lista nao foi inicilizada");
        }

        NodoLSE* aux = lista->inicio;
        while(aux!=NULL)
        {
            imprimirDadosCliente(&aux->cliente);
            aux = aux->proximo;
        }
    }
    else
    {
        printf("Erro, lista nao foi inicilizada");
    }
    printf("\n\n");
}
