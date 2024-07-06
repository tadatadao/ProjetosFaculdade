//@Marcos Tadao Shoji @aula8ex6
/*
6) Faça um programa que receba um número real, calcule e
exiba o quadrado dele. O programa deverá calcular o quadrado
de vários números e finalizar quando for digitado um número
negativo ou zero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    float numero_real = 1;
    float resultado;

    printf("Este programa calculara o quadrado de um numero inserido.\n\n");
    printf("Voce podera calcular o quadrado de qualquer numero.\n\n");
    printf("Exceto zero e numeros negativos.\n\n");
    printf("Use (.) para quebra decimal.\n\n");
    printf("Insira um numero real:\n\n");

    while(numero_real > 0) {

            scanf("%f", &numero_real);

            resultado = pow(numero_real,2);

            printf("\nO quadrado de %f e: %f\n\n", numero_real, resultado);

    }//while

    printf("Respeite as regras.\n");

return 0;
}//main
