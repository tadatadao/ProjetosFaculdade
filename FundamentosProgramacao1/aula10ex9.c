//@Marcos Tadao Shoji @2374200 @aula10ex9
/*
9) Desenvolva um programa que receba um numero
tamanho e exiba um quadrado de tamanho tamanho
utilizando o carácter #
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int lado_quadrado;
    int area_quadrado;

    printf("Este programa mostrara um quadrado de caracteres '#'.\n\n");
    printf("O usuario deve entrar com o tamanho numerico de um lado do quadrado.\n\n");
    printf("Use numeros naturais maiores que 0.\n\n");
    printf("Digite o tamanho do quadrado:\n\n");
    scanf("%i", &lado_quadrado);
    printf("\nO quadrado fica:\n\n");

    area_quadrado = pow(lado_quadrado,2);

    for(int contador = 1; contador <= area_quadrado; contador++){

        printf("#");

        if(contador % lado_quadrado == 0){

            printf("\n");

        }//if quebra de linha

    }//for quadrado de #

return 0;
}//main
