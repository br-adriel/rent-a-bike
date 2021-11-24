#include <string.h>
#include <ctype.h>

/* Função de validação de email */
/* retorna 0 se inválido, 1 se válido*/
int validaEmail(char email[]) {
  char *temEspaco = strchr(email, ' ');
  if (temEspaco) {
    return 0;
  }

  char *temArroba = strchr(email, '@');
  if (temArroba) { // verifica @
    int tamDominio = strlen(temArroba);
    if (tamDominio > 1) { // verifica provedor de email
      int tamUsuario = strlen(email) - tamDominio;
      if (tamUsuario > 0) { // verifica antes do @
        return 1;
      }
    }
  }
  return 0;
}

/* Funcao de validacao de codigo */
/* retorna 0 se invalido, 1 se valido */
int validaCodigo(char codigo[], int comprimentoMax) {
  int tamanho = strlen(codigo);
  if (tamanho > 0 && tamanho <= comprimentoMax) {
    char *temEspaco = strchr(codigo, ' ');
    if (!temEspaco) {
      char *temUnderline = strchr(codigo, '_');
      if (!temUnderline) {
        char *temTraco = strchr(codigo, '_');
        if (!temTraco) {
          return 1;
        }
      }
    }
  }

  return 0;
}


/* Funcao de validacao de nome/sobrenome */
/* retorna 0 se invalido, 1 se valido */
int validaNome(char nome[]) {
  char *temespaco = strchr(nome, ' ');

  if (!temespaco) {
    for (int i=0; i<strlen(nome); i++) {
      if (!isalpha(nome[i])) {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}
