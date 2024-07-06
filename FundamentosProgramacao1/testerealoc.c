#include <stdio.h>
#include <stdlib.h>

int main () {

  /*Variaveis Main: ----------------------------------------------------------*/
  int *vetor = malloc(10*sizeof(int));
  int tamanho;
  /*Variaveis Main ===========================================================*/

  printf("Digite o tamanho do vetor de inteiros: ");
  scanf("%d", &tamanho);

  if (tamanho < 10 || tamanho > 10)
    vetor = (int*)realloc(vetor, tamanho * sizeof(int));

  for (int i = 0; i < tamanho; i++) {
    printf("Vetor %d = ",i+1);
    scanf("%d", &vetor[i]);
  }

  printf("\n");

  for (int i = 0; i < tamanho; i++)
    printf("Vetor %d: %d\n",i+1,vetor[i]);

  printf("\n\n");
  return 0;
}//main
