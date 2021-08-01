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
int removerDadosCliente(ListaSequencialClientes* lista);
int buscarPosicaoCliente(ListaSequencialClientes* lista);
