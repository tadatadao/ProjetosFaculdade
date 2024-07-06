/**
 * @file aula21ex1.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 1)Escreva um programa que leia do usuário o nome de um arquivo
            texto. Em seguida, mostre na tela quantas linhas esse arquivo possui.
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void instrucoes(){

   printf("Este programa lera um arquivo especificado pelo usuario.\n\n");
   printf("Ao fim sera exibido a quantidade de linhas presentes no arquivo.\n\n");
   printf("Ao digitar o arquivo lembre-se que ele deve existir na pasta atual.\n\n");
   printf("Nao esqueca que a extensao do arquivo tambem deve estar presente (.txt, .doc, .pdf)\n\n");

return;
}//instrucoes

int main(){

   char texto[20];
   char procura_quebra_linha;
   int conta_quebra_linha = 0;

   instrucoes();

   printf("Digite o nome do arquivo: ");
   fgets(texto, 49, stdin);
   texto[strcspn(texto,"\n")] = '\0';
   setbuf(stdin,NULL);

   FILE *arquivo = fopen(texto,"r");

   if(arquivo == NULL){

      printf("Ocorreu um erro.\n\n");
      exit(1);

   }//if erro

   while((procura_quebra_linha = fgetc(arquivo)) != EOF){

      if(procura_quebra_linha == '\n'){

         conta_quebra_linha++;

      }//if texto e quebra de linha

   }//le o arquivo ate o fim

   printf("\nO arquivo possui %i linha(s)\n\n",conta_quebra_linha+1);//linhas = quebras de linhas + 1

   fclose(arquivo);

return 0;
}//main