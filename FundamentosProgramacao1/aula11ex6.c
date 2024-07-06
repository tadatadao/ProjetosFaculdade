//@Marcos Tadao Shoji @2374200 @aula11ex5
/*
6) Faça um programa que receba e armazene 20 números em
um vetor. Em seguida exiba:
 Quantos números são iguais a 30;
 Quantos números são maior que a média;
 Quantos números são iguais à media;
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int elementos_20[20];
    int indice;
    int soma;
    float media;
    int contador_igual_30 = 0;
    int contado_maior_media = 0;
    int contador_igual_media = 0;

    printf("Este programa recebera 20 numeros do usuario.\n\n");
    printf("Serao contados os numeros:\n\n");
    printf("*Iguais a 30.\n\n");
    printf("*Maiores que a media dos numeros.\n\n");
    printf("*Iguais a media dos numeros.\n\n");
    printf("Ao inserir os numeros use valores inteiros.\n");

    for(indice = 0; indice < 20; indice++){

        printf("\nInsira um numero:\n\n");
        scanf("%i", &elementos_20[indice]);

    }//for valores dos elementos

    soma = elementos_20[0];

    for(indice = 1; indice < 20; indice++){

        soma = soma + elementos_20[indice];

    }//for media

    media = (float)soma / 20;

    for(indice = 0; indice < 20; indice++){

        elementos_20[indice];

        if(elementos_20[indice] == 30){

            contador_igual_30++;

        }//if elemento = 30

        else if(elementos_20[indice] > media){

            contado_maior_media++;

        }//else if elemento maior que media

        else if(elementos_20[indice] == media){

            contador_igual_media++;

        }//else if igual media

    }//for comparacoes

    printf("\nA media dos numeros inseridos vale: %.2f\n\n", media);
    printf("Foram inseridaos:\n\n");
    printf("*%i valores iguais a 30.\n\n", contador_igual_30);
    printf("*%i valores maiores do que a media.\n\n", contado_maior_media);
    printf("*%i valores iguais a media.\n", contador_igual_media);

return 0;
}//main
