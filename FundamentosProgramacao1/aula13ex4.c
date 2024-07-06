//@Marcos Tadao Shoji @2374200 @aula13ex4
/*
4) Faça um programa que receba um nome, ele deve perguntar
novamente caso o nome tenha tamanho inferior a 5 caracteres. Ao receber
um nome com 5 caracteres ou mais o programa exibe o nome e finaliza.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char nomes[30];
    int tamanho_nome;
    int loop = 0;
    int confirma;

    printf("Este programa recebera diferentes nomes.\n\n");
    printf("Entao sera checado a quantidade de caracteres.\n\n");
    printf("Se a quantidade de caracteres for inferior a 5.\n\n");
    printf("Ou seja com 4 caracteres ou menos.\n\n");
    printf("O programa perguntara se voce confirma a entrada.\n\n");
    printf("(1)Confirmara a entrada.\n\n(2)Negara a entrada e pedira uma nova.\n\n");
    printf("Para finalizar o programa o usario deve entrar um nome de 5 ou mais caracteres.\n\n");
    printf("O nome entrado sera exibido e o programa finalizado.\n\n");
    printf("Para finalizar o programa o nome deve ter no maximo 29 caracteres.\n\n");
    printf("Lembre que os espacos contam como caracteres, um cada espaco.\n\n");
    printf("Agora:\n");


    do{

        printf("\nInsira um nome:\n\n");
        fgets(nomes, 30, stdin);
        nomes[strcspn(nomes, "\n")] = '\0';
        setbuf(stdin, NULL);

        tamanho_nome = strlen(nomes);

        if(tamanho_nome >= 5){

            printf("\nEntrada com 5 ou mais caracteres.\n\n");
            printf("Nome: %-25s\n\n", nomes);
            printf("Finalizando programa.\n");
            break;

        }//if finaliza

        else if(tamanho_nome < 5){

            printf("\nVoce confirma a entrada deste nome?\n\n");
            printf("Insira (1) se sim ou (2) se nao:\n\n");
            scanf("%i", &confirma);
            setbuf(stdin, NULL);

            if(confirma == 1){

                printf("\nOk confirmado, prossiga.\n");

            }//if confirma

            else if(confirma == 2){

                printf("\nEntrada negada.\n\n");
                printf("Entre o nome desejado:\n\n");
                fgets(nomes, 30, stdin);
                nomes[strcspn(nomes, "\n")] = '\0';
                setbuf(stdin, NULL);

                tamanho_nome = strlen(nomes);

                if(tamanho_nome >= 5){

                    printf("\nEntrada com 5 ou mais caracteres.\n\n");
                    printf("Nome: %-25s\n\n", nomes);
                    printf("Finalizando programa.\n");
                    break;

                }//if finaliza

                else if(tamanho_nome < 5){

                    printf("\nNovo nome recebido, agora prossiga\n");

                }//if finaliza

            }//else if nega

        }//else if repete

    }while(loop >= 0);//do while loop

return 0;
}//main
