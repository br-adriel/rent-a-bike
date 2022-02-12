#include "Relatorio.h"
#include "Aluguel.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

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
        }
      }
    }
  }
  fclose(arquivo);

  return relatorio;
}