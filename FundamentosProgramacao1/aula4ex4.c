/*
4) Tendo a Altura da pessoa definida como uma constante,
calcule seu peso ideal utilizando a seguinte fórmula:
 peso ideal = 72.7 x altura – 58
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    float peso;
    float altura;
    altura = 1.72;
    peso = (72.7 * altura) -58;
    printf("Para saber o peso ideal de uma pessoa pode-se utilizar a formula:\n\n");
    printf("peso ideal = (72.7 * altura) - 58\n\n");
    printf("O peso ideal de uma pessoa com altura 1.72m vale: %fkg\n\n", peso);

return 0;

}
