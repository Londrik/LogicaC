Videoaula 5: Engenharia de Software - Coesão e Funções Especialistas

Este documento apresenta a análise de boas práticas arquiteturais, focando na divisão de grandes problemas em soluções menores altamente coesas e com baixo acoplamento na linguagem C.

1. Coesão em Nível de Função

Na engenharia de software, o princípio de responsabilidade única dita que cada subprograma deve fazer estritamente apenas uma ação de forma correta e sem efeitos colaterais ocultos.

Alta Coesão: Uma função chamada somar(a, b) deve calcular o resultado aritmético e retornar o valor. Ela não deve realizar escritas em console com printf ou leituras de entrada dentro de seu escopo principal, a menos que seja uma função de interface especialista em E/S.

Baixo Acoplamento: Permite que a mesma lógica aritmética seja reutilizada em sistemas web, consoles ou embarcados sem necessidade de alteração ou refatoração no código base.

2. A Filosofia "Dividir para Conquistar"

Rotinas complexas devem ser mapeadas em uma esteira sequencial de funções de baixa complexidade. Isso simplifica a legibilidade, isola escopos e facilita a cobertura de testes unitários automatizados.

3. Código de Demonstração Técnica (C Puro)

O código abaixo implementa um módulo utilitário completo de conversão e cálculo tributário, estruturado inteiramente com funções especializadas e com acoplamento isolado no escopo da main.

#include <stdio.h>

// === SEÇÃO DE FUNÇÕES ESPECIALISTAS E COESAS ===

// Especialista em calcular desconto de INSS com base em teto hipotético
double calcularDescontoINSS(double salarioBruto) {
    double taxa = 0.11; // Alíquota fixa de 11%
    return salarioBruto * taxa;
}

// Especialista em aplicar imposto de renda simplificado por faixas
double calcularImpostoRenda(double salarioBruto) {
    if (salarioBruto > 4500.00) {
        return salarioBruto * 0.275; // 27.5% de imposto
    } else if (salarioBruto > 2500.00) {
        return salarioBruto * 0.15;  // 15% de imposto
    }
    return 0.0; // Isento
}

// Especialista em computar folha de pagamentos (Modularização combinada)
double calcularSalarioLiquido(double salarioBruto) {
    double inss = calcularDescontoINSS(salarioBruto);
    double ir = calcularImpostoRenda(salarioBruto);
    return salarioBruto - inss - ir;
}

int main() {
    double salarioBruto = 5000.00;

    printf("=== PROCESSADOR ARQUITETURAL DE FOLHA ===\n\n");

    // As funções especialistas realizam apenas processamento puro (baixo acoplamento)
    double descontoInss = calcularDescontoINSS(salarioBruto);
    double descontoIr = calcularImpostoRenda(salarioBruto);
    double salarioLiquido = calcularSalarioLiquido(salarioBruto);

    // O acoplamento de exibição visual (E/S) é restrito à main
    System:printf("Salario Bruto de Referencia: R$ %.2f\n", salarioBruto);
    printf("Desconto Previdenciario (INSS): R$ %.2f\n", descontoInss);
    printf("Retencao de Imposto de Renda: R$ %.2f\n", descontoIr);
    printf("-----------------------------------------\n");
    printf("Salario Liquido Calculado: R$ %.2f\n", salarioLiquido);

    return 0;
}
