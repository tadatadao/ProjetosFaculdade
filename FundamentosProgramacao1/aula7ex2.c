/*
2) Crie uma calculadora usando a instrução switch, que
pergunte qual das operações básicas quer fazer (+, -, *
e /), em seguida peça os dois números e mostre o
resultado da operação matemática entre eles.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    char operador;
    float numero1;
    float numero2;
    float soma;
    float subtracao;
    float divisao;
    float multiplicacao;

    printf("Esta e uma calculadora simples.\n\n");
    printf("Podem ser realizadas apenas:\n\n");
    printf("Somas, subtracoes, divisoes e multiplicacoes.\n\n");
    printf("As operacoes recebem apenas dois numeros.\n\n");
    printf("Ao inserir os numeros use (.) para quebra decimal.\n\n");
    printf("Digite:\n\n");
    printf("(a) para adicoes\n(s) para subtracoes\n(d) para divisoes\n(m) para multiplicacoes\n\n");
    scanf("%c", &operador);

    switch (operador) {

    case 'a':

        printf("\nInsira o primeiro valor a ser somado:\n\n");
        scanf("%f", &numero1);
        printf("\nInsira o segundo valor a ser somado:\n\n");
        scanf("%f", &numero2);

        soma = numero1 + numero2;

        printf("\nO resultado da soma e: %.2f\n", soma);
        break;

    case 's':

        printf("\nInsira o minuendo:\n\n");
        scanf("%f", &numero1);
        printf("\nInsira o subtraendo:\n\n");
        scanf("%f", &numero2);

        subtracao = numero1 - numero2;

        printf("\nO resultado da subtracao e: %.2f\n", subtracao);
        break;

    case 'd':

        printf("\nInsira o numerador:\n\n");
        scanf("%f", &numero1);
        printf("\nInsira o denominador:\n\n");
        scanf("%f", &numero2);

        divisao = numero1 / numero2;

        printf("\nO resultado da divisao e: %.2f\n", divisao);
        break;

    case 'm':

        printf("\nInsira o primeiro valor a ser multiplicado:\n\n");
        scanf("%f", &numero1);
        printf("\nInsira o segundo valor a ser multiplicado:\n\n");
        scanf("%f", &numero2);

        multiplicacao = numero1 * numero2;

        printf("\nO resultado da multiplicacao e: %.2f\n", multiplicacao);
        break;

    default:

        printf("\nCaracter invalido\n");

    }//switch

return 0;
}//main
