typedef struct{
    Cliente cliente;
    struct No* proximo;
}No;

typedef struct{
    No* inicio;
}ListaEncadeadaDeClientes;

ListaEncadeadaDeClientes* criarListaEncadeada();

void inserirFinal(ListaEncadeadaDeClientes* lista, Cliente c);
void inserirInicio(ListaEncadeadaDeClientes* lista, Cliente c);
int buscarCliente(ListaEncadeadaDeClientes* lista, int cpf, Cliente* clienteEncontrado);
void removerCliente(ListaEncadeadaDeClientes* lista, int cpf);
void imprimirDadosDaLista(ListaEncadeadaDeClientes* lista);
