Videoaula 3: Recursividade e Gerenciamento da Call Stack em C

Este documento técnico analisa o comportamento de subprogramas que invocam a si mesmos e o impacto do empilhamento de chamadas na memória do computador.

1. O Mecanismo da Recursão

Recursividade é um método de resolução de problemas onde uma função chama a si mesma diretamente ou indiretamente para solucionar subproblemas menores da mesma natureza.

Caso Base (Condição de Parada): É a guarda lógica obrigatória que cessa as chamadas recursivas, retornando um valor fixo e iniciando o desempilhamento. Sem um caso base válido, o programa entra em recursão infinita.

Caso Recursivo: A chamada da própria função com argumentos reduzidos em direção ao caso base.

2. Anatomia da Pilha e Stack Overflow

A cada chamada recursiva, um novo contexto de variáveis locais e endereço de retorno é armazenado na pilha do sistema (Call Stack). Se a quantidade de chamadas recursivas for excessiva, ocorre o estouro físico da capacidade máxima de pilha reservada pelo sistema operacional, gerando o erro fatal de Stack Overflow.

3. Código de Demonstração Técnica (C Puro)

O código abaixo apresenta o cálculo matemático de fatorial resolvido por meio de uma função recursiva com análise de limite.

#include <stdio.h>

// Protótipo da função recursiva de cálculo de fatorial
long long calcularFatorial(int n);

int main() {
    int numero = 5;

    printf("=== COMPILADOR RECURSIVO EM C ===\n\n");

    if (numero < 0) {
        printf("Erro: Fatorial nao existe para numeros negativos.\n");
        return 1;
    }

    long long resultado = calcularFatorial(numero);
    printf("O fatorial de %d! calculado de forma recursiva eh: %lld\n", numero, resultado);

    return 0;
}

// Implementação técnica do algoritmo recursivo
long long calcularFatorial(int n) {
    // 1. Caso Base (Garante o desempilhamento de registros da Stack)
    if (n == 0 || n == 1) {
        return 1;
    }

    // 2. Caso Recursivo: Reduz o problema em N-1 direcionando ao caso base
    return n * calcularFatorial(n - 1);
}
