//@Marcos Tadao Shoji @aula9ex2
/*
2) Faça um programa que receba valores enquanto eles estiverem no
intervalo de 500 a 1000. Ao receber um valor fora da faixa, o
programa deverá parar de solicitar valores, exibir quantos valores
válidos foram digitados e finalizar.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int contador;
    int valor_inserido;
    int loop = 0;

    printf("Este programa recebera um valor.\n\n");
    printf("O valor deve ser natural.\n\n");
    printf("Ele devera estar no intervalo fechado de 500 a 1000.\n\n");
    printf("Para finalizar o programa entre um valor fora do intervalo.\n\n");
    printf("Ao final sera mostrado a quantidade de entradas validas.\n\n");

    do {

        printf("Digite o numero:\n\n");
        scanf("%i", &valor_inserido);
        printf("\nPara finalizar o programa entre um valor fora do intervalo.\n\n");

        if (valor_inserido < 500 || valor_inserido > 1000) {

            printf("Valor fora do intervalo.\n\n");
            printf("O programa sera finalizado.\n\n");
            break;

        }//if fora do intervalo

        contador++;

    }while (loop >= 0);

    printf("Foram entrados %i valores dentro do intervalo.\n", contador);

return 0;
}//main
