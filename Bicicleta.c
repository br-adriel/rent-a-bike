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
  strcpy(bicicleta->disponivel, disponivel ? "SIM" : "NÃO");
  bicicleta->ativa = 1;
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
  int numLinha = -1;
  int linhaAtual = 0;

  Bicicleta *bic;
  bic = (Bicicleta *)malloc(sizeof(Bicicleta));

  FILE *arquivo;

  // Cria o arquivo caso seja a primeira execução
  arquivo = fopen("./bicicletas.dat", "ab");
  fclose(arquivo);

  // le bicicletas do arquivo
  arquivo = fopen("./bicicletas.dat", "rb");
  while (fread(bic, sizeof(Bicicleta), 1, arquivo) && numLinha == -1)
  {
    // verifica se o codigo corresponde
    if (strcmp(bic->codigo, codigo) == 0 && bic->ativa)
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
  arquivo = fopen("./bicicletas.dat", "ab");
  fwrite(bicicleta, sizeof(Bicicleta), 1, arquivo);
  fclose(arquivo);
  return 1;
};

Bicicleta *verBicicleta(char codigo[])
{
  Bicicleta *bicicleta = malloc(sizeof(Bicicleta));

  FILE *arquivo;
  // Cria o arquivo caso seja a primeira execução
  arquivo = fopen("./bicicletas.dat", "ab");
  fclose(arquivo);

  // busca bicicleta no arquivo
  arquivo = fopen("./bicicletas.dat", "rb");
  while (fread(bicicleta, sizeof(Bicicleta), 1, arquivo))
  {
    // verifica se o código corresponde
    if (strcmp(bicicleta->codigo, codigo) == 0 && bicicleta->ativa)
    {
      fclose(arquivo);
      break;
    }
  }
  return bicicleta;
};

/*
Atualiza registro de uma bicicleta

Atributos:
  codigo: codigo da bicicleta a ser alterada
  cor: nova cor
  categoria: nova categoria
  disponivel: novo estado de disponibilidade
Retornos:
  0 - A bicicleta nao existe
  1 - Bicicleta atualizada
*/
int atualizarBicicleta(char codigo[], char cor[], char categoria[], int disponivel)
{
  // verifica se o bicicleta está salvo
  if (bicicletaExiste(codigo) == -1)
  {
    return 0;
  }

  Bicicleta *bic;
  bic = (Bicicleta *)malloc(sizeof(Bicicleta));

  FILE *arquivo;
  arquivo = fopen("./bicicletas.dat", "r+b");

  while (fread(bic, sizeof(Bicicleta), 1, arquivo))
  {
    // verifica se o codigo corresponde
    if (strcmp(bic->codigo, codigo) == 0 && bic->ativa)
    {
      fseek(arquivo, -1 * sizeof(Bicicleta), SEEK_CUR);

      // atualiza os dados
      strcpy(bic->cor, cor);
      strcpy(bic->categoria, categoria);
      strcpy(bic->disponivel, disponivel ? "SIM" : "NÃO");

      fwrite(bic, sizeof(Bicicleta), 1, arquivo);
      break;
    }
  }
  fclose(arquivo);
  return 1;
}

/*
Deleta registro de uma bicicleta

Atributos:
  codigo: codigo da bicicleta a ser exlcuida
Retornos:
  0 - Bicicleta nao existe
  1 - Bicicleta deletada
*/
int excluirBicicleta(char codigo[])
{
  // verifica se o bicicleta está salvo
  if (bicicletaExiste(codigo) == -1)
  {
    return 0;
  }

  Bicicleta *bic;
  bic = (Bicicleta *)malloc(sizeof(Bicicleta));

  FILE *arquivo;
  arquivo = fopen("./bicicletas.dat", "r+b");

  while (fread(bic, sizeof(Bicicleta), 1, arquivo))
  {
    // verifica se o codigo corresponde
    if (strcmp(bic->codigo, codigo) == 0 && bic->ativa)
    {
      bic->ativa = 0;
      fseek(arquivo, -1 * sizeof(Bicicleta), SEEK_CUR);
      fwrite(bic, sizeof(Bicicleta), 1, arquivo);
      fclose(arquivo);
      break;
    }
  }
  return 1;
}

/*
Busca bicicleta que tenha dado especifico

Atributos:
  termo: termo de busca
Retornos:
  Bicicleta*: vetor de bicicletas
*/
Bicicleta **buscaBicicleta(char termo[])
{

  Bicicleta **resultado = malloc(0);
  Bicicleta *bicAtual;

  bicAtual = (Bicicleta *)malloc(sizeof(Bicicleta));
  int quantidade = 0;
  FILE *arquivo;

  arquivo = fopen("./bicicletas.dat", "rb");

  while (fread(bicAtual, sizeof(Bicicleta), 1, arquivo))
  {
    if (
        bicAtual->ativa &&
        (strstr(bicAtual->cor, termo) ||
         strstr(bicAtual->categoria, termo) ||
         strstr(bicAtual->codigo, termo) ||
         strstr(bicAtual->disponivel, termo)))
    {
      quantidade++;
      resultado = realloc(resultado, quantidade * sizeof(Bicicleta));

      Bicicleta *bic = malloc(sizeof(Bicicleta));
      memcpy(bic, bicAtual, sizeof(Bicicleta));
      resultado[quantidade - 1] = bic;
    }
  }

  // marca o fim do array
  bicAtual = novaBicicleta("/!fim/!", "/!fim/!", "/!fim/!", 0);
  quantidade++;
  resultado = realloc(resultado, quantidade * sizeof(Bicicleta));
  resultado[quantidade - 1] = bicAtual;
  return resultado;
}

void listarBicicletas(int disponivel)
{
  FILE *arquivo;
  arquivo = fopen("./bicicletas.dat", "rb");

  Bicicleta *bicAtual = (Bicicleta *)malloc(sizeof(Bicicleta));

  while (fread(bicAtual, sizeof(Bicicleta), 1, arquivo))
  {
    if (disponivel)
    {
      if (bicAtual->ativa && strstr(bicAtual->disponivel, "SIM"))
      {
        char *codigoF = formatarPalavra(bicAtual->codigo, 6);
        char *corF = formatarPalavra(bicAtual->cor, 20);
        printf("%s | %s | %s\n",
               codigoF,
               corF,
               bicAtual->categoria);
        free(codigoF);
        free(corF);
      }
    }
    else
    {
      if (bicAtual->ativa && strstr(bicAtual->disponivel, "NÃO"))
      {
        char *codigoF = formatarPalavra(bicAtual->codigo, 6);
        char *corF = formatarPalavra(bicAtual->cor, 20);
        printf("%s | %s | %s\n",
               codigoF,
               corF,
               bicAtual->categoria);
        free(codigoF);
        free(corF);
      }
    }
  }
}