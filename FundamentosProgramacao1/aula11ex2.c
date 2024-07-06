//@Marcos Tadao Shoji @2374200 @aula11ex2
/*
2) Crie um algoritmo que receba 10 números e os armazene em
um vetor A. Em seguida, gere o vetor B onde cada elemento é o
quadrado do valor da mesma posição no vetor A
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float valores_usuario[10];
    float quadrado_valores[10];
    int indice;

    printf("Este programa calculara o quadrado de 10 numeros.\n\n");
    printf("Os numeros serao dados pelo usuario.\n\n");
    printf("Os valores podem ser qualquer numero real.\n\n");
    printf("Para separacao decimal use (.).\n");

    for(indice = 0; indice < 10; indice++){

        printf("\nEntre com um numero:\n\n");
        scanf("%f", &valores_usuario[indice]);

    }//for valores do usuario

    for(indice = 0; indice < 10; indice++){

        quadrado_valores[indice] = pow(valores_usuario[indice],2);

        printf("\nQuadrado[%i] = %.2f\n", indice, quadrado_valores[indice]);

    }//for quadrado dos valores

return 0;
}//main
