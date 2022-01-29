#include <stdio.h>
#include "telasAluguel.h"
#include "telasCliente.h"
#include "telasBicicleta.h"
#include "utils.h"
#include "Aluguel.h"
#include "validadores.h"

void telaInicial(void);
void telaSobre(void);
void telaBoasVindas(void);

int main(void)
{
  if (lerPrecoHora() <= 0)
  {
    telaBoasVindas();
  }
  telaInicial();
  return 0;
}

void telaBoasVindas(void)
{
  float novoPreco = 0.0;
  int precoValido = 0;
  int opcao = 0;

  printf("//////////////////////////////////////////////////\n");
  printf("RENT A BIKE - Boas vindas\n");
  printf("--------------------------------------------------\n\n");
  printf("Obrigado por escolher o Rent a Bike como seu sistema\n");
  printf("de gerenciamento de aluguéis.\n\n");
  printf("Para começar a utilizar o software defina o preço da\n");
  printf("hora de uso.\n");

  printf("\n/!/ Lembre-se de usar . ao invés de ,\n");
  do
  {
    do
    {
      printf("Novo preço: R$ ");
      scanf("%f", &novoPreco);
      limparBuffer();

      precoValido = validaPreco(novoPreco);
      printf("\n");
    } while (!precoValido);

    printf("\nO preço será R$ %.2f, deseja salvar?\n", novoPreco);
    printf("[1] Sim\n[2] Não, alterar\n");
    printf(">> ");
    scanf("%1d", &opcao);

    limparBuffer();
    switch (opcao)
    {
    case 1:
      definirPrecoHora(novoPreco);
    case 2:
      break;
    default:
      msgInvalido();
    }
  } while (opcao != 1);
}

void telaInicial(void)
{
  int opcao = 0;
  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Página inicial\n");
    printf("--------------------------------------------------\n");
    printf("\n[1] Gerenciar aluguéis\n");
    printf("[2] Gerenciar clientes\n");
    printf("[3] Gerenciar bicicletas\n\n");
    printf("[4] Sobre\n");
    printf("[5] Encerrar\n");
    printf(">> ");
    scanf("%1d", &opcao);
    limparBuffer();
    printf("\n");

    switch (opcao)
    {
    case 1:
      telaGerenciarAlugueis();
      break;
    case 2:
      telaGerenciarClientes();
      break;
    case 3:
      telaGerenciarBicicletas();
      break;
    case 4:
      telaSobre();
      break;
    case 5:
      break;
    default:
      msgInvalido();
    }
  } while (opcao != 5);
}

void telaSobre(void)
{
  int opcao = 0;

  do
  {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Sobre\n");
    printf("--------------------------------------------------\n\n");
    printf("Versão: 0.12\n");
    printf("Última atualização: 22/01/2022\n");
    printf("Desenvolvido por Adriel Faria dos Santos\n");
    printf("\n--------------------------------------------------\n");
    printf("\n");
    printf("[1] Voltar\n");
    printf(">> ");
    scanf("%1d", &opcao);
    limparBuffer();
    printf("\n");

    switch (opcao)
    {
    case 1:
      break;
    default:
      msgInvalido();
    }
  } while (opcao != 1);
}
