//@Marcos Tadao Shoji @aula8ex11
/*
Faça um programa que receba valores enquanto eles estiverem no intervalo de 500 a 1000.
Ao receber um valor fora da faixa, o programa deverá parar de solicitar valores,
exibir quantos valores válidos foram digitados e finalizar.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int intervalo = 0;
    int numero;
    int contador;

    printf("O programa lera valores inseridos entre 500 e 1000.\n\n");
    printf("O valor inserido deve ser natural.\n\n");
    printf("Para finalizar as entradas digite um numero invalido.\n\n");
    printf("Ao final exibiremos a quantidade de entradas validas.\n\n");

    while (intervalo >= 0) {

        printf("No intervalo de 500 a 1000.\n\n");
        printf("Insira um numero:\n\n");
        scanf("%i", &numero);

        if(numero >= 500 && numero <= 1000) {

            printf("\nLembre-se que para finalizar basta digitar um numero invalido.\n\n");
            printf("Continuando.\n\n");

        }//if valido

            else if(numero < 500 || numero > 1000) {

                printf("\nNumero invalido.\n\n");
                printf("Finalizando programa.\n\n");
                break;

            }//else invalido

        contador++;

    }//while

    printf("Voce digitou %i entradas validas.\n", contador);

return 0;
}//main
