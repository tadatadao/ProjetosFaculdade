/*
4) Calcule a média aritmética de 4 números reais que o usuário
digitar. Imprima a média na tela apenas com 2 casas decimais.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    double numero1;
    double numero2;
    double numero3;
    double numero4;
    double media;
    /*
    média aritmética é a soma de todos os números
    dividdo pela quantidade de números.
    */
    printf("Vamos calcular uma media aritmetica entre 4 numeros.\n\n");
    printf("Nos informe o primeiro numero, lembre-se de usar a quebra decimal com (.).\n");
    scanf("%lf", &numero1);
    printf("\nNos informe o segundo numero.\n");
    scanf("%lf", &numero2);
    printf("\nNos informe o terceiro numero.\n");
    scanf("%lf", &numero3);
    printf("\nNos informe o quarto numero.\n");
    scanf("%lf", &numero4);

    media = (numero1 + numero2 + numero3 + numero4) / 4;

    printf("\nA media aritmetica dos valores informados e: %.2lf\n", media);

return 0;
}
