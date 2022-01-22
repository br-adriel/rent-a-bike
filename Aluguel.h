#include <time.h>

struct Aluguel
{
  int codigo;
  int ativo;
  char cliente[71];
  char bicicleta[7];
  float valor;
  struct tm saida;
  struct tm retorno;
  char situacao[10];
};

typedef struct Aluguel Aluguel;

void definirPrecoHora(float);
float lerPrecoHora();
Aluguel *novoAluguel(char[], char[]);
int aluguelExiste(int);
int gravarAluguel(Aluguel *);
Aluguel *verAluguel(int);
char *saidaAluguelStr(Aluguel *);
char *retornoAluguelStr(Aluguel *);
Aluguel **buscarAluguel(char[]);
int fecharAluguel(int);
int excluirAluguel(int);
