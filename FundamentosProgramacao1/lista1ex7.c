/*
7) Considerando uma aplicação de renda fixa, faça um programa que receba o capital investido,
a taxa (em %) e a quantidade de meses.
O programa deverá retornar o montante final considerando o desconto do imposto de renda segundo regras abaixo:

22,5% - prazo inferior a 6 meses
20% - de 6 a 12 meses
17,5% - de 12 a 24 meses
15% - igual ou superior a 24 meses

Obs: O imposto é calculado apenas sobre o lucro da aplicação.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Para calcular juros compostos o montante é igual ao capital investido multiplicado
pela soma de um mais a taxa de juros inicial elevado ao tempo
*/

int main() {

    float capital_investido;
    float taxa_rendimento;
    float tempo_meses;
    float montante;
    float convercao_de_taxa;
    float lucro;
    float deducao;
    float taxa_deducao;
    float montante_final;

    printf("Vamos calcular o montante do seu investento.\n\n");
    printf("Informe o capital investido:\n\n");
    scanf("%f", &capital_investido);
    printf("\nInforme a taxa de rendimeto em porcentagem:\n\n");
    scanf("%f", &taxa_rendimento);
    printf("\nInforme o tempo em meses:\n\n");
    scanf("%f", &tempo_meses);

    convercao_de_taxa = taxa_rendimento / 100;
    montante = (capital_investido) * (pow(1 + convercao_de_taxa, tempo_meses));
    lucro = montante - capital_investido;

    printf("\nO montante do investimento e: %f reais\n\n", montante);
    printf("Agora vamos deduzir o imposto de renda no investimento.\n\n");

    if (tempo_meses < 6) {

        taxa_deducao = 0.225;
        deducao = lucro - (lucro * taxa_deducao);
        montante_final = montante - deducao;

        printf("O montante final sera de: %lf reais\n\n", montante_final);
    }//if 6 meses

        else if(tempo_meses >= 6 && tempo_meses <12) {

            taxa_deducao = 0.2;
            deducao = lucro - (lucro * taxa_deducao);
            montante_final = montante - deducao;

            printf("O montante final sera de: %lf reais\n\n", montante_final);
        }//else de 6 a 12 meses

                else if(tempo_meses >= 12 && tempo_meses <24) {

                    taxa_deducao = 0.175;
                    deducao = lucro - (lucro * taxa_deducao);
                    montante_final = montante - deducao;

                    printf("O montante final sera de: %lf reais\n\n", montante_final);
                }//else de 12 a 24 meses

                    else if(tempo_meses >= 24) {

                        taxa_deducao = 0.15;
                        deducao = lucro - (lucro * taxa_deducao);
                        montante_final = montante - deducao;

                        printf("O montante final sera de: %lf reais\n\n", montante_final);
                    }//else de 12 a 24 meses


return 0;
}//main
