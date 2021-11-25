#include <string.h>
#include <ctype.h>
#include <stdio.h>

/*
Validação de email

Atributos:
  email: email para verificar validade

Retorno:
  0 - invalido
  1 - valido
*/
int validaEmail(char email[])
{
  // verifica se tem espaço em branco
  char *temEspaco = strchr(email, ' ');
  if (temEspaco)
  {
    printf("/!/ Email inválido: contém espaços\n");
    return 0;
  }

  // verifica se nao tem @
  char *temArroba = strchr(email, '@');
  if (!temArroba)
  {
    printf("/!/ Email inválido: o email deve conter @\n");
    return 0;
  }

  // verrifica se nao tem conteudo apos o @
  int tamDominio = strlen(temArroba);
  if (tamDominio < 1)
  {
    printf("/!/ Email inválido: o email deve conter conteúdo após o @\n");
    return 0;
  }

  // verifica se nao tem conteudo antes do @
  int tamUsuario = strlen(email) - tamDominio;
  if (tamUsuario < 0)
  {
    printf("/!/ Email inválido: o email deve conter conteúdeo antes do @\n");
    return 0;
  }

  return 1;
}

/*
Validação de código

Atributos:
  codigo: codigo para verificar validade
  comprimento: tamanho maximo do codigo

Retorno:
  0 - invalido
  1 - valido
*/
int validaCodigo(char codigo[], int comprimentoMax)
{
  // verifica se codigo esta dentro do comprimento maximo
  int tamanho = strlen(codigo);
  if (!(tamanho > 0 && tamanho <= comprimentoMax))
  {
    printf("/!/ Código inválido: código muito curto ou comprido demais\n");
    return 0;
  }

  // verifica se há espaços em branco
  char *temEspaco = strchr(codigo, ' ');
  if (temEspaco)
  {
    printf("/!/ Código inválido: contém espaços\n");
    return 0;
  }

  // verifica se há underlines
  char *temUnderline = strchr(codigo, '_');
  if (temUnderline)
  {
    printf("/!/ Código inválido: o código não deve conter underline\n");
    return 0;
  }

  // verifica se tem traços no código
  char *temTraco = strchr(codigo, '-');
  if (temTraco)
  {
    printf("/!/ Código inválido: o código não deve conter traços\n");
    return 0;
  }
  return 1;
}

/*
Validação de nome/sobrenome

Atributos:
  nome: nome para verificar validade

Retorno:
  0 - invalido
  1 - valido
*/
int validaNome(char nome[])
{
  // verifica se tem espaços
  char *temespaco = strchr(nome, ' ');
  if (temespaco)
  {
    printf("Inválido: nomes e sobrenomes não podem conter espaços\n");
    return 0;
  }

  // verifica se há numeros
  for (int i = 0; i < strlen(nome); i++)
  {
    if (!isalpha(nome[i]))
    {
      printf("Inválido: nomes e sobrenomes devem conter apenas letras\n");
      return 0;
    }
  }
  return 1;
}

/*
Validação de hora

Atributos:
  hora: hora apara verificar validade

Retorno:
  0 - invalido
  1 - valido
*/
int validaHora(int hora)
{
  if (hora >= 0)
  {
    return 1;
  }
  printf("Hora inválida: não há quantidade de horas negativa\n");
  return 0;
}

/*
Validação de minutos

Atributos:
  minutos: minutos para verificar validade

Retorno:
  0 - invalido
  1 - valido
*/
int validaMinutos(int minutos)
{
  if (minutos >= 0 && minutos < 60)
  {
    return 1;
  }
  return 0;
}
