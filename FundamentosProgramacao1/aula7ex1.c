/*
1) Crie um programa que forneça um menu com duas
opções. Caso o usuário digite 1, o programa solicitará um
número e verificará se o valor é par ou impar. Caso o
usuário digite 2, o programa solicitará uma idade e
verificará se pessoa é maior ou menor de idade.
Veja o exemplo de menu abaixo:
Menu de programa:
1 – Verifica par/impar
2 – Verifica maior/menor de idade
Digite sua opção:
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int opcao;
    int numero;
    int idade;

    printf("Este programa pode descobrir se um numero e par ou impar.\n\n");
    printf("E tambem podemos verificar se voce pode assistir ao filme: Alunos vida tensa\n\n");
    printf("Digite:\n\n");
    printf("1 se voce deseja descobir se um numero e par ou impar\n\n");
    printf("2 se voce quer saber se pode assistir ao filme: Alunos vida tensa\n\n");
    scanf("%i", &opcao);

    switch (opcao) {

    case 1:

        printf("\nDigite o numero que deseja classificar:\n\n");
        printf("Use apenas numeros inteiros.\n\n");
        scanf("%i", &numero);

        if(numero % 2 == 0) {
            printf("\nO numero %i e par.\n", numero);
        }//if par
            else if(numero % 2 != 0) {
                printf("\nO numero %i e impar.\n", numero);
            }//else impar
        break;

    case 2:

        printf("\nO filme possui classificacao indicativa 18+.\n\n");
        printf("Digite a sua idade:\n\n");
        scanf("%i", &idade);

        if(idade >= 18) {
            printf("\nVoce pode assistir Alunos vida tensa.\n");
        }//if pode assistir
            else {
                printf("\nVoce nao pode assistir Alunos vida tensa.\n");
            }//else nao pode assistir
        break;

    default:

        printf("\nEi opcao invalida.\n");

    }//switch

return 0;
}//main
