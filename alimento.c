#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alimento.h"
#include "utils.h"

void cadastrarAlimento() {
    int id = rand() % 10000;
    char nome[50];
    int idEstab;

    FILE* f = fopen("dados/alimentos.txt", "a");
    if (f == NULL) {
        perror("Erro ao abrir alimentos.txt");
        return;
    }

    printf("Nome do alimento: ");
    scanf(" %[^\n]", nome);

    // Mostrar estabelecimentos disponíveis
    FILE* est = fopen("dados/estabelecimentos.txt", "r");
    if (est == NULL) {
        perror("Erro ao abrir estabelecimentos.txt");
        fclose(f);
        return;
    }

    char linha[100], nomeEstab[50];
    int idE;
    printf("\n--- Estabelecimentos disponíveis ---\n");
    while (fgets(linha, sizeof(linha), est)) {
        sscanf(linha, "%d|%[^\n]", &idE, nomeEstab);
        printf("%d - %s\n", idE, nomeEstab);
    }
    fclose(est);

    printf("ID do estabelecimento: ");
    scanf("%d", &idEstab);

    fprintf(f, "%d|%s|%d\n", id, nome, idEstab);
    fclose(f);

    printf("Alimento cadastrado com ID %d\n", id);
    pausarTela();
}


void listarAlimentos() {
    FILE* fAlimentos = fopen("dados/alimentos.txt", "r");
    FILE* fEstabs = fopen("dados/estabelecimentos.txt", "r");
    if (fAlimentos == NULL || fEstabs == NULL) {
        perror("Erro ao abrir arquivos");
        return;
    }

    // Carrega os estabelecimentos em memória
    typedef struct {
        int id;
        char nome[50];
    } Estab;

    Estab estabs[100];
    int totalEstabs = 0;
    char linha[100];

    while (fgets(linha, sizeof(linha), fEstabs)) {
        sscanf(linha, "%d|%[^\n]", &estabs[totalEstabs].id, estabs[totalEstabs].nome);
        totalEstabs++;
    }
    fclose(fEstabs);

    // Lista os alimentos com nome do estabelecimento
    printf("\n--- Lista de Alimentos ---\n");
    int idAlimento, idEstab;
    char nomeAlimento[50];

    while (fgets(linha, sizeof(linha), fAlimentos)) {
        sscanf(linha, "%d|%[^|]|%d", &idAlimento, nomeAlimento, &idEstab);

        // Procura nome do estabelecimento
        char nomeEstab[50] = "Desconhecido";
        for (int i = 0; i < totalEstabs; i++) {
            if (estabs[i].id == idEstab) {
                strcpy(nomeEstab, estabs[i].nome);
                break;
            }
        }

        printf("%d - %s (%s)\n", idAlimento, nomeAlimento, nomeEstab);
    }

    fclose(fAlimentos);
}


int alimentoExiste(int idBuscado) {
    FILE* f = fopen("dados/alimentos.txt", "r");
    if (f == NULL) return 0;

    int id;
    char linha[100];
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

void excluirAlimento() {
    int idAlimento;
    printf("ID do alimento a excluir: ");
    scanf("%d", &idAlimento);

    if (!alimentoExiste(idAlimento)) {
        printf("❌ Alimento com ID %d não existe.\n", idAlimento);
        pausarTela();
        return;
    }

    FILE* f = fopen("dados/alimentos.txt", "r");
    FILE* temp = fopen("dados/temp.txt", "w");
    if (f == NULL || temp == NULL) {
        perror("Erro ao abrir arquivos");
        return;
    }

    char linha[100];
    int id;
    while (fgets(linha, sizeof(linha), f)) {
        sscanf(linha, "%d|", &id);
        if (id != idAlimento) {
            fputs(linha, temp);
        }
    }

    fclose(f);
    fclose(temp);
    remove("dados/alimentos.txt");
    rename("dados/temp.txt", "dados/alimentos.txt");

    printf(" Alimento %d excluído com sucesso.\n", idAlimento);
    pausarTela();
}
