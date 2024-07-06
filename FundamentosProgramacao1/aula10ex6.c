//@Marcos Tadao Shoji @RA:2374200 @aula10ex6
/*
6) Faça um programa que receba 10 números e calcule o
quadrado desse número (um de cada vez).
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float valor_usuario;
    float quadrado_valor;
    int contador;

    printf("Este programa calculara um dado numero ao quadrado.\n\n");
    printf("O procedimeto sera feito para 10 numeros escolhidos pelo usuario.\n\n");
    printf("O numero a ser iserido pode ser qualquer numero real.\n\n");
    printf("Havendo a necessidade de separacao decimal use (.).\n");

    for(contador = 0; contador < 10; contador++){

        printf("\nInsira o numero:\n\n");
        scanf("%f", &valor_usuario);

        quadrado_valor = pow(valor_usuario,2);//calculo do quadrado

        printf("\nO valor inserido ao quadrado vale: %.3f\n", quadrado_valor);

    }//for repetir 10 vezes

return 0;
}//main
