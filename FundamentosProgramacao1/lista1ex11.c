/*
11) Desenvolva um algoritmo que receba vários números no intervalo fechado de 1 a 1000.
Ao receber um valor fora da faixa,
o programa deverá exibir a soma dos números pares e o produto dos números ímpares e finalizar.
Obs: O valor fora da faixa utilizado para sair não deverá entrar na conta da soma nem do produto.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int valor_recebido = 1;
    int soma_numeros_pares = 0;
    int produto_numeros_impares = 1;

    printf("Este programa recebera valores inteiros entre 1 e 1000.\n\n");
    printf("Para finalizar o programa insira um valor fora do intervalo.\n\n");
    printf("Ao fim serao realizados:\n");
    printf("-A soma dos valores pares.\n");
    printf("-O produto dos valores impares.\n\n");
    printf("O valor fora do intervalo nao sera contabilizado.\n");

    do {

        printf("\nDigite o numero:\n\n");
        scanf("%i", &valor_recebido);

        if(valor_recebido % 2 == 0){

            soma_numeros_pares = soma_numeros_pares + valor_recebido;

        }//if soma par

        else if(valor_recebido % 2 != 0){

            produto_numeros_impares = produto_numeros_impares * valor_recebido;

        }//else if produto impar

        if(valor_recebido <= 0 || valor_recebido > 1000){

            if(valor_recebido % 2 == 0){

            soma_numeros_pares = soma_numeros_pares - valor_recebido;

            }//if valor par

            else if(valor_recebido % 2 != 0){

            produto_numeros_impares = produto_numeros_impares / valor_recebido;

            }//else valor impar

        }//if valor fora do intervalo

    }while(valor_recebido > 0 && valor_recebido <= 1000);//do while valor no intervalo de 1 a 1000

    printf("\nA soma dos numeros pares inseridos e: %i\n\n", soma_numeros_pares);
    printf("O produto dos numeros impares e: %i\n", produto_numeros_impares);

}//main
