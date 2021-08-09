typedef struct{
    char nome[100];
    int id;
    int cpf;
    struct Cliente *proximo;
}Cliente;

void imprimirDadosCliente(Cliente* c);
//Cliente *alocarCliente();
