#include <stdio.h>
#include <string.h>
#include "alimento.h"
#include "utils.h"

void cadastrarAlimento() {
    Alimento a;
    FILE* f = fopen("dados/alimentos.txt", "a");

    a.id = gerarIdUnico();
    printf("Nome do alimento: ");
    limparBuffer();
    fgets(a.nome, 50, stdin);
    strtok(a.nome, "\n");

    printf("Descrição: ");
    fgets(a.descricao, 100, stdin);
    strtok(a.descricao, "\n");

    fprintf(f, "%d|%s|%s\n", a.id, a.nome, a.descricao);
    fclose(f);

    printf("Alimento cadastrado com sucesso!\n");
    pausarTela();
}

void excluirAlimento(int id) {
    Alimento a;
    FILE* f = fopen("dados/alimentos.txt", "r");
    FILE* temp = fopen("dados/temp.txt", "w");

    while (fscanf(f, "%d|%[^|]|%[^\n]\n", &a.id, a.nome, a.descricao) != EOF) {
        if (a.id != id) {
            fprintf(temp, "%d|%s|%s\n", a.id, a.nome, a.descricao);
        }
    }

    fclose(f);
    fclose(temp);
    remove("dados/alimentos.txt");
    rename("dados/temp.txt", "dados/alimentos.txt");

    printf("Alimento excluído!\n");
    pausarTela();
}

void listarAlimentos() {
    Alimento a;
    FILE* f = fopen("dados/alimentos.txt", "r");

    printf("\n--- Lista de Alimentos ---\n");
    while (fscanf(f, "%d|%[^|]|%[^\n]\n", &a.id, a.nome, a.descricao) != EOF) {
        printf("ID: %d\nNome: %s\nDescrição: %s\n\n", a.id, a.nome, a.descricao);
    }

    fclose(f);
    pausarTela();
}
