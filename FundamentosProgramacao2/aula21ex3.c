/**
 * @file aula21ex3.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 3)Escreva um programa para converter o conteúdo de um arquivo
            texto em caracteres maiúsculos. O programa deverá ler do usuário o
            nome do arquivo a ser convertido e o nome do arquivo a ser salvo.
 * @version 0.1
 * @date 2022-05-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void instrucoes(){

   printf("Este programa lera um arquivo texto definido pelo usuario.\n\n");
   printf("Em seguida o programa convertera o conteudo em minusculo para maiusculo.\n\n");
   printf("O arquivo em maiusculo sera nomeado pelo usuario.\n\n");
   printf("Tanto para o arquivo a ser lido tanto para o arquivo de maiusculos nao esqueca de acrecentar a extensao .txt\n\n");

return;
}//instrucoes

int main(){

   char nome_arquivo_ler[20];
   char nome_arquivo_escrever[20];
   char le_caractere;
   char salva_conteudo[50];
   char conteudo_maiusculo[50];
   int posicao = 0;

   instrucoes();

   printf("Digite o nome do arquivo a ser lido: ");
   fgets(nome_arquivo_ler, 19, stdin);
   nome_arquivo_ler[strcspn(nome_arquivo_ler, "\n")] = '\0';
   setbuf(stdin, NULL);

   FILE *arquivo_lido = fopen(nome_arquivo_ler, "r");

   if(arquivo_lido == NULL){

      printf("\nOcorreu o errro 1.\n\n");
      exit(1);

   }//if erro

   while ((le_caractere = fgetc(arquivo_lido)) != EOF){
      
      salva_conteudo[posicao] = le_caractere;
      posicao++;

   }//le e salva os caracteres do arquivo

   for(int tamanho = 0; tamanho < posicao; tamanho++){

      conteudo_maiusculo[tamanho] = toupper(salva_conteudo[tamanho]);      

   }//for tamanho, converte caracteres para maiusculo

   printf("\nDigite o nome do arquivo de maiusculos: ");
   fgets(nome_arquivo_escrever, 19, stdin);
   nome_arquivo_escrever[strcspn(nome_arquivo_escrever, "\n")] = '\0';
   setbuf(stdin, NULL);
   
   FILE *arquivo_escrito = fopen(nome_arquivo_escrever, "w");

   if(arquivo_escrito == NULL){

      printf("\nOcorreu o erro 2.\n\n");
      exit(1);

   }//if erro

   for(int tamanho = 0; tamanho < posicao; tamanho++){

      fputc(conteudo_maiusculo[tamanho], arquivo_escrito);

   }//for tamanho, passa o conteudo maiusculo para o arquivo

   fclose(arquivo_lido);
   fclose(arquivo_escrito);

   printf("\nCheque a pasta dos arquivos para conferir o resultado.\n\n");

return 0;
}//main