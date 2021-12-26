#include <time.h>

struct Aluguel
{
  char codigo[10];
  char cliente[71];
  char bicicleta[7];
  float valor;
  struct tm *saida;
  struct tm *retorno;
  char situacao[10];
  char codigo[10];
};

typedef struct Aluguel Aluguel;

void definirPrecoHora(float);
float lerPrecoHora();
Aluguel *novoAluguel(char[], char[]);
