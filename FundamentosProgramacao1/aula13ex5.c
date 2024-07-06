//@Marcos Tadao Shoji @2374200 @aula13ex5
/*
5) Faça um programa que receba uma frase e depois exiba quantas vezes
cada vogal aparece. Ele deve contar considerando o tamanho da String.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char frase[50];
    char vogal_a = 'a';
    char vogal_e = 'e';
    char vogal_i = 'i';
    char vogal_o = 'o';
    char vogal_u = 'u';
    char vogal_A = 'A';
    char vogal_E = 'E';
    char vogal_I = 'I';
    char vogal_O = 'O';
    char vogal_U = 'U';
    int tamanho_frase;
    int contador_a = 0;
    int contador_e = 0;
    int contador_i = 0;
    int contador_o = 0;
    int contador_u = 0;
    int posicao_caractere;

    printf("Este programa recebera uma frase do usuario\n\n");
    printf("Serao contadas e exibidas todas as vogais da frase.\n\n");
    printf("A frase possui um limite de 49 caracteres.\n\n");
    printf("Os espacos contam como caracteres, um cada espaco.\n\n");
    printf("Insira a frase:\n\n");
    fgets(frase, 50, stdin);
    frase[strcspn(frase, "\n")] = '\0';
    setbuf(stdin, NULL);

    tamanho_frase = strlen(frase) + 1;

    for(posicao_caractere = 0; posicao_caractere < tamanho_frase; posicao_caractere++){

        if(frase[posicao_caractere] == vogal_a || frase[posicao_caractere] == vogal_A){

            contador_a++;

        }//else if conta a

        else if(frase[posicao_caractere] == vogal_e || frase[posicao_caractere] == vogal_E){

            contador_e++;

        }//else if conta e

        else if(frase[posicao_caractere] == vogal_i || frase[posicao_caractere] == vogal_I){

            contador_i++;

        }//else if conta i

        else if(frase[posicao_caractere] == vogal_o || frase[posicao_caractere] == vogal_O){

            contador_o++;

        }//else if conta o

        else if(frase[posicao_caractere] == vogal_u || frase[posicao_caractere] == vogal_U){

            contador_u++;

        }//else if conta u

    }//for checa caractere

    printf("\nNa frase: '%s', foram usados:\n\n", frase);
    printf("A vogal 'a' foi utilizada %i vezes.\n\n", contador_a);
    printf("A vogal 'e' foi utilizada %i vezes.\n\n", contador_e);
    printf("A vogal 'i' foi utilizada %i vezes.\n\n", contador_i);
    printf("A vogal 'o' foi utilizada %i vezes.\n\n", contador_o);
    printf("A vogal 'u' foi utilizada %i vezes.\n", contador_u);

return 0;
}//main
