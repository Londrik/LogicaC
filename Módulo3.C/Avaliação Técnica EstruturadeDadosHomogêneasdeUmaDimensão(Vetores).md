Avaliação Técnica: Estrutura de Dados Homogêneas de Uma Dimensão (Vetores)

Resposta Correta: a. Armazenar e acessar dados do mesmo tipo de forma organizada e eficiente.

Justificativa de Engenharia e Arquitetura de Memória

A principal finalidade de um vetor (array) na linguagem C baseia-se nas especificações de alocação de baixo nível físicas da arquitetura de Von Neumann:

Contiguidade Física: Um vetor reserva um bloco ininterrupto de posições consecutivas de memória na pilha de execução (Stack). Isto elimina fragmentações e permite que o sistema gerencie coleções massivas de dados sob um único identificador lógico.

Aritmética de Ponteiros de Tempo Constante $O(1)$: A homogeneidade de tipo é um requisito físico. Como todos os elementos possuem rigorosamente o mesmo tamanho em bytes, o processador calcula instantaneamente o endereço de memória de qualquer índice utilizando uma operação aritmética simples de multiplicação e soma de barramento de dados:


$$\text{Endereço do Elemento} = \text{Endereço Base} + (\text{Índice} \times \text{Tamanho do Tipo em Bytes})$$


Isso garante acesso de leitura e gravação em tempo constante $O(1)$, maximizando a eficiência de algoritmos de ordenação e busca.

 Código de Demonstração Técnica (C Puro)

O código abaixo apresenta uma aplicação completa de gerenciamento e manipulação física de vetores na linguagem C. Ele realiza a leitura, o cálculo de médias e a inspeção direta de ponteiros para demonstrar a contiguidade física dos blocos de dados.

#include <stdio.h>

#define TAMANHO_NOTAS 5

int main() {
    // Alocação contígua de 40 bytes na pilha (5 elementos * 8 bytes do tipo double)
    double notas[TAMANHO_NOTAS];
    double soma = 0.0;

    printf("=== DIAGNÓSTICO E MONITORAÇÃO FÍSICA DE VETORES ===\n\n");

    // Preenchimento dinâmico do vetor via console
    for (int i = 0; i < TAMANHO_NOTAS; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        
        // Ponteiro explícito apontando para a célula de memória específica via operador '&'
        if (scanf("%lf", &notas[i]) != 1) {
            printf("[ERRO CRÍTICO] Falha na leitura de ponto flutuante.\n");
            return 1;
        }
        soma += notas[i];
    }

    // Processamento estatístico da média aritmética
    double media = soma / TAMANHO_NOTAS;
    printf("\nMedia final calculada: %.2f\n\n", media);

    printf("=== INSPEÇÃO ARQUITETURAL DE MEMÓRIA (PONTES CONTÍGUOS) ===\n");
    printf("Endereco Base do Vetor (notas): %p\n", (void*)notas);

    for (int i = 0; i < TAMANHO_NOTAS; i++) {
        // Observe que a diferença entre cada endereço consecutivo é de exatamente 8 bytes (tamanho de um double)
        printf("Indice %d | Valor: %.2f | Endereco de Memoria: %p\n", 
               i, notas[i], (void*)&notas[i]);
    }

    return 0;
}
