#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "admin.h"
#include "alimento.h"
#include "pedido.h"
#include "avaliacao.h"
#include "utils.h"

void menuUsuario(char* nome) {
    int opcao, idPedido, idAlimento, estrelas;

    do {
        printf("\n--- Menu do Usuário (%s) ---\n", nome);
        printf("1. Buscar alimento por \n");
        printf("2. Criar pedido\n");
        printf("3. Excluir pedido\n");
        printf("4. Adicionar alimento ao pedido\n");
        printf("5. Avaliar pedido\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("ID do alimento: ");
                scanf("%d", &idAlimento);
                buscarAlimentoPorId(idAlimento);
                break;
            case 2:
                criarPedido(nome);
                break;
            case 3:
                printf("ID do pedido: ");
                scanf("%d", &idPedido);
                excluirPedido(idPedido);
                break;
            case 4:
                printf("ID do pedido: ");
                scanf("%d", &idPedido);
                printf("ID do alimento: ");
                scanf("%d", &idAlimento);
                adicionarAlimentoAoPedido(idPedido, idAlimento);
                break;
            case 5:
                printf("ID do pedido: ");
                scanf("%d", &idPedido);
                printf("Nota (0 a 5): ");
                scanf("%d", &estrelas);
                avaliarPedido(idPedido, estrelas);
                break;
        }
    } while (opcao != 0);
}

void menuAdmin() {
    int opcao;

    do {
        printf("\n--- Menu do Administrador ---\n");
        printf("1. Cadastrar alimento\n");
        printf("2. Mostrar estatísticas\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAlimento();
                break;
            case 2:
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

    return 0;
}
