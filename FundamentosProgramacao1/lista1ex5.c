/*
5) Faça um programa que receba 2 números referentes ao numerador e denominador de uma fração
e informe se é uma fração própria, imprópria, ou aparente
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    float numerador;
    float denominador;
    float resto;
    float divisao;
    int numero;

    printf("Vamos classificar dada fracao em:\n\n");
    printf("propria; impropria; aparente\n\n");
    printf("Informe o numerador (apenas inteiros):\n\n");
    scanf("%f", &numerador);
    printf("\nAgora o denominador (apenas inteiros):\n\n");
    scanf("%f", &denominador);

    if (denominador == 0) {
        printf("\nCuidado com divisoes por zero.\n");
    }//if divisao por 0

        else {

            resto = (int)numerador % (int)denominador;
            divisao = numerador / denominador;



            if (divisao >= 1 && resto == numero) {
                printf("\nEssa e uma fracao impropria e aparente.\n");
            }//else improprio e aparente

                else if (divisao >=1 & resto != numero) {
                    printf("\nEssa e uma fracao impropria.\n");
                }//else improprio

                    else if (divisao < 1 && divisao > 0) {
                        printf("\nEssa e uma fracao propria.\n");
                    }//else proprio

                        else if (divisao < 0) {
                            printf("\nValor negativo, ou seja, nao classificavel.\n");
                        }//else valor negativo

                            else if (divisao == 0) {
                                printf("\nFracionamento de zero nao e classificavel.\n");
                            }//numerador 0
        }//else

return 0;
}//main
