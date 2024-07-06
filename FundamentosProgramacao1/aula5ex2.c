/*
2) Faça um programa que calcule e mostre a idade de uma
pessoa a partir do ano em que a pessoa nasceu e do ano atual.
Os valores serão digitados pelo usuário.
Obs.:Considere que ela já fez aniversário neste ano.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int ano_atual;
    int ano_nascimento;
    int idade;
    /*
    Para calculara a idade aproximada basta subtrair o ano atual pelo ano de nascimeto.
    */
    printf("Se voce abriu este arquivo significa que voce deseja saber sua idade aproximada.\n");
    printf("Nos informe o ano atual\n");
    scanf("%i", &ano_atual);
    printf("\nNos informe seu ano de nascimento.\n");
    scanf("%i", &ano_nascimento);

    idade = (ano_atual - ano_nascimento);

    printf("\nAgora magica!\n\n");
    printf("Sua idade e de %i anos.\n", idade);

return 0;
}
