/*
2) Faça um programa que receba um número e determine
se ele é um número par ou ímpar.
 Obs.: Utilize o operador % que retorna o resto da divisão)
*/
#include <stdio.h>
#include <stdlib.h>
/*
Para determinar se um número é par:
O resto da divisão do número por 2 deve ser 0.
Se o resto for diferente de 0, o número é ímpar.
Par e ímpar são pertencentes ao conjunto dos números inteiros.
*/
int main() {

    int numero;
    int verificacao;
    printf("Esta com duvida se um numero e par ou impar?\n\n");
    printf("Entao vamos te ajudar!\n\n");
    printf("Primeiramente um numero so pode ser par ou impar.\n\n");
    printf("Se tal numero pertencer ao conjunto dos numeros inteiros.\n\n");
    printf("Insira o numero do qual voce esta com duvida:\n\n");
    scanf("%i", &numero);

    verificacao = numero % 2;

    if (verificacao == 0) {
        printf("\nEste numero e Par.\n");
    }//if
    else if (verificacao != 0) {
        printf("\nEste numero e Impar.\n");
    }
return 0;
}//else
