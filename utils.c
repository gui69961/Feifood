#include <stdio.h>     
#include <stdlib.h>    
#include <time.h>     
#include "utils.h"     

//  limpar o buffer do teclado
void limparBuffer() {
    int c;
    // Lê e descarta todos os caracteres até encontrar ENTER ('\n') ou EOF
    while ((c = getchar()) != '\n' && c != EOF);
}

//  pausar a tela e esperar o usuário pressionar ENTER
void pausarTela() {
    printf("\nPressione ENTER para continuar...");
    limparBuffer(); // Garante que o ENTER seja capturado corretamente
}

//  gerar um ID aleatório entre 0 e 9999
int gerarIdUnico() {
    srand(time(NULL));        // Inicializa o gerador de números aleatórios com base no tempo atual
    return rand() % 10000;    // Retorna um número aleatório entre 0 e 9999
}
