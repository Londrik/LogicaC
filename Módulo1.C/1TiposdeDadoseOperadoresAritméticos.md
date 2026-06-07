Videoaula 1: Tipos de Dados e Operadores Aritméticos em C

Este documento técnico apresenta a análise detalhada sobre como o compilador C gerencia tipos primitivos de dados de diferentes tamanhos e a semântica da execução de operadores de atribuição e aritméticos.

1. Tipagem e Representação de Memória

A linguagem C é estaticamente tipada, o que significa que o tipo de dado determina o volume exato de bits alocado na memória para o armazenamento e as operações de barramento de dados:

int: Representação inteira padrão de 32 bits na maioria das arquiteturas modernas (suporta valores de $-2.147.483.648$ a $2.147.483.647$).

float: Ponto flutuante de precisão simples (32 bits).

double: Ponto flutuante de precisão dupla (64 bits), ideal para cálculos científicos ou monetários devido à maior precisão na representação binária da mantissa.

2. Aritmética e o Operador de Resto de Divisão (%)

O operador % (módulo) é utilizado estritamente entre operando inteiros em C e serve para extrair o resto físico de uma divisão inteira.

Aplicação de Engenharia: Muito utilizado para validar condições de divisibilidade, como paridade (se numero % 2 == 0, o valor é par) ou periodicidade de loops.

3. Código de Demonstração Técnica (C Puro)

O código a seguir apresenta a leitura de dados numéricos via teclado e executa operações matemáticas elementares e lógicas de restos de divisão na linguagem C.

#include <stdio.h>

int main() {
    int valorA = 0;
    int valorB = 0;

    printf("=== ENTRADA DE DADOS E OPERADORES EM C ===\n\n");

    printf("Informe o valor inteiro de A: ");
    if (scanf("%d", &valorA) != 1) {
        printf("Falha ao ler valor inteiro para A.\n");
        return 1;
    }

    printf("Informe o valor inteiro de B: ");
    if (scanf("%d", &valorB) != 1) {
        printf("Falha ao ler valor inteiro para B.\n");
        return 1;
    }

    // Processamento aritmético padrão
    int soma = valorA + valorB;
    int subtracao = valorA - valorB;
    int multiplicacao = valorA * valorB;
    
    // Tratamento preventivo de exceção de hardware: Divisão por Zero
    if (valorB == 0) {
        printf("\n[ERRO CRÍTICO] Impossivel dividir ou extrair resto de divisao por zero.\n");
        return 1;
    }

    double divisao = (double)valorA / valorB; // Coerção explícita de tipo (Casting)
    int resto = valorA % valorB;               // Operador módulo

    // Exibição dos resultados formatados
    printf("\n=== RESULTADOS DO PROCESSAMENTO ===\n");
    printf("Soma (A + B): %d\n", soma);
    printf("Subtracao (A - B): %d\n", subtracao);
    printf("Multiplicacao (A * B): %d\n", multiplicacao);
    printf("Divisao Real (A / B): %.2f\n", divisao);
    printf("Resto da Divisao Inteira (A %% B): %d\n", resto);

    return 0;
}

