#include <string.h>
#include <stdio.h>

struct Cliente
{
  char nome[20];
  char sobrenome[20];
  char email[70];
};

typedef struct Cliente Cliente;

Cliente novoCliente(char nome[], char sobrenome[], char email[])
{
  Cliente cliente;
  strcpy(cliente.nome, nome);
  strcpy(cliente.sobrenome, sobrenome);
  strcpy(cliente.email, email);
  return cliente;
}

int clienteExiste(char email[])
{
  char linha[150] = "";
  int existe = 0;

  FILE *arquivo;

  // Cria o arquivo caso seja a primeira execução
  arquivo = fopen("./clientes.txt", "a");
  fclose(arquivo);

  // le clientes do arquivo
  arquivo = fopen("./clientes.txt", "r");
  while (fgets(linha, 150, arquivo) != NULL && existe == 0)
  {
    // verifica se o email corresponde
    if (strstr(linha, email))
    {
      existe = 1;
    }
  }
  fclose(arquivo);
  return existe;
}
