#ifndef ALIMENTO_H
#define ALIMENTO_H

typedef struct {
    int id;
    char nome[50];
} Alimento;

void cadastrarAlimento();
void buscarAlimentoPorId(int idBuscado);

#endif
