//@Marcos Tadao Shoji @RA:2374200 @aula10ex6
/*
7) Faça um programa que mostre n elementos da sequência de
Fibonacci.
 O valor de n é passado para o programa.
 O primeiro termo é 0, e o segundo termo é 1, os demais devem seguir a
fórmula t
n = tn-1 + tn-2
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int elemento_n;//elemento n da sequencia de fibonacci
    int sequente;//sequente de fibonacci
    int sequente_anterior = 0;
    int contador = 1;

    printf("Este programa mostrara a sequencia de fibonacci.\n\n");
    printf("O usuario deve inserir a quantidade de elementos da sequencia.\n\n");
    printf("Use apenas numeros naturais.\n\n");
    printf("Insira a quantidade de elementos:\n\n");
    scanf("%i", &elemento_n);
    printf("\n0\n");
    printf("1\n");

    for(sequente = 1; contador < (elemento_n - 2); contador++){
    /*
    Os elementos 1 e 2 da sequencia de fibonacci nao sao determinados pela regra
    em que elemento n = sequente n - sequente n-1, os elementos 1 e 2 valem respectivamente 0 e 1.
    */
        sequente = (sequente + sequente_anterior);

        sequente_anterior = sequente - sequente_anterior;

        printf("%i\n", sequente);

    }//for fibonacci até n-2

return 0;
}//main
