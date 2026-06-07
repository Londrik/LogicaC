Vídeo 1: Introdução à Alocação de Memória de Vetores em C

Este documento técnico apresenta a análise arquitetural de como o sistema operacional gerencia a memória física para variáveis simples versus variáveis compostas unidimensionais (vetores) na linguagem C.

1. Fundamentos da Alocação na Pilha (Stack)

Variáveis primitivas simples (como int ou char) armazenam apenas um estado lógico por vez em um endereço de memória isolado. Quando declaramos um vetor em C, o compilador reserva um bloco sequencial e contíguo de bytes diretamente na pilha de execução (Stack).

Homogeneidade: Todos os elementos do vetor possuem obrigatoriamente o mesmo tipo para que o tamanho físico de cada compartimento seja idêntico.

Cálculo de Deslocamento: O compilador utiliza o tamanho do tipo de dado em bytes para saber a distância exata entre as células de memória.

2. A Ausência de Verificação de Limites (Bounds Checking)

A especificação da linguagem C prioriza a performance bruta de execução. Por conta disso, o compilador não verifica se o índice acessado pelo programador está dentro do limite alocado.

Se declararmos um vetor de 5 posições e tentarmos escrever no índice 5 (vetor[5]), o programa tentará acessar a memória vizinha, o que pode causar corrupção de dados ou o encerramento abrupto do programa pelo sistema operacional com o erro de violação de segmento (Segmentation Fault).

3. Código de Demonstração Técnica (C Puro)

O código abaixo ilustra a declaração de um vetor em C e imprime os endereços físicos de memória de cada índice para provar a contiguidade física dos bytes na pilha de execução.

#include <stdio.h>

int main() {
    // Declaração estática: Aloca imediatamente 20 bytes contíguos na pilha (5 elementos * 4 bytes de int)
    int idades[5]; 

    // Atribuição individual baseada em deslocamento de índice
    idades[0] = 19;
    idades[1] = 22;
    idades[2] = 21;
    idades[3] = 25;
    idades[4] = 18;

    printf("=== MAPA FÍSICO DE ALOCAÇÃO DE MEMÓRIA ===\n\n");
    printf("Endereco Base do Vetor (idades): %p\n\n", (void*)idades);

    // Iteração para exibir os endereços de memória de cada compartimento
    for (int i = 0; i < 5; i++) {
        // Observe que a diferença entre os endereços é de exatamente 4 bytes (tamanho de um int)
        printf("Indice %d | Valor: %d | Endereco Fisico: %p\n", 
               i, idades[i], (void*)&idades[i]);
    }

    printf("\nCapacidade do vetor inspecionada com sucesso.\n");
    return 0;
}
