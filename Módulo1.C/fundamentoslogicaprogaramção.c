Módulo 1: Fundamentos da Lógica de Programação
Este guia prático compila os fundamentos da lógica de programação abordados no primeiro módulo, incluindo estruturas de decisão, operadores lógicos e repetição. O objetivo é servir como material de apoio e consulta para estudantes de tecnologia.
1. Estruturas Condicionais e Fluxogramas
No desenvolvimento de sistemas, a lógica de decisão é o que permite ao software reagir a diferentes situações. Antes de escrever o código, utilizamos fluxogramas para visualizar o caminho dos dados.
Estudo de Caso: Concessão de Empréstimos
Em um sistema bancário, o ponto central não é apenas coletar dados, mas analisá-los para tomar uma decisão.
Questão de Avaliação: Em que etapa de um fluxograma bancário encontramos uma condicional?
Resposta: Na etapa de avaliação da capacidade de pagamento.
O "Porquê": Uma condicional (if) representa um desvio no fluxo. Somente após a "avaliação" é que o sistema decide se segue para a aprovação ou para o indeferimento.
Implementação em Linguagem C
Abaixo, um exemplo simples de como traduzir essa lógica bancária:
#include <stdio.h>

int main() {
    float renda, parcela;

    printf("Digite a renda mensal: ");
    scanf("%f", &renda);
    printf("Digite o valor da parcela: ");
    scanf("%f", &parcela);

    // Condicional: Se a parcela for menor ou igual a 30% da renda
    if (parcela <= (renda * 0.30)) {
        printf("Resultado: Emprestimo Aprovado\n");
    } else {
        printf("Resultado: Emprestimo Reprovado\n");
    }

    return 0;
}


2. Operadores Lógicos (E / OU)
Sistemas complexos raramente dependem de uma única condição. Operadores lógicos permitem combinar verificações para decisões precisas.
Estudo de Caso: Monitoramento Agrícola
Imagine um sensor que decide o nível de irrigação baseado em Temperatura e Umidade.
Questão de Avaliação: Qual lógica implementa corretamente a necessidade de água?
Resposta: se temperatura > 30 OU umidade < 60 então escreva("Muita água").
O "Porquê": O operador OU (||) é usado aqui porque se estiver muito quente OU se o solo estiver seco, a planta já precisa de atenção imediata.
Implementação em Linguagem C
Utilizamos || para o operador OU e && para o operador E.
#include <stdio.h>

int main() {
    int temperatura, umidade;

    printf("Temperatura atual: ");
    scanf("%d", &temperatura);
    printf("Umidade do solo (%%): ");
    scanf("%d", &umidade);

    if (temperatura > 30 || umidade < 60) {
        printf("Status: Planta precisa de muita agua\n");
    } 
    else if (temperatura > 25 && umidade < 40) {
        printf("Status: Planta precisa de agua moderadamente\n");
    } 
    else {
        printf("Status: Planta esta bem\n");
    }

    return 0;
}


3. Estruturas de Repetição (Loops)
Loops são essenciais para tarefas repetitivas, como processar listas de dados ou realizar cálculos matemáticos sucessivos.
Estudo de Caso: Cálculo de Fatorial
O fatorial de um número () é a multiplicação dele por todos os seus antecessores até chegar em 1.
Questão de Avaliação: Qual a estrutura correta para calcular o fatorial de forma iterativa?
Resposta: Um loop while que multiplica a variável de controle pelo acumulador e a incrementa até atingir o número desejado.
O "Porquê": O loop garante que a operação de multiplicação se repita de forma automática até que a condição de parada seja atingida.
Implementação em Linguagem C
Exemplo utilizando a estrutura while (enquanto):
#include <stdio.h>

int main() {
    int numero, contador = 1;
    int fatorial = 1;

    printf("Calcular o fatorial de: ");
    scanf("%d", &numero);

    while (contador <= numero) {
        fatorial = fatorial * contador;
        contador = contador + 1; // Incremento da variável de controle
    }

    printf("O fatorial de %d e: %d\n", numero, fatorial);

    return 0;
}


Conclusão
Dominar a lógica de programação no Módulo 1 significa entender que:
Entrada: Recebemos dados (scanf).
Processamento: Analisamos dados (if/else) ou repetimos tarefas (while).
Saída: Entregamos o resultado ao usuário (printf).
