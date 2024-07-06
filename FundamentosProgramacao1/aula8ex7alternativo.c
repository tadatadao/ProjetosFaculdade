//@Marcos Tadao Shoji @aula8ex7
/*
7) Faça um programa que calcule o fatorial de um número a ser
digitado.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int numero_fatoracao;
    int resultado = 1;
    int comparacao;//comparacao = numero_fatorcao inicial

    printf("Este programa realiza fatoracao de um dado numero.\n\n");
    printf("So podem ser fatorados numeros naturais.\n\n");
    printf("Digite o numero:\n\n");
    scanf("%i", &numero_fatoracao);

    comparacao = numero_fatoracao;

    if (numero_fatoracao > 0) {

        while(numero_fatoracao >= 1) {

            resultado = resultado * (numero_fatoracao);//loop multiplica valor de resultado ate o valor de numero_fatoracao definido
            numero_fatoracao--;

        }//while

         printf("\nO fatorial de %i e: %i\n", comparacao, resultado);

    }//if

        else if(numero_fatoracao == 0) {

            printf("\nFatorial de zero vale um.\n");

        }//else zero

            else {

                printf("\nValor sem fatorial possivel.\n");

            }//else sem fatorial

return 0;
}//main
