#include <string.h>
#include <ctype.h>

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
    msgEmailInválido(1);
    return 0;
  }

  // verifica se nao tem @
  char *temArroba = strchr(email, '@');
  if (!temArroba)
  {
    msgEmailInválido(2);
    return 0;
  }

  // verrifica se nao tem conteudo apos o @
  int tamDominio = strlen(temArroba);
  if (tamDominio < 1)
  {
    msgEmailInválido(3);
    return 0;
  }

  // verifica se nao tem conteudo antes do @
  int tamUsuario = strlen(email) - tamDominio;
  if (tamUsuario < 0)
  {
    msgEmailInválido(4);
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
  int tamanho = strlen(codigo);
  if (tamanho > 0 && tamanho <= comprimentoMax)
  {
    char *temEspaco = strchr(codigo, ' ');
    if (!temEspaco)
    {
      char *temUnderline = strchr(codigo, '_');
      if (!temUnderline)
      {
        char *temTraco = strchr(codigo, '_');
        if (!temTraco)
        {
          return 1;
        }
      }
    }
  }

  return 0;
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
  char *temespaco = strchr(nome, ' ');

  if (!temespaco)
  {
    for (int i = 0; i < strlen(nome); i++)
    {
      if (!isalpha(nome[i]))
      {
        return 0;
      }
    }
    return 1;
  }
  return 0;
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

// Mensagens de erro
/*
Mensagem de email inválido

Atributos:
  motivo: inidica qual erro exibir

*/
void msgEmailInválido(int motivo)
{
  switch (motivo)
  {
  case 1:
    printf("/!/ Email inválido: contém espaços\n");
    break;
  case 2:
    printf("/!/ Email inválido: o email deve conter @\n");
    break;
  case 3:
    printf("/!/ Email inválido: o email deve conter conteúdo após o @\n");
    break;
  case 4:
    printf("/!/ Email inválido: o email deve conter conteúdeo antes do @\n");
    break;
  default:
    printf("/!/ Email inválido\n");
  }
}
