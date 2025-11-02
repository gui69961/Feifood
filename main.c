#include <stdio.h>
#include <string.h>
#include "usuario.h"
#include "admin.h"
#include "alimento.h"
#include "pedido.h"
#include "avaliacao.h"
#include "utils.h"

void menuUsuario(char* nome) {
    int opcao, id, estrelas;

    do {
        printf("\n--- Menu do Usuário (%s) ---\n", nome);
        printf("1. Buscar alimentos\n");
        printf("2. Listar alimentos\n");
        printf("3. Criar pedido\n");
        printf("4. Excluir pedido\n");
        printf("5. Adicionar alimento ao pedido\n");
        printf("6. Avaliar pedido\n");
        printf("7. Listar pedidos\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarAlimentos();
                break;
            case 2:
                listarAlimentos();
                break;
            case 3:
                criarPedido(nome);
                break;
            case 4:
                printf("ID do pedido: ");
                scanf("%d", &id);
                excluirPedido(id);
                break;
            case 5:
                printf("ID do pedido: ");
                scanf("%d", &id);
                printf("ID do alimento: ");
                int idAlimento;
                scanf("%d", &idAlimento);
                adicionarAlimentoAoPedido(id, idAlimento);
                break;
            case 6:
                printf("ID do pedido: ");
                scanf("%d", &id);
                printf("Nota (0 a 5): ");
                scanf("%d", &estrelas);
                avaliarPedido(id, estrelas);
                break;
            case 7:
                listarPedidos();
                break;
        }
    } while (opcao != 0);
}

void menuAdmin() {
    int opcao, id;

    do {
        printf("\n--- Menu do Administrador ---\n");
        printf("1. Cadastrar alimento\n");
        printf("2. Excluir alimento\n");
        printf("3. Listar alimentos\n");
        printf("4. Consultar usuários\n");
        printf("5. Ver estatísticas\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAlimento();
                break;
            case 2:
                printf("ID do alimento: ");
                scanf("%d", &id);
                excluirAlimento(id);
                break;
            case 3:
                listarAlimentos();
                break;
            case 4:
                FILE* f = fopen("dados/usuarios.txt", "r");
                char nome[50], senha[20];
                printf("\n--- Usuários Cadastrados ---\n");
                while (fscanf(f, "%s %s", nome, senha) != EOF) {
                    printf("Nome: %s\n", nome);
                }
                fclose(f);
                pausarTela();
                break;
            case 5:
                mostrarEstatisticas();
                break;
        }
    } while (opcao != 0);
}

int main() {
    int tipo;
    char nome[50], senha[20];

   do {
    printf("\n--- FEIFood ---\n");
    printf("1. Cadastrar usuário\n");
    printf("2. Login como usuário\n");
    printf("3. Login como administrador\n");
    printf("4. Cadastrar administrador\n");
    printf("0. Sair\n");
    printf("Escolha: ");
    scanf("%d", &tipo);

    switch (tipo) {
        case 1:
            cadastrarUsuario();
            break;
        case 2:
            printf("Nome: ");
            scanf("%s", nome);
            printf("Senha: ");
            scanf("%s", senha);
            if (loginUsuario(nome, senha)) {
                menuUsuario(nome);
            } else {
                printf("Login inválido!\n");
                pausarTela();
            }
            break;
        case 3:
            printf("Admin: ");
            scanf("%s", nome);
            printf("Senha: ");
            scanf("%s", senha);
            if (loginAdministrador(nome, senha)) {
                menuAdmin();
            } else {
                printf("Login inválido!\n");
                pausarTela();
            }
            break;
        case 4:
            cadastrarAdministrador();
            break;
        case 0:
            printf("Encerrando FEIFood...\n");
            break;
        default:
            printf("Opção inválida!\n");
            pausarTela();
    }
} while (tipo != 0);

    printf("Encerrando FEIFood...\n");
    return 0;
}
