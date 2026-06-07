Vídeo 5: Passagem de Vetores para Funções em C

Este documento técnico analisa as regras de escopo e transferência de blocos contíguos de memória ao passar arrays como argumentos de subprogramas (funções) em C.

1. O Decaimento para Ponteiros (Pointer Decay)

Em C, quando o identificador de um vetor (o nome do vetor) é passado como argumento para uma função, ele sofre um decaimento implícito e se torna um ponteiro que aponta para o seu primeiro elemento (&vetor[0]).

Isso significa que a linguagem C realiza a transferência por cópia de referência.

Qualquer alteração executada nos índices de um array dentro de uma função secundária altera diretamente a memória física original definida na função chamadora (main).

2. A Necessidade de Passar o Tamanho Logicamente

Como a função secundária recebe apenas um ponteiro para o início da estrutura, ela perde a informação de quantos elementos contíguos existem a partir dali.

Diferente do Java (que herda isso como um objeto contendo o atributo .length), em C é obrigatório passar a quantidade de elementos de forma explícita na assinatura da função (int tamanho) para que as iterações de loop ocorram de forma segura.

3. Código de Demonstração Técnica (C Puro)

O código abaixo demonstra uma função que duplica os valores de um vetor de forma persistente sobre a memória base e utiliza parâmetros de controle para garantir a integridade física dos limites.

#include <stdio.h>

// Assinatura de funções que operam sobre arrays.
// O parâmetro 'int* vetor' ou 'int vetor[]' recebe o ponteiro base do array original.
void duplicarValores(int* vetor, int tamanho);
void exibirVetor(int* vetor, int tamanho);

int main() {
    int dados[4] = {10, 20, 30, 40};
    int tamanhoDados = 4;

    printf("=== PASSAGEM DE VETORES PARA FUNÇÕES ===\n\n");

    printf("Estado original dos dados na main:\n");
    exibirVetor(dados, tamanhoDados);

    // Passagem por referencia implicita. repassa apenas o endereço do primeiro elemento
    duplicarValores(dados, tamanhoDados);

    printf("\nEstado dos dados apos a alteracao executada pela funcao:\n");
    // Os valores originais foram modificados, provando a passagem de referencia
    exibirVetor(dados, tamanhoDados);

    return 0;
}

// Implementação da rotina de duplicação sobre o ponteiro físico
void duplicarValores(int* vetor, int tamanho) {
    // Usamos o parâmetro 'tamanho' para evitar a invasão de memória externa
    for (int i = 0; i < tamanho; i++) {
        // Altera o conteúdo apontado pela referência física direta
        vetor[i] = vetor[i] * 2;
    }
}

// Implementação da rotina de leitura sequencial de ponteiros
void exibirVetor(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}
