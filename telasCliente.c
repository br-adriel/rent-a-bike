#include <stdio.h>
#include "utils.h"
#include "telasCliente.h"
#include "validadores.h"
#include <limits.h>
#include "Cliente.h"
#include <stdlib.h>
#include <string.h>

void telaGerenciarClientes(void)
{
  int opcao = 0;
  char email[PATH_MAX] = "";
  int inputValido = 0;

  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Gerenciar clientes\n");
    printf("--------------------------------------------------\n");
    printf("\n[1] Novo cliente\n");
    printf("[2] Buscar cliente\n");
    printf("[3] Ver cliente\n");
    printf("\n[4] Voltar\n");
    printf(">> ");
    scanf("%1d", &opcao);
    limparBuffer();
    printf("\n");

    switch (opcao)
    {
    case 1:
      telaNovoCliente();
      break;
    case 2:
      telaBuscarCliente();
      break;
    case 3:
      do
      {
        printf("\nDigite o email do cliente: ");
        scanf("%s", email);
        limparBuffer();

        inputValido = validaEmail(email);
        printf("\n");
      } while (!inputValido);

      telaVerCliente(email);
      break;
    case 4:
      break;
    default:
      msgInvalido();
    }
  } while (opcao != 4);
}

void telaNovoCliente(void)
{
  int opcao = 2;
  char email[PATH_MAX] = "";
  char nome[PATH_MAX] = "";
  char sobrenome[PATH_MAX] = "";
  char telefone[12] = "";
  int inputValido = 0;

  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Novo cliente\n");
    printf("--------------------------------------------------\n");
    if (opcao == 2)
    {
      do
      {
        printf("\nEmail: ");
        scanf("%s", email);
        limparBuffer();

        inputValido = validaEmail(email);
        printf("\n");
      } while (!inputValido);

      do
      {
        printf("\nNome: ");
        scanf("%s", nome);
        limparBuffer();

        inputValido = validaPalavra(nome, 20);
        printf("\n");
      } while (!inputValido);

      do
      {
        printf("\nSobrenome: ");
        scanf("%s", sobrenome);
        limparBuffer();

        inputValido = validaPalavra(sobrenome, 20);
        printf("\n");
      } while (!inputValido);

      do
      {
        printf("\nTelefone: ");
        scanf("%s", telefone);
        limparBuffer();

        inputValido = validaTelefone(telefone);
        printf("\n");
      } while (!inputValido);

      printf("\n--------------------------------------------------\n");
    }
    printf("\nEmail: %s\n", email);
    printf("Nome: %s\n", nome);
    printf("Sobrenome: %s\n", sobrenome);
    printf("Telefone: %s", formatarTelefone(telefone));
    printf("\n\n--------------------------------------------------\n\n");
    printf("Salvar registro?");
    printf("\n[1] Sim\n[2] Não, preencher novamente\n[3] Cancelar");
    printf("\n>> ");
    scanf("%1d", &opcao);
    limparBuffer();
    printf("\n");

    switch (opcao)
    {
    case 1:
      if (gravarCliente(novoCliente(nome, sobrenome, email, telefone)) == 1)
      {
        msgRegistroSalvo();
      }
      else
      {
        printf("/!/ Já existe um cliente com esse email\n\n");
      }
      break;
    }
  } while (opcao == 2);
}

void telaBuscarCliente(void)
{
  int opcao = 0;
  char termoBusca[PATH_MAX] = "";
  char email[PATH_MAX] = "";
  int inputValido = 0;

  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Buscar cliente\n");
    printf("--------------------------------------------------\n");
    printf("\nTermo de busca: ");
    scanf("%s", termoBusca);
    limparBuffer();
    printf("\n--------------------------------------------------\n");

    Cliente **resultado = buscaCliente(termoBusca);

    // exibe resultado
    printf("\nResultados:\n");
    printf("Nome                 | Sobrenome            | Telefone        | Email\n");

    int i = 0;
    if (!strstr(resultado[0]->nome, "/!fim/!"))
    {
      while (!strstr(resultado[i]->nome, "/!fim/!"))
      {
        Cliente *cli = resultado[i];
        char *nomeF = formatarPalavra(cli->nome, 20);
        char *sobrenomeF = formatarPalavra(cli->sobrenome, 20);
        char *telefoneF = formatarTelefone(cli->telefone);
        printf("%s | %s | %s | %s\n", nomeF, sobrenomeF, telefoneF, cli->email);
        free(nomeF);
        free(sobrenomeF);
        free(telefoneF);
        free(cli);
        i++;
      }
    }
    else
    {
      printf("/i/ Nenhum cliente encontrado!\n");
    }
    free(resultado);
    printf("\n");
    printf("[1] Ver cliente\n");
    printf("[2] Voltar\n");
    printf(">> ");
    scanf("%1d", &opcao);
    limparBuffer();

    switch (opcao)
    {
    case 1:
      do
      {
        printf("\nDigite o email do cliente: ");
        scanf("%s", email);
        limparBuffer();

        inputValido = validaEmail(email);
        printf("\n");
      } while (!inputValido);
      if (clienteExiste(email) != -1)
      {
        telaVerCliente(email);
      }
      else
      {
        printf("/!/ O cliente não existe\n");
      }
      opcao = 2;
      break;
    case 2:
      break;
    default:
      msgInvalido();
    }
  } while (opcao != 2);
}

