//@Marcos Tadao Shoji @aula8ex5alternativo
/*
5) Faça um programa que receba um número real, calcule e
exiba o quadrado dele. O programa deverá repetir esse
procedimento para 10 números, um de cada vez.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    float numero_real;
    float resultado;
    int inicial;

    printf("Este programa calculara um dado numero ao quadrado.\n\n");
    printf("Poderao ser inseridos um total de 6 numeros para calcular.\n\n");
    printf("Use (.) como quebra decimal.\n\n");
    printf("Use qualquer numero real.\n\n");

    for (inicial = 0; inicial < 6; inicial++) {

        printf("Insira o numero:\n\n");
        scanf("%f", &numero_real);

        resultado = pow(numero_real,2);

        printf("\n%f elevado ao quadrado vale: %f\n\n", numero_real, resultado);

    }//for

    printf("Esperamos ter ajudado.\n\n");

return 0;
}//main
