struct Cliente
{
  char nome[20];
  char sobrenome[20];
  char email[70];
};

typedef struct Cliente Cliente;

Cliente novoCliente(char[], char[], char[]);
int clienteExiste(char[]);
int gravarCliente(Cliente);
Cliente verCliente(char[]);
int atualizarCliente(char[], char[], char[], char[]);
int excluirCliente(char[]);
Cliente *buscaCliente(char[]);
Cliente linhaParaCliente(char[]);
