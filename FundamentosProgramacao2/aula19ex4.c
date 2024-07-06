/**
 * @file aula19ex4.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 4) Crie um programa que contenha um vetor de inteiros de tamanho 5.
          Utilizando aritmética de ponteiros, leia os dados do teclado e exiba seus
          valores multiplicado por 2. Em seguida, exiba o endereço de memória das
          posições que contém valores pares.
 * @version 0.1
 * @date 2022-05-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>

void instrucoes(){

    printf("Este programa recebera do usuario 5 valores inteiros.\n\n");
    printf("Os valores serao salvos em vetor.\n\n");
    printf("O programa ira multiplicar todos os valores por 2.\n\n");
    printf("Em seguida o programa ira exibir o endereco de memoria dos valores pares digitados pelo usuario.\n\n");

return;
}//instrucoes

void operaPonteiro(int vetor[]){

    for(int linha = 0; linha < 5; linha++){

        printf("\nO dobro da posicao %i vale: %i\n", linha, (*(vetor + linha)) * 2);

    }//for linha

    printf("\nO endereco de memoria dos valores pares sao:\n");

    for(int linha = 0; linha < 5; linha++){

        if((*(vetor + linha)) % 2 == 0){

            printf("\nposicao [%i] endereco: %p\n", linha, vetor+linha);            

        }

    }//for linha

return;
}//opera ponteiro

int main(){

    int vetor[5];

    instrucoes();

    for(int linha = 0; linha < 5; linha++){

        printf("\nDigite o valor para posicao [%i]:", linha);
        scanf("%i",&vetor[linha]);
        setbuf(stdin,NULL);

    }//for linha

    operaPonteiro(vetor);

return 0;
}//main