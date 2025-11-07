#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"
#include "utils.h"
#include "alimento.h"

int criarPedido(char* nomeUsuario, int idAlimento) {
    int id = rand() % 10000;
    FILE* f = fopen("dados/pedidos.txt", "a");
    if (f == NULL) {
        perror("Erro ao abrir pedidos.txt");
        return -1;
    }

    fprintf(f, "%d|%s|%d|0\n", id, nomeUsuario, idAlimento);
    fclose(f);
    return id;
}

void excluirPedido(int idPedido) {
    if (!pedidoExiste(idPedido)) {
        printf("❌ Pedido com ID %d não existe. Exclusão cancelada.\n", idPedido);
        pausarTela();
        return;
    }

    FILE* f = fopen("dados/pedidos.txt", "r");
    FILE* temp = fopen("dados/temp.txt", "w");
    if (f == NULL || temp == NULL) {
        perror("Erro ao abrir arquivos");
        return;
    }

    char linha[300];
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

void avaliarPedido(int idPedido, int estrelas) {
    if (!pedidoExiste(idPedido)) {
        printf("❌ Pedido com ID %d não existe. Avaliação cancelada.\n", idPedido);
        pausarTela();
        return;
    }

    FILE* f = fopen("dados/pedidos.txt", "r");
    FILE* temp = fopen("dados/temp.txt", "w");
    if (f == NULL || temp == NULL) {
        perror("Erro ao abrir arquivos");
        return;
    }

    char linha[300], nome[50], alimentos[200];
    int id, avaliacao;
    while (fgets(linha, sizeof(linha), f)) {
        sscanf(linha, "%d|%[^|]|%[^|]|%d", &id, nome, alimentos, &avaliacao);
        if (id == idPedido) {
            fprintf(temp, "%d|%s|%s|%d\n", id, nome, alimentos, estrelas);
        } else {
            fputs(linha, temp);
        }
    }

    fclose(f);
    fclose(temp);
    remove("dados/pedidos.txt");
    rename("dados/temp.txt", "dados/pedidos.txt");

    printf("Pedido %d avaliado com %d estrelas\n", idPedido, estrelas);
    pausarTela();
}

void adicionarAlimentoAoPedido(int idPedido, int idAlimento) {
    if (!pedidoExiste(idPedido)) {
        printf("❌ Pedido com ID %d não existe. Operação cancelada.\n", idPedido);
        pausarTela();
        return;
    }

    FILE* f = fopen("dados/pedidos.txt", "r");
    FILE* temp = fopen("dados/temp.txt", "w");
    if (f == NULL || temp == NULL) {
        perror("Erro ao abrir arquivos");
        return;
    }

    char linha[300], nome[50], alimentos[200];
    int id, avaliacao;

    while (fgets(linha, sizeof(linha), f)) {
        sscanf(linha, "%d|%[^|]|%[^|]|%d", &id, nome, alimentos, &avaliacao);
        if (id == idPedido) {
            char novoAlimentos[250];
            snprintf(novoAlimentos, sizeof(novoAlimentos), "%s,%d", alimentos, idAlimento);
            fprintf(temp, "%d|%s|%s|%d\n", id, nome, novoAlimentos, avaliacao);
        } else {
            fputs(linha, temp);
        }
    }

    fclose(f);
    fclose(temp);
    remove("dados/pedidos.txt");
    rename("dados/temp.txt", "dados/pedidos.txt");

    printf("✅ Alimento %d adicionado ao pedido %d\n", idAlimento, idPedido);
    pausarTela();
}

int pedidoExiste(int idBuscado) {
    FILE* f = fopen("dados/pedidos.txt", "r");
    if (f == NULL) {
        perror("Erro ao abrir pedidos.txt");
        return 0;
    }

    int id;
    char linha[300];
    while (fgets(linha, sizeof(linha), f)) {
        sscanf(linha, "%d|", &id);
        if (id == idBuscado) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}

void fazerPedido(char* nomeUsuario) {
    int idAlimento;

    listarAlimentos();

    printf("\nDigite o ID do alimento que deseja pedir: ");
    scanf("%d", &idAlimento);

    if (!alimentoExiste(idAlimento)) {
        printf("❌ Alimento com ID %d não existe. Pedido cancelado.\n", idAlimento);
        pausarTela();
        return;
    }

    int idPedido = criarPedido(nomeUsuario, idAlimento);

    if (idPedido != -1) {
        printf("✅ Pedido realizado com sucesso! ID do pedido: %d\n", idPedido);
    } else {
        printf("❌ Erro ao criar o pedido.\n");
    }

    pausarTela();
}
