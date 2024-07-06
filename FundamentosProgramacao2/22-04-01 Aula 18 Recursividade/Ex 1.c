/**
 * @file aula18ex1
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief Crie uma função que retorne o fatorial de um número passado por
          parâmetro
 * @version 1.0
 * @date 2022-04-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

void instrucoes(){

  printf("Este programa calculara o fatorial de um numero.\n\n");
  printf("O numero sera informado pelo usuario.\n\n");
  printf("O numero informado deve ser inteiro e nao negativo.\n\n");

return;
}//instrucoes

int fatoral(int num){

  if(num == 1 || num == 0){

    return 1;

  }//if zero ou um

  else{

    return num * fatoral( (num - 1));

  }//if inteiro

return;
}//fatorial

int main () {

  int numero;

  instrucoes();

  printf("Digite o numero a ser fatoriado:\n\n");
  scanf("%i", &numero);
  setbuf(stdin,NULL);

  while(numero < 0){

    printf("Sem numero negativo, tente de novo.\n\n");
    printf("Digite novamente o numero:\n\n");
    scanf("%i", &numero);
    setbuf(stdin,NULL);

  }//while numero negativo

  printf("\n");
  printf("O fatoral de %i vale %i.\n\n", numero, fatoral(numero));

return 0;
}//main
