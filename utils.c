#include <stdio.h>
#include "utils.h"


void limparBuffer() {
    // fonte:
    //https://stackoverflow.com/questions/7898215/how-to-clear-input-buffer-in-c
    char c;
    while ( (c = getchar()) != '\n' && c != EOF ) { }
}

void msgInvalido(void) {
    printf("\n///////////////////////\n");
    printf("// Escolha inválida! //\n");
    printf("///////////////////////\n\n");
}