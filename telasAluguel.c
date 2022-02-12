#include <stdio.h>
#include "utils.h"
#include "telasAluguel.h"
#include "validadores.h"
#include <limits.h>
#include "Aluguel.h"
#include "Bicicleta.h"
#include "Cliente.h"
#include <string.h>
#include <stdlib.h>

void telaGerenciarAlugueis(void)
{
  int opcao = 0;

  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Gerenciar aluguéis\n");
    printf("--------------------------------------------------\n");
    printf("\n[1] Novo aluguél\n");
    printf("[2] Buscar aluguél\n");
    printf("[3] Relatório de atividades\n");
    printf("[4] Alterar preço da hora\n");
    printf("\n[5] Voltar\n");
    printf(">> ");
    scanf("%1d", &opcao);
    limparBuffer();
    printf("\n");

    switch (opcao)
    {
    case 1:
      telaNovoAluguel();
      break;
    case 2:
      telaBuscarAluguel();
      break;
    case 3:
      telaRelatorioAtividades();
      break;
    case 4:
      telaAlterarPreco();
      break;
    case 5:
      break;
    default:
      msgInvalido();
    }
  } while (opcao != 5);
}

void telaNovoAluguel(void)
{
  int opcao = 2;
  char codBicicleta[PATH_MAX] = "";
  char emailCliente[PATH_MAX] = "";
  Bicicleta *bicicleta;
  Cliente *cliente;
  int inputValido = 0;

  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Novo aluguél\n");
    printf("--------------------------------------------------\n");
    if (opcao == 2)
    {
      do
      {
        printf("\nCódigo da bicicleta: ");
        scanf("%s", codBicicleta);
        limparBuffer();

        inputValido = validaCodigo(codBicicleta, 6);
      } while (!inputValido);

      do
      {
        printf("\nEmail do cliente: ");
        scanf("%s", emailCliente);
        limparBuffer();

        inputValido = validaEmail(emailCliente);
      } while (!inputValido);

      printf("\n\n--------------------------------------------------\n");
    }
    printf("\nCliente: %s\n", emailCliente);
    printf("Código da bicicleta: %s\n", codBicicleta);
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
      if (bicicletaExiste(codBicicleta) == -1)
      {
        printf("/!/ A bicicleta não existe\n");
      }
      else
      {
        bicicleta = verBicicleta(codBicicleta);
        if (strstr(bicicleta->disponivel, "NÃO"))
        {
          printf("/!/ A bicicleta não está disponível para aluguél\n");
        }
        else if (clienteExiste(emailCliente) == -1)
        {
          printf("/!/ O cliente não existe\n");
        }
        else
        {
          cliente = verCliente(emailCliente);
          if (strstr(cliente->temPendencia, "SIM"))
          {
            printf("/!/ O cliente já possui um aluguél em aberto\n");
          }
          else
          {
            gravarAluguel(novoAluguel(emailCliente, codBicicleta));
            atualizarBicicleta(bicicleta->codigo, bicicleta->cor, bicicleta->categoria, 0);
            atualizarCliente(cliente->email, cliente->nome, cliente->sobrenome, cliente->telefone, "SIM");
            msgRegistroSalvo();
          }
        }
      }

      break;
    }
  } while (opcao == 2);
}

