#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
#include "utils.h"

void cadastrarAdministrador() {
    char nome[50], senha[20];
    FILE* f = fopen("dados/administradores.txt", "a");
    if (f == NULL) {
        perror("Erro ao abrir o arquivo de administradores");
        exit(1);
    }

    printf("Nome do administrador: ");
    limparBuffer();
    if (fgets(nome, sizeof(nome), stdin) == NULL) {
        printf("Erro ao ler nome.\n");
        fclose(f);
        return;
    }
    strtok(nome, "\n");

    printf("Senha: ");
    if (fgets(senha, sizeof(senha), stdin) == NULL) {
        printf("Erro ao ler senha.\n");
        fclose(f);
        return;
    }
    strtok(senha, "\n");

    fprintf(f, "%s|%s\n", nome, senha);
    fclose(f);

    printf("Administrador cadastrado com sucesso!\n");
    pausarTela();
}

int loginAdministrador(char* nome, char* senha) {
    char nomeArq[50], senhaArq[20];
    FILE* f = fopen("dados/administradores.txt", "r");
    if (f == NULL) {
        perror("Erro ao abrir o arquivo de administradores");
        return 0;
    }

    while (fscanf(f, "%[^|]|%[^\n]\n", nomeArq, senhaArq) != EOF) {
        if (strcmp(nomeArq, nome) == 0 && strcmp(senhaArq, senha) == 0) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}
