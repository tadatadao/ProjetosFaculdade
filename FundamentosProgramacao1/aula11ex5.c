//@Marcos Tadao Shoji @2374200 @aula11ex5
/*
5)Dado dois vetores, A (4 elementos) e B (5 elementos), faça
um programa em C que imprima todos os elementos comuns
aos dois vetores.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int elementos_a[4];
    int elementos_b[5];
    int indice_1;
    int indice_2;

    printf("Este programa montara 2 conjuntos com entradas do usuario.\n\n");
    printf("O primeiro conjunto sera 'A' e o segundo 'B'.\n\n");
    printf("O conjunto A recebe 4 numeros.\n\n");
    printf("O conjunto B recebe 5 numeros.\n\n");
    printf("Os numeros devem ser inteiros.\n");

    for(indice_1 = 0; indice_1 < 4; indice_1++){

        printf("\nEntre com um valor para A:\n\n");
        scanf("%i", &elementos_a[indice_1]);

    }//for valores de A

    printf("\n\n---------------------------------------\n\n");

    for(indice_2 = 0; indice_2 < 5; indice_2++){

        printf("\nEntre com um valor para B:\n\n");
        scanf("%i", &elementos_b[indice_2]);

    }//for valores de B

    printf("\n\n---------------------------------------\n\n\n");

    printf("Sao iguais os numeros:\n\n");

    for(indice_1 = 0; indice_1 < 4; indice_1++){

        elementos_a[indice_1];

        for(indice_2 = 0; indice_2 < 5; indice_2++){

            elementos_b[indice_2];

            if(elementos_a[indice_1] == elementos_b[indice_2]){

               printf("%i\n", elementos_a[indice_1]);

            }//if iguais

        }//for circula os elementos B

    }//for iguais

return 0;
}//main
