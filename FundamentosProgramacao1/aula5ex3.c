/*
3) Tendo como entrada de dados o total vendido por um
funcionário no mês, calcule a sua comissão e o salário bruto no
mês. Para isso, considere um salário base de R$1.200,00 e
comissão de 10% sobre o total vendido.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    double valor_total_vendas;
    double salario_fixo = 1200;
    double salario_total;

    printf("Em uma empresa os funcionarios de venda recebem um salario fixo de 1200 reais.\n\n");
    printf("Tais funcionarios recebem dez por cento do valor de suas vendas.\n\n");
    printf("Tendo os dados podemos calcular o salario total dos funcionario de vendas.\n\n");
    printf("Basta multiplicarmos o valor de suas vendas por 0.1\n\ne por fim adicionar o valor do salario fixo.\n\n");
    printf("Vamos colocar a hipotese a prova?\n\n");
    printf("Informe abaixo qualquer valor em reais para o total de vendas de um funcionario.\n");
    scanf("%lf", &valor_total_vendas);

    salario_total = (0.1 * valor_total_vendas) + salario_fixo;

    printf("\nDado o valor %.2lf reais o salario total e de %.2lf reais.\n", valor_total_vendas, salario_total);

return 0;
}
