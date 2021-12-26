#include <stdio.h>
#include "utils.h"
#include "telasAluguel.h"
#include "validadores.h"
#include <limits.h>
#include "Aluguel.h"

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
    printf("[3] Relatório de lucros\n");
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
      telaRelatorioLucros();
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
  int horasUso = 0;
  int minutosUso = 0;
  char emailCliente[PATH_MAX] = "";
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
        printf("\nHoras em uso: ");
        scanf("%d", &horasUso);
        limparBuffer();

        inputValido = validaHora(horasUso);
      } while (!inputValido);

      do
      {
        printf("\nMinutos em uso: ");
        scanf("%2d", &minutosUso);
        limparBuffer();

        inputValido = validaMinutos(minutosUso);
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
    printf("Tempo em uso: %dh %dmin\n", horasUso, minutosUso);
    printf("Código da bicicleta: %s\n", codBicicleta);
    printf("Preço: R$ 32.21\n");
    printf("Data de emissão: 31/12/9999");
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
      printf("\n= = = = = = = =");
      printf("\nRegistro salvo!");
      printf("\n= = = = = = = =\n\n");
      break;
    }
  } while (opcao == 2);
}

void telaVerAluguel(char codigo[])
{
  int opcao = 3;
  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Aluguél #%s\n", codigo);
    printf("--------------------------------------------------\n");
    printf("-- Cliente ---------------------------------------\n");
    printf("Nome: Fulano Sicrano\n");
    printf("Email: fulano@email.com\n");
    printf("-- Bicicleta -------------------------------------\n");
    printf("Código: 123456\n");
    printf("Cor: Azul\n");
    printf("Situação: Em manutenção\n");
    printf("-- Aluguél ------------------------------------\n");
    printf("Tempo em uso: 1h 15min\n");
    printf("Preço: R$ 32.21\n");
    printf("Data de emissão: 31/12/9999");
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
      telaEditarAluguel(codigo);
      break;
    case 2:
      telaExcluirAluguel(codigo);
      opcao = 3;
      break;
    case 3:
      break;
    default:
      msgInvalido();
    }
  } while (opcao != 3);
}

void telaEditarAluguel(char codigo[])
{
  int opcao = 2;

  char codBicicleta[PATH_MAX] = "";
  int horasUso = 0;
  int minutosUso = 0;
  char emailCliente[PATH_MAX] = "";
  int inputValido = 0;

  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Editar aluguél #%s", codigo);
    if (opcao == 2)
    {
      do
      {
        printf("\n--------------------------------------------------\n");
        printf("\nCódigo da bicicleta [123456]: ");
        scanf("%s", codBicicleta);
        limparBuffer();

        inputValido = validaCodigo(codBicicleta, 6);
      } while (!inputValido);

      do
      {
        printf("\nHoras em uso [1]: ");
        scanf("%d", &horasUso);
        limparBuffer();

        inputValido = validaHora(horasUso);
      } while (!inputValido);

      do
      {
        printf("\nMinutos em uso [30]: ");
        scanf("%2d", &minutosUso);
        limparBuffer();

        inputValido = validaMinutos(minutosUso);
      } while (!inputValido);

      do
      {
        printf("\nEmail do cliente [fulano@email.com]: ");
        scanf("%s", emailCliente);
        limparBuffer();

        inputValido = validaEmail(emailCliente);
      } while (!inputValido);
    }
    printf("\n\n--------------------------------------------------\n\n");
    printf("Código da bicicleta: %s\n", codBicicleta);
    printf("Horas em uso: %d\n", horasUso);
    printf("Minutos em uso: %d\n", minutosUso);
    printf("Email do cliente: %s\n", emailCliente);
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
      // Salva mudanças
      printf("\n= = = = = = = = = =");
      printf("\nAlterações salvas!");
      printf("\n= = = = = = = = = =\n\n");
      break;
    case 2:
    case 3:
      break;
    default:
      msgInvalido();
      break;
    }
  } while (opcao != 1 && opcao != 3);
}

void telaExcluirAluguel(char codigo[])
{
  int opcao = 0;

  do
  {
    printf("\n");
    printf("Excluir aluguél #%s?", codigo);
    printf("\n[1] Sim\n[2] Não");
    printf("\n>> ");
    scanf("%1d", &opcao);
    limparBuffer();
    printf("\n");

    switch (opcao)
    {
    case 1:
      printf("\n= = = = = = = = = =");
      printf("\nAluguél #%s excluído!", codigo);
      printf("\n= = = = = = = = = =\n\n");
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
  int dia = 0;
  int mes = 0;
  int ano = 0;
  int inputValido = 0;
  char codigo[PATH_MAX];
  int dataValida = 0;

  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Buscar aluguél\n");
    printf("--------------------------------------------------\n");
    do
    {
      printf("\nData do aluguél (DD/MM/AAAA): ");
      scanf("%d/%d/%d", &dia, &mes, &ano);

      dataValida = validaData(dia, mes, ano);
    } while (!dataValida);
    limparBuffer();

    printf("\n");
    // faz a busca
    printf("\n--------------------------------------------------\n");
    printf("\nResultados:\n");
    printf("Código | Email do cliente | Preço    | Data\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
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
        scanf("%s", codigo);
        limparBuffer();

        inputValido = validaCodigo(codigo, 6);
      } while (!inputValido);

      telaVerAluguel(codigo);
      break;
    case 2:
      break;
    default:
      msgInvalido();
    }
  } while (opcao != 2);
}

void telaRelatorioLucros(void)
{
  int opcao = 0;

  do
  {
    if (opcao == 0)
    {
      printf("//////////////////////////////////////////////////\n");
      printf("RENT A BIKE - Relatório de lucros\n");
      printf("--------------------------------------------------\n");
      printf("\n[1] Diário\n");
      printf("[2] Semanal\n");
      printf("[3] Mensal\n");
      printf("\n[4] Voltar\n");
      printf(">> ");
      scanf("%1d", &opcao);
      limparBuffer();

      if (opcao == 4)
      {
        break;
      }

      printf("\n");
      printf("\nGerando relatório...\n");
    }

    printf("\n-- Relatório 12/02/2020 ---------------------------\n");
    printf("Aluguéis: 230\n");
    printf("Lucro total: R$ 250.32\n");
    printf("\n-- Detalhamento -----------------------------------\n");
    printf("Código | Cliente          | Preco    | Data\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("\n");
    printf("Exportar?\n");
    printf("[1] Sim\n[2] Não\n");
    printf(">> ");
    scanf("%1d", &opcao);
    limparBuffer();

    switch (opcao)
    {
    case 1:
      printf("\n= = = = = = = = = = = = = = = = = = = = = = = = =");
      printf("\nExportado para o arquivo \"Extrato-2021-11-05.txt\"");
      printf("\n= = = = = = = = = = = = = = = = = = = = = = = = =\n");
      break;
    case 2:
      break;
    default:
      msgInvalido();
    }
  } while (opcao != 1 && opcao != 2);
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
