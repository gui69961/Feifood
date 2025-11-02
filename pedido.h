#ifndef PEDIDO_H
#define PEDIDO_H

void criarPedido(char* nomeUsuario);
void excluirPedido(int idPedido);
void adicionarAlimentoAoPedido(int idPedido, int idAlimento);

#endif