void telaVerCliente(char email[])
{
  int opcao = 3;
  Cliente *cliente;

  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Ver cliente");
    printf("\n--------------------------------------------------\n");
    if (clienteExiste(email) == -1)
    {
      printf("\n/!/ O cliente não existe\n\n");
      opcao = 3;
    }
    else
    {
      cliente = verCliente(email);
      printf("Nome: %s\n", cliente->nome);
      printf("Sobrenome: %s\n", cliente->sobrenome);
      printf("Telefone: %s\n", formatarTelefone(cliente->telefone));
      printf("Email: %s", cliente->email);
      printf("\n--------------------------------------------------\n");
      printf("\n");
      printf("[1] Editar\n");
      printf("[2] Apagar\n");
      printf("\n[3] Voltar\n");
      printf(">> ");
      scanf("%1d", &opcao);
      limparBuffer();
      printf("\n");

      switch (opcao)
      {
      case 1:
        telaEditarCliente(email);
        opcao = 3;
        break;
      case 2:
        telaExcluirCliente(email);
        opcao = 3;
        break;
      case 3:
        break;
      default:
        msgInvalido();
      }
    }
  } while (opcao != 3);
  free(cliente);
}

void telaEditarCliente(char email[])
{
  int opcao = 2;

  char novoEmail[PATH_MAX] = "";
  char nome[PATH_MAX] = "";
  char sobrenome[PATH_MAX] = "";
  char telefone[12] = "";
  int inputValido = 0;
  Cliente *cliente = verCliente(email);

  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Editar cliente");
    if (opcao == 2)
    {
      printf("\n--------------------------------------------------\n");
      do
      {
        printf("\nEmail [ %s ]: ", cliente->email);
        scanf("%s", novoEmail);
        limparBuffer();

        inputValido = validaEmail(novoEmail);
        printf("\n");
      } while (!inputValido);

      do
      {
        printf("\nNome do cliente [ %s ]: ", cliente->nome);
        scanf("%s", nome);
        limparBuffer();

        inputValido = validaPalavra(nome, 20);
        printf("\n");
      } while (!inputValido);

      do
      {
        printf("\nSobrenome do cliente [ %s ]: ", cliente->sobrenome);
        scanf("%s", sobrenome);
        limparBuffer();

        inputValido = validaPalavra(sobrenome, 20);
        printf("\n");
      } while (!inputValido);

      do
      {
        printf("\nTelefone do cliente [ %s ]: ", formatarTelefone(cliente->telefone));
        scanf("%11s", telefone);
        limparBuffer();

        inputValido = validaTelefone(telefone);
        printf("\n");
      } while (!inputValido);
    }
    printf("\n\n--------------------------------------------------\n\n");
    printf("Email: %s\n", novoEmail);
    printf("Nome: %s\n", nome);
    printf("Sobrenome: %s\n", sobrenome);
    printf("Telefone: %s\n", formatarTelefone(telefone));
    printf("\n--------------------------------------------------\n\n");
    printf("Atualizar?");
    printf("\n[1] Sim\n[2] Não, preencher novamente\n[3] Cancelar");
    printf("\n>> ");
    scanf("%1d", &opcao);
    limparBuffer();
    printf("\n");

    switch (opcao)
    {
    case 1:
      if (atualizarCliente(cliente->email, novoEmail, nome, sobrenome, telefone))
      {
        msgRegistroSalvo();
      }
      else
      {
        printf("/!/ Um erro ocoreu.\n\n");
      }
      break;
    case 2:
    case 3:
      break;
    default:
      msgInvalido();
      break;
    }
  } while (opcao != 1 && opcao != 3);
  free(cliente);
}

void telaExcluirCliente(char email[])
{
  Cliente *cliente = verCliente(email);
  int opcao = 0;

  printf("//////////////////////////////////////////////////\n");
  printf("RENT A BIKE - Excluir cliente");
  do
  {
    printf("\n\n--------------------------------------------------\n\n");
    printf("Email: %s\n", cliente->email);
    printf("Nome: %s\n", cliente->nome);
    printf("Sobrenome: %s\n", cliente->sobrenome);
    printf("Telefone: %s\n", cliente->telefone);
    printf("\n--------------------------------------------------\n");
    printf("\n");
    printf("Excluir cliente?");
    printf("\n[1] Sim\n[2] Não");
    printf("\n>> ");
    scanf("%1d", &opcao);
    limparBuffer();
    printf("\n");

    switch (opcao)
    {
    case 1:
      if (excluirCliente(cliente->email))
      {
        msgRegistroExcluido();
      }
      else
      {
        msgErro();
      }
      break;
    case 2:
      break;
    default:
      msgInvalido();
    }
  } while (opcao != 1 && opcao != 2);
  free(cliente);
}
