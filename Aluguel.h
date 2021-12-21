#include <time.h>

struct Aluguel
{
  char cliente[71];
  char bicicleta[7];
  float valor;
  struct tm saida;
  struct tm retorno;
};
