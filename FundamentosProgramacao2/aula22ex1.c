/**
 * @file aula22ex1.txt
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 1)Faça um programa que gere 100 números aleatórios. Esse
            programa deverá, em seguida,armazenar esses números em um
            arquivo binário.
 * @version 0.1
 * @date 2022-05-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    
    int numeros_aleatorios[100];

    srand(time(NULL));

    for(int tamanho = 0; tamanho < 100; tamanho++){

        numeros_aleatorios[tamanho] = rand() % 1000;

    }//for tamanho

    FILE *arquivo = fopen("a22e1.bin", "wb");

    if(arquivo == NULL){

       printf("\nOcorreu o  erro 1.\n\n");

    }//if erro

    fwrite(numeros_aleatorios, sizeof(int), 100, arquivo);

    fclose(arquivo);

return 0;

}//main