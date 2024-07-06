/**
 * @file aula20ex4.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 4)Escreva uma função que receba como parâmetro um valor L e um valor C e retorne
            o ponteiro para uma matriz alocada dinamicamente contendo L linhas e C colunas.
            Essa matriz deve ser inicializada com o valor 0 em todas as suas posições.
 * @version 0.1
 * @date 2022-05-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>

void instrucoes(){

   printf("Este programa ira receber dois numeros interios positivos do usuario.\n\n");
   printf("O primeiro numero sera o tamanho de linhas de uma matriz.\n\n");
   printf("o segundo numero sera o tamanho da coluna da matriz.\n\n");
   printf("Em seguida o programa ira preencher a matriz com zeros.\n\n");

return;
}//main

int** matriz_alocada(int linha, int coluna){

   int **matriz = (int**) malloc(linha * sizeof(int*));

   for(int l = 0; l < linha; l++){

      matriz[l] = (int*) malloc(coluna * sizeof(int));

      for(int c = 0; c < coluna; c++){
         
         matriz[l][c] = 0;

      }//for coluna

   }//for linha*-

return matriz;
}//matriz alocada

int main(){

   int linhas_matriz;
   int colunas_matriz;
   int **recebe_matriz;

   instrucoes();

   printf("Digite o numero de linhas: ");
   scanf("%i",&linhas_matriz);
   setbuf(stdin,NULL);
   printf("\nDigite o numero de colunas: ");
   scanf("%i",&colunas_matriz);
   setbuf(stdin,NULL);
   printf("\n");

   recebe_matriz = matriz_alocada(linhas_matriz, colunas_matriz);

   printf("A matriz nula com os dados informados fica:\n\n");

   for(int linha = 0; linha < linhas_matriz; linha++){

      for(int coluna = 0; coluna < colunas_matriz; coluna++){

         printf("%-3i ", recebe_matriz[linha][coluna]);

      }//for coluna

      printf("\n");

   }//for linha

   for(int linha = 0; linha < linhas_matriz; linha++){

      free(recebe_matriz[linha]);

   }//for linha

   free(recebe_matriz);
   
return 0;
}//main