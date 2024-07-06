//@Marcos Tadao Shoji @2374200 @aula12ex4
/*
4) Faça um programa que multiplique por 5 a
matriz A (preenchida a partir do teclado) para gerar a
matriz C.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int linha;
    int coluna;
    int linha_usuario;
    int coluna_usuario;

    printf("Este programa recebera uma matriz A do usuario.\n\n");
    printf("A matriz A tera sera multiplicada pelo escalar 5.\n\n");
    printf("A matriz resultante da operacao sera apresentada por uma matriz C.\n\n");
    printf("As linhas e colunas devem receber valores naturais.\n\n");
    printf("Os elementos da matriz devem possuir valores inteiros.\n\n");
    printf("Insira a quantidade de linhas da matriz A:\n\n");
    scanf("%i", &linha_usuario);
    printf("\nInsira a quantidade de colunas da matriz A:\n\n");
    scanf("%i", &coluna_usuario);

    int matriz_a[linha_usuario][coluna_usuario];
    int matriz_c[linha_usuario][coluna_usuario];

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

    for(linha = 0; linha < linha_usuario; linha++){

        for(coluna = 0; coluna < coluna_usuario; coluna++){

            matriz_c[linha][coluna] = 5 * matriz_a[linha][coluna];

        }//for coluna

    }//for linha

    printf("\nComo resultado a matriz C tem formato:\n\n");

    for(linha = 0; linha < linha_usuario; linha++){

        for(coluna = 0; coluna < coluna_usuario; coluna++){

            matriz_c[linha][coluna];

            printf("%5i", matriz_c[linha][coluna]);

        }//for coluna

        printf("\n");

    }//for linha

return 0;
}//main
