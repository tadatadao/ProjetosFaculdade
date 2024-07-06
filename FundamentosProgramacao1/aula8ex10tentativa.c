//@Marcos Tadao Shoji @aula8ex10tentativa
/*
Fa�a um programa que calcule a m�dia para 5 alunos,
sendo que cada aluno tem 2 notas (reais).
O programa somente dever� aceitar notas no intervalo fechado de 0 a 10,
solicitando nova digita��o quando necess�rio.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    float nota1;
    float nota2;
    float media;
    int inicial = 0;

    printf("Ola professor da UTFPR!\n\n");
    printf("Este programa calcula a media para 5 alunos.\n\n");
    printf("A media e calculada entre duas notas.\n\n");
    printf("As notas devem ter escala de 0 a 10.\n\n");
    printf("As notas pertencem ao conjunto de numeros reais.\n\n");
    printf("Use (.) para quebra decimal.\n\n");

    while(inicial >= 0 && inicial < 5) {

        printf("Insira a primeira nota:\n\n");
        scanf("%f", &nota1);
        printf("\nInsira a segunda nota:\n\n");
        scanf("%f", &nota2);

        media = ((nota1 + nota2) / 2);

        if(nota1 >= 0 && nota1 <= 10 && nota2 >= 0 && nota2 <= 10){

            printf("\nA media do aluno e: %.2f\n\n", media);

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

                printf("\nA media do aluno e: %.2f\n\n", media);

            }//else

        inicial++;

    }//while

return 0;
}//main
