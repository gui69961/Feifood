#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "utils.h"

void cadastrarUsuario() {
    Usuario u;

    // Abrir o arquivo em modo append
    FILE* f = fopen("dados/usuarios.txt", "a");
    if (f == NULL) {
        perror("Erro ao abrir o arquivo de usuários");
        exit(1); // Encerra o programa se não conseguir abrir
    }

    // Coletar nome
    printf("Nome: ");
    limparBuffer(); // Limpa o lixo do teclado
    if (fgets(u.nome, sizeof(u.nome), stdin) == NULL) {
        printf("Erro ao ler nome.\n");
        fclose(f);
        return;
    }
    strtok(u.nome, "\n"); // Remove o \n do final

    // Coletar senha
    printf("Senha: ");
    if (fgets(u.senha, sizeof(u.senha), stdin) == NULL) {
        printf("Erro ao ler senha.\n");
        fclose(f);
        return;
    }
    strtok(u.senha, "\n");

    // Gravar no arquivo com separador seguro
    fprintf(f, "%s|%s\n", u.nome, u.senha);
    fclose(f);

    printf("Usuário cadastrado com sucesso!\n");
    pausarTela();
}

int loginUsuario(char* nome, char* senha) {
    Usuario u;
    FILE* f = fopen("dados/usuarios.txt", "r");
    if (f == NULL) {
        perror("Erro ao abrir o arquivo de usuários");
        return 0;
    }

    // Leitura com separador '|'
    while (fscanf(f, "%[^|]|%[^\n]\n", u.nome, u.senha) != EOF) {
        if (strcmp(u.nome, nome) == 0 && strcmp(u.senha, senha) == 0) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}
