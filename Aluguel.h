#include <time.h>

struct Aluguel
{
  char cliente[71];
  char bicicleta[7];
  float valor;
  struct tm *saida;
  struct tm *retorno;
};

typedef struct Aluguel Aluguel;

void definirPrecoHora(float);
float lerPrecoHora();
Aluguel *novoAluguel(char[], char[]);
