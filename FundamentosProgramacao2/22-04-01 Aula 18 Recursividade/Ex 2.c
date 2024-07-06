/**
 * @file aula18ex2
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 2) Crie uma função que retorne x*y através de operação de soma. A função
          recebe x e y por parâmetro
 * @version 1.0
 * @date 2022-04-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

void instrucoes(){

  printf("Este programa calculara o produto de 2 numeros.\n\n");
  printf("O produto sera calculado atraves de repetidas operacoes de soma.\n\n");
  printf("Ambos numeros serao informados pelo usuario.\n\n");
  printf("Use apenas numeros inteiros.\n\n");
  printf("O segundo numero tambem nao pode ser negativo.\n\n");
  printf("O primeiro numero e a base a ser somada.\n\n");
  printf("O segundo numero e a quantidade de vezes que a soma se repete.\n\n");

return;
}//instrucoes

int produto_por_soma(int x, int y){

  if(y == 0){

    return 0;

  }//if multiplicacao por 0

  else{

    return x + produto_por_soma(x, y-1);

  }//else inteiros

return;
}//produto_por_soma

int main () {

  int x, y;

  instrucoes();

  printf("Digite o primeiro numero:\n\n");
  scanf("%i", &x);
  setbuf(stdin,NULL);
  printf("\n");
  printf("Digite o segundo numero:\n\n");
  scanf("%i", &y);
  setbuf(stdin,NULL);
  printf("\n");
  printf("O produto entre os numeros vale %i.\n\n", produto_por_soma(x,y));

return 0;
}//main
