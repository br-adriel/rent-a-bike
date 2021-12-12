struct Cliente
{
  char nome[21];
  char sobrenome[21];
  char telefone[12];
  char email[71];
};

typedef struct Cliente Cliente;

Cliente* novoCliente(char[], char[], char[], char[]);
int clienteExiste(char[]);
int gravarCliente(Cliente*);
Cliente* verCliente(char[]);
int atualizarCliente(char[], char[], char[], char[], char[]);
int excluirCliente(char[]);
Cliente **buscaCliente(char[]);
Cliente *linhaParaCliente(char[]);
