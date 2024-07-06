/*
1) Sabendo-se que 200 quilowatts de energia custa um quarto do salário mínimo, faça um programa que receba o valor do salário mínimo
e a quantidade de quilowatts gasta por uma residência e mostre:
a) O valor em reais de cada quilowatt;
b) O valor em reais a ser pago pelos quilowatts gastos;
c) O novo valor a ser pago por essa residência com um desconto de 12%;
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    float kwatts = 200;
    float salario_minimo;
    float custo_de_cada_kwatt;
    float kwatts_consumidos;
    float conta_sem_desconto;
    float conta_com_desconto;

    printf("Vamos descobrir o valor da sua conta de energia?\n\n");
    printf("Insira o valor do salario minimo atual. Use (.) para quebra decimal.\n\n");
    scanf("%f", &salario_minimo);
    printf("\nAgora nos informe o consumo de energia em kilowatts\n\n");
    scanf("%f", &kwatts_consumidos);

    custo_de_cada_kwatt = ((salario_minimo / 4) / kwatts);
    conta_sem_desconto = custo_de_cada_kwatt * kwatts_consumidos;
    conta_com_desconto = conta_sem_desconto - (0.12 * conta_sem_desconto);

    printf("\nLembrando que o custo de cada Kwatt e: %.3f reais\n\n", custo_de_cada_kwatt);
    printf("O valor da sua conta sem desconto e: %.3f reais\n\n", conta_sem_desconto);
    printf("Com desconto de 12 por cento a sua conta e: %.3f reais\n", conta_com_desconto);

return 0;
}
