/**
 * @file aula18ex6
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 6) Considere a funcaox abaixo. O que essa função faz? Escreva
          uma função não-recursiva que resolve o mesmo problema
          int funcaox(int a){
          if(a <= 0) return 0;
          else return a + funcaox(a-1);
          }//funcaox
 * @version 0.1
 * @date 2022-04-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//A função descrita é um somatório que soma um montante pelo termo n 

#include <stdio.h>

void instrucoes(){

  printf("Este programa calculara a soma de um montante de uma soma.\n\n");
  printf("Em outras palavras um somatorio.\n\n");
  printf("O usuario vai informar o termo n do somatorio.\n\n");
  printf("n deve ser um numero natural.\n\n");

return;
}//instrucoes

int somatorio(int recebe_numero){

  int somatorio = 0;

  int auxiliar = 1;

  for(recebe_numero > 0; auxiliar <= recebe_numero; auxiliar++){

    somatorio = somatorio + auxiliar;
    
  }//for recebe numero

return somatorio;
}//somatorio

int main (){

  int informa_n;

  instrucoes();

  printf("Digite n:\n\n");
  scanf("%i", &informa_n);
  setbuf(stdin,NULL);
  printf("\n");

  while(informa_n < 0){

    printf("n tem que ser natural ou seja positivo.\n\n");
    printf("Digite um numero valido para n.\n\n");
    scanf("%i", &informa_n);
    setbuf(stdin,NULL);
    printf("\n");

  }//while negativo  

  printf("O somatorio de %i termos vale %i\n\n", informa_n, somatorio(informa_n));

return 0;
}//main