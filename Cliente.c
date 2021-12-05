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
