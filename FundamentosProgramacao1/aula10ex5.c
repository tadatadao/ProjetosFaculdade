//@Marcos Tadao Shoji @RA:2374200 @aula10ex5
/*
5) Faça um programa que calcule o fatorial de um número a ser
digitado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int numero_fatorar;
    int resultado;
    int salvar_numero;//auxiliar para guardar o numero do usuario

    printf("Este programa calculara o fatorial de um dado numero.\n\n");
    printf("Ao entrar com o numero use apenas numeros naturais.\n\n");
    printf("Digite o numero:\n\n");
    scanf("%i", &numero_fatorar);

    salvar_numero = numero_fatorar;

    if(numero_fatorar < 0){

        printf("\nNao existe fatorial de numero negativo.\n");

    }//if numero negativo

    else if(numero_fatorar == 0){

        printf("\nO fatorial de 0 vale 1.\n");

    }//else if zero

    else if(numero_fatorar > 0){

        for(resultado = 1; numero_fatorar >= 1; numero_fatorar--){

            resultado = resultado * numero_fatorar;

        }//for fatorial do numero

        printf("\nO fatorial de %i vale %i\n", salvar_numero, resultado);

    }//else if fatorial possivel

return 0;
}//main
