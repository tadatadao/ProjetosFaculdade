//@Marcos Tadao Shoji @2374200 @aula13ex3
/*
3) Desenvolva um programa que armazene o nome e o
telefone de 5 pessoas. Ao digitar a posição desejada, o
programa deve exibir o nome e telefone daquela posição. O
programa finaliza ao receber a entrada -1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char nomes[5][25];
    int ddd[5];
    int telefones[5];
    int linhas;
    int loop = 0;
    int posicao = 1;

    printf("Este programa recebera nome e telefone de 5 pessoas.\n\n");
    printf("Cada nome e telefone sera guardado em uma posicao de 1 a 5.\n\n");
    printf("O usuario podera entrar com a posicao e ser informado dos dados inseridos.\n\n");
    printf("Ao inserir o nome ha um limite de 24 caracteres.\n\n");
    printf("Os espacos contam como caracteres, um cada espaco.\n\n");
    printf("Ao digitar o telefone ambos ddd e o numero devem ser valores naturais.\n\n");
    printf("Para encerrar a visualizacao de dados insira (-1) na posicao.\n\n");
    printf("Agora abaixo:\n");

    for(linhas = 0; linhas < 5; linhas++, posicao++){

        printf("\nInsira o nome da pessoa [%i]:\n\n", posicao);
        fgets(nomes[linhas], 25, stdin);
        nomes[linhas][strcspn(nomes[linhas], "\n")] = '\0';
        setbuf(stdin, NULL);
        printf("\nInsira o ddd da pessoa [%i]:\n\n", posicao);
        scanf("%i", &ddd[linhas]);
        setbuf(stdin, NULL);
        printf("\nInsira o telefone da pessoa [%i]:\n\n", posicao);
        scanf("%i", &telefones[linhas]);
        setbuf(stdin, NULL);

    }//for preenche dados

    while(loop >= 0){

        printf("\nAs posicoes sao de 1 a 5.\n\n");
        printf("Para sair digite (-1).\n\n");
        printf("Insira a posicao desejada:\n\n");
        scanf("%i", &posicao);

        if(posicao == 1){

            printf("\nNome: %-25s | Telefone: (%i)%i\n", nomes[0], ddd[0], telefones[0]);

        }//if posicao 1

        else if(posicao == 2){

            printf("\nNome: %-25s | Telefone: (%i)%i\n", nomes[1], ddd[1], telefones[1]);

        }//else if posicao 2

        else if(posicao == 3){

            printf("\nNome: %-25s | Telefone: (%i)%i\n", nomes[2], ddd[2], telefones[2]);

        }//else if posicao 3

        else if(posicao == 4){

            printf("\nNome: %-25s | Telefone: (%i)%i\n", nomes[3], ddd[3], telefones[3]);

        }//else if posicao 4

        else if(posicao == 5){

            printf("\nNome: %-25s | Telefone: (%i)%i\n", nomes[4], ddd[4], telefones[4]);

        }//else if posicao 5

        else if(posicao == -1){

            printf("\nFinalizando programa.\n");
            break;

        }//else if encerra

        else if(posicao < 1 || posicao > 5){

            printf("\nPosicao invalida tente novamente por favor.\n");

        }//else if invalido

    }//while loop

return 0;
}//main
