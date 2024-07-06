/*
3) Altere o exercício anterior para receber os 3 valores no
mesmo scanf.
Exemplo:
Digite a conta a ser realizada: 5+8
O resultado é: 13
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    char operador;
    float numero1;
    float numero2;
    float conta;

    printf("Esta e uma calculadora simples.\n\n");
    printf("Podem ser realizadas apenas:\n\n");
    printf("Somas, subtracoes, divisoes e multiplicacoes.\n\n");
    printf("As operacoes recebem dois numeros.\n\n");
    printf("Utilize os operadores:\n\n");
    printf("(+) para soma\n(-) para subtracao\n(/) para divisao\n(*) para multiplicacao\n\n");
    printf("Use (.) para quebra decimal.\n\n");
    printf("Para realizar a conta digite:\n\n");
    printf("(numero qualquer)(operador)(numero qualquer)\n\n");
    printf("Respeitando as regras insira a conta:\n\n");
    scanf("%f%c%f", &numero1, &operador, &numero2);

    switch (operador) {

    case '+':

        conta = numero1 + numero2;

        printf("\nO resultado e: %.2f\n", conta);
        break;

    case '-':

        conta = numero1 - numero2;

        printf("\nO resultado e: %.2f\n", conta);
        break;

    case '/':

        conta = numero1 / numero2;

        printf("\nO resultado e: %.2f\n", conta);
        break;

    case '*':

        conta = numero1 * numero2;

        printf("\nO resultado e: %.2f\n", conta);
        break;

    default:

        printf("\nFoi cometido um erro, respeite as regras.\n\n");

    }//switch

return 0;
}//main
