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
int inserirCliente(ListaSequencialClientes* lista, Cliente cliente);
int buscarClientePorCpf(ListaSequencialClientes* lista, int cpf, Cliente* clienteRetornado);

//implementar
void liberarListaSequencialClientes(ListaSequencialClientes* lista);
int removerClientePorCpf(ListaSequencialClientes* lista, int cpf);
void imprimirListaClientes(ListaSequencialClientes* lista);
int tamanhoLista(ListaSequencialClientes* lista);
int listaVazia(ListaSequencialClientes* lista);
int listaCheia(ListaSequencialClientes* lista);

