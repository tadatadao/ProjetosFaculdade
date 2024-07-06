//@Marcos Tadao Shoji @2374200 @aula12ex6
/*
6) Faça um programa que multiplique as matrizes A e D
abaixo gerando matriz AD

A
3 7 10
1 5 0
(2 linhas x 3 colunas)

D
1 2
5 6
2 3
(3 linhas x 2 colunas)

AD
3*1 + 7*5 + 10*2 = 58 | 3*2 + 7*6 + 10*3 = 78
1*1 + 5*5 + 0*2 = 26  | 1*2 + 5*6 + 3*0 = 32
(2 linhas x 2 colunas)
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int matriz_a[2][3];
    int matriz_d[3][2];
    int matriz_ad[2][2];
    int linha;
    int coluna;
    int linha_coluna_iguais;

    matriz_a[0][0] = 3;
    matriz_a[0][1] = 7;
    matriz_a[0][2] = 10;
    matriz_a[1][0] = 1;
    matriz_a[1][1] = 5;
    matriz_a[1][2] = 0;

    matriz_d[0][0] = 1;
    matriz_d[0][1] = 2;
    matriz_d[1][0] = 5;
    matriz_d[1][1] = 6;
    matriz_d[2][0] = 2;
    matriz_d[2][1] = 3;

    printf("Tendo em consideracao a matriz A [2] x [3]:\n\n");

    for(linha = 0; linha < 2; linha++){

        for(coluna = 0; coluna < 3; coluna++){

            matriz_a[linha][coluna];

            printf("%4i", matriz_a[linha][coluna]);

        }//for coluna

        printf("\n");

    }//for linha

    printf("\nE a matriz D [3] x [2]:\n\n");

    for(linha = 0; linha < 3; linha++){

        for(coluna = 0; coluna < 2; coluna++){

            matriz_d[linha][coluna];

            printf("%4i", matriz_d[linha][coluna]);

        }//for coluna

        printf("\n");

    }//for linha

    printf("\nA multiplicacao da matriz A pela matriz D.\n\n");
    printf("Tem como resultado a matriz AD.\n\n");
    printf("A matriz AD tem formato:\n\n");

    for(linha = 0; linha < 2; linha++){

        for(coluna = 0; coluna < 2; coluna++){

            matriz_ad[linha][coluna] = 0;

        }//for coluna

    }//for linha

    for(linha = 0; linha < 2; linha++){

        for(coluna = 0; coluna < 2; coluna++){

            for(linha_coluna_iguais = 0; linha_coluna_iguais < 3; linha_coluna_iguais++){

                matriz_ad[linha][coluna] = matriz_ad[linha][coluna] + (matriz_a[linha][linha_coluna_iguais] * matriz_d[linha_coluna_iguais][coluna]);

            }//for multiplica

        }//for coluna

    }//for linha

    for(linha = 0; linha < 2; linha++){

        for(coluna = 0; coluna < 2; coluna++){

            matriz_ad[linha][coluna];

            printf("%4i", matriz_ad[linha][coluna]);

        }//for coluna

        printf("\n");

    }//for linha

return 0;
}//main
