#include "Relatorio.h"
#include "Aluguel.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

/* Fonte da lógica por trás da lista estrutura*/
/* https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/tutorial/ */

struct item
{
  Aluguel *aluguel;
  struct item *prox;
};

typedef struct item *Item;

Item novoItem()
{
  Item temp;
  temp = (Item)malloc(sizeof(struct item));
  temp->prox = NULL;
  return temp;
}

Item adicionarItem(Item inicio, Aluguel *aluguel)
{
  Item temp, aux;
  temp = novoItem();
  temp->aluguel = aluguel;
  if (inicio == NULL)
  {
    inicio = temp;
  }
  else
  {
    aux = inicio;
    while (aux->prox != NULL)
    {
      aux = aux->prox;
    }
    aux->prox = temp;
  }
  return inicio;
}

Relatorio *gerarRelatorio(int dias)
{
  Relatorio *relatorio = malloc(sizeof(Relatorio));

  // inicializacao de variaveis
  relatorio->abertos = 0;
  relatorio->fechados = 0;
  relatorio->total = 0;
  relatorio->lucro = 0;

  // data da geracao do relatorio
  time_t hoje;
  time(&hoje);

  Aluguel *aluguelAtual;
  aluguelAtual = (Aluguel *)malloc(sizeof(Aluguel));

  FILE *arquivo;
  arquivo = fopen("./alugueis.dat", "rb");

  Item comecoAbertos = malloc(sizeof(struct item));
  comecoAbertos = NULL;

  Item comecoFechados = malloc(sizeof(struct item));
  comecoFechados = NULL;

  while (fread(aluguelAtual, sizeof(Aluguel), 1, arquivo))
  {
    if (aluguelAtual->ativo)
    {

      if (strstr(aluguelAtual->situacao, "FECHADO"))
      {
        float diferenca = difftime(hoje, mktime(&(aluguelAtual->retorno)));
        float diferencaDias = diferenca / 86400;
        if (diferencaDias <= dias)
        {
          relatorio->total++;
          relatorio->fechados++;
          relatorio->lucro = relatorio->lucro + aluguelAtual->valor;

          Aluguel *alu = malloc(sizeof(Aluguel));
          memcpy(alu, aluguelAtual, sizeof(Aluguel));
          comecoFechados = adicionarItem(comecoFechados, alu);
        }
      }
      else
      {
        float diferenca = difftime(hoje, mktime(&(aluguelAtual->saida)));
        float diferencaDias = diferenca / 86400;
        if (diferencaDias <= dias)
        {
          relatorio->total++;
          relatorio->abertos++;

          Aluguel *alu = malloc(sizeof(Aluguel));
          memcpy(alu, aluguelAtual, sizeof(Aluguel));
          comecoAbertos = adicionarItem(comecoAbertos, alu);
        }
      }
    }
  }
  fclose(arquivo);

  printf("ALUGUÉIS EM ABERTO:\n");
  printf("Código     | Email do cliente                             | Bicicleta | Retirada               \n");
  Item atual;
  atual = comecoAbertos;

  while (atual != NULL)
  {
    char *aluEmail = formatarPalavra(atual->aluguel->cliente, 45);
    char *aluBici = formatarPalavra(atual->aluguel->bicicleta, 10);

    char aluCodigo[11] = "";
    sprintf(aluCodigo, "%d", atual->aluguel->codigo);
    strcpy(aluCodigo, formatarPalavra(aluCodigo, 11));
    printf("%s| %s| %s| %s\n",
           aluCodigo,
           aluEmail,
           aluBici,
           saidaAluguelStr(atual->aluguel));

    free(aluEmail);
    free(aluBici);
    atual = atual->prox;
  }
  printf("\n");

  printf("ALUGUÉIS FECHADOS:\n");
  printf("Código     | Email do cliente                             | Bicicleta | Retirada               | Retorno                | Preço\n");

  atual = comecoFechados;
  while (atual != NULL)
  {
    char *aluEmail = formatarPalavra(atual->aluguel->cliente, 45);
    char *aluBici = formatarPalavra(atual->aluguel->bicicleta, 10);

    char aluCodigo[11] = "";
    sprintf(aluCodigo, "%d", atual->aluguel->codigo);
    strcpy(aluCodigo, formatarPalavra(aluCodigo, 11));

    printf("%s| %s| %s| %s | %s | R$ %.2f\n",
           aluCodigo,
           aluEmail,
           aluBici,
           saidaAluguelStr(atual->aluguel),
           retornoAluguelStr(atual->aluguel),
           atual->aluguel->valor);
    free(aluEmail);
    free(aluBici);
    atual = atual->prox;
  }
  return relatorio;
}