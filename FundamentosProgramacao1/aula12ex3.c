//@Marcos Tadao Shoji @2374200 @aula12ex3
/*
3) Construa um programa que leia uma matriz de tamanho
5 x 5 e escreva:
 O valor e a localização (linha, coluna) do maior valor encontrado
na matriz.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int matriz[5][5];
    int linha = 0;
    int coluna = 0;
    int comparacao = 0;
    int comparante = 0;

    printf("Este programa recebera uma matriz 5 x 5.\n\n");
    printf("Sera imprimido o maior elemento da matriz e sua posicao.\n\n");
    printf("Ao inserir os elementos das matrizes use numeros inteiros.\n");

    for(linha = 0; linha < 5; linha++){

        for(coluna = 0; coluna < 5; coluna++){

            matriz[linha][coluna];

            printf("\nInsira o elementeo [%i] x [%i]:\n\n", linha, coluna);
            scanf("%i", &matriz[linha][coluna]);

        }//for coluna

    }//for linha

    comparacao = matriz[0][0];

    printf("\nA matriz inserida tem formato:\n\n");

    for(linha = 0; linha < 5; linha++){

        for(coluna = 0; coluna < 5; coluna++){

            matriz[linha][coluna];

            printf("%5i", matriz[linha][coluna]);

        }//for coluna

        printf("\n");

    }//for linha

    for(linha = 0; linha < 5; linha++){

        for(coluna = 0; coluna < 5; coluna++){

            comparante = matriz[linha][coluna];

            if(comparante > comparacao){

                comparacao = matriz[linha][coluna];

            }//if valor maior

        }//for coluna

    }//for linha

    printf("\nO maior elemento vale: %i\n\n", comparacao);

    printf("A ou as posicoes do maior valor sao:\n");

    for(linha = 0; linha < 5; linha++){

        for(coluna = 0; coluna < 5; coluna++){

            matriz[linha][coluna];

            if(matriz[linha][coluna] == comparacao){

                printf("\n[%i] x [%i]\n", linha, coluna);

            }//if posicoes do maior elemento

        }//for coluna

    }//for linha

return 0;
}//main
