/**
 * @file aula19ex3.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief  3) Crie um programa que contenha uma matriz (3x3) de float. Imprima o
           endereço de cada posição dessa matriz.
 * @version 0.1
 * @date 2022-05-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>

void instrucoes(){

    printf("Este programa exibira o endereco de memoria de uma matriz 3 x 3.\n");

return;
}//instrucoes

void matrizPonteiro(float matriz[][3]){

    for(int linha = 0; linha < 3; linha++){

        for(int coluna = 0; coluna < 3; coluna++){

            printf("\nO endereco de memoria da posicao [%i] x [%i] eh: %p\n", linha, coluna, *matriz + 3 * linha + coluna);

        }//for coluna

    }//for linha

return;
}//matriz ponteiro

int main(){

    float matriz[3][3];

    instrucoes();

    matrizPonteiro(matriz);

return 0;
}//main