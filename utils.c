#include <stdio.h>
#include "utils.h"


void limparBuffer() {
    // código extraído de 
    // cprogressivo.net/2012/12/Buffer--o-que-e-como-limpar-e-as-funcoes-fflush-e-fpurge.html
    //__fpurge(stdin); // linux
    // fflush(stdin); // windows
}

void msgInvalido(void) {
    printf("\n///////////////////////\n");
    printf("// Escolha inválida! //\n");
    printf("///////////////////////\n\n");
}