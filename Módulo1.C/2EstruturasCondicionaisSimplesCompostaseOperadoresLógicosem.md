Videoaula 2: Estruturas Condicionais Simples, Compostas e Operadores Lógicos em C

Este documento técnico analisa o controle de desvio de execução no fluxo do processador utilizando portas lógicas condicionais em linguagem C.

1. Operações Condicionais e a Tabela Verdade

Para realizar avaliações complexas de decisão, o fluxo do programa depende da avaliação de expressões booleanas combinadas por operadores lógicos:

&& (Operador E): Retorna verdadeiro se e somente se ambas as condições avaliadas forem válidas.

|| (Operador OU): Retorna verdadeiro se pelo menos uma das condições for avaliada como verdadeira.

! (Operador NÃO): Inverte o estado lógico de uma expressão booleana.

2. A Estrutura Condicional if-else-if

O encadeamento estruturado evita processamento inútil no processador. Em uma estrutura if / else if / else, assim que uma condição é avaliada como verdadeira, o bloco de instruções correspondente é executado e o processador ignora todas as validações subsequentes, otimizando o consumo de ciclos de máquina.

3. Código de Demonstração Técnica (C Puro)

O código abaixo realiza a validação de faixa de notas e frequência escolar de um estudante, aplicando desvios lógicos complexos com múltiplos operadores condicionais na linguagem C.

#include <stdio.h>

int main() {
    double notaFinal = 0.0;
    int frequenciaPercentual = 0;

    printf("=== VALIDADOR ACADÊMICO CONDICIONAL ===\n\n");

    printf("Digite a nota final do aluno (0.0 a 10.0): ");
    scanf("%lf", &notaFinal);

    printf("Digite a frequencia do aluno (0 a 100%%): ");
    scanf("%d", &frequenciaPercentual);

    // Validação de entrada para integridade dos dados
    if (notaFinal < 0.0 || notaFinal > 10.0 || frequenciaPercentual < 0 || frequenciaPercentual > 100) {
        printf("\n[ERRO] Valores de entrada invalidos.\n");
        return 1;
    }

    // Estrutura Condicional Composta com operadores lógicos conjunção (&&)
    if (notaFinal >= 7.0 && frequenciaPercentual >= 75) {
        printf("\nResultado: Estudante APROVADO com sucesso.\n");
    } 
    // Condição alternativa para recuperação de notas
    else if (notaFinal >= 5.0 && notaFinal < 7.0 && frequenciaPercentual >= 75) {
        printf("\nResultado: Estudante em recuperacao (Nota insuficiente, frequencia OK).\n");
    } 
    // Reprovação direta (Frequência insuficiente OU Nota muito baixa)
    else {
        printf("\nResultado: Estudante REPROVADO.\n");
        if (frequenciaPercentual < 75) {
            printf("Motivo: Frequencia abaixo do limite minimo (%d%% < 75%%).\n", frequenciaPercentual);
        }
        if (notaFinal < 5.0) {
            printf("Motivo: Nota final insuficiente (%.1f < 5.0).\n", notaFinal);
        }
    }

    return 0;
}

