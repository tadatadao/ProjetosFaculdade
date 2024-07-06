/**
 * @file aula18ex3
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief Crie uma função que retorne x elevado a y através
          de operação de multiplicação.
          A função recebe x e y por parâmetro.
 * @version 1.0
 * @date 2022-04-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

void instrucoes(){

  printf("Este programa calculara a potencicao entre dois numeros.\n\n");
  printf("O usuario deve informar a base e o expoente.\n\n");
  printf("Ambos devem ser numeros inteiros.\n\n");
  printf("O expoente deve ser maior que zero.\n\n");

return;
}//instrucoes

int potencicao_por_multiplicacao(int x, int y){

  if(y == 1){

    return x;

  }//if elevado a 1

  else{

    return x * potencicao_por_multiplicacao(x, y-1);

  }//else inteiros

return;
}//potencicao_por_multiplicacao

int main () {

  int x,y;

  instrucoes();

  printf("Digite a base:\n\n");
  scanf("%i", &x);
  setbuf(stdin,NULL);
  printf("\n");
  printf("Digite o expoente:\n\n");
  scanf("%i", &y);
  setbuf(stdin,NULL);
  printf("\n");
  printf("A potencicao entre os numeros vale %i.\n\n", potencicao_por_multiplicacao(x,y));

return 0;
}//main
