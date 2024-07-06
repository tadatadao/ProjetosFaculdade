/*
3) Faça um programa que receba os coeficientes a, b e c
de uma equação do segundo grau e retorne as raízes da
equação (se existirem).
 Para isso, lembre-se da fórmula de Báskara:
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    /*
    Este programa mostrara um cáluculo pela fórmula de Báskara.
    Forma de uma equação do segundo grau:
    f(x) = a*x^2 + bx + c
    Formula de Báskara:
    x = – b ± √b^2 – 4ac
              2·a
    */
    double a;//a da fórmula de Báskara
    double b;//b da fórmula de Báskara
    double c;//c da fórmula de Báskara
    double d;//delta da fórmula de Báskara
    double x;//x único para delta = 0
    double x1;//resultado para x com delta > 0
    double x2;//resultado para x com delta > 0

    printf("Vamos praticar a formula de Baskara\n\n");
    printf("Lembre-se de usar (.) para quebra decimal.\n\n");
    printf("Entre a\n");
    scanf("%lf", &a);
    printf("Entre b\n");
    scanf("%lf", &b);
    printf("Entre c\n");
    scanf("%lf", &c);

    d = ((pow(b,2)) - (4 * a * c));

    if (d < 0){
        /*
        quando delta é negativo x não pertence aos reais.
        */
        printf("\nO valor de delta vale: %.2lf\n\n", d);
        printf("Portanto sera uma raiz negativa\n\n");
        printf("Logo x nao pertencera aos reais\n");
    }//if
    else if(d > 0){
        /*
        quando delta é positivo x possui dois resultados reais.
        */
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);

        printf("\nOs valores de x sao: %.2lf e %.2lf\n", x1, x2);
    }//else
    else if (d == 0) {
        /*
        quando delta é igual a zero x possui apenas um resultado real.
        */
        x = -b / (2 * a);

        printf("\nO valor de x e: %.2lf\n", x);
    }//else

return 0;
}//main
