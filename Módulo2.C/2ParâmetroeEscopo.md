Videoaula 2: Passagem de Parâmetros e Escopo de Variáveis em C

Este documento técnico apresenta as regras físicas de escopo de dados e os mecanismos de passagem de parâmetros por cópia (valor) na linguagem C.

1. Escopo de Variáveis (Locais vs. Globais)

O escopo define a visibilidade e o ciclo de vida de uma variável em memória:

Variáveis Locais: Declaradas dentro do escopo de um bloco de chaves {}. Elas existem temporariamente na pilha de execução (Stack Frame) daquela função e são desalocadas assim que a função encerra.

Variáveis Globais: Declaradas fora de qualquer função. Estão presentes na memória durante toda a execução da aplicação. Nota de Engenharia: Devem ser evitadas, pois quebram o encapsulamento e aumentam o risco de acoplamento indesejado.

2. Passagem por Valor (Cópia)

Por padrão, a linguagem C transfere dados para funções usando passagem por valor.

Quando uma variável é passada como argumento, o sistema operacional duplica o valor lógico em um endereço de memória completamente diferente, pertencente ao escopo físico da função secundária.

Qualquer modificação feita no parâmetro dentro da função secundária não altera a variável original localizada na função chamadora (main).

3. Código de Demonstração Técnica (C Puro)

O código abaixo prova a integridade e o isolamento de memória gerados pela passagem por valor em C.

#include <stdio.h>

// Protótipo de função para simular modificação de escopo
void tentarModificarValor(int x);

int main() {
    // Variável local no escopo de pilha da função main
    int original = 10;

    printf("=== DEMONSTRAÇÃO DE ESCOPO E PASSAGEM ===\n\n");
    printf("Valor da variavel 'original' antes da chamada: %d\n", original);

    // Passagem de dados por cópia de valor (isolando o endereço de memória original)
    tentarModificarValor(original);

    // O valor original se mantém inalterado
    printf("Valor da variavel 'original' apos a chamada (main): %d\n", original);

    return 0;
}

// Função que recebe a cópia lógica do valor
void tentarModificarValor(int x) {
    printf("\n[Funcao] Valor de 'x' recebido no escopo: %d\n", x);
    
    x = x + 50; // Modificação aplicada apenas sobre a cópia local
    
    printf("[Funcao] Valor de 'x' modificado localmente: %d\n", x);
}
