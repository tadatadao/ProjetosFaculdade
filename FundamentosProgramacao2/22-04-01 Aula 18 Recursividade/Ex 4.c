/**
 * @file aula18ex4
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 4) Faça uma função recursiva que retorne o n-ésimo termo da sequência de
          Fibonacci, sendo que n é recebido por parâmetro. Utilize essa função para
          desenvolver um programa que mostre no main() os n termos dessa
          sequência na tela, a partir do valor de n recebido pelo teclado. Sabe-se que
          o 1º termo é 0 e o 2º termo é 1.
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>

void instrucoes(){

  printf("Este programa informara o n-esimo termo da sequencia de fibonacci.\n\n");
  printf("O usuario devera informar n.\n\n");
  printf("Sendo n um numero inteiro maior que zero.\n\n");

return;
}//instrucoes

int fibonacci(int recebe_n){

  if(recebe_n == 0)
    return 0;

  if(recebe_n == 1)
    return 1;

  else
    return fibonacci(recebe_n-1) + fibonacci(recebe_n-2);

}//fibonacci

int main(){

  int informa_n;

  instrucoes();

  printf("Insira n:\n\n");
  scanf("%i", &informa_n);
  setbuf(stdin,NULL);
  printf("\n");

  printf("A sequencia de %i termos fica:\n\n", informa_n);

  for(int linha = 0; linha < informa_n; linha++){

    printf("%i", fibonacci(linha));
    printf("\n");

  }//for linha

return 0;
}//main
