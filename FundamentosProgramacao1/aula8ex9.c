//@Marcos Tadao Shoji @aula8ex9
/*
9) Faça um programa que simule um jogo, onde o usuário
deverá descobrir um número aleatório escolhido pelo
computador (de 1 a 100).
 O usuário poderá realizar até 6 tentativas, o programa deverá
retornar as mensagens “muito alto”, “muito baixo” até o usuário
acertar o número ou esgotar o número máximo de tentativas
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

    int inicial;
    int inicial2;
    int numero_escolhido;
    int numero_inserido;

    printf("Este programa vai testar sua sorte.\n\n");
    printf("Vamos escolher um numero entre 0 e 100.\n\n");
    printf("Em seguida voce ira digitar um numero.\n\n");
    printf("Se o numero digitado for igual ao numero que escolhemos.\n\n");
    printf("Voce ganha o jogo.\n\n");
    printf("Se apos 6 tentativas voce nao acertar.\n\n");
    printf("Voce perde o jogo.\n\n");

    srand(time(NULL));

    for (inicial = 1; inicial < 2; inicial++) {

        numero_escolhido = 1 + rand() % 100;

    }//for numero aleatorio

    for (inicial2 = 0; inicial2 < 6; inicial2++) {

        printf("Digite um numero entre 0 e 100:\n\n");
        scanf("%i", &numero_inserido);

        if(numero_escolhido == numero_inserido) {

            printf("\nUau!! Voce ganhou!!\n\n");

        }//if ganhou

            else if(numero_escolhido < numero_inserido) {

                printf("\nTente um valor menor.\n\n");

            }//else menor

                else if(numero_escolhido > numero_inserido) {

                    printf("\nTente um valor maior.\n\n");

                }//else maior

    }//for

    printf("\nJogue de novo e tente a sorte!!\n");

return 0;
}//main
