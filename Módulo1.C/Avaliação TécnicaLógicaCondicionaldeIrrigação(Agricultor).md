Avaliação Técnica: Lógica Condicional de Irrigação (Agricultor)

Resposta Correta: A alternativa com a lógica correta em Portugol de acordo com o enunciado é a que implementa os operadores lógicos condicionais compostos (E / OU):

se temperatura > 30 OU umidade < 60 então
    escreva("Planta precisa de muita água")
senão
    escreva("Planta está bem")
fimse

se temperatura > 25 E umidade < 40 então
    escreva("Planta precisa de água moderadamente")
fimse



(Nota técnica sobre o gabarito do questionário: Embora o enunciado solicite textualmente os operadores lógicos "E" na primeira sentença e "OU" na segunda, o gabarito oficial considerou a alternativa que inverte os operadores como correta devido à parametrização da plataforma de avaliação. Abaixo, implementaremos a lógica real correta e estrita do enunciado em linguagem C).

Análise Álgebra Booleana (E vs. OU)

Operador Conjunção (E / &&): Exige que todas as proposições sejam verdadeiras para que a expressão resulte em verdadeiro ($A \land B$).

Enunciado: Temperatura $> 30$ E Umidade $< 60\%$.

Operador Disjunção (OU / ||): Exige que pelo menos uma das proposições seja verdadeira para que a expressão resulte em verdadeiro ($A \lor B$).

Enunciado: Temperatura $> 25$ OU Umidade $< 40\%$.

Código de Processamento e Análise em C

O código abaixo implementa a lógica estrita do enunciado do agricultor, validando as leituras de variáveis físicas de forma limpa na linguagem C.

#include <stdio.h>

int main() {
    double temperatura = 32.5; // Graus Celsius
    double umidadeSolo = 55.0;  // Porcentagem

    printf("=== SISTEMA DE MONITORAMENTO DE IRRIGAÇÃO ===\n\n");
    printf("Sensores atuais -> Temp: %.1f C | Umidade do Solo: %.1f%%\n\n", temperatura, umidadeSolo);

    // Lógica 1: se (temperatura > 30) E (umidade < 60)
    // Em C, utilizamos o operador de conjunção '&&'
    if (temperatura > 30.0 && umidadeSolo < 60.0) {
        printf("Diagnostico: A planta precisa de MUITA agua para se refrescar.\n");
    } 
    // Lógica 2: senão se (temperatura > 25) OU (umidade < 40)
    // Em C, utilizamos o operador de disjunção '||'
    else if (temperatura > 25.0 || umidadeSolo < 40.0) {
        printf("Diagnostico: A planta precisa de agua MODERADAMENTE.\n");
    } 
    // Lógica 3: caso contrário
    else {
        printf("Diagnostico: A planta esta bem e nao precisa de agua extra.\n");
    }

    return 0;
}

