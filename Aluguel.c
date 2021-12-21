#include "Aluguel.h"

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
  strcpy(aluguel->cliente, cliente);
  strcpy(aluguel->bicicleta, bicicleta);

  time_t dataHoraSaida;
  time(&dataHoraSaida);

  aluguel->saida = localtime(&dataHoraSaida);
  return aluguel;
}
