Avaliação Técnica: Análise de Condicionais em Fluxo Bancário

Resposta Correta: c. Na etapa de avaliação da capacidade de pagamento do cliente.

Justificativa de Engenharia de Requisitos

Em modelagem de processos de negócios (BPMN) e engenharia de software, as tomadas de decisão são representadas graficamente por elementos de desvio (gateways decimais/losangos). Esses desvios traduzem-se diretamente em estruturas condicionais no código-fonte.

Por que a alternativa C está correta? A "avaliação da capacidade de pagamento" exige uma análise lógica de variáveis (ex: comprometimento de renda, score de crédito e histórico de inadimplência). O fluxo do banco divide-se neste ponto de forma binária ou multi-caminho:

SE a capacidade de pagamento atender aos critérios mínimos $\rightarrow$ O empréstimo prossegue para aprovação e liberação.

SENÃO $\rightarrow$ A solicitação é sumariamente rejeitada.

As etapas de preenchimento de formulário (A) e liberação de fundos (D) são sequenciais e operacionais (ações diretas ou processamentos lineares sem desvios). A etapa de aprovação (B) é meramente a consequência ou o estado resultante da decisão condicional tomada no passo (C).

Demonstração de Fluxo de Decisão em C

O código abaixo implementa a lógica exata de avaliação da capacidade de pagamento com estruturas condicionais aninhadas de forma técnica.

#include <stdio.h>
#include <stdbool.h>

// Definição da estrutura de dados do cliente (Abstração de Dados)
typedef struct {
    double rendaMensal;
    double parcelaSolicitada;
    int scoreCredito;
} Cliente;

// Função especialista em avaliar capacidade de pagamento
bool avaliarCapacidadePagamento(Cliente* c) {
    // Regra 1: A parcela não pode comprometer mais de 30% da renda mensal bruta
    double limiteComprometimento = c->rendaMensal * 0.30;
    
    // Regra 2: O score de crédito mínimo exigido pela instituição é de 600 pontos
    if (c->parcelaSolicitada > limiteComprometimento) {
        printf("[REJEITADO] Parcela compromete %.1f%% da renda (Maximo permitido: 30%%).\n", 
               (c->parcelaSolicitada / c->rendaMensal) * 100);
        return false; // Desvio condicional negativo
    }
    
    if (c->scoreCredito < 600) {
        printf("[REJEITADO] Score de credito abaixo do limite minimo (%d < 600).\n", c->scoreCredito);
        return false; // Desvio condicional negativo
    }
    
    return true; // Desvio condicional positivo (Aprovado)
}

int main() {
    Cliente solicitante = {5000.00, 1200.00, 650}; // Parcela compromete 24% da renda, Score de 650

    printf("=== MOTOR DE DECISÃO DE EMPRÉSTIMOS ===\n\n");
    
    // Ponto de decisão (Estrutura Condicional)
    if (avaliarCapacidadePagamento(&solicitante)) {
        printf("[APROVADO] Cliente elegivel para concessao de credito. Liberando fundos...\n");
    } else {
        printf("[REPROVADO] Nao foi possivel conceder o emprestimo.\n");
    }

    return 0;
}

