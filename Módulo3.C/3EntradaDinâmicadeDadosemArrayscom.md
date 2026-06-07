Vídeo 3: Entrada Dinâmica de Dados em Arrays com C

Este documento técnico apresenta a análise de rotinas de leitura de dados via console para preenchimento de matrizes unidimensionais na linguagem C, com foco na manipulação de ponteiros na entrada padrão.

1. Entrada de Dados e o Operador de Endereço &

Ao utilizar a função padrão de leitura scanf() para popular as células de um vetor, é imperativo que o parâmetro de destino aponte para o endereço de memória exato da variável que receberá os dados.

A sintaxe &temperaturas[i] fornece ao scanf o ponteiro físico correspondente à célula de memória mapeada pelo índice i.

O formato de leitura de dados flutuantes de dupla precisão (double) exige o especificador %lf no scanf para garantir a conversão correta dos bits.

2. Mitigação de Ruídos na Entrada

A entrada padrão de dados via teclado armazena dados em um buffer de entrada. Durante leituras sequenciais, é essencial garantir que apenas os valores numéricos válidos sejam capturados e as operações aritméticas de acumulação ocorram de forma linear.

3. Código de Demonstração Técnica (C Puro)

O código abaixo implementa uma rotina para coletar dinamicamente quatro valores de temperatura do usuário, armazena em um vetor e realiza o cálculo matemático da média.

#include <stdio.h>

int main() {
    // Alocação de 32 bytes para 4 variáveis double (4 * 8 bytes)
    double temperaturas[4];
    double soma = 0.0;

    printf("=== ENTRADA DINÂMICA DE DADOS EM ARRAYS ===\n\n");

    // Loop de entrada de dados sequenciais
    for (int i = 0; i < 4; i++) {
        printf("Informe o valor da temperatura %d: ", i + 1);
        
        // O operador & é fundamental para apontar para o endereço de memória exato do índice i
        if (scanf("%lf", &temperaturas[i]) != 1) {
            printf("Erro crítico na leitura de dados. Finalizando o programa.\n");
            return 1;
        }
        
        soma += temperaturas[i]; // Acumulação do valor lido
    }

    // Processamento da média baseada no tamanho lógico do vetor
    double media = soma / 4.0;

    printf("\n=== RELATÓRIO DE TEMPERATURAS ===\n");
    for (int i = 0; i < 4; i++) {
        printf("Temperatura %d: %.2f C\n", i + 1, temperaturas[i]);
    }
    
    printf("\nA media das temperaturas calculada eh: %.2f C\n", media);

    return 0;
}
