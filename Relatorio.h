struct Relatorio
{
  int total;
  int abertos;
  int fechados;
  float lucro;
};

typedef struct Relatorio Relatorio;

Relatorio *gerarRelatorio(int);