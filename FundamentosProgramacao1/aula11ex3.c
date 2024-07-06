//@Marcos Tadao Shoji @2374200 @aula11ex3
/*
3) Leia um vetor A com 10 elementos inteiros correspondentes
as idades de um grupo de pessoas. Escreva um programa que
conte e exiba a quantidade de pessoas que possuem idade
superior a 35 anos.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int idades[10];
    int indice;
    int contador = 0;

    printf("Este programa salvara 10 idades dados pelo usuario.\n\n");
    printf("Serao exibidos apenas idades superiores a 35 anos.\n\n");
    printf("No fim sera exibido a quantidade de idades que respeitaram a condicao.\n\n");
    printf("Ao inserir a idade use apenas numeros naturais.\n");

    for(indice = 0; indice < 10; indice++){

        printf("\nInsira uma idade:\n\n");
        scanf("%i", &idades[indice]);

    }//for idades inseridas

    printf("\nAs idades acima de 35 anos sao:\n");

    for(indice = 0; indice < 10; indice++){

        if(idades[indice] > 35){

            printf("\n%i\n", idades[indice]);

            contador++;

        }//if acima de 35

    }//for idade acima de 35

    printf("\nForam iseridas %i idades acima de 35 anos.\n", contador);

return 0;
}//main
