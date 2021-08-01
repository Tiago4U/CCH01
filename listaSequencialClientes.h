typedef struct{
	char nome[100];
	int id;
	int cpf;
}Cliente;

typedef struct{
	int index;
	Cliente dados[100];
}ListaSequencialClientes;

ListaSequencialClientes* criarLista();
void imprimirDadosCliente(Cliente* cliente);
int inserirCliente(ListaSequencialClientes* lista, int posicao);
int buscarClientePorCpf(ListaSequencialClientes* lista, Cliente* clienteRetornado);
int removerDadosCliente(ListaSequencialClientes* lista, Cliente* cliente);
int buscarPosicaoCliente(ListaSequencialClientes* lista, Cliente* cliente);

//implementar
void liberarListaSequencialClientes(ListaSequencialClientes* lista);
int removerClientePorCpf(ListaSequencialClientes* lista, int cpf);
void imprimirListaClientes(ListaSequencialClientes* lista);
int tamanhoLista(ListaSequencialClientes* lista);
int listaVazia(ListaSequencialClientes* lista);
int listaCheia(ListaSequencialClientes* lista);

