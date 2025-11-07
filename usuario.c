#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "utils.h"

// Cadastra um novo usuário
void cadastrarUsuario() {
    char nome[50], senha[20];
    FILE* f = fopen("dados/usuarios.txt", "a");
    if (f == NULL) {
        perror("Erro ao abrir usuarios.txt");
        return;
    }

    printf("Nome do usuário: ");
    scanf("%s", nome);
    printf("Senha: ");
    scanf("%s", senha);

    fprintf(f, "%s|%s\n", nome, senha);
    fclose(f);

    printf("Usuário cadastrado com sucesso!\n");
    pausarTela();
}

// Verifica login do usuário
int loginUsuario(char* nome, char* senha) {
    char linha[100], nomeArq[50], senhaArq[20];
    FILE* f = fopen("dados/usuarios.txt", "r");
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
