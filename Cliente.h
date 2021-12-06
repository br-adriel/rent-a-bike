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
int atualizarCliente(Cliente);
int excluirCliente(char[]);
