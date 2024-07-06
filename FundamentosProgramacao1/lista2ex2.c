/*
2) Crie um programa que receba um n�mero positivo Z
e imprima todos os n�meros de Z at� 1
e no final exiba quais s�o os n�meros m�ltiplos de 4,
quantos n�meros s�o m�ltiplos de 3
e a m�dia dos n�meros m�ltiplos de 5.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int valor_usuario;
    int multiplo_tres;
    int multiplo_quatro;
    int multiplo_cinco;
    int soma = 0;
    float media;
    int linha;
    int contador = 0;

    printf("Este programa recebera um valor do usuario.\n\n");
    printf("O valor inserido deve ser natural.\n\n");
    printf("Sera mostrado:\n\n");
    printf("-A ordem decrescente do numero informado ate 1.\n");
    printf("-Os multiplos de 3.\n");
    printf("-Os multiplos de 4.\n");
    printf("-E a media dos multiplos de 5.\n\n");
    printf("Insira o numero:\n\n");
    scanf("%i", &valor_usuario);

    int salva_valores[valor_usuario];

    for(linha = 0; linha < valor_usuario; linha++){

        salva_valores[linha] = linha + 1;

    }//for salva os valores

    printf("\nA ordem decrescente dos valores e:\n");

    for(linha = valor_usuario - 1; linha >= 0; linha--){

        printf("\n%i\n", salva_valores[linha]);

    }//for salva os valores

    printf("\nOs multiplos de 3 sao:\n");

    for(linha = 0; linha < valor_usuario; linha++){

        if(salva_valores[linha] % 3 == 0){

            printf("\n%i\n", salva_valores[linha]);

        }//imprime multiplo de 3

    }//for linhas

    printf("\nOs multiplos de 4 sao:\n");

    for(linha = 0; linha < valor_usuario; linha++){

        if(salva_valores[linha] % 4 == 0){

            printf("\n%i\n", salva_valores[linha]);

        }//imprime multiplo de 4

    }//for linhas

    for(linha = 1; linha < valor_usuario; linha++){

        if(salva_valores[linha] % 5 == 0){

            soma = soma + salva_valores[linha];

            contador++;

        }//soma os multiplos de 5

    }//for linhas

    media = (float)soma / contador;

    printf("\nA media dos multiplos de 5 vale: %.2f\n", media);

return 0;
}//main
