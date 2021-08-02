typedef struct{
    int index;
    Cliente dados[100];
}ListaSequencialDeClientes;

ListaSequencialDeClientes* criarLista();
void liberarListaSequencialDeClientes(ListaSequencialDeClientes* li);

int inserirClienteFinalLista(ListaSequencialDeClientes* lista, Cliente cliente);
//inserirClienteInicioLista(ListaSequencialDeClientes* lista, Cliente cliente);
//inserirClienteNaPosicao(ListaSequencialDeClientes* lista, Cliente cliente, int posicao);

int consultarClientePosicao(ListaSequencialDeClientes* lista, int pos, Cliente* clienteRetornado);
int consultarClientePorCpf(ListaSequencialDeClientes* lista, int cpf, Cliente* clienteRetornado);

int removerClientePorCpf(ListaSequencialDeClientes* lista, int cpf);


void imprimirListaDeClientes(ListaSequencialDeClientes* lista);
