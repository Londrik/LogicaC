Avaliação Técnica: O Conceito de Funções na Resolução de Labirintos

Resposta Correta: d. Funções.

 Justificativa de Engenharia de Algoritmos

No cenário de um jogo de labirinto repleto de ramificações e desvios, o desafio de software consiste em explorar múltiplos caminhos de forma organizada, registrando pontos de decisão e permitindo retroceder (backtracking) quando um beco sem saída for atingido.

Por que "Funções" é o conceito correto?
Para explorar opções de forma estruturada, o paradigma procedural utiliza a subdivisão do problema em subprogramas (funções). Cada chamada de função representa a entrada em um novo nó ou bifurcação do labirinto.

Gerenciamento de Pilha (Call Stack):
Toda vez que uma função de exploração é executada, o sistema operacional empilha um novo registro de ativação (Stack Frame), salvando o estado atual e as coordenadas do jogador. Se a função atingir um beco sem saída, ela encerra sua execução, retornando o controle físico para o registro de ativação anterior. Isso permite que o algoritmo continue a explorar caminhos alternativos sem perder o histórico do trajeto.

 Demonstração de Algoritmo de Busca (DFS) em C

O código abaixo simula a busca de uma saída em uma matriz de labirinto bidimensional utilizando chamadas de funções para modularizar o comportamento de exploração.

#include <stdio.h>
#include <stdbool.h>

#define LINHAS 5
#define COLUNAS 5

// Representação física do labirinto (0: Caminho, 1: Parede, 2: Saída, 3: Visitado)
int labirinto[LINHAS][COLUNAS] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 2}, // Saída representada pelo valor 2 no índice [2][4]
    {1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}
};

// Protótipo da função especialista de navegação
bool explorarCaminho(int x, int y);

int main() {
    printf("=== SIMULADOR DE RESOLUÇÃO DE LABIRINTO ===\n\n");
    
    // Inicia a exploração a partir da coordenada inicial [0][0]
    if (explorarCaminho(0, 0)) {
        printf("\n[SUCESSO] Caminho para a saida mapeado com sucesso!\n");
    } else {
        printf("\n[FALHA] Nao existe um caminho possivel para a saida.\n");
    }

    return 0;
}

// Implementação da função de exploração estruturada
bool explorarCaminho(int x, int y) {
    // Verificação de limites físicos da matriz
    if (x < 0 || x >= LINHAS || y < 0 || y >= COLUNAS) {
        return false; 
    }

    // Se atingir uma parede (1) ou uma posição já visitada (3), a rota é inválida
    if (labirinto[x][y] == 1 || labirinto[x][y] == 3) {
        return false;
    }

    // Caso de Sucesso: Atingiu a Saída (2)
    if (labirinto[x][y] == 2) {
        printf("Saida encontrada na coordenada: [%d][%d]\n", x, y);
        return true;
    }

    // Marcação física do ponto atual como visitado para evitar loops infinitos de recursão
    labirinto[x][y] = 3;
    printf("Explorando posicao: [%d][%d]\n", x, y);

    // Bifurcações: Invoca subprogramas especialistas para buscar nas quatro direções cardeais
    // 1. Explorar para Baixo (x + 1)
    if (explorarCaminho(x + 1, y)) return true;

    // 2. Explorar para a Direita (y + 1)
    if (explorarCaminho(x, y + 1)) return true;

    // 3. Explorar para Cima (x - 1)
    if (explorarCaminho(x - 1, y)) return true;

    // 4. Explorar para a Esquerda (y - 1)
    if (explorarCaminho(x, y - 1)) return true;

    // Se nenhuma direção encontrar a saída, limpa o registro de visitação (Backtracking)
    labirinto[x][y] = 0;
    return false;
}
