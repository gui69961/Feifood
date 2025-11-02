#include <stdio.h>
#include "avaliacao.h"
#include "utils.h"

void avaliarPedido(int idPedido, int estrelas) {
    FILE* f = fopen("dados/avaliacoes.txt", "a");
    if (f == NULL) {
        perror("Erro ao abrir arquivo de avaliações");
        return;
    }
    fprintf(f, "%d|%d\n", idPedido, estrelas);
    fclose(f);
    printf("Pedido %d avaliado com %d estrelas\n", idPedido, estrelas);
    pausarTela();
}

void mostrarEstatisticas() {
    int totalUsuarios = 0, totalAlimentos = 0, totalPedidos = 0;
    char linha[200];

    FILE* f1 = fopen("dados/usuarios.txt", "r");
    while (fgets(linha, sizeof(linha), f1)) totalUsuarios++;
    fclose(f1);

    FILE* f2 = fopen("dados/alimentos.txt", "r");
    while (fgets(linha, sizeof(linha), f2)) totalAlimentos++;
    fclose(f2);

    FILE* f3 = fopen("dados/pedidos.txt", "r");
    while (fgets(linha, sizeof(linha), f3)) totalPedidos++;
    fclose(f3);

    printf("\n--- Estatísticas ---\n");
    printf("Total de usuários: %d\n", totalUsuarios);
    printf("Total de alimentos: %d\n", totalAlimentos);
    printf("Total de pedidos: %d\n", totalPedidos);
    pausarTela();
}
