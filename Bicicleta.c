#include "Bicicleta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/*
Cria uma nova Bicicleta

Atributos:
  codigo: identificador unico
  cor: cor da bicicleta
  categoria: tipo de bicicleta
  disponivel: se disponivel para aluguel
Return:
  Bicicleta
*/
Bicicleta *novaBicicleta(char codigo[], char cor[], char categoria[], int disponivel)
{
  Bicicleta *bicicleta = malloc(sizeof(Bicicleta));
  strcpy(bicicleta->codigo, codigo);
  strcpy(bicicleta->cor, cor);
  strcpy(bicicleta->categoria, categoria);
  bicicleta->disponivel = disponivel;
  return bicicleta;
}

/*
Verifica se a bicicleta existe

Atributos:
  codigo: codigo para fazer a busca
Retorna:
  A linha do arquivo em que foi encontrada ou -1
*/
int bicicletaExiste(char codigo[])
{
  char linha[70] = "";
  int numLinha = -1;
  int linhaAtual = 0;

  FILE *arquivo;

  // Cria o arquivo caso seja a primeira execução
  arquivo = fopen("./bicicletas.txt", "a");
  fclose(arquivo);

  // le bicicletas do arquivo
  arquivo = fopen("./bicicletas.txt", "r");
  while (fgets(linha, sizeof(linha), arquivo) != NULL && numLinha == -1)
  {
    // verifica se o codigo corresponde
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
Verifica se a bicicleta existe

Atributos:
  codigo: codigo para fazer a busca
Retorna:
  A linha do arquivo em que foi encontrada ou -1
*/
int gravarBicicleta(Bicicleta *bicicleta)
{
  if (bicicletaExiste(bicicleta->codigo) != -1)
  {
    return 0;
  }

  FILE *arquivo;
  arquivo = fopen("./bicicletas.txt", "a");
  fprintf(arquivo, "%s|%d|%s|%s|\n", bicicleta->codigo, bicicleta->disponivel, bicicleta->cor, bicicleta->categoria);
  fclose(arquivo);
  return 1;
};

Bicicleta *verBicicleta(char codigo[])
{
  Bicicleta *bicicleta = malloc(sizeof(Bicicleta));
  char linha[70] = "";

  FILE *arquivo;
  // Cria o arquivo caso seja a primeira execução
  arquivo = fopen("./bicicletas.txt", "a");
  fclose(arquivo);

  // busca bicicleta no arquivo
  arquivo = fopen("./bicicletas.txt", "r");
  while (fgets(linha, sizeof(linha), arquivo))
  {
    // verifica se o código corresponde
    if (strstr(linha, codigo))
    {
      bicicleta = linhaParaBicicleta(linha);
      fclose(arquivo);
      break;
    }
  }
  return bicicleta;
};

// int atualizarBicicleta(char[], char[], char[], char[]);
// int excluirBicicleta(char[]);
// Bicicleta **buscaBicicleta(char[]);

/*
Funcao que converte linha de texto em Bicicleta

Atributos:
  linha: "codigo|disponivel|cor|categoria|\n"
Retornos:
  Bicicleta: bicicleta com as informacoes passadas
*/
Bicicleta *linhaParaBicicleta(char linha[])
{
  Bicicleta *bicicleta = malloc(sizeof(Bicicleta));
  char **dadosBicicleta = quebrarStr(linha, '|');
  strcpy(bicicleta->codigo, dadosBicicleta[0]);
  bicicleta->disponivel = atoi(dadosBicicleta[1]);
  strcpy(bicicleta->cor, dadosBicicleta[2]);
  strcpy(bicicleta->categoria, dadosBicicleta[3]);

  for (int i = 0; i < 5; i++)
  {
    free(dadosBicicleta[i]);
  }
  free(dadosBicicleta);
  return bicicleta;
}
