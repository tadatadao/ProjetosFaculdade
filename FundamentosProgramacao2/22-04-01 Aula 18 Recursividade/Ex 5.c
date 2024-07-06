/**
 * @file aula18ex5
 * @author Marcos Tadao Shoji
 * @brief 5) Um problema típico em ciência da computação consiste em
          converter um número da sua forma decimal para binária. Crie um
          algoritmo recursivo para resolver esse problema.
          - Solução trivial: x=0 quando o número inteiro já foi convertido para
          binário
          - Passo da recursão: saber como x/2 é convertido. Depois, imprimir um
          dígito (0 ou 1) dado o sucesso da divisão.
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

void instrucoes(){

  printf("Este programa mudara um numero da base decimal para base binaria.\n\n");
  printf("O usuario informara o numero na base decimal.\n\n");
  printf("O numero deve ser natural.\n\n");

return;
}//instrucoes

void decimal_binario(int recebe_numero){

  int quociente;

  if(recebe_numero != 0){

    quociente = recebe_numero / 2;
    decimal_binario(quociente);

    printf("%i", recebe_numero % 2);

  }//if recursao imprime por desimpilhamento ou seja de tras para frente

  else{

    printf("%i", recebe_numero % 2);
  
  }//else caso base que imprime o primeiro numero

return;
}//decimal_binario

int main () {

  int informa_numero;

  instrucoes();

  printf("Digite o numero a ser convertido:\n\n");
  scanf("%i", &informa_numero);
  setbuf(stdin,NULL);
  printf("\n");
  printf("O binario de %i fica:\n\n", informa_numero);

  decimal_binario(informa_numero);

  printf("\n\n");

  return 0;
}//main