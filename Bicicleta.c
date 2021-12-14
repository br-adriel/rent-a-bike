#include "Bicicleta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Bicicleta *verBicicleta(char[]);
// int atualizarBicicleta(char[], char[], char[], char[]);
// int excluirBicicleta(char[]);
// Bicicleta **buscaBicicleta(char[]);
// Bicicleta *linhaParaBicicleta(char[]);
