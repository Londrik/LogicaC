 Videoaula 1: Declaração, Protótipos e Retorno em C

Este documento técnico apresenta os fundamentos de encapsulamento lógico utilizando funções e procedimentos na linguagem C.

1. Funções vs. Procedimentos

No paradigma procedural de programação, blocos de códigos que realizam rotinas repetitivas são isolados em subprogramas:

Funções: Subprogramas que processam instruções e obrigatoriamente retornam um valor de um tipo de dado específico (ex: int, double) à função chamadora via instrução return.

Procedimentos: Subprogramas especialistas que apenas executam uma sequência de ações sem retornar dados ao chamador. Em C, são representados pelo tipo de retorno void.

2. A Importância dos Protótipos

O compilador C realiza a leitura do código-fonte de cima para baixo. Se uma função for invocada dentro do escopo da main antes de sua definição real, o compilador emitirá um erro de compilação implícito.

Solução: O uso de Protótipos de Funções (declaração da assinatura da função contendo seu tipo, nome e parâmetros no topo do arquivo) informa o compilador sobre a existência do subprograma, permitindo que a implementação real seja feita em qualquer local do arquivo.

3. Código de Demonstração Técnica (C Puro)

O código abaixo demonstra a estruturação recomendada de arquivos em C utilizando protótipos de funções e separando procedimentos de funções com retorno.

#include <stdio.h>

// === SEÇÃO DE PROTÓTIPOS (Declaração de assinaturas) ===
void exibirCabecalho(void); // Procedimento (sem retorno)
double calcularMedia(double nota1, double nota2); // Função com retorno double

int main() {
    double n1 = 8.5;
    double n2 = 9.5;

    // Invocação de procedimento especialista
    exibirCabecalho();

    // Invocação de função com retorno, armazenando o resultado na pilha da main
    double resultado = calcularMedia(n1, n2);

    printf("A media calculada foi: %.2f\n", resultado);

    return 0;
}

// === IMPLEMENTAÇÃO DOS SUBPROGRAMAS ===

// Procedimento para exibição de interface texto
void exibirCabecalho(void) {
    printf("=========================================\n");
    printf("     SISTEMA DE PROCESSAMENTO ESCOLAR    \n");
    printf("=========================================\n\n");
}

// Função especialista em cálculo de média aritmética simples
double calcularMedia(double nota1, double nota2) {
    double media = (nota1 + nota2) / 2.0;
    return media; // Retorna o valor computado para a pilha de chamada
}
