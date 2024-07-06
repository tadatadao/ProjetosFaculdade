#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char linha[100];

    // Abre o arquivo para leitura
    arquivo = fopen("funcionarios3.txt", "r");

    if(arquivo == NULL){

      printf("Erro ao abrir arquivo\n");
      exit(1);

   }//if erro

    // Lê a primeira linha do arquivo
    fgets(linha, 100, arquivo);
    // Imprime a primeira linha na tela
    printf("A primeira linha do arquivo eh: %s\n", linha);

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}