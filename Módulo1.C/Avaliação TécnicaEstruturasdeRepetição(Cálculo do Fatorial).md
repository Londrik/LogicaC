Avaliação Técnica: Estruturas de Repetição (Cálculo do Fatorial)

Resposta Correta: a. O programador pode utilizar um loop "while" que verifica se a variável de controle é menor ou igual ao número desejado. Enquanto a condição for verdadeira, ele multiplica a variável de controle pelo fatorial em andamento e a incrementa.

Justificativa de Engenharia de Algoritmos

O fatorial de um número natural $N$ (indicado por $N!$) é o produto de todos os inteiros positivos menores ou iguais a $N$.
Matematicamente:

$$N! = N \times (N-1) \times (N-2) \times \dots \times 1$$

Por que o loop while crescente (Alternativa A) funciona perfeitamente?
Ele inicializa uma variável de controle (ex: i = 1) e uma acumuladora (fatorial = 1). A cada ciclo da repetição, a condição i <= N é avaliada. Se for válida, computa-se fatorial = fatorial * i, e o contador é incrementado em uma unidade (i++). Esse fluxo garante a multiplicação sequencial exata de $1 \times 2 \times 3 \times \dots \times N$.

Por que a alternativa D (for decrescente) não é a única, embora seja comum?
O enunciado busca a análise conceitual sobre loops equivalentes. A alternativa A descreve com exatidão a implementação iterativa progressiva válida matematicamente pela propriedade comutativa da multiplicação ($1 \times 2 \times 3 = 3 \times 2 \times 1$).

Comparativo Técnico de Implementações em C

Implementação Progressiva com while (Alternativa A)

Este código traduz a lógica descrita na resposta correta para a sintaxe nativa da linguagem C.

#include <stdio.h>

int main() {
    int numeroDesejado = 5; // Queremos calcular 5!
    
    // Variáveis de controle de escopo e acumulação
    long long fatorial = 1;
    int controle = 1;

    printf("=== CÁLCULO DE FATORIAL (WHILE PROGRESSIVO) ===\n\n");

    // Enquanto a variável de controle for menor ou igual ao limite desejado
    while (controle <= numeroDesejado) {
        fatorial = fatorial * controle; // Multiplica acumulador pelo termo de controle
        controle++;                     // Incrementa a variável de controle
    }

    printf("Fatorial de %d! calculado de forma crescente: %lld\n", numeroDesejado, fatorial);
    return 0;
}



Implementação Alternativa Progressiva com for

Para fins de análise comparativa de compilação, o mesmo algoritmo mapeado na estrutura de repetição determinada por intervalos (for):

#include <stdio.h>

int main() {
    int numeroDesejado = 5;
    long long fatorial = 1;

    printf("=== CÁLCULO DE FATORIAL (FOR PROGRESSIVO) ===\n\n");

    // Inicialização, limite condicional e incremento agrupados na instrução do loop
    for (int i = 1; i <= numeroDesejado; i++) {
        fatorial *= i;
    }

    printf("Fatorial de %d! calculado via loop FOR: %lld\n", numeroDesejado, fatorial);
    return 0;
}

