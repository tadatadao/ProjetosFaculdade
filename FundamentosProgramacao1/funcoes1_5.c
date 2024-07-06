/**
 * @file aula16ex5.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
5) Crie uma função que que receba o valor de um inteiro
positivo N, calcule e retorne o fatorial desse número.
*/

#include <stdio.h>
#include <stdlib.h>

int calcula_fatorial(int numero, int fatorial);//cabeçalho
void esclarecimentos();//cabeçalho

int main(){

    int recebe_numero;
    int recebe_fatorial;
    int resultado;

    esclarecimentos();
    printf("Insira o numero para o calculo do fatorial:\n\n");
    scanf("%i", &recebe_numero);
    setbuf(stdin,NULL);

    resultado = calcula_fatorial(recebe_numero, recebe_fatorial);
    printf("\nO fatorial vale: %i\n", resultado);

return 0;
}//main

int calcula_fatorial(int numero, int fatorial){

    for(fatorial = 1; numero > 1; numero--){

        fatorial = fatorial * numero;

    }//for calcula fatorial

return fatorial;
}//fatorial;

void esclarecimentos(){

    printf("Este programa um numero do usuario.\n\n");
    printf("Sera exibido o fatorial do numero.\n\n");
    printf("Use apenas numeros inteiros positivos.\n\n");

return;
}//esclarecimentos
