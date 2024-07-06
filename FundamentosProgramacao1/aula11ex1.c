//@Marcos Tadao Shoji @2374200 @aula11ex1
/*
1) Faça um programa que leia e armazene dois vetores de
tamanho 5. Ao final o programa deve calcular e exibir o vetor
soma;
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int vetor_1[5];
    int vetor_2[5];
    int vetor_soma[5];
    int indice;

    printf("Este programa salvara 10 valores dados pelo usuario.\n\n");
    printf("5 valores serao para 1 vetor 1 e 5 valores para o vetor 2.\n\n");
    printf("Apos a entrada dos valores sera exibida a soma dos vetores 1 e 2.\n\n");
    printf("Devem ser usados apenas numeros inteiros.\n\n");

    for(indice = 0; indice < 5; indice++){

        printf("\nEntre com um valor do vetor 1:\n\n");

        scanf("%i", &vetor_1[indice]);

    }//for valores de vetor 1

    for(indice = 0; indice < 5; indice++){

        printf("\nEntre com um valor para o vetor 2.\n\n");

        scanf("%i", &vetor_2[indice]);

    }//for valores para vetor 2

    printf("\nA soma vale:\n\n");

    for(indice = 0; indice < 5; indice++){

        vetor_soma[indice] = vetor_1[indice] + vetor_2[indice];

        printf("Soma[%i] = %i\n", indice, vetor_soma[indice]);

    }//for valores para soma

return 0 ;
}//main
