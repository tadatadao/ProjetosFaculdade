/**
 * @file aula21ex5.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 5)Elabore um programa para calcular e exibir o número de
            vezes que cada letra ocorre dentro de um arquivo texto.
            Ignore as letras com acento. O usuário deverá informar o
            nome do arquivo.

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

   printf("Este programa lera um arquivo definido pelo usuario.\n\n");
   printf("Ao inserir o nome do arquivo lembre-se de adicionar a extensao .txt\n\n");
   printf("O program ira contar e exibir os caracteres que apareceram no texto.\n\n");

return;
}//instrucoes

int main(){

   char nome_arquivo[20];
   char caractere_lido;
   char letras[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
   int conta_letra[26];

   instrucoes();

   for(int posicao = 0; posicao < 26; posicao++){

      conta_letra[posicao] = 0;

   }//for posicao

   printf("Digite o nome do arquivo: ");
   fgets(nome_arquivo, 19, stdin);
   nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';
   setbuf(stdin, NULL);

   FILE *arquivo = fopen(nome_arquivo, "r");

   if(arquivo == NULL){

      printf("\nOcorreu o erro 1.\n\n");
      exit(1);

   }//if erro

   while((caractere_lido = fgetc(arquivo)) != EOF){

      if(caractere_lido == 65 || caractere_lido == 65+32)
         conta_letra[0]++;
      if(caractere_lido == 66 || caractere_lido == 66+32)
         conta_letra[1]++;
      if(caractere_lido == 67 || caractere_lido == 67+32)
         conta_letra[2]++;
      if(caractere_lido == 68 || caractere_lido == 68+32)
         conta_letra[3]++;
      if(caractere_lido == 69 || caractere_lido == 69+32)
         conta_letra[4]++;
      if(caractere_lido == 70 || caractere_lido == 70+32)
         conta_letra[5]++;
      if(caractere_lido == 71 || caractere_lido == 71+32)
         conta_letra[6]++;
      if(caractere_lido == 72 || caractere_lido == 72+32)
         conta_letra[7]++;
      if(caractere_lido == 73 || caractere_lido == 73+32)
         conta_letra[8]++;
      if(caractere_lido == 74 || caractere_lido == 74+32)
         conta_letra[9]++;
      if(caractere_lido == 75 || caractere_lido == 75+32)
         conta_letra[10]++;
      if(caractere_lido == 76 || caractere_lido == 76+32)
         conta_letra[11]++;
      if(caractere_lido == 77 || caractere_lido == 77+32)
         conta_letra[12]++;
      if(caractere_lido == 78 || caractere_lido == 78+32)
         conta_letra[13]++;
      if(caractere_lido == 79 || caractere_lido == 79+32)
         conta_letra[14]++;
      if(caractere_lido == 80 || caractere_lido == 80+32)
         conta_letra[15]++;
      if(caractere_lido == 81 || caractere_lido == 81+32)
         conta_letra[16]++;
      if(caractere_lido == 82 || caractere_lido == 82+32)
         conta_letra[17]++;
      if(caractere_lido == 83 || caractere_lido == 83+32)
         conta_letra[18]++;
      if(caractere_lido == 84 || caractere_lido == 84+32)
         conta_letra[19]++;
      if(caractere_lido == 85 || caractere_lido == 85+32)
         conta_letra[20]++;
      if(caractere_lido == 86 || caractere_lido == 86+32)
         conta_letra[21]++;
      if(caractere_lido == 87 || caractere_lido == 87+32)
         conta_letra[22]++;
      if(caractere_lido == 88 || caractere_lido == 88+32)
         conta_letra[23]++;
      if(caractere_lido == 89 || caractere_lido == 89+32)
         conta_letra[24]++;
      if(caractere_lido == 90 || caractere_lido == 90+32)
         conta_letra[25]++;

   }//while le o arquivo ate o fim

   for(int tamanho = 0; tamanho < 26; tamanho++){

      if(conta_letra[tamanho] != 0){

         printf("\nA letra %c repete %i vezes\n", letras[tamanho], conta_letra[tamanho]);

      }//if nao contem a letra

   }//for tamanho

   fclose(arquivo);

return 0;
}//main