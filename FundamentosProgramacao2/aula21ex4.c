/**
 * @file aula21ex4.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 4)Crie um programa para calcular e exibir o número de palavras
            contido em um arquivo texto. O usuário deverá informar o nome do
            arquivo.
 * @version 0.1
 * @date 2022-05-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void instrucoes(){

   printf("Este programa contara a quantidade de palavras de um arquivo sem tabulacao.\n\n");
   printf("O usuario deve entrar com o arquivo que vai ser lido.\n\n");
   printf("Ao entrar o arquivo nao esquecer de adicionar a extensao .txt\n\n");

return;
}//instrucoes

int main(){

   char nome_arquivo[20];
   int conta_espaco = 0;
   char le_caractere;

   instrucoes();

   printf("Digite o nome do arquivo: ");
   fgets(nome_arquivo, 19, stdin);
   nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';
   setbuf(stdin, NULL);

   FILE *arquivo = fopen(nome_arquivo, "r");

   if(arquivo == NULL){

      printf("\nOcorreu o erro 1.\n\n");
      exit(1);

   }//if erro

   while((le_caractere = fgetc(arquivo)) != EOF){

      if(le_caractere == ' ' || le_caractere == '\n'){

         conta_espaco++;

      }//if caractere espaco

   }//while le o texto do arquivo ate o fim

   printf("\nO arquivo contem %i palavras\n\n", conta_espaco + 1);

   fclose(arquivo);

return 0;
}//main