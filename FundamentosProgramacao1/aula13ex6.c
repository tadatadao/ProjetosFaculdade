//@Marcos Tadao Shoji @2374200 @aula13ex6
/*
6) Faça um programa que receba um nome e um sobrenome. Ele deve
construir uma nova string no formato americano (Sobrenome, Nome)
Exemplo: Silva, José
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char nome[25];
    char sobrenome[25];

    printf("Este programa recebera um nome e um sobrenome.\n\n");
    printf("O nome recebido sera convertido para o formato americano:\n\n");
    printf("Sobrenome, Nome\n\n");
    printf("Ambos nome e sobrenome possuem um limite de 24 caracteres.\n\n");
    printf("Os espacos contam como caracteres, 1 cada espaco.\n\n");
    printf("Agora:\n\n");
    printf("Insira o nome:\n\n");
    fgets(nome, 25, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    setbuf(stdin, NULL);
    printf("\nInsira o sobrenome.:\n\n");
    fgets(sobrenome, 25, stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0';
    setbuf(stdin, NULL);
    printf("\nO nome no formato americano fica:\n\n");
    printf("%s, %s\n", sobrenome, nome);

return 0;
}//main
