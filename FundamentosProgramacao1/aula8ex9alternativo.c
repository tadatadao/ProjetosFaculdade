#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int inicial = 1;
    int inicial2 = 0;
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

    while(inicial >= 1 && inicial < 2) {

        numero_escolhido = 1 + rand() % 100;

        inicial++;

    }//while escolhendo

    while(inicial2 >= 0 && inicial2 <6) {

        printf("Digite um numero de 0 a 100:\n\n");
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

        inicial2++;

    }//while jogo

    printf("Jogue de novo!!\n");

return 0;
}//main
