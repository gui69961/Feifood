#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

// Limpa o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Pausa a tela até o usuário pressionar ENTER
void pausarTela() {
    printf("\nPressione ENTER para continuar...");
    limparBuffer();
}

// Gera um ID aleatório entre 0 e 9999
int gerarIdUnico() {
    srand(time(NULL));
    return rand() % 10000;
}
