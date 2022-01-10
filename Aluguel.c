#include "Aluguel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include <time.h>

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
  sprintf(aluguel->codigo, "r%db", getCodigo());
  strcpy(aluguel->cliente, cliente);
  strcpy(aluguel->bicicleta, bicicleta);
  strcpy(aluguel->situacao, "EM ABERTO");

  aluguel->valor = lerPrecoHora();
  time_t dataHora;
  time(&dataHora);
  struct tm *dataHoraTm = localtime(&dataHora);

  // data de saida
  aluguel->saida.tm_mday = dataHoraTm->tm_mday;
  aluguel->saida.tm_mon = dataHoraTm->tm_mon - 1;
  aluguel->saida.tm_year = dataHoraTm->tm_year - 1900;
  aluguel->saida.tm_hour = dataHoraTm->tm_hour;
  aluguel->saida.tm_min = dataHoraTm->tm_min;
  aluguel->saida.tm_sec = dataHoraTm->tm_sec;

  // data de retorno
  aluguel->retorno.tm_mday = dataHoraTm->tm_mday;
  aluguel->retorno.tm_mon = dataHoraTm->tm_mon - 1;
  aluguel->retorno.tm_year = dataHoraTm->tm_year - 1900;
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

  time_t tempo;
  time(&tempo);
  struct tm *saidaAluguel = localtime(&tempo);

  saidaAluguel->tm_mday = aluguel->saida.tm_mday;
  saidaAluguel->tm_mon = aluguel->saida.tm_mon + 1;
  saidaAluguel->tm_year = aluguel->saida.tm_year + 1900;
  saidaAluguel->tm_hour = aluguel->saida.tm_hour;
  saidaAluguel->tm_min = aluguel->saida.tm_min;
  saidaAluguel->tm_sec = aluguel->saida.tm_sec;

  strftime(saidaFormatada, sizeof saidaFormatada, "%d|%m|%Y|%H|%M|%S", saidaAluguel);

  char retornoFormatado[20];

  struct tm *retornoAluguel = localtime(&tempo);
  retornoAluguel->tm_mday = aluguel->retorno.tm_mday;
  retornoAluguel->tm_mon = aluguel->retorno.tm_mon + 1;
  retornoAluguel->tm_year = aluguel->retorno.tm_year + 1900;
  retornoAluguel->tm_hour = aluguel->retorno.tm_hour;
  retornoAluguel->tm_min = aluguel->retorno.tm_min;
  retornoAluguel->tm_sec = aluguel->retorno.tm_sec;

  strftime(retornoFormatado, sizeof retornoFormatado, "%d|%m|%Y|%H|%M|%S", retornoAluguel);

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
  aluguel->saida.tm_mday = atoi(dadosAluguel[4]);
  aluguel->saida.tm_mon = atoi(dadosAluguel[5]) - 1;
  aluguel->saida.tm_year = atoi(dadosAluguel[6]) - 1900;
  aluguel->saida.tm_hour = atoi(dadosAluguel[7]);
  aluguel->saida.tm_min = atoi(dadosAluguel[8]);
  aluguel->saida.tm_sec = atoi(dadosAluguel[9]);

  // data de retorno
  aluguel->retorno.tm_mday = atoi(dadosAluguel[10]);
  aluguel->retorno.tm_mon = atoi(dadosAluguel[11]) - 1;
  aluguel->retorno.tm_year = atoi(dadosAluguel[12]) - 1900;
  aluguel->retorno.tm_hour = atoi(dadosAluguel[13]);
  aluguel->retorno.tm_min = atoi(dadosAluguel[14]);
  aluguel->retorno.tm_sec = atoi(dadosAluguel[15]);

  strcpy(aluguel->situacao, dadosAluguel[16]);

  for (int i = 0; i < 18; i++)
  {
    free(dadosAluguel[i]);
  }
  free(dadosAluguel);
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
    // verifica se o codigo corresponde
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
  int quantidade = 0;
  FILE *arquivo;
  char linha[250];

  // Cria o arquivo caso seja a primeira execução
  arquivo = fopen("./alugueis.txt", "a");
  fclose(arquivo);

  arquivo = fopen("./alugueis.txt", "r");
  while (fgets(linha, sizeof(linha), arquivo))
  {
    if (strstr(linha, termo))
    {
      Aluguel *aluguelAtual = malloc(sizeof(Aluguel));
      aluguelAtual = linhaParaAluguel(linha);

      quantidade++;
      resultado = realloc(resultado, quantidade * sizeof(Aluguel));
      resultado[quantidade - 1] = aluguelAtual;
    }
  }

  // marca o fim do array
  Aluguel *aluguelAtual = malloc(sizeof(Aluguel));
  aluguelAtual = linhaParaAluguel("/!fim/!|/!fim/!|/!fim/!|0.0|01|01|2000|10|10|10|01|01|2000|10|10|10|/!fim/!|\n");
  quantidade++;
  resultado = realloc(resultado, quantidade * sizeof(Aluguel));
  resultado[quantidade - 1] = aluguelAtual;
  return resultado;
}

// Atualiza aluguel em aberto e calcula preco
void fecharAluguel(char codigo[])
{
  Aluguel *aluguel = verAluguel(codigo);
  if (strstr(aluguel->situacao, "EM ABERTO"))
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

    char linha[250] = "";
    FILE *arquivo, *temp;
    arquivo = fopen("./alugueis.txt", "r");
    temp = fopen("./alugueis.temp.txt", "a");

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
      // verifica se o codigo corresponde
      if (strstr(linha, codigo))
      {
        fprintf(
            temp, "%s|%s|%s|%f|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%d|%s|\n",
            aluguel->codigo,
            aluguel->cliente,
            aluguel->bicicleta,
            aluguel->valor,
            aluguel->saida.tm_mday,
            aluguel->saida.tm_mon + 1,
            aluguel->saida.tm_year + 1900,
            aluguel->saida.tm_hour,
            aluguel->saida.tm_min,
            aluguel->saida.tm_sec,
            aluguel->retorno.tm_mday,
            aluguel->retorno.tm_mon + 1,
            aluguel->retorno.tm_year + 1900,
            aluguel->retorno.tm_hour,
            aluguel->retorno.tm_min,
            aluguel->retorno.tm_sec,
            aluguel->situacao);
      }
      else
      {
        fprintf(temp, "%s", linha);
      }
    }

    fclose(temp);
    fclose(arquivo);

    // deleta arquivo desatualizado e renomeia temporario
    remove("./alugueis.txt");
    rename("./alugueis.temp.txt", "./alugueis.txt");
  }
}
