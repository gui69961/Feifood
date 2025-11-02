#ifndef ALIMENTO_H
#define ALIMENTO_H

typedef struct {
    int id;
    char nome[50];
    char descricao[100];
} Alimento;

void cadastrarAlimento();
void excluirAlimento(int id);
void listarAlimentos();

#endif
