Videoaula 3: Estruturas de Repetição (while e for) em C

Este documento analisa as regras de controle de laços de repetição, mapeando as semelhanças e as diferenças práticas de uso entre loops baseados em condição (while) e loops baseados em intervalos (for).

1. Critérios de Parada e Loops Infinitos

Estruturas de repetição executam um bloco de código repetidas vezes até que uma condição lógica de parada seja violada.

Controle Lógico: É obrigatório que, dentro do corpo de execução do laço de repetição, exista uma instrução que altere diretamente a variável de teste (como um incremento ou decremento de variável de controle). Caso contrário, o critério de parada nunca será atingido, criando um loop infinito que trava a aplicação e satura o consumo do núcleo de processamento do computador.

2. Escolha da Estrutura Ideal

while: Melhor para situações onde a quantidade exata de repetições é desconhecida antes da execução (ex: ler entradas do usuário até que um comando "SAIR" seja digitado).

for: Ideal para loops de intervalos controlados onde o tamanho e a quantidade de ciclos são previamente delimitados (ex: percorrer de 1 a 100).

3. Código de Demonstração Técnica (C Puro)

O código abaixo implementa uma simulação de média ponderada de notas utilizando tanto a estrutura for (para loops conhecidos de iteração) quanto o loop while como validador dinâmico de segurança contra dados corrompidos.

#include <stdio.h>

int main() {
    int totalAlunos = 0;
    double nota = 0.0;
    double somaNotas = 0.0;

    printf("=== CALCULADORA DE MÉDIAS TURMA ===\n\n");

    // Loop WHILE para garantir que o número de alunos seja positivo
    while (totalAlunos <= 0) {
        printf("Informe a quantidade de alunos na sala (numero maior que zero): ");
        scanf("%d", &totalAlunos);
        if (totalAlunos <= 0) {
            printf("[ALERTA] Quantidade invalida. Tente novamente.\n");
        }
    }

    printf("\nIniciando o processamento das notas...\n\n");

    // Loop FOR para iterar estritamente no intervalo conhecido de alunos
    for (int i = 1; i <= totalAlunos; i++) {
        
        // Loop WHILE aninhado para garantir entrada de nota válida por estudante (Validação de Dados)
        while (1) {
            printf("Digite a nota do Aluno %d (0.0 a 10.0): ", i);
            scanf("%lf", &nota);
            
            if (nota >= 0.0 && nota <= 10.0) {
                break; // Sai do while de validação se a nota for aceitável
            }
            printf("[ERRO] Nota invalida! A nota deve estar entre 0.0 e 10.0.\n");
        }
        
        somaNotas += nota; // Acumulação do resultado válido
    }

    double mediaTurma = somaNotas / totalAlunos;
    printf("\n=== RELATÓRIO ACADÊMICO ===\n");
    printf("Total de estudantes avaliados: %d\n", totalAlunos);
    printf("Media final da turma: %.2f\n", mediaTurma);

    return 0;
}

