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
Return:
  Cliente
*/
Cliente novoCliente(char nome[], char sobrenome[], char email[])
{
  Cliente cliente;
  strcpy(cliente.nome, nome);
  strcpy(cliente.sobrenome, sobrenome);
  strcpy(cliente.email, email);
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
  char linha[150] = "";
  int numLinha = -1;
  int linhaAtual = 0;

  FILE *arquivo;

  // Cria o arquivo caso seja a primeira execução
  arquivo = fopen("./clientes.txt", "a");
  fclose(arquivo);

  // le clientes do arquivo
  arquivo = fopen("./clientes.txt", "r");
  while (fgets(linha, 150, arquivo) != NULL && numLinha == -1)
  {
    // verifica se o email corresponde
    if (strstr(linha, email))
    {
      numLinha = linhaAtual;
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
int gravarCliente(Cliente cliente)
{
  if (clienteExiste(cliente.email) != -1)
  {
    return 0;
  }

  FILE *arquivo;
  arquivo = fopen("./clientes.txt", "a");
  fprintf(arquivo, "%s|%s|%s|\n", cliente.nome, cliente.sobrenome, cliente.email);
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
Cliente verCliente(char email[])
{
  Cliente cliente;
  char linha[150] = "";

  FILE *arquivo;
  // Cria o arquivo caso seja a primeira execução
  arquivo = fopen("./clientes.txt", "a");
  fclose(arquivo);

  // busca cliente no arquivo
  arquivo = fopen("./clientes.txt", "r");
  while (fgets(linha, sizeof(linha), arquivo))
  {
    // verifica se o email corresponde
    if (strstr(linha, email))
    {
      char **dadosCliente = quebrarStr(linha, '|');
      strcpy(cliente.nome, dadosCliente[0]);
      strcpy(cliente.sobrenome, dadosCliente[1]);
      strcpy(cliente.email, dadosCliente[2]);

      for (int i = 0; i < 4; i++)
      {
        free(dadosCliente[i]);
      }
      free(dadosCliente);
      fclose(arquivo);
      break;
    }
  }
  return cliente;
}

/*
Atualiza registro de um cliente

Atributos:
  emailAntigo: email do cliente a ser atualizado
  email: novo email
  nome: novo nome
  sobrenome: novo sobrenome
Retornos:
  0 - O cliente nao existe
  1 - Cliente atualizado
*/
int atualizarCliente(char emailAntigo[], char email[], char nome[], char sobrenome[])
{
  // verifica se o cliente está salvo
  int linhaRegistro = clienteExiste(emailAntigo);
  if (linhaRegistro == -1)
  {
    return 0;
  }

  // transfere dados do arquivo original para um temporario
  char linha[150] = "";
  FILE *arquivo, *temp;
  arquivo = fopen("./clientes.txt", "r");
  temp = fopen("./clientes.temp.txt", "a");

  while (fgets(linha, 150, arquivo) != NULL)
  {
    // verifica se o email corresponde
    if (strstr(linha, emailAntigo))
    {
      // atualiza os dados
      fprintf(temp, "%s|%s|%s|\n", nome, sobrenome, email);
    }
    else
    {
      fprintf(temp, "%s", linha);
    }
  }

  fclose(temp);
  fclose(arquivo);

  // deleta arquivo desatualizado e renomeia temporario
  remove("./clientes.txt");
  rename("./clientes.temp.txt", "./clientes.txt");

  return 1;
}

/*
Deleta registro de um cliente

Atributos:
  cliente: cliente a ser atualizado
Retornos:
  0 - O cliente nao existe
  1 - Cliente deletado
*/
int excluirCliente(char email[])
{
  // verifica se o cliente está salvo
  int linhaRegistro = clienteExiste(email);
  if (linhaRegistro == -1)
  {
    return 0;
  }

  // transfere dados do arquivo original para um temporario
  char linha[150] = "";
  FILE *arquivo, *temp;
  arquivo = fopen("./clientes.txt", "r");
  temp = fopen("./clientes.temp.txt", "a");

  while (fgets(linha, 150, arquivo) != NULL)
  {
    // verifica se o email nao corresponde
    if (!strstr(linha, email))
    {
      fprintf(temp, "%s", linha);
    }
  }

  fclose(temp);
  fclose(arquivo);

  // deleta arquivo desatualizado e renomeia temporario
  remove("./clientes.txt");
  rename("./clientes.temp.txt", "./clientes.txt");

  return 1;
}
