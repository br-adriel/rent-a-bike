#include <stdio.h>
#include "utils.h"
#include <string.h>
#include <stdlib.h>

void limparBuffer()
{
  // fonte:
  // https://stackoverflow.com/questions/7898215/how-to-clear-input-buffer-in-c
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
}

void msgInvalido(void)
{
  printf("\n/!/ Escolha inválida!\n");
}

void msgRegistroSalvo(void)
{
  printf("\n/i/ Registro salvo!\n\n");
}

void msgErro(void)
{
  printf("\n/!/ Um erro ocoreu.\n\n");
}

void msgRegistroExcluido(void)
{
  printf("\n/i/ Registro excluído!\n\n");
}

/*
Separa uma string em varias

origem: string original
pontoQuebra: carctere onde a string será dividida
*/
char **quebrarStr(char origem[], char pontoQuebra)
{
  int tamOrigem = strlen(origem);
  char **resultado = malloc(0);
  int tamTotal = 0;
  int tamPalavra = 0;
  char *palavra = malloc(0);

  for (int i = 0; i < tamOrigem; i++)
  {
    if (origem[i] == pontoQuebra)
    {
      tamPalavra++;
      palavra = realloc(palavra, tamPalavra * sizeof(char));
      palavra[tamPalavra - 1] = '\0';

      tamTotal++;
      resultado = realloc(resultado, tamTotal * sizeof(char *));
      resultado[tamTotal - 1] = palavra;
      palavra = malloc(0);
      tamPalavra = 0;
    }
    else
    {
      tamPalavra++;
      palavra = realloc(palavra, tamPalavra * sizeof(char));
      palavra[tamPalavra - 1] = origem[i];
    }
  }

  // retorna palavra se há letras apos a ultima quebra
  if (strlen(palavra) > 0)
  {
    tamPalavra++;
    palavra = realloc(palavra, tamPalavra * sizeof(char));
    palavra[tamPalavra - 1] = '\0';

    tamTotal++;
    resultado = realloc(resultado, tamTotal * sizeof(char *));
    resultado[tamTotal - 1] = palavra;
  }
  return resultado;
}

char *formatarPalavra(char palavra[], int tamanho)
{
  char *resultado = malloc(0);
  int tamPalavra = strlen(palavra);

  for (int i = 0; i < tamanho - 1; i++)
  {
    resultado = realloc(resultado, (i + 1) * sizeof(char));
    if (i < tamPalavra)
    {
      resultado[i] = palavra[i];
    }
    else
    {
      resultado[i] = ' ';
    }
  }

  resultado = realloc(resultado, tamanho * sizeof(char));
  resultado[tamanho - 1] = '\0';
  return resultado;
}

char *formatarTelefone(char telefone[])
{
  char *resultado = malloc(sizeof(char) * 16);
  resultado[0] = '(';

  int iRes = 1;
  for (int i = 0; i < 2; i++)
  {
    resultado[iRes] = telefone[i];
    iRes++;
  }

  resultado[3] = ')';
  resultado[4] = ' ';
  iRes = 5;
  for (int i = 2; i < 7; i++)
  {
    resultado[iRes] = telefone[i];
    iRes++;
  }

  resultado[10] = '-';
  iRes = 11;
  for (int i = 7; i < 12; i++)
  {
    resultado[iRes] = telefone[i];
    iRes++;
  }

  resultado[iRes] = '\0';
  return resultado;
}
