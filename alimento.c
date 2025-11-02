#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alimento.h"
#include "utils.h"

void cadastrarAlimento() {
    Alimento a;
    a.id = rand() % 10000;

    FILE* f = fopen("dados/alimentos.txt", "a");
    if (f == NULL) {
        perror("Erro ao abrir alimentos.txt");
        exit(1);
    }

    printf("Nome do alimento: ");
    limparBuffer();
    if (fgets(a.nome, sizeof(a.nome), stdin) == NULL) {
        printf("Erro ao ler nome.\n");
        fclose(f);
        return;
    }
    strtok(a.nome, "\n");

    fprintf(f, "%d|%s\n", a.id, a.nome);
    fclose(f);

    printf("Alimento cadastrado com sucesso! ID: %d\n", a.id);
    pausarTela();
}

void buscarAlimentoPorId(int idBuscado) {
    Alimento a;
    int encontrado = 0;

    FILE* f = fopen("dados/alimentos.txt", "r");
    if (f == NULL) {
        perror("Erro ao abrir alimentos.txt");
        return;
    }

    while (fscanf(f, "%d|%[^\n]\n", &a.id, a.nome) != EOF) {
        if (a.id == idBuscado) {
            encontrado = 1;
            break;
        }
    }

    fclose(f);

    if (encontrado) {
        printf("✅ Alimento \"%s\" (ID %d) está disponível!\n", a.nome, a.id);
    } else {
        printf("❌ Alimento com ID %d não encontrado.\n", idBuscado);
    }

    pausarTela();
}
