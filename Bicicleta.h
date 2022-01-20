struct Bicicleta
{
  char codigo[7];
  char cor[21];
  char categoria[21];
  char disponivel[5];
  int ativa;
};

typedef struct Bicicleta Bicicleta;


Bicicleta* novaBicicleta(char[], char[], char[], int);
int bicicletaExiste(char[]);
int gravarBicicleta(Bicicleta*);
Bicicleta* verBicicleta(char[]);
int atualizarBicicleta(char[], char[], char[], int);
int excluirBicicleta(char[]);
Bicicleta **buscaBicicleta(char[]);