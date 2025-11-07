#ifndef PEDIDO_H
#define PEDIDO_H

int criarPedido(char* nomeUsuario, int idAlimento);
void excluirPedido(int idPedido);
void avaliarPedido(int idPedido, int estrelas);
void adicionarAlimentoAoPedido(int idPedido, int idAlimento);
int pedidoExiste(int idPedido);
void fazerPedido(char* nomeUsuario);

#endif
