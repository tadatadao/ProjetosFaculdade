/*Faça um programa que some as matrizes A e B,
gerando C*/
#include<stdio.h>
#include<stdlib.h>

int soma_matriz(int linha, int coluna, int *matrizA, int *matrizB);
void esclarecimentos();

int main(){

    int linha;
    int coluna;
    int recebe_linha;
    int recebe_coluna;

    esclarecimentos();
    printf("Insira a quantidade de linhas para matriz A e B:\n\n");
    scanf("%i", &recebe_linha);
    printf("\nInsira a quantidade de colunas para matriz A e B:\n\n");
    scanf("%i", &recebe_coluna);

    int recebe_matrizA[recebe_linha][recebe_coluna];
    int recebe_matrizB[recebe_linha][recebe_coluna];
    int recebe_matrizC[recebe_linha][recebe_coluna];

    for(linha = 0; linha < recebe_linha; linha++){

        for(coluna = 0; coluna < recebe_coluna; coluna++){

            recebe_matrizA[linha][coluna];

            printf("\nInsira o elemento A: [%i] x [%i]:\n\n", linha, coluna);
            scanf("%i", &recebe_matrizA[linha][coluna]);

        }//for coluna

    }//for linha

    printf("\nA matriz A tem formato:\n\n");
    for(linha = 0; linha < recebe_linha; linha++){

        for(coluna = 0; coluna < recebe_coluna; coluna++){

            recebe_matrizA[linha][coluna];

            printf("%5i", recebe_matrizA[linha][coluna]);

        }//for coluna

        printf("\n");

    }//for linha

    printf("\nAgora preencha a matriz B:\n");

    for(linha = 0; linha < recebe_linha; linha++){

        for(coluna = 0; coluna < recebe_coluna; coluna++){

            recebe_matrizB[linha][coluna];

            printf("\nInsira o elemento B: [%i] x [%i]:\n\n", linha, coluna);
            scanf("%i", &recebe_matrizB[linha][coluna]);

        }//for coluna

    }//for linha

    printf("\nA matriz B tem formato:\n\n");

    for(linha = 0; linha < recebe_linha; linha++){

        for(coluna = 0; coluna < recebe_coluna; coluna++){

            recebe_matrizB[linha][coluna];

            printf("%5i", recebe_matrizB[linha][coluna]);

        }//for coluna

        printf("\n");

    }//for linha

    recebe_matrizC[recebe_linha][recebe_coluna] = soma_matriz(recebe_linha, recebe_coluna, recebe_matrizA, recebe_matrizB);

    printf("\nA matriz C com o resultado da soma das matrizes A e B tem formato:\n\n");

    for(linha = 0; linha < recebe_linha; linha++){

        for(coluna = 0; coluna < recebe_coluna; coluna++){

            recebe_matrizC[linha][coluna];

            printf("%5i", recebe_matrizC[linha][coluna]);

        }//for coluna

        printf("\n");

    }//for linha

return 0;
}//main

int soma_matriz(int linha, int coluna, int *matrizA, int *matrizB){

    int matrizC[linha][coluna];
    int l,c;//linha e coluna

    for(l = 0; l < linha; l++){

        for(c = 0; c < coluna; c++){

            matrizC[l][c] = matrizA[l][c] + matrizB[l][c];

        }//for coluna

    }//for linha

return matrizC[linha][coluna];
}//soma_matriz

void esclarecimentos(){

    printf("Este programa somara uma matriz A e B.\n\n");
    printf("O usuario deve informar as linhas, colunas e valores das matrizes.");
    printf("Sera exibido a soma em uma matriz C.\n\n");
    printf("Para os medias:\n\n");
    printf("Use numeros inteiros.\n\n");
    printf("Lembre que so e possivel somar matrizes quando elas possuem linhas e colunas iguais.\n\n");

return;
}//esclarecimentos
