/**
 * @file aula21ex6.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 6)Elabore um programa no qual o usuário informe o nome
            de um arquivo texto e uma palavra, e o programa informe o
            número de vezes que aquela palavra aparece

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

   printf("Este programa ira contar as repeticoes de uma palavra em um arquivo texto.\n\n");
   printf("A palavra deve ser digitada pelo usuario quando requisitado.\n\n");
   printf("O usuario tambem deve inserir o nome do arquivo a ser lido.\n\n");
   printf("Nao esquecer de adicionar a extensao .txt ao dim do nome do arquivo.\n\n");

return;
}//istrucoes

int main(){

   char palavra_usuario[50];//palavra desejada pelo usuario
   char nome_arquivo[20];//nome do arquivo a ser lido
   char le_caractere_arquivo;//le os caracteres do arquivo
   char salva_texto_arquivo[200];//copia o conteudo do arquivo
   char salva_parte_texto[50];//salva parte do texto definido pelo for
   int posicao = 0;//posicao do vetor
   int contador_palavra = 0;//conta as repeticoes da palavra
   int condicao_para_palavra = 1;//condicao para entrar no if que conta palavras
   
   instrucoes();

   printf("Digite a palavra desejada: ");
   fgets(palavra_usuario, 49, stdin);
   palavra_usuario[strcspn(palavra_usuario, "\n")] = '\0';
   setbuf(stdin, NULL);

   printf("\nDigite o nome do arquivo: ");
   fgets(nome_arquivo, 19, stdin);
   nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';
   setbuf(stdin, NULL);

   FILE *arquivo = fopen(nome_arquivo, "r");

   if(arquivo == NULL){

      printf("\nOcorreu o erro 1.\n\n");
      exit(1);

   }// if erro

   while((le_caractere_arquivo = fgetc(arquivo)) != EOF){

      salva_texto_arquivo[posicao] = le_caractere_arquivo;
      posicao++; 

   }//while le ate o fim do arquivo

   for(int tamanho = 0; tamanho < posicao; tamanho++){

      for(int valor = tamanho, posicao_palavra = 0; posicao_palavra < strlen(palavra_usuario); valor++, posicao_palavra++){

         salva_parte_texto[posicao_palavra] = salva_texto_arquivo[valor];

         if(salva_texto_arquivo[valor + 1] >= 32 && salva_texto_arquivo[valor + 1] <= 47 ||
            salva_texto_arquivo[valor + 1] >= 58 && salva_texto_arquivo[valor + 1] <= 64 ||
            salva_texto_arquivo[valor + 1] >= 91 && salva_texto_arquivo[valor + 1] <= 95 ||
            salva_texto_arquivo[valor + 1] >= 123 && salva_texto_arquivo[valor + 1] <= 127){

            condicao_para_palavra = 0;

         }//if proximo caractere e espaco            

      }//for valor percorre a string no tamanho da palavra
   
      if(strcasecmp(palavra_usuario, salva_parte_texto) == 0 && condicao_para_palavra == 0){

         contador_palavra++;
         condicao_para_palavra = 0;

      }//if restante igual      

   }//for tamanho percorre a string ate o fim   

   if(contador_palavra == 0){

      printf("\nA palavra %s nao existe no texto.\n\n", palavra_usuario);

   }//if nao tem a palavra

   else{

      printf("\nA palavra %s repete %i vezes.\n\n", palavra_usuario, contador_palavra);

   }//else tem a palavra

   fclose(arquivo);
   
return 0;
}//main