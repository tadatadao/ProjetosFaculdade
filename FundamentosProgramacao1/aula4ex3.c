/*
3) Faça um programa com 2 variáveis, A e B, onde A terá
o valor 40 e B terá o valor -1. Imprima o valor de A+B, A-B,
AxB e A/B. Em seguida, faça B incrementar de uma
unidade e repita as 4 operações.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    float a; //variavel A
    float b; //variavel B
    float soma;
    float subtrai;
    float multiplica;
    float divide;
    a = 40;
    b = -1;
    soma = a + b;
    subtrai = a - b;
    multiplica = a * b;
    divide = a / b;
    printf("Existe o valor A = 40\n");
    printf("Existe o valor B = -1\n");
    printf("A soma de A + B = %.2f\n", soma);
    printf("A diferenca de A - B = %.2f\n", subtrai);
    printf("A multiplicacao de A * B = %.2f\n", multiplica);
    printf("A divisao A / B = %.2f\n\n\n", divide);
    b= ++b;
    soma = a + b;
    subtrai = a - b;
    multiplica = a * b;
    divide = a / b;
    printf("Caso incremente-se o valor de B em +1, teremos:\n");
    printf("A soma de A + B = %.2f\n", soma);
    printf("A diferenca de A - B = %.2f\n", subtrai);
    printf("A multiplicacao de A * B = %.2f\n", multiplica);
    printf("A divisao A / B = Nao pertecentes aos reais. Divisao por zero.\n");

return 0;

}
