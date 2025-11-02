#include <stdio.h>
#include <string.h>
#include "pedido.h"
#include "utils.h"

void criarPedido(char* usuario) {
    Pedido p;
    FILE* f = fopen("dados/pedidos.txt", "a");

    p.id = gerarIdUnico();
    strcpy(p.usuario, usuario);
    p.qtdAlimentos = 0;

    fprintf(f, "%d|%s|%d\n", p.id, p.usuario, p.qtdAlimentos);
    fclose(f);

    printf("Pedido criado com ID %d\n", p.id);
    pausarTela();
}

void excluirPedido(int id) {
    Pedido p;
    FILE* f = fopen("dados/pedidos.txt", "r");
    FILE* temp = fopen("dados/temp.txt", "w");

    while (fscanf(f, "%d|%[^|]|%d\n", &p.id, p.usuario, &p.qtdAlimentos) != EOF) {
        if (p.id != id) {
            fprintf(temp, "%d|%s|%d\n", p.id, p.usuario, p.qtdAlimentos);
        }
    }

    fclose(f);
    fclose(temp);
    remove("dados/pedidos.txt");
    rename("dados/temp.txt", "dados/pedidos.txt");

    printf("Pedido excluído!\n");
    pausarTela();
}

void adicionarAlimentoAoPedido(int idPedido, int idAlimento) {
    // Simples: apenas registrar em um arquivo separado
    FILE* f = fopen("dados/pedido_alimentos.txt", "a");
    fprintf(f, "%d|%d\n", idPedido, idAlimento);
    fclose(f);

    printf("Alimento %d adicionado ao pedido %d\n", idAlimento, idPedido);
    pausarTela();
}

void listarPedidos() {
    Pedido p;
    FILE* f = fopen("dados/pedidos.txt", "r");

    printf("\n--- Pedidos ---\n");
    while (fscanf(f, "%d|%[^|]|%d\n", &p.id, p.usuario, &p.qtdAlimentos) != EOF) {
        printf("ID: %d\nUsuário: %s\nQtd Alimentos: %d\n\n", p.id, p.usuario, p.qtdAlimentos);
    }

    fclose(f);
    pausarTela();
}
