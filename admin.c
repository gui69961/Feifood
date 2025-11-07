#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
#include "utils.h"

// Cadastra um novo administrador
void cadastrarAdministrador() {
    char nome[50], senha[20];
    FILE* f = fopen("dados/administradores.txt", "a");
    if (f == NULL) {
        perror("Erro ao abrir administradores.txt");
        return;
    }

    printf("Nome do administrador: ");
    scanf("%s", nome);
    printf("Senha: ");
    scanf("%s", senha);

    fprintf(f, "%s|%s\n", nome, senha);
    fclose(f);

    printf("Administrador cadastrado com sucesso!\n");
    pausarTela();
}

// Verifica login do administrador
int loginAdministrador(char* nome, char* senha) {
    char linha[100], nomeArq[50], senhaArq[20];
    FILE* f = fopen("dados/administradores.txt", "r");
    if (f == NULL) return 0;

    while (fgets(linha, sizeof(linha), f)) {
        sscanf(linha, "%[^|]|%s", nomeArq, senhaArq);
        if (strcmp(nome, nomeArq) == 0 && strcmp(senha, senhaArq) == 0) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}

// Cadastra um novo estabelecimento
void cadastrarEstabelecimento() {
    int id = rand() % 10000;
    char nome[50];
    FILE* f = fopen("dados/estabelecimentos.txt", "a");
    if (f == NULL) {
        perror("Erro ao abrir estabelecimentos.txt");
        return;
    }

    printf("Nome do estabelecimento: ");
    scanf(" %[^\n]", nome);

    fprintf(f, "%d|%s\n", id, nome);
    fclose(f);

    printf("Estabelecimento cadastrado com ID %d\n", id);
    pausarTela();
}

// Lista todos os usuários cadastrados
void consultarUsuarios() {
    FILE* f = fopen("dados/usuarios.txt", "r");
    if (f == NULL) {
        perror("Erro ao abrir usuarios.txt");
        return;
    }

    char linha[100], nome[50], senha[20];
    printf("\n--- Lista de Usuários ---\n");

    while (fgets(linha, sizeof(linha), f)) {
        sscanf(linha, "%[^|]|%s", nome, senha);
        printf("- %s\n", nome);
    }

    fclose(f);
    pausarTela();
}

// Mostra estatísticas do sistema
void mostrarEstatisticas() {
    int totalUsuarios = 0, totalEstabs = 0, totalAlimentos = 0;
    int avaliacoesPorAlimento[1000] = {0};
    char nomesAlimentos[1000][50];
    int idsAlimentos[1000];

    FILE* f;

    // Conta usuários
    f = fopen("dados/usuarios.txt", "r");
    if (f != NULL) {
        char linha[100];
        while (fgets(linha, sizeof(linha), f)) totalUsuarios++;
        fclose(f);
    }

    // Conta estabelecimentos
    f = fopen("dados/estabelecimentos.txt", "r");
    if (f != NULL) {
        char linha[100];
        while (fgets(linha, sizeof(linha), f)) totalEstabs++;
        fclose(f);
    }

    // Carrega alimentos
    f = fopen("dados/alimentos.txt", "r");
    if (f != NULL) {
        char linha[100];
        int id, idEstab;
        char nome[50];
        while (fgets(linha, sizeof(linha), f)) {
            sscanf(linha, "%d|%[^|]|%d", &id, nome, &idEstab);
            idsAlimentos[totalAlimentos] = id;
            strcpy(nomesAlimentos[totalAlimentos], nome);
            totalAlimentos++;
        }
        fclose(f);
    }

    // Conta avaliações por alimento
    f = fopen("dados/avaliacoes.txt", "r");
    if (f != NULL) {
        char linha[100];
        int id, nota;
        while (fgets(linha, sizeof(linha), f)) {
            sscanf(linha, "%d|%d", &id, &nota);
            for (int i = 0; i < totalAlimentos; i++) {
                if (idsAlimentos[i] == id) {
                    avaliacoesPorAlimento[i]++;
                    break;
                }
            }
        }
        fclose(f);
    }

    // Exibe estatísticas
    printf("\n--- Estatísticas do Sistema ---\n");
    printf(" Total de usuários: %d\n", totalUsuarios);
    printf(" Total de estabelecimentos: %d\n", totalEstabs);
    printf(" Total de alimentos: %d\n", totalAlimentos);

    // Top 5 mais avaliados
    printf("\n Top 5 alimentos mais avaliados:\n");
    for (int k = 0; k < 5; k++) {
        int mais = -1;
        for (int i = 0; i < totalAlimentos; i++) {
            if (avaliacoesPorAlimento[i] > 0 &&
                (mais == -1 || avaliacoesPorAlimento[i] > avaliacoesPorAlimento[mais])) {
                mais = i;
            }
        }
        if (mais != -1) {
            printf("- %s (%d avaliações)\n", nomesAlimentos[mais], avaliacoesPorAlimento[mais]);
            avaliacoesPorAlimento[mais] = -1;
        }
    }

    // Top 5 menos avaliados
    printf("\n Top 5 alimentos menos avaliados:\n");
    for (int k = 0; k < 5; k++) {
        int menos = -1;
        for (int i = 0; i < totalAlimentos; i++) {
            if (avaliacoesPorAlimento[i] >= 0 &&
                (menos == -1 || avaliacoesPorAlimento[i] < avaliacoesPorAlimento[menos])) {
                menos = i;
            }
        }
        if (menos != -1) {
            printf("- %s (%d avaliações)\n", nomesAlimentos[menos], avaliacoesPorAlimento[menos]);
            avaliacoesPorAlimento[menos] = -1;
        }
    }

    pausarTela();
}
