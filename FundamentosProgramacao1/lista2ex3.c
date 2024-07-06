/*
3) Faça um programa que solicite o tamanho de um quadrado e mostre a borda de um quadrado utilizando o caracter #.
Exemplo:
Digite o tamanho desejado: 10

#	#	#	#	#	#	#	#	#	#
#									#
#									#
#									#
#									#
#									#
#									#
#									#
#									#
#	#	#	#	#	#	#	#	#	#
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    char hashtag = '#';
    int tamanho;
    int linha;
    int coluna;

    printf("Este programa imprimira uma matriz quadrada.\n\n");
    printf("As bordas da matriz serao contidas pelo caractere '#'.\n\n");
    printf("O usuario informara o tamnho da matriz.\n\n");
    printf("Use apenas numeros naturais e positivos.\n\n");
    printf("Insira o tamanho da matriz:\n\n");
    scanf("%i", &tamanho);
    printf("\nA matriz fica:\n\n");

    int matriz[tamanho][tamanho];

    for(linha = 0; linha < tamanho; linha++){

        for(coluna = 0; coluna < tamanho; coluna++){

            if(coluna == 0 || linha == 0 || linha == tamanho -1 || coluna == tamanho - 1){

                printf("%c", hashtag);

            }//if #

            else{

                printf(" ");

            }//else vazio

        }//for colunha

        printf("\n");

    }//for linha

return 0;
}//main
