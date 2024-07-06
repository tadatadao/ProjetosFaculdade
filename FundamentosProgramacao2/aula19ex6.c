/**
 * @file aula19ex6.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 6) Considere a seguinte declaração:
            int a, *b, **c, ***d;
            Escreva um programa que receba o valor de a, calcule e exiba:
             O dobro do valor a, utilizando o ponteiro b
             O triplo do valor a, utilizando o ponteiro c
             O quadruplo do valor a, utilizando o ponteiro d
 * @version 0.1
 * @date 2022-05-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>

void instrucoes(){

    printf("Este programa recebere do usuario um valor inteiro.\n\n");
    printf("Em seguida sera exibido o dobro, o triplo e o quadruplo do valor informado.\n\n");

return;
}//main

int main(){

    int a, *b, **c, ***d;

    printf("Digite o valor desejado: ");
    scanf("%i",&a);
    setbuf(stdin,NULL);

    b = &a;
    c = &b;
    d = &c;

    printf("\nO dobro do valor informado vale: %d\n\n", 2 * *b);
    printf("O triplo vale: %d\n\n", 3 * **c);
    printf("O quadruplo vale: %d\n\n", 4 * ***d);

return 0;
}//main
