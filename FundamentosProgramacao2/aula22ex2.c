/**
 * @file aula22ex2.txt
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 2)Elabore um programa que leia um arquivo binário contendo
            100 números. Mostre na tela a soma desses números.
 * @version 0.1
 * @date 2022-05-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>

int main(){

    int salva_numero[100];
    int soma_numero = 0;

    FILE *arquivo = fopen("a22e1.bin", "rb");

    if(arquivo == NULL){

       printf("\nOcorreu o  erro 1.\n\n");

    }//if erro

    fread(salva_numero, sizeof(int), 100, arquivo);

    for(int tamanho = 0; tamanho < 100; tamanho++){

        soma_numero = salva_numero[tamanho] + soma_numero;

    }//for tamanho

    printf("A soma dos numeros do arquivo vale %i.\n\n", soma_numero);

    fclose(arquivo);

return 0;
}//main