void telaVerAluguel(int codigo)
{
  int opcao = 2;
  Aluguel *aluguel;
  Cliente *cliente;
  Bicicleta *bicicleta;

  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Ver aluguél\n");
    printf("--------------------------------------------------\n");
    if (aluguelExiste(codigo) == -1)
    {
      printf("\n/!/ O aluguél não existe\n");
    }
    else
    {
      aluguel = verAluguel(codigo);
      printf("\n-- Aluguél --------------------------------------\n");
      printf("Código: %d\n", aluguel->codigo);
      printf("Situação: %s\n", aluguel->situacao);
      printf("Data de retirada: %s\n", saidaAluguelStr(aluguel));
      if (strstr(aluguel->situacao, "FECHADO"))
      {
        printf("Data de retorno: %s\n", retornoAluguelStr(aluguel));
        printf("Preço: R$ %.2f\n", aluguel->valor);
      }

      printf("-- Cliente ---------------------------------------\n");
      if (clienteExiste(aluguel->cliente) == -1)
      {
        printf("Email: %s\n", aluguel->cliente);
        printf("/i/ O cliente não está cadastrado no banco de dados\n");
      }
      else
      {
        cliente = verCliente(aluguel->cliente);
        printf("Nome: %s %s\n", cliente->nome, cliente->sobrenome);
        printf("Email: %s\n", cliente->email);
        printf("Telefone: %s\n", formatarTelefone(cliente->telefone));
      }

      printf("-- Bicicleta -------------------------------------\n");
      if (bicicletaExiste(aluguel->bicicleta) == -1)
      {
        printf("Código: %s\n", aluguel->bicicleta);
        printf("/i/ A bicicleta não está cadastrada no banco de dados\n");
      }
      else
      {
        bicicleta = verBicicleta(aluguel->bicicleta);
        printf("Código: %s\n", bicicleta->codigo);
        printf("Cor: %s\n", bicicleta->cor);
        printf("Categoria: %s\n", bicicleta->categoria);
        printf("Disponível atualmente: ");
        bicicleta->disponivel ? printf("SIM\n") : printf("NÃO\n");
      }
      printf("\n--------------------------------------------------\n");
      printf("\n");
      if (strstr(aluguel->situacao, "EM ABERTO"))
      {
        printf("[0] Fechar aluguél\n");
      }
      printf("[1] Apagar\n");
      printf("\n[2] Voltar\n");
      printf(">> ");
      scanf("%1d", &opcao);
      limparBuffer();
      printf("\n");

      switch (opcao)
      {
      case 0:
        fecharAluguel(codigo);
        if (bicicletaExiste(aluguel->bicicleta) != -1)
        {
          atualizarBicicleta(bicicleta->codigo, bicicleta->cor, bicicleta->categoria, 1);
          atualizarCliente(cliente->email, cliente->nome, cliente->sobrenome, cliente->telefone, "NÃO");
        }
        break;
      case 1:
        telaExcluirAluguel(codigo);
        opcao = 2;
        break;
      case 2:
        break;
      default:
        msgInvalido();
      }
    }
  } while (opcao != 2);
}

