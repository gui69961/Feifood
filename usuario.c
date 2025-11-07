#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "utils.h"

// Cadastra um novo usuário 
void cadastrarUsuario() {
    char nome[50], senha[20];
    FILE* f = fopen("dados/usuarios.txt", "a"); // Abre arquivo de usuários
    if (f == NULL) {
        perror("Erro ao abrir usuarios.txt");
        return;
    }

    // pede nome e senha
    printf("Nome do usuário: ");
    scanf("%s", nome);
    printf("Senha: ");
    scanf("%s", senha);

    // Salva no formato: nome|senha
    fprintf(f, "%s|%s\n", nome, senha);
    fclose(f);

    printf("Usuário cadastrado com sucesso!\n");
    pausarTela();
}

// validação
int loginUsuario(char* nome, char* senha) {
    char linha[100], nomeArq[50], senhaArq[20];
    FILE* f = fopen("dados/usuarios.txt", "r");
    if (f == NULL) return 0;

    //Comparação nome e senha
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
