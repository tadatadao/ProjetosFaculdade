/*
4) Faça um programa que calcule o imposto de renda a ser
pago tendo como entrada o salário de um empregado. O
imposto deve ser calculado da seguinte maneira:
imposto = salário x alíquota – parcela da dedução
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    double salario;
    double aliquota;
    double deducao;
    double imposto_renda;
    /*
    Base de Cálculo (R$)            Alíquota (%)        Parcela a Deduzir (R$)
    de 0,00 até 1.903,98                                    isento 0,00
    de 1.903,99 até 2.826,65           7,5                  142,80
    de 2.826,66 até 3.751,05           15                   354,80
    de 3.751,06 até 4.664,68           22,5                 636,13
    a partir de 4.664,68               27,5                 869,36
    */
    printf("Este programa vai te ajudar calcular o seu imposto de renda.\n\n");
    printf("Informe o seu salario\n\n");
    printf("Lembre-se de usar (.) para quebra decimal.\n\n");
    scanf("%lf", &salario);

    if (salario <= 1903.98) {
        printf("\nVoce esta isento do imposto de renda.\n");
    }//if
    else if (salario >= 1903.99 && salario <= 2826.65) {
        aliquota = 7.5;
        deducao = 142.80;
        imposto_renda = salario * aliquota - deducao;
        printf("\nO valor a ser pago e de: %.2lf reais\n", imposto_renda);
    }//else
    else if (salario >= 2826.66 && salario <= 3751.05) {
        aliquota = 15;
        deducao = 354.80;
        imposto_renda = salario * aliquota - deducao;
        printf("\nO valor a ser pago e de: %.2lf reais\n", imposto_renda);
    }//else
        else if (salario >= 3751.06 && salario <= 4664.68) {
        aliquota = 22.5;
        deducao = 636.13;
        imposto_renda = salario * aliquota - deducao;
        printf("\nO valor a ser pago e de: %.2lf reais\n", imposto_renda);
    }//else
        else if (salario > 4664.68) {
        aliquota = 27.5;
        deducao = 869.36;
        imposto_renda = salario * aliquota - deducao;
        printf("\nO valor a ser pago e de: %.2lf reais\n", imposto_renda);
    }//else

return 0;
}//main
