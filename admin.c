#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
#include "utils.h"

// Cadastra admin
void cadastrarAdministrador() {
    char nome[50], senha[20];
    FILE* f = fopen("dados/administradores.txt", "a"); // Abre arquivo de administradores
    if (f == NULL) {
        perror("Erro ao abrir administradores.txt");
        return;
    }

    // nome e senha do adm
    printf("Nome do administrador: ");
    scanf("%s", nome);
    printf("Senha: ");
    scanf("%s", senha);

    // Salva no formato: nome|senha
    fprintf(f, "%s|%s\n", nome, senha);
    fclose(f);

    printf("Administrador cadastrado com sucesso!\n");
    pausarTela();
}

// Verifica se o login do administrador é válido
int loginAdministrador(char* nome, char* senha) {
    char linha[100], nomeArq[50], senhaArq[20];
    FILE* f = fopen("dados/administradores.txt", "r");
    if (f == NULL) return 0;

    // Lê cada linha e compara nome e senha
    while (fgets(linha, sizeof(linha), f)) {
        sscanf(linha, "%[^|]|%s", nomeArq, senhaArq);
        if (strcmp(nome, nomeArq) == 0 && strcmp(senha, senhaArq) == 0) {
            fclose(f);
            return 1; // Login válido
        }
    }

    fclose(f);
    return 0; // Login inválido
}

// Mostra estatísticas dos pedidos
void mostrarEstatisticas() {
    FILE* f = fopen("dados/pedidos.txt", "r");
    if (f == NULL) {
        perror("Erro ao abrir pedidos.txt");
        return;
    }

    int total = 0;
    char linha[300];
    while (fgets(linha, sizeof(linha), f)) {
        total++; // Conta cada linha como um pedido
    }

    fclose(f);

    printf("\n--- Estatísticas ---\n");
    printf("Total de pedidos: %d\n", total);
    pausarTela();
}

// Cadastra um estabelecimento 
void cadastrarEstabelecimento() {
    int id = rand() % 10000; // Gera ID aleatório
    char nome[50];
    FILE* f = fopen("dados/estabelecimentos.txt", "a");
    if (f == NULL) {
        perror("Erro ao abrir estabelecimentos.txt");
        return;
    }

    printf("Nome do estabelecimento: ");
    scanf(" %[^\n]", nome); // Lê nome com espaços

    // Salva no formato: ID|NOME
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

    // Lê e exibe nome de cada usuário
    while (fgets(linha, sizeof(linha), f)) {
        sscanf(linha, "%[^|]|%s", nome, senha);
        printf("- %s\n", nome);
    }

    fclose(f);
    pausarTela();
}
