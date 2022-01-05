#include "Aluguel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int getCodigo()
{
  FILE *arquivo;
  arquivo = fopen("./.codAluguel.txt", "r");

  char linha[10] = "";
  fgets(linha, sizeof(linha), arquivo);
  fclose(arquivo);

  int codigoInt = atoi(linha);
  codigoInt++;

  arquivo = fopen("./.codAluguel.txt", "w");
  fprintf(arquivo, "%d", codigoInt);
  fclose(arquivo);

  return codigoInt - 1;
}

/*
Define o preco da hora dos alugueis

Atributos:
  preco: novo valor
*/
void definirPrecoHora(float preco)
{
  FILE *arquivo;
  arquivo = fopen("./preco.txt", "w");
  fprintf(arquivo, "%f", preco);
  fclose(arquivo);
}

/*
Le o preco da hora do aluguel

Retorno:
  preco atual da hora do aluguel
*/
float lerPrecoHora()
{
  FILE *arquivo;
  char linha[50] = "";

  arquivo = fopen("./preco.txt", "a");
  fclose(arquivo);

  arquivo = fopen("./preco.txt", "r");
  fgets(linha, sizeof linha, arquivo);
  fclose(arquivo);

  return atof(linha);
}

/*
Cria um novo Aluguél

Atributos:
  Cliente: email do cliente
  Bicicleta: código da bicicleta
Return:
  Aluguel
*/
Aluguel *novoAluguel(char cliente[], char bicicleta[])
{
  Aluguel *aluguel = malloc(sizeof(Aluguel));
  sprintf(aluguel->codigo, "al%d", getCodigo());
  strcpy(aluguel->cliente, cliente);
  strcpy(aluguel->bicicleta, bicicleta);
  strcpy(aluguel->situacao, "EM ABERTO");

  aluguel->valor = lerPrecoHora();
  time_t dataHoraSaida;
  time(&dataHoraSaida);
  aluguel->saida = localtime(&dataHoraSaida);
  aluguel->retorno = localtime(&dataHoraSaida);
  return aluguel;
}

