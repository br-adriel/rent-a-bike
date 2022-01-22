#include <string.h>
#include <stdio.h>
#include "Cliente.h"
#include "utils.h"
#include <stdlib.h>

/*
Cria um novo Cliente

Atributos:
  Nome: nome do cliente
  Sobrenome: sobrenome do cliente
  Email: email do cliente
  Telefone: telefone do cliente
Return:
  Cliente
*/
Cliente *novoCliente(char nome[], char sobrenome[], char email[], char telefone[])
{
  Cliente *cliente = malloc(sizeof(Cliente));
  strcpy(cliente->nome, nome);
  strcpy(cliente->sobrenome, sobrenome);
  strcpy(cliente->email, email);
  strcpy(cliente->telefone, telefone);
  cliente->ativo = 1;
  cliente->temPendencia = 0;
  return cliente;
}

/*
Verifica se o cliente existe

Atributos:
  email: email para fazer a busca
Retorna:
  A linha do arquivo em que foi encontrado ou -1
*/
int clienteExiste(char email[])
{
  int numLinha = -1;
  int linhaAtual = 0;

  Cliente *cli;
  cli = (Cliente *)malloc(sizeof(Cliente));

  FILE *arquivo;

  // Cria o arquivo caso seja a primeira execução
  arquivo = fopen("./clientes.dat", "ab");
  fclose(arquivo);

  // le clientes do arquivo
  arquivo = fopen("./clientes.dat", "rb");
  while (fread(cli, sizeof(Cliente), 1, arquivo) && numLinha == -1)
  {
    // verifica se o email corresponde
    if (strcmp(cli->email, email) == 0 && cli->ativo)
    {
      numLinha = linhaAtual;
      break;
    }
    linhaAtual++;
  }
  fclose(arquivo);
  return numLinha;
}

/*
Grava o cliente no arquivo

Atributos:
  cliente: Cliente a ser gravado
Retorna:
  0 - cliente já está registrado
  1 - cliente gravado no arquivo
*/
int gravarCliente(Cliente *cliente)
{
  if (clienteExiste(cliente->email) != -1)
  {
    return 0;
  }

  FILE *arquivo;
  arquivo = fopen("./clientes.dat", "ab");
  fwrite(cliente, sizeof(Cliente), 1, arquivo);
  fclose(arquivo);
  return 1;
}

/*
Ver dados de cliente específico

Atributos;
  email; email do cliente
Retornos:
  Cliente: dados do cliente
*/
Cliente *verCliente(char email[])
{
  Cliente *cli;
  cli = (Cliente *)malloc(sizeof(Cliente));

  FILE *arquivo;

  // Cria o arquivo caso seja a primeira execução
  arquivo = fopen("./clientes.dat", "ab");
  fclose(arquivo);

  // busca cliente no arquivo
  arquivo = fopen("./clientes.dat", "rb");
  while (fread(cli, sizeof(Cliente), 1, arquivo))
  {
    // verifica se o email corresponde
    if (strcmp(cli->email, email) == 0 && cli->ativo)
    {
      fclose(arquivo);
      break;
    }
  }
  return cli;
}

/*
Atualiza registro de um cliente

Atributos:
  email: novo email
  nome: novo nome
  sobrenome: novo sobrenome
  telefone: novo telefone
Retornos:
  0 - O cliente nao existe
  1 - Cliente atualizado
*/
int atualizarCliente(char email[], char nome[], char sobrenome[], char telefone[])
{
  // verifica se o cliente está salvo
  int linhaRegistro = clienteExiste(email);
  if (linhaRegistro == -1)
  {
    return 0;
  }

  Cliente *cli;
  cli = (Cliente *)malloc(sizeof(Cliente));

  FILE *arquivo;
  arquivo = fopen("./clientes.dat", "r+b");

  while (fread(cli, sizeof(Cliente), 1, arquivo))
  {
    // verifica se o email corresponde
    if (strcmp(cli->email, email) == 0 && cli->ativo)
    {
      fseek(arquivo, -1 * sizeof(Cliente), SEEK_CUR);

      // atualiza os dados
      strcpy(cli->nome, nome);
      strcpy(cli->sobrenome, sobrenome);
      strcpy(cli->telefone, telefone);

      fwrite(cli, sizeof(Cliente), 1, arquivo);
      fclose(arquivo);
      break;
    }
  }
  return 1;
}

/*
Deleta registro de um cliente

Atributos:
  email: email do cliente a ser exlcuido
Retornos:
  0 - O cliente nao existe
  1 - Cliente deletado
*/
int excluirCliente(char email[])
{
  // verifica se o cliente está salvo
  if (clienteExiste(email) == -1)
  {
    return 0;
  }

  Cliente *cli;
  cli = (Cliente *)malloc(sizeof(Cliente));

  FILE *arquivo;
  arquivo = fopen("./clientes.dat", "r+b");

  while (fread(cli, sizeof(Cliente), 1, arquivo))
  {
    // verifica se o email nao corresponde
    if (strcmp(cli->email, email) == 0 && cli->ativo)
    {
      cli->ativo = 0;
      fseek(arquivo, -1 * sizeof(Cliente), SEEK_CUR);
      fwrite(cli, sizeof(Cliente), 1, arquivo);
      fclose(arquivo);
      break;
    }
  }
  return 1;
}

/*
Busca cliente que tenha dado especifico

Atributos:
  termo: termo de busca
Retornos:
  Cliente*: vetor de clientes
*/
Cliente **buscaCliente(char termo[])
{
  Cliente **resultado = malloc(0);
  Cliente *clienteAtual;

  clienteAtual = (Cliente *)malloc(sizeof(Cliente));
  int quantidade = 0;
  FILE *arquivo;

  arquivo = fopen("./clientes.dat", "rb");
  while (fread(clienteAtual, sizeof(Cliente), 1, arquivo))
  {
    if (
        clienteAtual->ativo &&
        (strstr(clienteAtual->nome, termo) ||
         strstr(clienteAtual->sobrenome, termo) ||
         strstr(clienteAtual->telefone, termo) ||
         strstr(clienteAtual->email, termo)))
    {
      quantidade++;
      resultado = realloc(resultado, quantidade * sizeof(Cliente));

      Cliente *cli = malloc(sizeof(Cliente));
      memcpy(cli, clienteAtual, sizeof(Cliente));
      resultado[quantidade - 1] = cli;
    }
  }

  fclose(arquivo);

  // marca o fim do array
  clienteAtual = novoCliente("/!fim/!", "/!fim/!", "/!fim/!", "/!fim/!");
  quantidade++;
  resultado = realloc(resultado, quantidade * sizeof(Cliente));
  resultado[quantidade - 1] = clienteAtual;
  return resultado;
}
