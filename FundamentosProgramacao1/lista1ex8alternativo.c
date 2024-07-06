/*
8) Crie um programa que, ao receber três números,
verifique se podem ser lados de um triângulo e nesse caso mostre se o triângulo é equilátero,
isosceles ou escaleno.
Caso seja um triângulo retângulo, o programa deve também informar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>>

/*
Só irá existir um triângulo se, somente se, os seus lados obedeceram à seguinte regra:
um de seus lados deve ser maior que o valor absoluto (módulo) da diferença dos outros dois lados
e menor que a soma dos outros dois lados. Veja o resumo da regra abaixo:

| b - c | < a < b + c
| a - c | < b < a + c
| a - b | < c < a + b
*/

int main() {

    float lado_a;
    float lado_b;
    float lado_c;
    float triangulo_retangulo;
    int contador = 0;

    printf("Neste programa sera verificado a existencia de um triangulo.\n\n");
    printf("Para isso serao inseridos os comprimentos de 3 linhas.\n\n");
    printf("Entao o programa fara a leitura se as 3 linhas podem formar um triangulo.\n\n");
    printf("Por fim o triangulo sera classificado em:\n\n");
    printf("Isosceles, equilatero ou escaleno.\n\n");
    printf("Tambem sera informado se o traingulo e retangulo.\n\n");
    printf("Serao usados as regras de condicao de exitencia.\n\n");
    printf("Os lados nao podem conter valores negativos.\n\n");
    printf("Caso necessario use (.) como quebra decimal.\n\n");
    printf("Insira o valor do primeiro lado:\n\n");
    scanf("%f", &lado_a);
    printf("\nInsira o segundo lado:\n\n");
    scanf("%f", &lado_b);
    printf("\nInsira o terceiro lado:\n\n");
    scanf("%f", &lado_c);

    if((abs(lado_b - lado_c) >= lado_a) || (abs(lado_a - lado_c) >= lado_b) || (abs(lado_a - lado_b) >= lado_c)){

        printf("\nNao e possivel montar um triangulo com estes valores.\n\n");

    }//if nao da triangulo

        else {

            while (contador < 1){

                if((abs(lado_b - lado_c) < lado_a && lado_a < lado_b + lado_c) || (abs(lado_a - lado_c) < lado_b && lado_b < lado_a + lado_c) || (abs(lado_a - lado_b) < lado_c && lado_b < lado_a + lado_b)){

                    printf("\nCom estes lados e possivel montar um triangulo.\n\n");

                    if(lado_a == lado_b || lado_a == lado_c || lado_b == lado_c){

                        printf("O triangulo e isosceles.\n\n");

                    }//if isoceles

                        else if(lado_a == lado_b && lado_b == lado_c){

                            printf("O triangulo e equilatero.\n\n");

                        }//else if equilatero

                            else if(lado_a != lado_b && lado_a != lado_c && lado_b != lado_c){

                                printf("O triangulo e escaleno.\n\n");

                            }//else if escaleno

                }//if triangulo

                contador++;

            }//while contador

        }//else

return 0;
}//main
