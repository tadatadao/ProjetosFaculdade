/*
8) Crie um programa que, ao receber tr�s n�meros,
verifique se podem ser lados de um tri�ngulo e nesse caso mostre se o tri�ngulo � equil�tero,
isosceles ou escaleno.
Caso seja um tri�ngulo ret�ngulo, o programa deve tamb�m informar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>>

/*
S� ir� existir um tri�ngulo se, somente se, os seus lados obedeceram � seguinte regra:
um de seus lados deve ser maior que o valor absoluto (m�dulo) da diferen�a dos outros dois lados
e menor que a soma dos outros dois lados. Veja o resumo da regra abaixo:

| b - c | < a < b + c
| a - c | < b < a + c
| a - b | < c < a + b
*/

int main() {

    float lado_a;
    float lado_b;
    float lado_c;

    printf("Neste programa sera verificado a existencia de um triangulo.\n\n");
    printf("Para isso serao inseridos os comprimentos de 3 linhas.\n\n");
    printf("Entao o programa fara a leitura se as 3 linhas podem formar um triangulo.\n\n");
    printf("Por fim o traangulo sera classificado em:\n\n");
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

    if((abs(lado_b - lado_c) < lado_a && lado_a < lado_b + lado_c) || (abs(lado_a - lado_c) < lado_b && lado_b < lado_a + lado_c) || (abs(lado_a - lado_b) < lado_c && lado_b < lado_a + lado_b)) {

        printf("\nCom os lados oferecidos pode-se construir um triangulo.\n\n");

        if((lado_a == lado_b && lado_a != lado_c) || (lado_a == lado_c && lado_a != lado_b) || (lado_b == lado_c && lado_b != lado_a)){

            printf("O triangulo e isosceles.\n\n");

            if((pow(lado_a,2) == pow(lado_b,2) + pow(lado_c,2)) || (pow(lado_b,2) == pow(lado_a,2) + pow(lado_c,2)) || (pow(lado_c,2) == pow(lado_a,2) + pow(lado_b,2))){

                printf("O triangulo tambem e retangulo.\n\n");

            }//if triangulo retangulo

        }//if isoceles

            else if(lado_a == lado_b && lado_b == lado_c){

                printf("O triangulo e equilatero.\n\n");
                printf("Os triangulos equilateros nao podem ser retangulos.\n\n");

            }//else if equilatero

                else if(lado_a != lado_b && lado_a != lado_c && lado_b != lado_c){

                    printf("O triangulo e escaleno.\n\n");

                    if((pow(lado_a,2) == pow(lado_b,2) + pow(lado_c,2)) || (pow(lado_b,2) == pow(lado_a,2) + pow(lado_c,2)) || (pow(lado_c,2) == pow(lado_a,2) + pow(lado_b,2))){

                        printf("O triangulo tambem e retangulo.\n\n");

                    }//if triangulo retangulo

                }//else if escaleno

    }//if triangulo

        else if((abs(lado_b - lado_c) >= lado_a) || (abs(lado_a - lado_c) >= lado_b) || (abs(lado_a - lado_b))){

            printf("\nNao e possivel montar um triangulo com estes lados.\n\n");

        }//else nao possivel

return 0;
}//main
