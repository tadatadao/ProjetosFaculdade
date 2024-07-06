//@Marcos Tadao Shoji @aula9ex1
/*
1) Faça um programa que calcule a média para 5 alunos, sendo que
cada aluno tem 2 notas (reais). O programa somente deverá aceitar
notas no intervalo fechado de 0 a 10, solicitando nova digitação
quando necessário.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    float primeira_nota;
    float segunda_nota;
    float media;
    int contador = 0;

    printf("Ola docente da UTFPR.\n\n");
    printf("Este programa vai te ajudar a calcular a media de 5 alunos.\n\n");
    printf("As notas podem ser numeros reais.\n\n");
    printf("Elas devem estar dentro do intervalo fechado de 0 a 10.\n\n");

    do {

        printf("Digite a primeira nota:\n\n");
        scanf("%f", &primeira_nota);
        printf("\nDigite a segunda nota:\n\n");
        scanf("%f", &segunda_nota);

        if (primeira_nota >= 0 && segunda_nota >= 0 && primeira_nota <= 10 && segunda_nota <= 10) {

            media = ((primeira_nota + segunda_nota) / 2);

            printf("\nA media do aluno e: %.2f\n\n", media);

        }//if nota nos padrões

            else {

                do {

                    printf("\nErro. Valores de notas invalidos.\n\n");
                    printf("Lembre-se, notas de 0 a 10.\n\n");
                    printf("Digite a primeira nota:\n\n");
                    scanf("%f", &primeira_nota);
                    printf("\nDigite a segunda nota:\n\n");
                    scanf("%f", &segunda_nota);

                }while (primeira_nota < 0 || segunda_nota < 0 || primeira_nota > 10 || segunda_nota > 10);

                media = ((primeira_nota + segunda_nota) / 2);

                printf("\nA media do aluno e: %.2f\n\n", media);

            }//else notas fora dos padrões

        contador++;

    }while (contador >= 0 && contador < 5);

return 0;
}//main
