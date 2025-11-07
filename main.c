#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "admin.h"
#include "alimento.h"
#include "pedido.h"
#include "utils.h"

void menuUsuario(char* nome) {
    int opcao, idPedido, idAlimento, estrelas;

    do {
        printf("\n--- Menu do Usuário (%s) ---\n", nome);
        printf("1. Fazer pedido\n");
        printf("2. Excluir pedido\n");
        printf("3. Avaliar pedido\n");
        printf("4. Adicionar alimento ao pedido\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                fazerPedido(nome);
                break;
            case 2:
                printf("ID do pedido: ");
                scanf("%d", &idPedido);
                excluirPedido(idPedido);
                break;
            case 3:
                printf("ID do pedido: ");
                scanf("%d", &idPedido);
                printf("Nota (0 a 5): ");
                scanf("%d", &estrelas);
                avaliarPedido(idPedido, estrelas);
                break;
            case 4:
                listarAlimentos();
                printf("ID do pedido: ");
                scanf("%d", &idPedido);

                if (!pedidoExiste(idPedido)) {
                    printf("❌ Pedido com ID %d não existe. Operação cancelada.\n", idPedido);
                    pausarTela();
                    break;
                }

                printf("ID do alimento: ");
                scanf("%d", &idAlimento);

                if (!alimentoExiste(idAlimento)) {
                    printf("❌ Alimento com ID %d não existe.\n", idAlimento);
                    pausarTela();
                    break;
                }

                adicionarAlimentoAoPedido(idPedido, idAlimento);
                break;
        }
    } while (opcao != 0);
}

void menuAdmin() {
    int opcao;

    do {
        printf("\n--- Menu do Administrador ---\n");
        printf("1. Cadastrar alimento\n");
        printf("2. Excluir alimento\n");
        printf("3. Cadastrar estabelecimento\n");
        printf("4. Consultar usuários\n");
        printf("5. Mostrar estatísticas\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAlimento();
                break;
            case 2:
                excluirAlimento();
                break;
            case 3:
                cadastrarEstabelecimento();
                break;
            case 4:
                consultarUsuarios();
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

    return 0;
}
