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
  // verifica se email esta no limite de caracteres
  int tamEmail = strlen(email);
  if (tamEmail > 70)
  {
    printf("/!/ Email inválido: o email contém mais de 70 caracteres\n");
    return 0;
  }

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

  // verfifica se tem símbolos
  char simbolos[] = ":;,|/!?#$*()=+-*'\"`'[{]}ªº^~°$";
  for (int i = 0; i < strlen(simbolos); i++)
  {
    if (strchr(email, simbolos[i]))
    {
      printf("/!/ Email inválido: o email não pode ter símbolos especiais\n");
      return 0;
    }
  }

  // verifica se nao tem conteudo apos o @
  int tamDominio = strlen(temArroba);
  if (tamDominio <= 1)
  {
    printf("/!/ Email inválido: o email deve conter conteúdo após o @\n");
    return 0;
  }

  // verifica se nao tem conteudo antes do @
  int tamUsuario = tamEmail - tamDominio;
  if (tamUsuario == 0)
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
  comprimento: tamanho que o codigo deve ter

Retorno:
  0 - invalido
  1 - valido
*/
int validaCodigo(char codigo[], int comprimento)
{
  // verifica se codigo esta dentro do comprimento maximo
  if (!(strlen(codigo) == comprimento))
  {
    printf("/!/ Código inválido: o código deve conter %d digitos \n", comprimento);
    return 0;
  }

  // verifica se há espaços em branco
  if (strchr(codigo, ' '))
  {
    printf("/!/ Código inválido: contém espaços\n");
    return 0;
  }

  // verifica se contém apenas letras e numeros
  if (isalnum(codigo))
  {
    printf("/!/ Código inválido: o código não pode ter símbolos\n");
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
  // verifica se tem mais de 20 caracteres
  if (strlen(nome) > 20)
  {
    printf("/!/ Inválido: nomes e sobrenomes não podem exceder 20 caracteres\n");
    return 0;
  }

  // verifica se tem espaços
  if (strchr(nome, ' '))
  {
    printf("/!/ Inválido: nomes e sobrenomes não podem conter espaços\n");
    return 0;
  }

  // verifica se há numeros
  for (int i = 0; i < strlen(nome); i++)
  {
    if (!isalpha(nome[i]))
    {
      printf("/!/ Inválido: nomes e sobrenomes devem conter apenas letras\n");
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
  printf("/!/ Hora inválida: não há quantidade de horas negativa\n");
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
  printf("/!/ Minutos inválidos: o minuto deve ser um valor de 0 à 59\n");
  return 0;
}

/*
Validação de cor

Atributos:
  cor: cor para verificar validade

Retorno:
  0 - invalido
  1 - valido
*/
int validaCor(char cor[])
{
  // verifica se tem mais de 20 caracteres
  if (strlen(cor) > 20)
  {
    printf("/!/ Cor inválida: a cor não pode exceder 20 caracteres\n");
    return 0;
  }

  // verifica se tem espaços
  if (strchr(cor, ' '))
  {
    printf("/!/ Cor inválida: a cor não pode conter espaços\n");
    return 0;
  }

  // verifica se há numeros
  for (int i = 0; i < strlen(cor); i++)
  {
    if (!isalpha(cor[i]))
    {
      printf("/!/ Cor inválida: a cor deve conter apenas letras\n");
      return 0;
    }
  }
  return 1;
}

/*
Validação de bicicleta ativa

Atributos:
  opcao: opcao passada para verificar validade

Retorno:
  0 - invalido
  1 - valido
*/
int validaBicicletaAtiva(int opcao)
{
  if (opcao == 0 || opcao == 1)
  {
    return 1;
  }
  printf("/!/ Opção inválida: precisa ser 0 ou 1\n");
  return 0;
}

/*
Validação de data

Atributos:
  dia
  mes
  ano

Retorno:
  0 - invalida
  1 - valida
*/
int validaData(int dia, int mes, int ano)
// Fonte: includehelp.com/c-programs/validate-date.aspx
{
  if (ano >= 1900 && ano <= 3000)
  {
    if (mes >= 1 && mes <= 12)
    {
      if ((dia >= 1 && dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12))
      {
        return 1;
      }
      else if ((dia >= 1 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11))
      {
        return 1;
      }
      else if ((dia >= 1 && dia <= 28) && (mes == 2))
      {
        return 1;
      }
      else if (dia == 29 && mes == 2 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)))
      {
        return 1;
      }
      else
      {
        printf("/!/ Data inválida: não há dia %d para o mês %d\n", dia, mes);
        return 0;
      }
    }
    else
    {
      printf("/!/ Data inválida: o mês precisa ser um valor de 01 a 12\n");
      return 0;
    }
  }
  else
  {
    printf("/!/ Data inválida: o ano precisa ser um valor de 1900 à 3000\n");
    return 0;
  }
}
