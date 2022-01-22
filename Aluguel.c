#include "Aluguel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include <time.h>

int getCodigo()
{
  FILE *arquivo;
  arquivo = fopen("./codAluguel.dat", "rb");

  int codigo = 0;
  fread(&codigo, sizeof(int), 1, arquivo);
  fclose(arquivo);

  codigo++;

  arquivo = fopen("./codAluguel.dat", "wb");
  fwrite(&codigo, sizeof(int), 1, arquivo);
  fclose(arquivo);
  return codigo;
}

/*
Define o preco da hora dos alugueis

Atributos:
  preco: novo valor
*/
void definirPrecoHora(float preco)
{
  FILE *arquivo;
  arquivo = fopen("./preco.dat", "wb");
  fwrite(&preco, sizeof(float), 1, arquivo);
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

  arquivo = fopen("./preco.dat", "ab");
  fclose(arquivo);

  float preco;

  arquivo = fopen("./preco.dat", "rb");
  fread(&preco, sizeof(float), 1, arquivo);

  fclose(arquivo);

  return preco;
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

  aluguel->codigo = getCodigo();
  aluguel->ativo = 1;

  strcpy(aluguel->cliente, cliente);
  strcpy(aluguel->bicicleta, bicicleta);
  strcpy(aluguel->situacao, "EM ABERTO");

  aluguel->valor = lerPrecoHora();
  time_t dataHora;
  time(&dataHora);
  struct tm *dataHoraTm = localtime(&dataHora);

  // data de saida
  aluguel->saida.tm_mday = dataHoraTm->tm_mday;
  aluguel->saida.tm_mon = dataHoraTm->tm_mon;
  aluguel->saida.tm_year = dataHoraTm->tm_year;
  aluguel->saida.tm_hour = dataHoraTm->tm_hour;
  aluguel->saida.tm_min = dataHoraTm->tm_min;
  aluguel->saida.tm_sec = dataHoraTm->tm_sec;

  // data de retorno
  aluguel->retorno.tm_mday = dataHoraTm->tm_mday;
  aluguel->retorno.tm_mon = dataHoraTm->tm_mon;
  aluguel->retorno.tm_year = dataHoraTm->tm_year;
  aluguel->retorno.tm_hour = dataHoraTm->tm_hour;
  aluguel->retorno.tm_min = dataHoraTm->tm_min;
  aluguel->retorno.tm_sec = dataHoraTm->tm_sec;
  return aluguel;
}

