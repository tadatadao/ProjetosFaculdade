//@Marcos Tadao Shoji @2374200 @aula12ex1
/*
1) Crie uma matriz identidade com dimensões 5 x 5;
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int matriz[5][5];
    int linha;
    int coluna;

    printf("Este programa mostrara uma matriz ideintidade 5 x 5.\n\n");

    for(linha = 0; linha < 5; linha++){

        for(coluna = 0; coluna < 5; coluna++){

            matriz[linha][coluna];

            if(linha == coluna){

                matriz[linha][coluna] = 1;

            }//if 1

            else if(linha != coluna){

                matriz[linha][coluna] = 0;

            }//else if 0

        }//for coluna

    }//for linha

    for(linha = 0; linha < 5; linha++){

        for(coluna = 0; coluna < 5; coluna++){

            matriz[linha][coluna];

            printf("%4i", matriz[linha][coluna]);

        }//for coluna

        printf("\n");

    }//for linha

return 0;
}//main
