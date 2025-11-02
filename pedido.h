#ifndef PEDIDO_H
#define PEDIDO_H

typedef struct {
    int id;
    char usuario[50];
    int alimentos[10];
    int qtdAlimentos;
} Pedido;

void criarPedido(char* usuario);
void excluirPedido(int id);
void adicionarAlimentoAoPedido(int idPedido, int idAlimento);
void listarPedidos();

#endif
