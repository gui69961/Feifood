#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "admin.h"
#include "alimento.h"
#include "pedido.h"
#include "utils.h"

// Menu para o usuário 
void menuUsuario(char* nome) {
    int opcao, idPedido, idAlimento, estrelas;

    do {
        // Exibe opções disponíveis para o usuário
        printf("\n--- Menu do Usuário (%s) ---\n", nome);
        printf("1. Fazer pedido\n");
        printf("2. Excluir pedido\n");
        printf("3. Avaliar pedido\n");
        printf("4. Adicionar alimento ao pedido\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        // Executa a opção escolhida
        switch (opcao) {
            case 1:
                fazerPedido(nome); // Cria um novo pedido
                break;
            case 2:
                printf("ID do pedido: ");
                scanf("%d", &idPedido);
                excluirPedido(idPedido); // Exclui pedido existente
                break;
            case 3:
                printf("ID do pedido: ");
                scanf("%d", &idPedido);
                printf("Nota (0 a 5): ");
                scanf("%d", &estrelas);
                avaliarPedido(idPedido, estrelas); // Avalia pedido
                break;
            case 4:
                listarAlimentos(); // Mostra alimentos disponíveis
                printf("ID do pedido: ");
                scanf("%d", &idPedido);

                // Verifica se o pedido existe
                if (!pedidoExiste(idPedido)) {
                    printf(" Pedido com ID %d não existe. Operação cancelada.\n", idPedido);
                    pausarTela();
                    break;
                }

                printf("ID do alimento: ");
                scanf("%d", &idAlimento);

                // Verifica se o alimento existe
                if (!alimentoExiste(idAlimento)) {
                    printf(" Alimento com ID %d não existe.\n", idAlimento);
                    pausarTela();
                    break;
                }

                adicionarAlimentoAoPedido(idPedido, idAlimento); // Adiciona alimento ao pedido
                break;
        }
    } while (opcao != 0); // Repete até o usuário sair
}

// Menu para o administrador
void menuAdmin() {
    int opcao;

    do {
        // Exibe opções disponíveis para o administrador
        printf("\n--- Menu do Administrador ---\n");
        printf("1. Cadastrar alimento\n");
        printf("2. Excluir alimento\n");
        printf("3. Cadastrar estabelecimento\n");
        printf("4. Consultar usuários\n");
        printf("5. Mostrar estatísticas\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        // Executa a opção escolhida
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
    } while (opcao != 0); // Repete até o administrador sair
}

// main
int main() {
    int tipo;
    char nome[50], senha[20];

    do {
        // Menu inicial do sistema
        printf("\n--- FEIFood ---\n");
        printf("1. Cadastrar usuário\n");
        printf("2. Login como usuário\n");
        printf("3. Login como administrador\n");
        printf("4. Cadastrar administrador\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &tipo);

        // Executa a opção escolhida
        switch (tipo) {
            case 1:
                cadastrarUsuario(); // Cria novo usuário
                break;
            case 2:
                printf("Nome: ");
                scanf("%s", nome);
                printf("Senha: ");
                scanf("%s", senha);
                if (loginUsuario(nome, senha)) {
                    menuUsuario(nome); // Acessa menu do usuário
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
                    menuAdmin(); // Acessa menu do administrador
                } else {
                    printf("Login inválido!\n");
                    pausarTela();
                }
                break;
            case 4:
                cadastrarAdministrador(); // Cria novo administrador
                break;
            case 0:
                printf("Encerrando FEIFood...\n"); // Encerra o programa
                break;
            default:
                printf("Opção inválida!\n");
                pausarTela();
        }
    } while (tipo != 0); // Repete até o usuário sair

    return 0;
}
