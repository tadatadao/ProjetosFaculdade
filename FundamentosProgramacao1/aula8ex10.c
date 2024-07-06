//@Marcos Tadao Shoji @aula8ex10
/*
Faça um programa que calcule a média para 5 alunos,
sendo que cada aluno tem 2 notas (reais).
O programa somente deverá aceitar notas no intervalo fechado de 0 a 10,
solicitando nova digitação quando necessário.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    float nota1;
    float nota2;
    float media;
    int inicial;

    printf("Ola professor da UTFPR!\n\n");
    printf("Este programa calcula a media para 5 alunos.\n\n");
    printf("A media e calculada entre duas notas.\n\n");
    printf("As notas devem ter escala de 0 a 10.\n\n");
    printf("As notas pertencem ao conjunto de numeros reais.\n\n");
    printf("Use (.) para quebra decimal.\n\n");

    for (inicial = 0; inicial < 5; inicial++) {

        printf("Insira a primeira nota:\n\n");
        scanf("%f", &nota1);
        printf("\nInsira a segunda nota:\n\n");
        scanf("%f", &nota2);

        if(nota1 >= 0 && nota1 <= 10 && nota2 >= 0 && nota2 <= 10) {

            media = ((nota1 + nota2) / 2);

            printf("\nA media do aluno foi de: %.2f\n\n", media);

        }//if

            else {

                while(nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10) {

                    printf("\nLembre-se as notas estao no intervalo de 0 a 10.\n\n");
                    printf("Insira novamente a primeira nota:\n\n");
                    scanf("%f", &nota1);
                    printf("\nInsira novamente a segunda nota:\n\n");
                    scanf("%f", &nota2);

                }//while

                media = ((nota1 + nota2) / 2);

                printf("\nA media do aluno foi de: %.2f\n\n", media);

            }//else

    }//for

return 0;
}//main


