/**
 * @file aula19ex5.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 5) Elabora uma função que receba duas strings como parâmetros e
            verifique se a segunda string está dentro da primeira. Para isso, utilize
            apenas aritmética de ponteiros.
 * @version 0.1
 * @date 2022-05-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void instrucoes(){

    printf("O usuario desvera digitar duas palavras quaisquer com limite de 40 caracteres.\n\n");
    printf("Em seguida o programa ira chacar se a segunda palavras esta contida na primeira.\n\n");
    printf("Exemplo: ""depurador"" e ""dor"" verificamos que dor esta contida em depurador.\n\n");

return;
}//instrucoes

int comparaString(char string1[], char string2[]){

   int tamanho1 = strlen(string1);
   int tamanho2 = strlen(string2);
   int auxiliar = 0;
   int contido = 0;

   for(int i = 0; i < tamanho1; i++){

       if(*(string1 + i) == *(string2)){

           for(int j = 0; j < tamanho2; j++){

               if(*(string1 + i + j) == *(string2 + j)){

                  auxiliar++;

                  if(auxiliar == tamanho2){

                     contido = 1;
                     return contido;
                       
                  }//if quebra repeticao achou igual

               }//if continua comparacao

               else{

                   break;

               }//else continuacao nao igual

           }//for j

           auxiliar = 0;

       }//if carctere igual

   }//for i

return contido;
}//compara string

int main(){

   char string1[41];
   char string2[41];

   instrucoes();

   printf("Digite a primeira palavra: ");
   fgets(string1, 41, stdin);
   string1[strcspn(string1, "\n")] = '\0';
   setbuf(stdin,NULL);
   printf("\nDigite a segunda palavra: ");
   fgets(string2, 41, stdin);
   string2[strcspn(string2, "\n")] = '\0';
   setbuf(stdin,NULL);

   if(comparaString(string1, string2) == 1){

      printf("\nA palavra 2 esta contida na palavra 1.\n\n");

   }//if contido

   else{

      printf("\nA palavra 2 nao esta contida na palavra 1.\n\n");

   }//else nao contido

return 0;
}//main