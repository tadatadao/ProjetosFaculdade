/**
 * @file aula19ex1.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 1) Escreva um programa que contenha duas variáveis inteiras. Compare os
          endereços e exiba o endereço e o conteúdo do maior endereço.
 * @version 0.1
 * @date 2022-05-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>

void instrucoes(){

    printf("Este programa recebera 2 valores inteiros do usuario.\n\n");
    printf("Em seguida o rpograma ira identificar o valor que foi salvo no maior endereco de memoria.\n\n");
    printf("Entao serao exibidos o enderececo e o valor contidos na memoria.\n\n");

return;
}//instrucoes

void ponteiros(int variavel1, int variavel2){

    
    int *ponteiro1;
    int *ponteiro2;

    ponteiro1 = &variavel1;
    ponteiro2 = &variavel2;

    if(ponteiro1 > ponteiro2){

        printf("A variavel de maior conteudo possui %d no conteudo e endereco de memoria %p.\n\n", *ponteiro1, ponteiro1);
        printf("A outra variavel possui %d no conteudo e endereco de memoria %p.\n\n", *ponteiro2, ponteiro2);

    }//if ponteiro 1 maior que ponteiro2

    else{

        printf("A variavel de maior conteudo possui %d no conteudo e endereco de memoria %p.\n\n", *ponteiro2, ponteiro2);

    }//else ponteiro 2 maior

return;
}//ponteiros

int main(){

    int variavel1;
    int variavel2;

    instrucoes();

    printf("Insira o valor da primeira variavel:");
    scanf("%i",&variavel1);
    setbuf(stdin,NULL);
    printf("\n");
    printf("Insira o valor da segunda variavel:");
    scanf("%i",&variavel2);
    setbuf(stdin,NULL);
    printf("\n");

    ponteiros(variavel1, variavel2);

return 0;
}//main