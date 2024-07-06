//@Marcos Tadao Shoji @2374200 @aula11ex4
/*
4) Crie e inicialize um vetor de inteiros de tamanho 8. Faça a
soma dos seus elementos, e apresente o resultado.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int valores_usuario[8];
    int indice;
    int indice_2;
    int soma;

    printf("Este programa recebera 8 numeros do usuario.\n\n");
    printf("Entao os valores serao somados.\n\n");
    printf("Ao inserir o numero use valores inteiros.\n");

    for(indice = 0; indice < 8; indice++){

        printf("\nInsira um numero:\n\n");
        scanf("%i", &valores_usuario[indice]);

    }//for valores do usuario

    soma = valores_usuario[0];

    for(indice = 1; indice < 8; indice++){

        soma = soma + valores_usuario[indice];

    }//for soma dos valores

    printf("\nA soma dos valores vale: %i\n\n", soma);

return 0;
}//main
