struct Bicicleta
{
  char codigo[7];
  char cor[21];
  char categoria[21];
  int disponivel;
};

typedef struct Bicicleta Bicicleta;


Bicicleta* novaBicicleta(char[], char[], char[], int);
int bicicletaExiste(char[]);
int gravarBicicleta(Bicicleta*);
Bicicleta* verBicicleta(char[]);
int atualizarBicicleta(char[], char[], char[], char[]);
int excluirBicicleta(char[]);
Bicicleta **buscaBicicleta(char[]);
Bicicleta *linhaParaBicicleta(char[]);