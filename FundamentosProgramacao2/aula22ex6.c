/**
 * @file aula22ex6.txt
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 6)Considerando a estrutura ranking do exercício anterior,
            escreva um programa que leia o arquivo gerado contendo
            os dados dos 5 jogadores.
 * @version 0.1
 * @date 2022-05-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct{

   char nome[50];
   int pontuacao;

}Jogadores;

int main(){

   Jogadores jog[5];

   FILE *arquivo = fopen("a22e5.txt", "r");

   if(arquivo == NULL){

       printf("\nOcorreu o  erro 1.\n\n");

   }//if erro

   for (int tamanho = 0; tamanho < 5; tamanho++){

      fscanf(arquivo, "%48[^\n] %i\n", jog[tamanho].nome, &jog[tamanho].pontuacao);
      printf("%s %i\n", jog[tamanho].nome, jog[tamanho].pontuacao);

   }//for tamanho

   fclose(arquivo);   

return 0;
}//main