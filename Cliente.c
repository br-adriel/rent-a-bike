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
Cliente novoCliente(char nome[], char sobrenome[], char email[], char telefone[])
{
  Cliente cliente;
  strcpy(cliente.nome, nome);
  strcpy(cliente.sobrenome, sobrenome);
  strcpy(cliente.email, email);
  strcpy(cliente.telefone, telefone);
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
  fprintf(arquivo, "%s|%s|%s|%s|\n", cliente.nome, cliente.sobrenome, cliente.telefone, cliente.email);
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
      cliente = linhaParaCliente(linha);
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
  telefone: novo telefone
Retornos:
  0 - O cliente nao existe
  1 - Cliente atualizado
*/
int atualizarCliente(char emailAntigo[], char email[], char nome[], char sobrenome[], char telefone[])
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
      fprintf(temp, "%s|%s|%s|%s|\n", nome, sobrenome, telefone, email);
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
  email: email do cliente a ser exlcuido
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

/*
Busca cliente que tenha dado especifico

Atributos:
  termo: termo de busca
Retornos:
  Cliente*: vetor de clientes
*/
Cliente *buscaCliente(char termo[])
{
  Cliente *resultado = malloc(0);
  Cliente clienteAtual;
  int quantidade = 0;
  FILE *arquivo;
  char linha[150];

  arquivo = fopen("./clientes.txt", "r");
  while (fgets(linha, sizeof(linha), arquivo))
  {
    if (strstr(linha, termo))
    {
      clienteAtual = linhaParaCliente(linha);

      quantidade++;
      resultado = realloc(resultado, quantidade * sizeof(Cliente));
      resultado[quantidade - 1] = clienteAtual;
    }
  }

  // marca o fim do array
  clienteAtual = linhaParaCliente("/!fim/!|/!fim/!|/!fim/!|/fim/!|\n");
  quantidade++;
  resultado = realloc(resultado, quantidade * sizeof(Cliente));
  resultado[quantidade - 1] = clienteAtual;
  return resultado;
}

/*
Funcao que converte linha de texto em Cliente

Atributos:
  linha: string de texto
Retornos:
  Cliente: cliente com as informacoes passadas
*/
Cliente linhaParaCliente(char linha[])
{
  Cliente cliente;
  char **dadosCliente = quebrarStr(linha, '|');
  strcpy(cliente.nome, dadosCliente[0]);
  strcpy(cliente.sobrenome, dadosCliente[1]);
  strcpy(cliente.telefone, dadosCliente[2]);
  strcpy(cliente.email, dadosCliente[3]);

  for (int i = 0; i < 5; i++)
  {
    free(dadosCliente[i]);
  }
  free(dadosCliente);
  return cliente;
}