void telaExcluirAluguel(int codigo)
{
  int opcao = 0;
  Aluguel *alu;
  Cliente *cli;
  int cliExiste = 0;

  do
  {
    printf("\n");
    printf("Excluir aluguél #%d?", codigo);
    printf("\n[1] Sim\n[2] Não");
    printf("\n>> ");
    scanf("%1d", &opcao);
    limparBuffer();
    printf("\n");

    switch (opcao)
    {
    case 1:
      alu = verAluguel(codigo);
      cliExiste = clienteExiste(alu->cliente);
      if (cliExiste)
      {
        cli = verCliente(alu->cliente);
      }
      if (excluirAluguel(codigo))
      {
        atualizarCliente(cli->email, cli->nome, cli->sobrenome, cli->telefone, "NÃO");
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
}

void telaBuscarAluguel(void)
{
  int opcao = 0;
  int inputValido = 0;
  int codigo = -1;
  char termoBusca[PATH_MAX] = "";

  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Buscar aluguél\n");
    printf("--------------------------------------------------\n");
    printf("\nTermo de busca: ");
    scanf("%s", termoBusca);
    limparBuffer();
    printf("\n");

    Aluguel **resultado = buscarAluguel(termoBusca);

    // exibe resultado
    printf("\nResultados:\n");
    printf("Código     | Email do cliente                             | Bicicleta | Retirada               | Retorno                | Situação  | Preço\n");

    int i = 0;
    if (!strstr(resultado[0]->cliente, "/!fim/!"))
    {
      while (!strstr(resultado[i]->cliente, "/!fim/!"))
      {
        Aluguel *alu = resultado[i];

        char aluCodigo[11] = "";
        sprintf(aluCodigo, "%d", alu->codigo);
        strcpy(aluCodigo, formatarPalavra(aluCodigo, 11));

        char *aluEmail = formatarPalavra(alu->cliente, 45);
        char *aluBici = formatarPalavra(alu->bicicleta, 10);
        char *aluSituacao = formatarPalavra(alu->situacao, 9);

        if (strstr(alu->situacao, "FECHADO"))
        {
          printf("%s| %s| %s| %s | %s | %s | R$ %.2f\n",
                 aluCodigo,
                 aluEmail,
                 aluBici,
                 saidaAluguelStr(alu),
                 retornoAluguelStr(alu),
                 aluSituacao,
                 alu->valor);
        }
        else
        {
          printf("%s| %s| %s| %s | %s | %s | R$ %s\n",
                 aluCodigo,
                 aluEmail,
                 aluBici,
                 saidaAluguelStr(alu),
                 "----------------------",
                 aluSituacao,
                 "---");
        }
        i++;

        free(aluEmail);
        free(aluBici);
        free(aluSituacao);
      }
    }
    else
    {
      printf("/i/ Nenhum aluguél encontrado!\n");
    }
    free(resultado);

    do
    {
      printf("\n");
      printf("[1] Ver Aluguel\n");
      printf("[2] Cancelar\n");
      printf(">> ");
      scanf("%1d", &opcao);
      limparBuffer();

      switch (opcao)
      {
      case 1:
        do
        {
          printf("\nDigite o código do aluguél: ");
          scanf("%d", &codigo);
          limparBuffer();

          if (aluguelExiste(codigo) == -1)
          {
            inputValido = 0;
            printf("/!/ Código inválido: o aluguél não existe\n");
          }
          else
          {
            inputValido = 1;
          }

        } while (!inputValido);

        telaVerAluguel(codigo);
        opcao = 2;
        break;
      case 2:
        break;
      default:
        msgInvalido();
      }
    } while (opcao != 1 && opcao != 2);
  } while (opcao != 2);
}

void telaRelatorioAtividades(void)
{
  int opcao = 0;
  Relatorio *rel;

  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Relatório de atividades\n");
    printf("--------------------------------------------------\n");
    printf("\n[1] Diário\n");
    printf("[2] Semanal\n");
    printf("[3] Mensal\n");
    printf("\n[4] Voltar\n");
    printf(">> ");
    scanf("%1d", &opcao);
    limparBuffer();

    switch (opcao)
    {
    case 1:
      rel = gerarRelatorio(1);
      telaRelatorio(rel, 1);
      break;
    case 2:
      rel = gerarRelatorio(7);
      telaRelatorio(rel, 7);
      break;
    case 3:
      rel = gerarRelatorio(30);
      telaRelatorio(rel, 30);
      break;
    case 4:
      break;
    default:
      msgInvalido();
    }
  } while (opcao != 4);
}

void telaRelatorio(Relatorio *rel, int dias)
{
  printf("\nAtividade nos últimos %d dias\n", dias);
  printf("Total de aluguéis alterados: %d\n", rel->total);
  printf("Aluguéis em aberto: %d\n", rel->abertos);
  printf("Aluguéis fechados: %d\n", rel->fechados);
  printf("Lucro gerado: R$ %.2f\n\n", rel->lucro);
}

void telaAlterarPreco(void)
{
  int opcao = 2;
  float novoPreco = 0.00;
  int precoValido = 0;

  do
  {
    printf("\n//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Alterar preço da hora\n");
    printf("--------------------------------------------------\n\n");

    if (opcao == 2)
    {
      printf("/!/ Lembre-se de usar . ao invés de ,\n");
      printf("Preço atual: R$ %.2f\n", lerPrecoHora());
      do
      {
        printf("Novo preço: R$ ");
        scanf("%f", &novoPreco);
        limparBuffer();

        precoValido = validaPreco(novoPreco);
      } while (!precoValido);
    }

    printf("\n\nO novo preço será R$ %.2f, deseja salvar?\n", novoPreco);
    printf("[1] Sim\n[2] Não, alterar novamente\n[3] Cancelar\n");
    printf(">> ");
    scanf("%1d", &opcao);
    limparBuffer();

    switch (opcao)
    {
    case 1:
      definirPrecoHora(novoPreco);
      msgRegistroSalvo();
      break;
    case 2:
    case 3:
      break;
    default:
      msgInvalido();
    }
  } while (opcao != 1 && opcao != 3);
}
