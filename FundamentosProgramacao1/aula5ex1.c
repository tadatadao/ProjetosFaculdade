/*
1) Faça um programa que receba a altura de uma pessoa e
calcule e exiba seu peso ideal utilizando a seguinte:
peso ideal = 72.7 x altura – 58
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    float peso;
    float altura;

    printf("Para saber o peso ideal de uma pessoa pode-se utilizar a formula:\n\n");
    printf("Peso ideal = (72.7 * altura) - 58\n\n");
    printf("Vamos descobrir o seu peso ideal?\n\n");
    printf("Digite a sua altura em metros usando (.) como quebra decimal\n\n");
    scanf("%f", &altura);

    peso = (72.7 * altura) -58;

    printf("\nO seu peso ideal vale: %.2fkg\n", peso);

return 0;
}
