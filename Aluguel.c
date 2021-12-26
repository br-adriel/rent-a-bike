#include "Aluguel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *getCodigo()
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
  sprintf(aluguel->codigo, "%d", getCodigo());
  strcpy(aluguel->cliente, cliente);
  strcpy(aluguel->bicicleta, bicicleta);

  aluguel->valor = lerPrecoHora();

  time_t dataHoraSaida;
  time(&dataHoraSaida);
  aluguel->saida = localtime(&dataHoraSaida);
  aluguel->retorno = localtime(&dataHoraSaida);
  return aluguel;
}
