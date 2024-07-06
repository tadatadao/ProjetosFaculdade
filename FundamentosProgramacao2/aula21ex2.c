/**
 * @file aula21ex2.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 2)Escreva um programa que leia do usuário os nomes de dois
            arquivos texto. Crie um terceiro arquivo texto com o conteúdo dos
            dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo do
            segundo).
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

   printf("Este programa juntara o conteudo de 2 arquivos definidos pelo usuario.\n\n");
   printf("Ao digitar o nome do arquivo deve-se adicionar a extensao dela o .txt\n\n");
   printf("Ao fim o programa salvara na mesma pasta que os arquivos definidos o arquivo a22e2p3.\n\n");
   printf("Neste arquivo estarao o conteudo o primeiro arquivo seguido do segundo.\n\n");

return;
}//instrucoes

int main(){

   char arquivo1[20];//entrada do usuario p/ o primeiro arquivo
   char arquivo2[20];//entrada do usuario p/ o segundo arquivo
   char salva_arquivo1[50];//salva em vetor o conteudo do arquivo1
   char salva_arquivo2[50];//salva em vetor o conteudo do arquivo2
   char texto_arquivo3[100];//salva o conteudo do arquivo1 em seguida o do arquivo2
   int posicao_vetor1 = 0;//auxiliar para posicao do vetor
   int posicao_vetor2 = 0;//auxiliar para posicao do vetor
   int posicao_vetor3 = 0;//auxiliar para posicao do vetor
   char caractere_arquivo;//os caracteres do arquivo

   printf("Digite o nome do primeiro arquivo: ");
   fgets(arquivo1, 19, stdin);
   arquivo1[strcspn(arquivo1, "\n")] = '\0';
   setbuf(stdin, NULL);

   printf("\nDigite o nome do segundo arquivo: ");
   fgets(arquivo2, 19, stdin);
   arquivo2[strcspn(arquivo2, "\n")] = '\0';
   setbuf(stdin, NULL);

   FILE *arquivo_1 = fopen(arquivo1, "r");

   if(arquivo_1 == NULL){

      printf("\nOcorreu um erro 1.\n\n");
      exit(1);

   }//if erro

   while ((caractere_arquivo = fgetc(arquivo_1)) != EOF){
      
      salva_arquivo1[posicao_vetor1] = caractere_arquivo;
      posicao_vetor1++;

   }//le os caracteres do texto ate o fim

   FILE *arquivo_2 = fopen(arquivo2, "r");

   if(arquivo_2 == NULL){

      printf("\nOcorreu um erro 2.\n\n");
      exit(1);

   }//if erro

   while ((caractere_arquivo = fgetc(arquivo_2)) != EOF){
      
      salva_arquivo2[posicao_vetor2] = caractere_arquivo; 
      posicao_vetor2++;

   }//le os caracteres do texto ate o fim

   for(int tamanho = 0; tamanho < posicao_vetor1; tamanho++){

      texto_arquivo3[tamanho] = salva_arquivo1[tamanho];

   }//for tamanho

   for(int tamanho = posicao_vetor1; tamanho <= posicao_vetor1 + posicao_vetor2; tamanho++, posicao_vetor3++){

      texto_arquivo3[tamanho] = salva_arquivo2[posicao_vetor3];

   }//for tamanho

   FILE *arquivo_3 = fopen("a22e2p3.txt", "w");

   if(arquivo_3 == NULL){

      printf("\nOcorreu um erro 3.\n\n");
      exit(1);

   }//if erro

   for(int tamanho = 0; tamanho < posicao_vetor1 + posicao_vetor2; tamanho++){

      fputc(texto_arquivo3[tamanho], arquivo_3);

   }//for tamanho

   fclose(arquivo_1);
   fclose(arquivo_2);
   fclose(arquivo_3);

   printf("\nAbra a pasta e cheque o arquivo a22e2p3.txt para conferir o resultado.\n\n");

return 0;
}//main