/**
 * @file aula16ex1.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
1) Faça um algoritmo que implemente uma função que receba 3 números
inteiros e retorne o maior valor;
*/

#include<stdio.h>
#include<stdlib.h>

int achar_maior(int *vnumeros);//cabeçalho
void esclarecimentos();//cabeçalho

int main(){

    int linha;
    int maior_valor;
    int vnumeros[3];

    esclarecimentos();

    for(linha = 0; linha < 3; linha++){

        printf("\nInsira o numero (%i):\n\n", linha+1);
        scanf("%i", &vnumeros[linha]);

    }//for numeros do usuário

    maior_valor = achar_maior(vnumeros);//chamada da função

    printf("\nO maior valor e: %i\n", maior_valor);

return 0;
}//main

int achar_maior(int *vnumeros){//ponteiro

    int linha;
    int linha_1;
    int maior;

    for(linha_1 = 1, linha = 0; linha_1 < 3; linha_1++, linha++){

        if(vnumeros[linha_1] > vnumeros[linha]){

            maior = vnumeros[linha_1];

        }//if maior numero

    }//for linhas

return maior;
}//achar maior

void esclarecimentos(){

    printf("Este programa recebera 3 numeros inteiros do usuario.\n\n");
    printf("Sera exibido o maior numero inserido.\n\n");
    printf("Lembre-se insira apenas numeros inteiros.\n");

return;
}//esclarecimentos