/*
Verifica se o aluguel existe

Atributos:
  saida: datetime de hora para fazer a busca
Retorna:
  A linha do arquivo em que foi encontrado ou -1
*/
int aluguelExiste(char codigo[])
{
  char linha[250] = "";
  int numLinha = -1;
  int linhaAtual = 0;

  FILE *arquivo;

  // Cria o arquivo caso seja a primeira execução
  arquivo = fopen("./alugueis.txt", "a");
  fclose(arquivo);

  // le alugueis do arquivo
  arquivo = fopen("./alugueis.txt", "r");
  while (fgets(linha, sizeof linha, arquivo) != NULL && numLinha == -1)
  {
    // verifica se a saida corresponde
    if (strstr(linha, codigo))
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
Grava o aluguel no arquivo

Atributos:
  aluguel: Aluguel a ser gravado
*/
void gravarAluguel(Aluguel *aluguel)
{
  char saidaFormatada[20];
  strftime(saidaFormatada, sizeof saidaFormatada, "%d|%m|%Y|%H|%M|%S", aluguel->saida);

  char retornoFormatado[20];
  strftime(retornoFormatado, sizeof retornoFormatado, "%d|%m|%Y|%H|%M|%S", aluguel->retorno);

  char situacao[] = "EM ABERTO";
  if (strstr(aluguel->situacao, "FECHADO"))
  {
    strcpy(situacao, "FECHADO");
  }

  FILE *arquivo;
  arquivo = fopen("./alugueis.txt", "a");
  fprintf(
      arquivo, "%s|%s|%s|%f|%s|%s|%s|\n",
      aluguel->codigo,
      aluguel->cliente,
      aluguel->bicicleta,
      aluguel->valor,
      saidaFormatada,
      retornoFormatado,
      situacao);
  fclose(arquivo);
}

/*
Funcao que converte linha de texto em Aluguel

Atributos:
  linha: string de texto
Retornos:
  Aluguel: aluguel com as informacoes passadas
*/
Aluguel *linhaParaAluguel(char linha[])
{
  Aluguel *aluguel = malloc(sizeof(Aluguel));
  char **dadosAluguel = quebrarStr(linha, '|');

  strcpy(aluguel->codigo, dadosAluguel[0]);
  strcpy(aluguel->cliente, dadosAluguel[1]);
  strcpy(aluguel->bicicleta, dadosAluguel[2]);
  aluguel->valor = atof(dadosAluguel[3]);

  // data de saida
  aluguel->saida->tm_mday = atoi(dadosAluguel[4]);
  aluguel->saida->tm_mon = atoi(dadosAluguel[5]);
  aluguel->saida->tm_year = atoi(dadosAluguel[6]);
  aluguel->saida->tm_hour = atoi(dadosAluguel[7]);
  aluguel->saida->tm_min = atoi(dadosAluguel[8]);
  aluguel->saida->tm_sec = atoi(dadosAluguel[9]);

  // data de retorno
  aluguel->retorno->tm_mday = atoi(dadosAluguel[10]);
  aluguel->retorno->tm_mon = atoi(dadosAluguel[11]);
  aluguel->retorno->tm_year = atoi(dadosAluguel[12]);
  aluguel->retorno->tm_hour = atoi(dadosAluguel[13]);
  aluguel->retorno->tm_min = atoi(dadosAluguel[14]);
  aluguel->retorno->tm_sec = atoi(dadosAluguel[15]);

  strcpy(aluguel->situacao, dadosAluguel[16]);
  return aluguel;
}

/*
Ver dados de aluguel específico

Atributos:
  codigo: codigo do aluguel
Retornos:
  Aluguel: dados do aluguel
*/
Aluguel *verAluguel(char codigo[])
{
  Aluguel *aluguel = malloc(sizeof(Aluguel));
  char linha[250] = "";

  // Cria o arquivo caso seja a primeira execução
  FILE *arquivo;
  arquivo = fopen("./alugueis.txt", "a");
  fclose(arquivo);

  // busca aluguel no arquivo
  arquivo = fopen("./alugueis.txt", "r");
  while (fgets(linha, sizeof(linha), arquivo))
  {
    // verifica se a saida corresponde
    if (strstr(linha, codigo))
    {
      aluguel = linhaParaAluguel(linha);
      fclose(arquivo);
      break;
    }
  }
  return aluguel;
}

/*
Retorna data/hora de saida do aluguel em string
*/
char *saidaAluguelStr(Aluguel *aluguel)
{
  char *saidaStr = "";
  strftime(saidaStr, 24, "%d/%m/%Y às %H:%M:%S", aluguel->saida);
  return saidaStr;
}

/*
Retorna data/hora de retorno do aluguel em string
*/
char *retornoAluguelStr(Aluguel *aluguel)
{
  char *retornoStr = "";
  strftime(retornoStr, 24, "%d/%m/%Y às %H:%M:%S", aluguel->retorno);
  return retornoStr;
}

/*
Atributos:
  termo: termo de busca
Retornos:
  Vetor de alugueis
*/
Aluguel **buscarAluguel(char termo[])
{
  Aluguel **resultado = malloc(0);
  Aluguel *aluguelAtual = malloc(sizeof(Aluguel));
  int quantidade = 0;
  FILE *arquivo;
  char linha[250];

  // Cria o arquivo caso seja a primeira execução
  FILE *arquivo;
  arquivo = fopen("./alugueis.txt", "a");
  fclose(arquivo);

  arquivo = fopen("./alugueis.txt", "r");
  while (fgets(linha, sizeof(linha), arquivo))
  {
    if (strstr(linha, termo))
    {
      aluguelAtual = linhaParaAluguel(linha);

      quantidade++;
      resultado = realloc(resultado, quantidade * sizeof(Aluguel));
      resultado[quantidade - 1] = aluguelAtual;
    }
  }

  // marca o fim do array
  aluguelAtual = linhaParaAluguel("/!fim/!|/!fim/!|/!fim/!|0.0|01|01|2000|10|10|10|01|01|2000|10|10|10|/!fim/!|\n");
  quantidade++;
  resultado = realloc(resultado, quantidade * sizeof(Aluguel));
  resultado[quantidade - 1] = aluguelAtual;
  return resultado;
}
