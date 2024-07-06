/*
13) Faça um programa que verifique se um número dado via teclado é primo.
Dica: para saber se um número n é primo,
basta dividir por cada um dos números entre 2 e raiz quadrada de n;
se o resto for diferente de zero pra todos ele é primo.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int numero_inserido;
    int divisao_incremento = 2;
    int verificador = 0;

    printf("Este programa determinara se o valor inserido e primo.\n\n");
    printf("Para ser primo o numero deve ser superior a 1\ne divisivel apenas por ele mesmo e por 1.\n\n");
    printf("Use apenas numeros naturais.\n\n");
    printf("Digite o numero:\n\n");
    scanf("%i", &numero_inserido);

    if(numero_inserido <= 1){

        printf("\nO zero, um ou numeros negativos nao sao primos.\n");

    }//if zero um ou negativo

    else{

        while(divisao_incremento >= 2 && divisao_incremento <= (numero_inserido/2)){

            if(numero_inserido % divisao_incremento == 0){

                verificador++;

            }//if verifica divisores do numero inserido

            divisao_incremento++;

        }//while repete divisoes incremento ate metade do numero inserido

        if(verificador == 0){

        printf("\nO numero %i e primo.\n", numero_inserido);

        }//if primo

        else{

            printf("\nO numero %i nao e primo.\n", numero_inserido);

        }//else nao primo

    }//else maior ou igual a dois

return 0;
}//main
