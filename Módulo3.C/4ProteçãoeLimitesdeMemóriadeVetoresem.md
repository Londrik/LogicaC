Vídeo 4: Proteção e Limites de Memória de Vetores em C

Este documento aborda a segurança da memória e a prevenção de falhas de segmentação ao manipular índices dinâmicos na linguagem C.

1. O Problema do Estouro de Buffer (Buffer Overflow)

Diferente de linguagens de alto nível que gerenciam a memória virtualmente (como o Java), a linguagem C executa instruções de forma direta sobre os ponteiros de memória.

Se um loop não for delimitado de forma estrita ao tamanho físico alocado, o processador lerá dados indesejados da memória vizinha (gerando ruído na análise) ou tentará ler de um espaço protegido do sistema operacional, resultando no encerramento abrupto do processo por Segmentation Fault.

2. Estratégia de Proteção de Software

Dado que o hardware do computador não impede o estouro de limites do vetor de forma automática na compilação em C, cabe ao desenvolvedor criar rotinas de validação lógica (guardas condicionais) para garantir a integridade dos limites do array.

3. Código de Demonstração Técnica (C Puro)

O código abaixo simula a proteção ativa de limites de escrita de vetor. Ele solicita o número do índice que o usuário quer alterar e rejeita dinamicamente entradas que extrapolam a capacidade física da estrutura.

#include <stdio.h>

#define TAMANHO_VETOR 5

int main() {
    int idades[TAMANHO_VETOR] = {20, 25, 30, 35, 40};
    int indiceEscolhido = 0;
    int novoValor = 0;

    printf("=== ATUALIZAÇÃO SEGURA DE VETORES ===\n\n");

    printf("Vetor atual: ");
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        printf("[%d] ", idades[i]);
    }
    printf("\n\n");

    printf("Qual indice deseja alterar (0 a %d)? ", TAMANHO_VETOR - 1);
    scanf("%d", &indiceEscolhido);

    // Guarda de proteção: Evita invasão de endereço físico de memória
    if (indiceEscolhido < 0 || indiceEscolhido >= TAMANHO_VETOR) {
        printf("\n[ERRO CRÍTICO] Falha de seguranca: O indice %d esta fora dos limites de memoria!\n", indiceEscolhido);
        printf("Operacao cancelada para evitar falha de segmentacao (Segmentation Fault).\n");
        return 1; // Encerra o programa de forma controlada indicando erro
    }

    printf("Digite o novo valor para a idade na posicao %d: ", indiceEscolhido);
    scanf("%d", &novoValor);

    // Escrita segura sobre a memória alocada
    idades[indiceEscolhido] = novoValor;

    printf("\n[SUCESSO] Dado gravado com seguranca na pilha.\n");
    printf("Novo estado do vetor: ");
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        printf("[%d] ", idades[i]);
    }
    printf("\n");

    return 0;
}
