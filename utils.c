#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pausarTela() {
    printf("\nPressione ENTER para continuar...");
    limparBuffer();
}

int gerarIdUnico() {
    srand(time(NULL));
    return rand() % 10000;
}
