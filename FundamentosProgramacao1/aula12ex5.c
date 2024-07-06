//@Marcos Tadao Shoji @2374200 @aula12ex5
/*
5) Faça um programa que some as matrizes A e B,
gerando C
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int linha_usuario;
    int coluna_usuario;
    int linha;
    int coluna;

    printf("Este programa recebera as matrizes A e B do usuario.\n\n");
    printf("As matrizes A e B serao somadas resultando em uma matriz C.\n\n");
    printf("Lembrando que para somar matrizes as linhas e colunas devem ser iguais.\n\n");
    printf("Tendo isso em mente insira as quantidades:\n\n");
    printf("De linhas para as matrizes A e B:\n\n");
    scanf("%i", &linha_usuario);
    printf("\nE colunas para as matrizes A e B:\n\n");
    scanf("%i", &coluna_usuario);

    int matriz_a[linha_usuario][coluna_usuario];
    int matriz_b[linha_usuario][coluna_usuario];
    int matriz_c[linha_usuario][coluna_usuario];

    printf("\nAgora preencha a matriz A:\n");

    for(linha = 0; linha < linha_usuario; linha++){

        for(coluna = 0; coluna < coluna_usuario; coluna++){

            matriz_a[linha][coluna];

            printf("\nInsira o elemento A: [%i] x [%i]:\n\n", linha, coluna);
            scanf("%i", &matriz_a[linha][coluna]);

        }//for coluna

    }//for linha

    printf("\nA matriz A tem formato:\n\n");

    for(linha = 0; linha < linha_usuario; linha++){

        for(coluna = 0; coluna < coluna_usuario; coluna++){

            matriz_a[linha][coluna];

            printf("%5i", matriz_a[linha][coluna]);

        }//for coluna

        printf("\n");

    }//for linha

    printf("\nAgora preencha a matriz B:\n");

    for(linha = 0; linha < linha_usuario; linha++){

        for(coluna = 0; coluna < coluna_usuario; coluna++){

            matriz_b[linha][coluna];

            printf("\nInsira o elemento B: [%i] x [%i]:\n\n", linha, coluna);
            scanf("%i", &matriz_b[linha][coluna]);

        }//for coluna

    }//for linha

    printf("\nA matriz B tem formato:\n\n");

    for(linha = 0; linha < linha_usuario; linha++){

        for(coluna = 0; coluna < coluna_usuario; coluna++){

            matriz_b[linha][coluna];

            printf("%5i", matriz_b[linha][coluna]);

        }//for coluna

        printf("\n");

    }//for linha

    for(linha = 0; linha < linha_usuario; linha++){

        for(coluna = 0; coluna < coluna_usuario; coluna++){

            matriz_c[linha][coluna] = matriz_a[linha][coluna] + matriz_b[linha][coluna];

        }//for coluna

    }//for linha

    printf("\nA matriz C com o resultado da soma das matrizes A e B tem formato:\n\n");

    for(linha = 0; linha < linha_usuario; linha++){

        for(coluna = 0; coluna < coluna_usuario; coluna++){

            matriz_c[linha][coluna];

            printf("%5i", matriz_c[linha][coluna]);

        }//for coluna

        printf("\n");

    }//for linha

return 0;
}//main
