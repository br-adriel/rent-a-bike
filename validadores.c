#include <string.h>

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
