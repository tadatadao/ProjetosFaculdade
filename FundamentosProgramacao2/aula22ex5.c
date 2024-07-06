/**
 * @file aula22ex5.txt
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 5)Crie uma estrutura representando um ranking. Essa
            estrutura deve conter o nome do jogador e sua pontuação.
            Em seguida, escreva um programa que leia os dados de 5
            jogadores e os armazene em um arquivo utilizando a
            técnica de Dados formatados.
 * @version 0.1
 * @date 2022-05-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{

   char nome[50];
   int pontuacao;

}Jogadores;

int main(){

   Jogadores jog[5];

   for(int tamanho = 0; tamanho < 5; tamanho++){

      printf("\nPara o jogador [%i]:\n\n", tamanho + 1);
      printf("Digite o nome do jogador: ");
      fgets(jog[tamanho].nome, 48, stdin);
      jog[tamanho].nome[strcspn(jog[tamanho].nome, "\n")] = '\0';
      setbuf(stdin, NULL);

      printf("Digite a pontuacao do jogador: ");
      scanf("%i", &jog[tamanho].pontuacao);
      setbuf(stdin, NULL);

   }//for tamanho

   FILE *arquivo = fopen("a22e5.txt", "w");

   if(arquivo == NULL){

       printf("\nOcorreu o erro 1.\n\n");

    }//if erro

   for (int tamanho = 0; tamanho < 5; tamanho++){

      fprintf(arquivo, "%-48s ", jog[tamanho].nome);
      fprintf(arquivo, "%i\n", jog[tamanho].pontuacao);

   }//for tamanho

   fclose(arquivo);   

return 0;
}//main