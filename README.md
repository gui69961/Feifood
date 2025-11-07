# FEIFood

Sistema de pedidos de comida inspirado no iFood, desenvolvido em linguagem C como parte do projeto da disciplina CCP110 – Fundamentos de Algoritmos.

## Requisitos

Antes de começar, certifique-se de ter:

- [x] Compilador C instalado (ex: GCC)
- [x] Sistema operacional compatível (Windows, Linux ou macOS)
- [x] Pasta `dados/` criada na raiz do projeto para armazenar os arquivos `.txt`

## 🛠️ Instalação e Execução

Siga os passos abaixo para compilar e rodar o projeto:

### 1. Clone ou baixe o projeto

### 2. Crie a pasta de dados
Estrutura de Arquivos
Os dados são salvos em arquivos .txt dentro da pasta dados/:

usuarios.txt — usuários cadastrados

administradores.txt — administradores cadastrados

estabelecimentos.txt — estabelecimentos disponíveis

alimentos.txt — alimentos disponíveis

pedidos.txt — pedidos realizados

### 3. Compile os arquivos
gcc main.c usuario.c admin.c alimentos.c pedido.c utils.c -o feifood

### 4. Execute o programa
./feifood

✅ Funcionalidades
Cadastro e login de usuários e administradores

Criação, exclusão e avaliação de pedidos

Cadastro e exclusão de alimentos

Cadastro de estabelecimentos

Consulta de usuários e estatísticas
