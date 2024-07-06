/**
 * @file aula22ex3.txt
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 3)Crie uma estrutura representando um atleta. Essa estrutura
            deve conter o nome do atleta, seu esporte, idade e altura. Agora,
            escreva um programa que leia os dados de cinco atletas e os
            armazene em um arquivo binário.
 * @version 0.1
 * @date 2022-05-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{

    char nome[50];
    char esporte[50];
    int idade;
    float altura;

}Atleta;

void escreve_arquivo_atleta(Atleta atle[]){

    for(int linha = 0; linha < 5; linha++){

        printf("\nPara o atleta [%i]:\n\n", linha + 1);
        printf("Digite o nome do atleta:\n\n");
        fgets(atle[linha].nome, 49, stdin);
        atle[linha].nome[strcspn(atle[linha].nome, "\n")] = '\0';
        setbuf(stdin, NULL);

        printf("\nDigite o esporte do atleta:\n\n");
        fgets(atle[linha].esporte, 49, stdin);
        atle[linha].esporte[strcspn(atle[linha].esporte, "\n")] = '\0';
        setbuf(stdin, NULL);

        printf("\nDigite a idade do atleta em anos:\n\n");
        scanf("%i", &atle[linha].idade);
        setbuf(stdin, NULL);

        printf("\nDigite a altura do atleta em metros:\n\n");
        scanf("%f", &atle[linha].altura);
        setbuf(stdin, NULL);

    }//for linha

    FILE *arquivo = fopen("a22e3.dat", "wb");

    fwrite(atle, sizeof(Atleta), 5, arquivo);

    fclose(arquivo);

}//passa os dados do atleta para o arquivo.

int main(){

    Atleta alte[5];

    escreve_arquivo_atleta(alte);

return 0;
}//main
