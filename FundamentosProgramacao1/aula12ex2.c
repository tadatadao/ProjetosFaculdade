//@Marcos Tadao Shoji @2374200 @aula12ex2
/*
2) Faça um algoritmo que leia uma matriz 3 por 3 (3x3) e
retorna a soma dos elementos da sua diagonal principal e
da sua diagonal secundária;
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int matriz[3][3];
    int linha;
    int coluna;
    int soma_diagonal_principal = 0;
    int soma_diagonal_secundaria = 0;

    printf("Este programa recebera uma matriz 3 x 3.\n\n");
    printf("Serao calculados a somas dos elementos das:\n\n");
    printf("Diagonais principais e diagonais secundarias.\n\n");
    printf("Ao inserir os elementos da matriz use numeros inteiros.\n");

    for(linha = 0; linha < 3; linha++){

        for(coluna = 0; coluna < 3; coluna++){

            matriz[linha][coluna];

            printf("\nInsira o elementeo [%i] x [%i]:\n\n", linha, coluna);
            scanf("%i", &matriz[linha][coluna]);

        }//for coluna

    }//for linha

    printf("\nA matriz inserida fica:\n\n");

    for(linha = 0; linha < 3; linha++){

        for(coluna = 0; coluna < 3; coluna++){

            matriz[linha][coluna];

            printf("%4i", matriz[linha][coluna]);

        }//for coluna

        printf("\n");

    }//for linha

    for(linha = 0; linha < 3; linha++){

        for(coluna = 0; coluna < 3; coluna++){

            matriz[linha][coluna];

            if((linha - coluna) == 0){

                soma_diagonal_principal = soma_diagonal_principal + matriz[linha][coluna];

            }//if soma da diagonal principal

        }//for coluna

    }//for linha

    for(linha = 0; linha < 3; linha++){

        for(coluna = 0; coluna < 3; coluna++){

            matriz[linha][coluna];

            if((linha + coluna) == 2){

                soma_diagonal_secundaria = soma_diagonal_secundaria + matriz[linha][coluna];

            }//if soma da diagonal secundaria

        }//for coluna

    }//for linha

    printf("\nA soma dos elementos da diagonal principal vale: %i\n\n", soma_diagonal_principal);
    printf("A soma dos elementos da diagonal secundaria vale: %i\n", soma_diagonal_secundaria);

return 0;
}//main
