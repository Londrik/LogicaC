Videoaula 4: Passagem de Parâmetros por Referência com Ponteiros em C

Este documento analisa o gerenciamento avançado de memória física através da manipulação direta de ponteiros e referências de endereços na linguagem C.

1. Variáveis Ponteiro (*) e Operador de Endereço (&)

Ponteiro: É uma variável de sistema que não armazena dados lógicos tradicionais, mas sim o endereço físico de memória de outra variável.

Operador de Endereço (&): Fornece o ponteiro de memória física associado a uma variável.

2. Passagem por Referência Real

Para contornar o isolamento padrão de passagem por valor da linguagem C, podemos passar o endereço de memória da variável como argumento.

Ao declarar o parâmetro da função secundária com a sintaxe de ponteiro (int* x), a função ganha o acesso de leitura e gravação diretamente sobre o espaço físico original do chamador (main).

Esse processo é conhecido como desreferenciamento (*x = novo_valor), alterando de forma persistente os valores das variáveis fora daquele escopo de função.

3. Código de Demonstração Técnica (C Puro)

O código abaixo implementa o algoritmo clássico de troca de valores entre duas variáveis (swap) utilizando ponteiros para alterar os estados de memória da main.

#include <stdio.h>

// Protótipo de função usando ponteiros para receber endereços físicos de memória
void inverterValores(int* ponteiroA, int* ponteiroB);

int main() {
    int valor1 = 100;
    int valor2 = 500;

    printf("=== ATRIBUIÇÃO FÍSICA VIA PONTEIROS EM C ===\n\n");
    printf("Valores iniciais na main: Valor 1 = %d | Valor 2 = %d\n", valor1, valor2);

    // Passagem de endereços de memória físicos através do operador '&'
    inverterValores(&valor1, &valor2);

    // Os valores originais da main foram invertidos com sucesso
    printf("\nValores na main apos inversao via ponteiros: Valor 1 = %d | Valor 2 = %d\n", valor1, valor2);

    return 0;
}

// Implementação da rotina de troca por desreferenciamento
void inverterValores(int* ponteiroA, int* ponteiroB) {
    // Variável local temporária para segurar o valor contido no endereço apontado por ponteiroA
    int temporario = *ponteiroA; 

    // Altera o dado no endereço apontado por ponteiroA, gravando o valor apontado por ponteiroB
    *ponteiroA = *ponteiroB;

    // Conclui a troca gravando o valor de temporario no endereço de ponteiroB
    *ponteiroB = temporario;
}
