//@Marcos Tadao Shoji @2374200 @aula13ex1
/*
1) Crie um programa para armazenar 10 nomes em um vetor
e imprimir uma lista numerada
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char nomes[10][25];
    int linha;
    int contador = 1;

    printf("Este programa recebera 10 nomes.\n\n");
    printf("Entao eles serao exibidos em uma lista enumerada.\n\n");
    printf("O programa possui um limite de 24 entradas de caracteres.\n\n");
    printf("Os espacos contam como um caractere cada.\n");

    for(linha = 0; linha < 10; linha++, contador++){

        printf("\nDigite o nome (%i):\n\n", contador);
        fgets(nomes[linha], 25, stdin);
        nomes[linha][strcspn(nomes[linha], "\n")] = '\0';
        setbuf(stdin, NULL);

    }//for recebe nomes

    printf("\nA lista dos nomes apresenta-se abaixo:\n");

    for(linha = 0, contador = 1; linha < 10; linha++, contador++){

        printf("\nNome%-2i: %-25s\n", contador, nomes[linha]);

    }//for imprime nomes

return 0;
}//main
