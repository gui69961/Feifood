#include <stdio.h>
#include <stdlib.h>
#include "pedido.h"
#include "utils.h"

void criarPedido(char* nomeUsuario) {
    int id = rand() % 10000;
    FILE* f = fopen("dados/pedidos.txt", "a");
    if (f == NULL) {
        perror("Erro ao abrir pedidos.txt");
        return;
    }

    fprintf(f, "%d|%s|0\n", id, nomeUsuario);
    fclose(f);

    printf("Pedido criado com ID %d\n", id);
    pausarTela();
}

void excluirPedido(int idPedido) {
    FILE* f = fopen("dados/pedidos.txt", "r");
    FILE* temp = fopen("dados/temp.txt", "w");
    if (f == NULL || temp == NULL) {
        perror("Erro ao abrir arquivos");
        return;
    }

    char linha[200];
    int id;
    while (fgets(linha, sizeof(linha), f)) {
        sscanf(linha, "%d|", &id);
        if (id != idPedido) {
            fputs(linha, temp);
        }
    }

    fclose(f);
    fclose(temp);
    remove("dados/pedidos.txt");
    rename("dados/temp.txt", "dados/pedidos.txt");

    printf("Pedido %d excluído com sucesso\n", idPedido);
    pausarTela();
}

void adicionarAlimentoAoPedido(int idPedido, int idAlimento) {
    FILE* f = fopen("dados/pedido_alimentos.txt", "a");
    if (f == NULL) {
        perror("Erro ao abrir pedido_alimentos.txt");
        return;
    }

    fprintf(f, "%d|%d\n", idPedido, idAlimento);
    fclose(f);

    printf("Alimento ID %d adicionado ao pedido %d\n", idAlimento, idPedido);
    pausarTela();
}
