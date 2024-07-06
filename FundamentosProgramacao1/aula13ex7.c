//@Marcos Tadao Shoji @2374200 @aula13ex7
/*
7) Escreva um programa que receba uma sigla de um estado da região
Sul ou Sudeste e exiba o nome completo do estado correspondente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char siglas[7][3] = {"ES","MG","PR","RJ","RS","SC","SP"};
    char estados[7][25] = {"Espirito Santo","Minas Gerais","Parana","Rio de Janeiro","Rio Grande do Sul","Santa Catarina","Sao Paulo"};
    char usuario[5];
    int linha;
    int comparacao;

    printf("Este programa recebera siglas dos estados sul e sudeste.\n\n");
    printf("O programa exibira a sigla e o nome do estado.\n\n");
    printf("Insira a sigla do estado:\n\n");
    fgets(usuario, 5, stdin);
    usuario[strcspn(usuario, "\n")] = '\0';
    setbuf(stdin, NULL);
    printf("\nA sigla e o nome do estado sao:\n\n");

    for(linha = 0; linha < 7; linha++){

        comparacao = strcasecmp(usuario,siglas[linha]);

        if(comparacao == 0){

            printf("Sigla: %-5s| Estado: %-25s\n", siglas[linha], estados[linha]);

        }//if imprime

    }//for checa sigla

return 0;
}//main