/*
Verifica se o aluguel existe

Atributos:
  saida: datetime de hora para fazer a busca
Retorna:
  A linha do arquivo em que foi encontrado ou -1
*/
int aluguelExiste(int codigo)
{
  int numLinha = -1;
  int linhaAtual = 0;

  FILE *arquivo;

  Aluguel *alu;
  alu = (Aluguel *)malloc(sizeof(Aluguel));

  // Cria o arquivo caso seja a primeira execução
  arquivo = fopen("./alugueis.dat", "ab");
  fclose(arquivo);

  // le alugueis do arquivo
  arquivo = fopen("./alugueis.dat", "rb");
  while (fread(alu, sizeof(Aluguel), 1, arquivo) && numLinha == -1)
  {
    // verifica se o codigo corresponde
    if (alu->codigo == codigo && alu->ativo)
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
int gravarAluguel(Aluguel *aluguel)
{
  if (aluguelExiste(aluguel->codigo) != -1)
  {
    return 0;
  }

  FILE *arquivo;
  arquivo = fopen("./alugueis.dat", "ab");
  fwrite(aluguel, sizeof(Aluguel), 1, arquivo);
  fclose(arquivo);
  return 1;
}

/*
Ver dados de aluguel específico

Atributos:
  codigo: codigo do aluguel
Retornos:
  Aluguel: dados do aluguel
*/
Aluguel *verAluguel(int codigo)
{
  Aluguel *aluguel = malloc(sizeof(Aluguel));

  // Cria o arquivo caso seja a primeira execução
  FILE *arquivo;
  arquivo = fopen("./alugueis.dat", "ab");
  fclose(arquivo);

  // busca aluguel no arquivo
  arquivo = fopen("./alugueis.dat", "rb");
  while (fread(aluguel, sizeof(Aluguel), 1, arquivo))
  {
    // verifica se o codigo corresponde
    if (aluguel->codigo == codigo && aluguel->ativo)
    {
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
  char saidaStr[30] = "";

  time_t tempo;
  time(&tempo);
  struct tm *saidaAluguel = localtime(&tempo);
  saidaAluguel->tm_mday = aluguel->saida.tm_mday;
  saidaAluguel->tm_mon = aluguel->saida.tm_mon;
  saidaAluguel->tm_year = aluguel->saida.tm_year;
  saidaAluguel->tm_hour = aluguel->saida.tm_hour;
  saidaAluguel->tm_min = aluguel->saida.tm_min;
  saidaAluguel->tm_sec = aluguel->saida.tm_sec;

  strftime(saidaStr, sizeof(saidaStr), "%d/%m/%Y às %H:%M:%S", saidaAluguel);
  return strndup(saidaStr, sizeof(saidaStr));
}

/*
Retorna data/hora de retorno do aluguel em string
*/
char *retornoAluguelStr(Aluguel *aluguel)
{
  char retornoStr[30] = "";

  time_t tempo;
  time(&tempo);
  struct tm *retornoAluguel = localtime(&tempo);

  retornoAluguel->tm_mday = aluguel->retorno.tm_mday;
  retornoAluguel->tm_mon = aluguel->retorno.tm_mon;
  retornoAluguel->tm_year = aluguel->retorno.tm_year;
  retornoAluguel->tm_hour = aluguel->retorno.tm_hour;
  retornoAluguel->tm_min = aluguel->retorno.tm_min;
  retornoAluguel->tm_sec = aluguel->retorno.tm_sec;

  strftime(retornoStr, sizeof(retornoStr), "%d/%m/%Y às %H:%M:%S", retornoAluguel);
  return strndup(retornoStr, sizeof(retornoStr));
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
  Aluguel *aluguelAtual;

  aluguelAtual = (Aluguel *)malloc(sizeof(Aluguel));
  int quantidade = 0;
  FILE *arquivo;

  arquivo = fopen("./alugueis.dat", "rb");
  while (fread(aluguelAtual, sizeof(Aluguel), 1, arquivo))
  {
    if (
        aluguelAtual->ativo &&
        (aluguelAtual->codigo == atoi(termo) ||
         strstr(aluguelAtual->bicicleta, termo) ||
         strstr(aluguelAtual->cliente, termo) ||
         strstr(aluguelAtual->situacao, termo) ||
         aluguelAtual->valor == atof(termo) ||
         strstr(saidaAluguelStr(aluguelAtual), termo) ||
         strstr(retornoAluguelStr(aluguelAtual), termo)))
    {
      quantidade++;
      resultado = realloc(resultado, quantidade * sizeof(Aluguel));

      Aluguel *alu = malloc(sizeof(Aluguel));
      memcpy(alu, aluguelAtual, sizeof(Aluguel));
      resultado[quantidade - 1] = alu;
    }
  }

  fclose(arquivo);

  // marca o fim do array
  Aluguel *aluguelFim = malloc(sizeof(Aluguel));
  strcpy(aluguelFim->cliente, "/!fim/!");
  strcpy(aluguelFim->bicicleta, "/!fim/!");

  quantidade++;
  resultado = realloc(resultado, quantidade * sizeof(Aluguel));
  resultado[quantidade - 1] = aluguelFim;
  return resultado;
}

// Atualiza aluguel em aberto e calcula preco
int fecharAluguel(int codigo)
{
  Aluguel *aluguel = verAluguel(codigo);
  if (strstr(aluguel->situacao, "EM ABERTO") && aluguel->ativo)
  {
    strcpy(aluguel->situacao, "FECHADO");

    time_t dataHoraRetorno;
    time(&dataHoraRetorno);
    struct tm *dataHoraTmRet = localtime(&dataHoraRetorno);

    aluguel->retorno.tm_mday = dataHoraTmRet->tm_mday;
    aluguel->retorno.tm_mon = dataHoraTmRet->tm_mon;
    aluguel->retorno.tm_year = dataHoraTmRet->tm_year;
    aluguel->retorno.tm_hour = dataHoraTmRet->tm_hour;
    aluguel->retorno.tm_min = dataHoraTmRet->tm_min;
    aluguel->retorno.tm_sec = dataHoraTmRet->tm_sec;

    time_t tempo;
    time(&tempo);
    struct tm *dataHoraTmSai = localtime(&tempo);
    dataHoraTmSai->tm_mday = aluguel->saida.tm_mday;
    dataHoraTmSai->tm_mon = aluguel->saida.tm_mon;
    dataHoraTmSai->tm_year = aluguel->saida.tm_year;
    dataHoraTmSai->tm_hour = aluguel->saida.tm_hour;
    dataHoraTmSai->tm_min = aluguel->saida.tm_min;
    dataHoraTmSai->tm_sec = aluguel->saida.tm_sec;

    // calcula tempo percorrido em segundos
    float tempoPercorrido = difftime(dataHoraRetorno, mktime(dataHoraTmSai));
    tempoPercorrido = tempoPercorrido / 3600; // transforma em horas

    // calcula preco do aluguel
    aluguel->valor = aluguel->valor * tempoPercorrido;

    FILE *arquivo;
    arquivo = fopen("./alugueis.dat", "r+b");

    Aluguel *alu = malloc(sizeof(Aluguel));

    while (fread(alu, sizeof(Aluguel), 1, arquivo))
    {
      // verifica se o codigo corresponde
      if (alu->codigo == codigo && alu->ativo)
      {
        fseek(arquivo, -1 * sizeof(Aluguel), SEEK_CUR);

        fwrite(aluguel, sizeof(Aluguel), 1, arquivo);
        fclose(arquivo);
        return 1;
      }
    }
    return 0;
  }
  return 0;
}

int excluirAluguel(int codigo)
{
  if (aluguelExiste(codigo) == -1)
  {
    return 0;
  }

  FILE *arquivo;
  arquivo = fopen("./alugueis.dat", "r+b");

  Aluguel *alu = malloc(sizeof(Aluguel));

  while (fread(alu, sizeof(Aluguel), 1, arquivo))
  {
    if (alu->codigo == codigo && alu->ativo)
    {
      fseek(arquivo, -1 * sizeof(Aluguel), SEEK_CUR);

      alu->ativo = 0;

      fwrite(alu, sizeof(Aluguel), 1, arquivo);
      fclose(arquivo);
      break;
    }
  }
  return 1;
}
